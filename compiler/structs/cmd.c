#include "cmd.h"
#include "dec.h"

// ------------------------------------------- IfCmd
IfCmd::IfCmd(Exp *cnd, Cmd *thn, int line1){
    condicao = cnd; then = thn; els = nullptr; line = line1;
}

IfCmd::IfCmd(Exp *cnd, Cmd *thn, Cmd *elz, int line1){
    condicao = cnd; then = thn; els = elz; line = line1;
}

int IfCmd::eval(){
    int retorno = 1;

    if (condicao->getTipo() != "bool") {
        cout << "Erro Semântico (l: " << line <<"): condição do comando if deve ser do tipo booleano (encontrado = " << condicao->getTipo() << ")!" <<endl;
        retorno = 0;
    }

    // chama a avaliacao dos outros objetos
    condicao->eval();
    then->eval();

    if (els != nullptr){
        els->eval();
    }

    return retorno;
}

string IfCmd::codeGen(){
    return "";
}

// ------------------------------------------- WhileCmd
WhileCmd::WhileCmd(Exp *cnd, Cmd *cmd, stack<Cmd *> *pilhaCmdRep, int line1){
    condicao = cnd; comando = cmd;
    pilhaCmdRepet = pilhaCmdRep;
    line = line1;
}

int WhileCmd::eval(){
    pilhaCmdRepet->push(this);
    int retorno = 1;

    if(condicao->getTipo() != "bool"){
        cout << "Erro Semântico (l: " << line <<"): a expressão de um comando while deve ser de tipo booleano (encontrado = "<< condicao->getTipo() <<")!\n";
        retorno = 0;
    }

    // chamar os outros metodos
    condicao->eval();
    comando->eval();

    pilhaCmdRepet->pop();

    return retorno;
}

string WhileCmd::codeGen(){
    return "";
}

// ----------------------------------------------ForCmd
ForCmd::ForCmd(Cmd *atriIni, Exp *ex, Cmd *atriPasso, Cmd* cman, stack<Cmd *> *pilhaCmdRep, int line1){
    exp = ex;
    atribIni = static_cast<AtribCmd *>(atriIni);
    atribPasso = static_cast<AtribCmd *>(atriPasso);
    comando = cman;
    pilhaCmdRepet = pilhaCmdRep;
    line = line1;
}

int ForCmd::eval(){
    int cond = 1;

    pilhaCmdRepet->push(this);

    if (this->exp->getTipo() != "bool"){
        cout << "Erro Semântico (l: " << line <<"): Expressão condicional do comando for deve retornar um tipo lógico (encontrado: "<< this->exp->getTipo()  <<")!\n";
        cond = 0;
    }

    // chamar os outros metodos
    atribIni->eval();
    exp->eval();
    atribPasso->eval();
    comando->eval();

    pilhaCmdRepet->pop();

    return cond;
}

string ForCmd::codeGen(){
    return "";
}

//-------------------------------------------- StopSkipCmd
StopSkipCmd::StopSkipCmd(string comando, stack<Cmd *> *pilhaCmdRep, int line1){
    cmd = comando;
    pilhaCmdRepet = pilhaCmdRep;
    line = line1;
}

int StopSkipCmd::eval(){
    if(pilhaCmdRepet->size() == 0){
        cout << "Erro Semântico (l: " << line <<"): o comando "<<cmd<<" deve estar envolvido diretamente ou indiretamente por um laço de repetição!\n";
        return 0;
    }

    return 1;
}

string StopSkipCmd::codeGen(){
    return "";
}

//-------------------------------------------- RetCmd
RetCmd::RetCmd(Exp *ret, stack<DeclSub *> *pilhaSub, int line1){
    retorno = ret;
    pilhaSubprog = pilhaSub;
    line = line1;
}

RetCmd::RetCmd(stack<DeclSub *> *pilhaSub, int line1){
    retorno = nullptr;
    pilhaSubprog = pilhaSub;
    line = line1;
}

