#include "dec.h"
#include "cmd.h" 

// ---------------------------------------------- StringTipoVar
StringTipoVar::StringTipoVar(){
    tam = "256";
}

StringTipoVar::StringTipoVar(string tm){
    tam = tm;
}

string StringTipoVar::getTipo(){
    return "string";
}

string StringTipoVar::getSize(){
    return tam;
}

string StringTipoVar::codeGen(ofstream &output){
    output << "\nstring ";
    return "";
}

// --------------------------------------------------- BoolTipoVar
BoolTipoVar::BoolTipoVar(){
    tam = "1";
}

string BoolTipoVar::getTipo(){
    return "bool";
}

string BoolTipoVar::getSize(){
    return tam;
}

string BoolTipoVar::codeGen(ofstream &output){
    output << "\nbool ";
    return "";
}

// ----------------------------------------------------- IntTipoVar
IntTipoVar::IntTipoVar(){
    tam = "1";
}

string IntTipoVar::getTipo(){
    return "int";
}

string IntTipoVar::getSize(){
    return tam;
}

string IntTipoVar::codeGen(ofstream &output){
    output << "\nint ";
    return "";
}

//-------------------------------------------------------- DecVarSimples
SpecVarSimples::SpecVarSimples(string id1, Exp *ini, int line1){
    inicializacao = ini;
    id = id1;
    line = line1;
}

SpecVarSimples::SpecVarSimples(string id1, int line1){
    inicializacao = nullptr;
    id = id1;
    line = line1;
}

string SpecVarSimples::codeGen(ofstream &output){
    output << id;
    if (inicializacao != nullptr){
        output << " = ";
        inicializacao->codeGen(output);
    }

    return "";
}

int SpecVarSimples::eval(){
    int cond = 1;

    if (inicializacao != nullptr){
        cond &= inicializacao->eval();
    }

    return cond;
}

string SpecVarSimples::getId(){
    return id;
}

bool SpecVarSimples::isArranjo(){
    return false;
}

bool SpecVarSimples::confereTipagem(string tipo){
    if(inicializacao != nullptr){
        if (tipo != inicializacao->getTipo()){
            cout << "Erro Semântico (l: " << line <<"): inicializaçã de variável ("<< id 
            <<") de tipo incorreto! ("<<inicializacao->getTipo() << " != "<<tipo <<")\n";
            return false;
        }
    }

    return true;
}

// ------------------------------------------------------------- SpecVarArranjo
SpecVarArranjo::SpecVarArranjo(string id1, Exp *tama, list<Exp *> *ini, int line1){
    inicializacao = ini;
    tam = tama;
    id = id1;
    line = line1;
}

SpecVarArranjo::SpecVarArranjo(string id1, Exp *tama, int line1){
    inicializacao = nullptr;
    tam = tama;
    id = id1;
    line = line1;
}

string SpecVarArranjo::codeGen(ofstream &output){
    output << id << "[";
    tam->codeGen(output);
    output << "]";
    if (inicializacao != nullptr){
        output << " = {";

        list<Exp *>::iterator i = inicializacao->begin();
        (*i)->codeGen(output);
        ++i;

        while(i != inicializacao->end()){
            output << ", ";
            (*i)->codeGen(output);
            ++i;
        }
        output << "}";

    }

    return "";
}

int SpecVarArranjo::eval(){
    int cond = 1;

    if (inicializacao != nullptr){
        list<Exp *>::iterator i;

        for (i = inicializacao->begin(); i != inicializacao->end(); ++i){
            cond &= (*i)->eval();
        }
    }

    return cond;
}

string SpecVarArranjo::getId(){
    return id;
}

bool SpecVarArranjo::isArranjo(){
    return true;
}

bool SpecVarArranjo::confereTipagem(string tipo){
    bool retorno = true;
    int count = 0;
    list<Exp *>::iterator i;
    
    if(inicializacao != nullptr){
        for(i=this->inicializacao->begin(); i != this->inicializacao->end(); ++i){
            count++;
            if ((*i)->getTipo() != tipo){
                cout << "Erro Semântico (l: " << line <<"): parâmetro #" << count 
                << " da inicialização de variável arranjo '"<<id
                <<"' possui tipo incorreto (" << (*i)->getTipo() << " != " <<tipo <<")\n";

                retorno = false;
            }    
        }
    }

    return retorno;
}

// -------------------------------------------------------- Param
Param::Param(string id1, bool arranj){
    id = id1;
    arranjo = arranj;
}

string Param::getId(){
    return id;
}

bool Param::getArranjo(){
    return arranjo;
}

// -------------------------------------------------------- SpecParam
SpecParam::SpecParam(list<Param *> *lista, TipoVar *typ){
    cnjParam = lista;
    type = typ;
}

list<Param *>* SpecParam::getCnjParam(){
    return cnjParam;
}

string SpecParam::getTipo(){
    return type->getTipo();
}

int SpecParam::getSize(){
    return cnjParam->size();
}

// --------------------------------------------------------- DeclVar
DeclVar::DeclVar(list<SpecVar *> *lista, TipoVar *type){
    listaSpecVar = lista;
    tipo = type;
}

string DeclVar::codeGen(ofstream &output){
    list<SpecVar *>::iterator i;

    for(i = listaSpecVar->begin(); i != listaSpecVar->end(); ++i){
        output << "\n" << tipo->getTipo() << " ";
        (*i)->codeGen(output);
        output << ";\n";
    }

    return "";
}

