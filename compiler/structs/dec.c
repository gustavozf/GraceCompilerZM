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

string StringTipoVar::codeGen(){
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

string BoolTipoVar::codeGen(){
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

string IntTipoVar::codeGen(){
    return "";
}

//-------------------------------------------------------- DecVarSimples
SpecVarSimples::SpecVarSimples(string id1, Exp *ini){
    inicializacao = ini;
    id = id1;
}

SpecVarSimples::SpecVarSimples(string id1){
    inicializacao = nullptr;
    id = id1;
}

string SpecVarSimples::codeGen(){
    return "";
}

int SpecVarSimples::eval(){
    return 1;
}

string SpecVarSimples::getId(){
    return id;
}

bool SpecVarSimples::isArranjo(){
    return false;
}

bool SpecVarSimples::confereTipagem(string tipo){
    if(inicializacao != nullptr){
        return (tipo == inicializacao->getTipo());
    }

    return true;
}

// ------------------------------------------------------------- SpecVarArranjo
SpecVarArranjo::SpecVarArranjo(string id1, Exp *tama, list<Exp *> *ini){
    inicializacao = ini;
    tam = tama;
    id = id1;
}

SpecVarArranjo::SpecVarArranjo(string id1, Exp *tama){
    inicializacao = nullptr;
    tam = tama;
    id = id1;
}

string SpecVarArranjo::codeGen(){
    return "";
}

int SpecVarArranjo::eval(){
    return 1;
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
                cout << "Erro: parametro #" << count << " da inicializacao possui tipo incorreto (" << (*i)->getTipo() <<")\n";
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

string DeclVar::codeGen(){
    return "";
}

int DeclVar::eval(){
    list<SpecVar *>::iterator i;
    int retorno = 1;

    for(i = this->listaSpecVar->begin(); i != this->listaSpecVar->end(); ++i){
        if(!(*i)->confereTipagem(this->tipo->getTipo())){
            retorno = 0;
        }
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
    bloco = block;
    pilhaSubprog = pilhaSub;
}

DeclSub::DeclSub(string id1, Cmd *block, stack<DeclSub *> *pilhaSub){
    tipo = "procedimento";
    id = id1;
    listaParam = new list<SpecParam *>(); // lista vazia
    retorno = nullptr;
    bloco = block;
    pilhaSubprog = pilhaSub;
}

// Declaracao de Funcao
DeclSub::DeclSub(string id1, list<SpecParam *> *lista, TipoVar *ret, Cmd *block, stack<DeclSub *> *pilhaSub){
    tipo = "funcao";
    id = id1;
    listaParam = lista;
    retorno = ret;
    bloco = block;
    pilhaSubprog = pilhaSub;
}

DeclSub::DeclSub(string id1, TipoVar *ret, Cmd *block, stack<DeclSub *> *pilhaSub){
    tipo = "funcao";
    id = id1;
    listaParam = new list<SpecParam *>(); // lista vazia
    retorno = ret;
    bloco = block;
    pilhaSubprog = pilhaSub;
}

string DeclSub::codeGen(){
    return "";
}

string DeclSub::getTipo(){
    return this->tipo;
}

string DeclSub::getId(){
    return this->id;
}

int DeclSub::eval(){
    pilhaSubprog->push(this);
    // chamar o eval() das outras estruturas
    pilhaSubprog->pop();

    return 1;
}

string DeclSub::getTipoRetorno(){
    if(retorno == nullptr){
        return "";
    }

    return this->retorno->getTipo();
}

void DeclSub::addTabSimb(Escopo *atual){
    int numParams = 0, j, tam;
    list<string > *tipos = new list<string>();
    
    list<SpecParam *>::iterator i;
    for(i=listaParam->begin(); i != listaParam->end(); ++i){
        tam = (*i)->getSize();
        numParams += tam;

        for(j=0; j < tam; j++){
            tipos->push_back((*i)->getTipo());
        }
    }

    atual->addElem( id, 
                    new ElemTab(tipo, 
                                (retorno == nullptr) ? "" : retorno->getTipo(), 
                                numParams, 
                                tipos)
                  );
}