int RetCmd::eval(){
    DeclSub *subprog;
    int ret = 1;

    if(pilhaSubprog->size() == 0){
        cout << "Erro Semântico (l: " << line <<"): retorno fora de subprograma!\n";
        ret = 0;
    } else {
        subprog = pilhaSubprog->top();

        if ((subprog->getTipo() == "procedimento") && (retorno != nullptr)){
            cout << "Erro Semântico (l: " << line <<"): retorno de procedimento não deve conter uma expressão!\n";
            ret = 0;
        } else {
            if ((subprog->getTipo() == "funcao")){
                if (retorno == nullptr){
                    cout << "Erro Semântico (l: " << line <<"): retorno de função deve conter uma expressão!\n";
                    ret = 0;
                } else if ((subprog->getTipoRetorno() != retorno->getTipo())){
                    cout << "Erro Semântico (l: " << line <<"): retorno de tipo incopatível com o tipo declarado na função!\n";
                    ret = 0;
                }
            }
        }
    }

    if(this->retorno != nullptr){
        this->retorno->eval();
    }

    return ret;
}

string RetCmd::codeGen(){
    return "";
}

// ----------------------------------------------AtribCmd
AtribCmd::AtribCmd(Exp *varia, string typ, Exp *ex, int line1){
    var = static_cast<VarExp *>(varia);
    type = typ;
    exp = ex;
    line = line1;
}

int AtribCmd::eval(){
    int ret = 1;
    string expTipo;

    if(!var->isInEscopo()){
        cout << "Erro Semântico (l: " << line <<"): Variável '" << var->getId() << "' não visível ao escopo em que foi chamada!\n";

        ret = 0;
    }else{
        expTipo = exp->getTipo();

        if (expTipo == ""){
            cout << "Erro Semântico (l: " << line <<"): Chamada de procedimento não pode ser utilizada para realizar uma atribuição!\n";
            ret = 0;
        } else if(var->getTipo() != expTipo){
            cout << "Erro Semântico (l: " << line <<"): Atribuicao de tipos incompatíveis ("<< var->getTipo() << " != " << exp->getTipo() <<")!\n";
            ret = 0;
        }
    }

    var->eval();
    exp->eval();

    return ret;
}

string AtribCmd::codeGen(){
    return "";
}

// --------------------------------------------WriteCmd
WriteCmd::WriteCmd(list<Exp *> *cnExp){
    cnjExp = cnExp;
}

int WriteCmd::eval(){
    list<Exp *>::iterator i;

    for(i = cnjExp->begin(); i != cnjExp->end(); ++i){
        (*i)->eval();
    }

    return 1;
}

string WriteCmd::codeGen(){
    return "";
}

// --------------------------------------------ReadCmd
ReadCmd::ReadCmd(Exp* varia, int line1){
    var = static_cast<VarExp *>(varia);
    line = line1;
}

int ReadCmd::eval(){
    int ret = 1;

    if(!var->isInEscopo()){
        cout << "Erro Semântico (l: " << line <<"): Var (" << var->getId() << ") não visível ao escopo em que foi chamada!\n";
        ret = 0;
    }

    var->eval();

    return ret;
}

string ReadCmd::codeGen(){
    return "";
}

// -------------------------------------------- BlocoCmd

BlocoCmd::BlocoCmd(list<Decl *> *decl, Escopo* at){
    declaracoes = decl;
    comandos = nullptr;
    atual = at;
}

BlocoCmd::BlocoCmd(list<Cmd *> *com, Escopo* at){
    declaracoes = nullptr;
    comandos = com;
    atual = at;
}

BlocoCmd::BlocoCmd(list<Decl *> *decl, list<Cmd *> *com, Escopo* at){
    declaracoes = decl;
    comandos = com;
    atual = at;
}

Escopo* BlocoCmd::getEscopo(){
    return this->atual;
}

int BlocoCmd::eval(){
    if(declaracoes != nullptr){
        list<Decl *>::iterator i;
        for(i=declaracoes->begin(); i != declaracoes->end(); ++i){
            (*i)->eval();
        }
    }

    if(comandos != nullptr){
        list<Cmd *>::iterator j;
        for(j=comandos->begin(); j != comandos->end(); ++j){
            (*j)->eval();
        }
    }

    return 1;
}