int DeclVar::eval(){
    list<SpecVar *>::iterator i;
    int retorno = 1;

    for(i = this->listaSpecVar->begin(); i != this->listaSpecVar->end(); ++i){
        if(!(*i)->confereTipagem(this->getTipo())){
            retorno = 0;
        }
    }

    // chama as avaliacoes das partes
    for(i = this->listaSpecVar->begin(); i != this->listaSpecVar->end(); ++i){
        retorno &= (*i)->eval();
    }

    return retorno;
}

string DeclVar::getTipo(){
    return this->tipo->getTipo();
}

void DeclVar::addTabSimb(Escopo *atual){
    list<SpecVar *>::const_iterator i;
    for(i=listaSpecVar->begin(); i != listaSpecVar->end(); ++i){
        atual->addElem((*i)->getId(), 
                       new ElemTab("variavel", 
                                   tipo->getTipo(), 
                                   (*i)->isArranjo())
                      );
    }
    
}


// ---------------------------------------------------------------- DeclSub
// Declaracao de Procedimento
DeclSub::DeclSub(string id1, list<SpecParam *> *lista, Cmd *block, stack<DeclSub *> *pilhaSub){
    tipo = "procedimento";
    id = id1;
    listaParam = lista;
    retorno = nullptr; 
    bloco = static_cast<BlocoCmd *>(block);
    pilhaSubprog = pilhaSub;
}

DeclSub::DeclSub(string id1, Cmd *block, stack<DeclSub *> *pilhaSub){
    tipo = "procedimento";
    id = id1;
    listaParam = new list<SpecParam *>(); // lista vazia
    retorno = nullptr;
    bloco = static_cast<BlocoCmd *>(block);
    pilhaSubprog = pilhaSub;
}

// Declaracao de Funcao
DeclSub::DeclSub(string id1, list<SpecParam *> *lista, TipoVar *ret, Cmd *block, stack<DeclSub *> *pilhaSub){
    tipo = "funcao";
    id = id1;
    listaParam = lista;
    retorno = ret;
    bloco = static_cast<BlocoCmd *>(block);
    pilhaSubprog = pilhaSub;
}

DeclSub::DeclSub(string id1, TipoVar *ret, Cmd *block, stack<DeclSub *> *pilhaSub){
    tipo = "funcao";
    id = id1;
    listaParam = new list<SpecParam *>(); // lista vazia
    retorno = ret;
    bloco = static_cast<BlocoCmd *>(block);
    pilhaSubprog = pilhaSub;
}

string DeclSub::codeGen(ofstream &output){
    list<SpecParam *>::iterator i, k;
    list<Param *>::iterator j;
    int alterado = 0;

    if(this->tipo == "funcao"){
        output << "\n" << retorno->getTipo() << " " << id << "(";
    } else {
        output << "\nvoid " << id << "(";
    }

    k = listaParam->begin();
    for(i = listaParam->begin(); i != listaParam->end(); ++i){
        if (i != k){
            output << ", ";
            ++k;
        }


        j = (*i)->getCnjParam()->begin();

        output << (*i)->getTipo() << " ";
        if((*j)->getArranjo()){
            output << "*";
        }
        output << (*j)->getId();
        ++j;

        while(j != (*i)->getCnjParam()->end()){
            output << ", " << (*i)->getTipo() << " ";
        
            if((*j)->getArranjo()){
                output << "*";
            }

            output << (*j)->getId();
            ++j;
        }

    }

    output << ") ";

    bloco->codeGen(output);

    return "";
}

string DeclSub::getTipo(){
    return this->tipo;
}

string DeclSub::getId(){
    return this->id;
}

int DeclSub::eval(){
    int ret = 1;

    pilhaSubprog->push(this);
    
    // chamar a avaliacao das outras estruturas
    ret &= bloco->eval();
    
    pilhaSubprog->pop();

    return ret;
}

string DeclSub::getTipoRetorno(){
    /*if(retorno == nullptr){
        return "";
    }

    return this->retorno->getTipo();*/

    return (retorno == nullptr) ? "" : retorno->getTipo();
}

void DeclSub::addTabSimb(Escopo *atual){
    int numParams = 0, j, tam;
    list<string > *tipos = new list<string>();
    Escopo* escopoBloco = bloco->getEscopo();
    list<SpecParam *>::iterator i;
    list<Param *>::iterator k;
    list<Param *> *parametros;
    string tipo;
    bool isArranjo;

    //cout << "Escopo do bloco ("<<id<<"): "<<escopoBloco->getId() <<endl;
    // Olha pra cada espeficicacao de parametro "id1, id2, ... , idN : tipo"
    for(i=listaParam->begin(); i != listaParam->end(); ++i){
        // pega a quantidade "N"
        tam = (*i)->getSize();
        // soma ao total
        numParams += tam;
        // pega o tipo
        tipo = (*i)->getTipo();

        /*for(j=0; j < tam; j++){
             tipos->push_back(tipo);
        }*/

        // pega o conjunto de IDs
        parametros = (*i)->getCnjParam();
        // para cada um, o adiciona na tabela de simbolos do escopo do bloco
        for(k = parametros->begin(); k != parametros->end(); ++k){
            isArranjo = (*k)->getArranjo();

            // adiciona N vezes em uma lista o "tipo"
            if (isArranjo){
                // se for arranjo, adiciona "array(tipo)"
                tipos->push_back(string("array(") + tipo + string(")"));
            } else {
                // caso contrário, "tipo"
                tipos->push_back(tipo);
            }
            //cout << "Inserindo parametro ao escopo!\n";
            escopoBloco->addElem((*k)->getId(),
                                    new ElemTab("param", tipo, isArranjo));
        }
        
    }

    // adiciona no escopo atual da funcao suas informacoes
    atual->addElem( id, 
                    new ElemTab(tipo, this->getTipoRetorno(), numParams, tipos));
}