string BlocoCmd::codeGen(){
    return "";
}

// ------------------------------------------------------ ProcCmd
ProcCmd::ProcCmd(string id1, Escopo *atual1, int line1){
    id = id1;
    expressoes = nullptr;
    atual = atual1;
    line = line1;
}

ProcCmd::ProcCmd(string id1, list<Exp *> *exps, Escopo *atual1, int line1){
    id = id1;
    expressoes = exps;
    atual = atual1;
    line = line1;
}

bool ProcCmd::isInEscopo(){
    bool encontrado = false;
    Escopo *i = this->atual;

    while((i != nullptr) && (!encontrado)){
        encontrado = i->checkInserido(id);

        if (!encontrado){
            i = i->getPai();
        } else {
            this->atual = i;
        }
    }

    return encontrado;
}

int ProcCmd::eval(){
    list<Exp *>::iterator i;
    list<string >::iterator j;
    ElemTab* proc;
    int count = 0, ret = 1;
    bool igual = true;
    
    if(!this->isInEscopo()){
        cout << "Erro Semântico (l: " << line <<"): Procedimento '" << this->id << "' não visível ao escopo em que foi chamado!\n";
        ret = 0;
    } else {
        proc = getElemTab();
        if (this->expressoes != nullptr){

            if(proc->numParams != this->expressoes->size()){
                cout << "Erro Semântico (l: " << line <<"): Número de parâmetros incompatível na chamada do procedimento '"<< this->id <<"'!\n";
                ret = 0; 
            } else {
                j = proc->params->begin();

                for(i = this->expressoes->begin(); i != this->expressoes->end(); ++i){
                    count++;
                    if((*j) != (*i)->getTipo()){
                        igual = false;
                        cout << "Erro Semântico (l: " << line <<"): Parâmetro #"<< count << " da chamada de procedimento '" << this->id << "' possui tipo incorreto!\n";
                    }

                    ++j;
                }
            }

            if(!igual) ret = 0;
        } else if (proc->numParams > 0){
            cout << "Erro Semântico (l: " << line <<"): Número de parâmetros incompatível na chamada do procedimento '"<< this->id <<"'!\n";
            ret = 0;
        }

    }

    if (expressoes != nullptr){
        list<Exp *>::iterator k;
        for(k = expressoes->begin(); k != expressoes->end(); ++k){
            (*k)->eval();
        }
    }

    return ret;
}

ElemTab* ProcCmd::getElemTab(){
    bool encontrado = false;
    Escopo *i = this->atual;

    while((i != nullptr) && (!encontrado)){
        //i->printId();
        encontrado = i->checkInserido(id);

        if (!encontrado){
            i = i->getPai();
        } else {
            return i->getElemTab(this->id);
        }
    }


    return nullptr;    
}

string ProcCmd::codeGen(){
    return "";
}


// -------------------------------------------- Programa
Programa::Programa(list<Decl *> *decl, Escopo *glob, int line1){
    declaracoes = decl;
    global = glob;
    line = line1;
}

int Programa::eval(){
    list<Decl *>::iterator i = declaracoes->end(); --i;
    DeclSub *ultimaFunc;
    int ret = 1;

    if ((*i)->getTipo() == "funcao"){
        ultimaFunc = static_cast<DeclSub *>(*i);

        if(ultimaFunc->getId() != "main"){
            cout << "Erro Semântico (l: " << line <<"): Última declaração do programa deve ser a função main!\n";
            ret = 0;
        } else if(ultimaFunc->getTipoRetorno() != "int") {
            cout << ultimaFunc->getTipoRetorno() << endl;
            cout << "Erro Semântico (l: " << line <<"): A função main deve retornar um tipo inteiro!\n";
            ret = 0;
        }
    } else {
        cout << "Erro Semântico (l: " << line <<"): Última declaração do programa deve ser a função main!\n";
        ret = 0;
    }

    for(i = declaracoes->begin(); i != declaracoes->end(); ++i){
        (*i)->eval();
    }

    return ret;
}

string Programa::codeGen(){
    return "";
}