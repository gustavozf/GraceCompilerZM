#include "cmd.h"
#include "dec.h"

// ------------------------------------------- IfCmd
IfCmd::IfCmd(Exp *cnd, Cmd *thn){
    condicao = cnd; then = thn; els = nullptr;
}

IfCmd::IfCmd(Exp *cnd, Cmd *thn, Cmd *elz){
    condicao = cnd; then = thn; els = elz;
}

int IfCmd::eval(){
    int retorno = 1;

    if (condicao->getTipo() != "bool") {
        cout << "Erro Semantico: condicao do comando if deve ser do tipo booleano! (encontrado = " << condicao->getTipo() << endl;
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
WhileCmd::WhileCmd(Exp *cnd, Cmd *cmd, stack<Cmd *> *pilhaCmdRep){
    condicao = cnd; comando = cmd;
    pilhaCmdRepet = pilhaCmdRep;
}

int WhileCmd::eval(){
    pilhaCmdRepet->push(this);
    int retorno = 1;

    if(condicao->getTipo() != "bool"){
        cout << "Erro Sematico: a expressao de um comando while deve ser de tipo booleano (encontrado = "<< condicao->getTipo() <<"!\n";
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
ForCmd::ForCmd(Cmd *atriIni, Exp *ex, Cmd *atriPasso, Cmd* cman, stack<Cmd *> *pilhaCmdRep){
    exp = ex;
    atribIni = static_cast<AtribCmd *>(atriIni);
    atribPasso = static_cast<AtribCmd *>(atriPasso);
    comando = cman;
    pilhaCmdRepet = pilhaCmdRep;
}

int ForCmd::eval(){
    int cond = 1;

    pilhaCmdRepet->push(this);

    if (this->exp->getTipo() != "bool"){
        cout << "Erro Semantico: Expressao condicional do comando for deve retornar um tipo logico (encontrado: "<< this->exp->getTipo()  <<")!\n";
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
StopSkipCmd::StopSkipCmd(string comando, stack<Cmd *> *pilhaCmdRep){
    cmd = comando;
    pilhaCmdRepet = pilhaCmdRep;
}

int StopSkipCmd::eval(){
    if(pilhaCmdRepet->size() == 0){
        cout << "Erro Semantico: o comando "<<cmd<<" deve estar involvido diretamente ou indiretamente por um laco de repeticao!\n";
        return 0;
    }

    return 1;
}

string StopSkipCmd::codeGen(){
    return "";
}

//-------------------------------------------- RetCmd
RetCmd::RetCmd(Exp *ret, stack<DeclSub *> *pilhaSub){
    retorno = ret;
    pilhaSubprog = pilhaSub;
}

RetCmd::RetCmd(stack<DeclSub *> *pilhaSub){
    retorno = nullptr;
    pilhaSubprog = pilhaSub;
}

int RetCmd::eval(){
    DeclSub *subprog;
    int ret = 1;

    if(pilhaSubprog->size() == 0){
        cout << "Erro Semantico: retorno fora de subprograma!\n";
        ret = 0;
    } else {
        subprog = pilhaSubprog->top();

        if ((subprog->getTipo() == "procedimento") && (retorno != nullptr)){
            cout << "Erro Semantico: retorno de procedimento nao deve conter uma expressao!\n";
            ret = 0;
        } else {
            if ((subprog->getTipo() == "funcao")){
                if (retorno == nullptr){
                    cout << "Erro Semantico: retorno de funcao deve conter uma expressao!\n";
                    ret = 0;
                } else if ((subprog->getTipoRetorno() != retorno->getTipo())){
                    cout << "Erro Semantico: retorno de tipo incopativel com o tipo declarado na funcao!\n";
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
AtribCmd::AtribCmd(Exp *varia, string typ, Exp *ex){
    var = static_cast<VarExp *>(varia);
    type = typ;
    exp = ex;
}

int AtribCmd::eval(){
    int ret = 1;

    if(!var->isInEscopo()){
        cout << "Erro Semantico: Var (" << var->getId() << ") nao visivel ao escopo em que foi chamada!\n";

        ret = 0;
    }else{
        if(!(var->getEscopo()->getElemTab(var->getId())->tipo == exp->getTipo())){
            cout << "Erro Semantico: Atribuicao de tipos incompatíveis";
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
ReadCmd::ReadCmd(Exp* varia){
    var = static_cast<VarExp *>(varia);
}

int ReadCmd::eval(){
    int ret = 1;

    if(!var->isInEscopo()){
        cout << "Erro Semantico: Var (" << var->getId() << ") nao visivel ao escopo em que foi chamada!\n";
        ret = 0;
    }

    var->eval();

    return ret;
}

string ReadCmd::codeGen(){
    return "";
}

// -------------------------------------------- BlocoCmd

BlocoCmd::BlocoCmd(list<Decl *> *decl){
    declaracoes = decl;
    comandos = nullptr;
}

BlocoCmd::BlocoCmd(list<Cmd *> *com){
    declaracoes = nullptr;
    comandos = com;
}

BlocoCmd::BlocoCmd(list<Decl *> *decl, list<Cmd *> *com){
    declaracoes = decl;
    comandos = com;
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
ProcCmd::ProcCmd(string id1, Escopo *atual1){
    id = id1;
    expressoes = nullptr;
    atual = atual1;
}

ProcCmd::ProcCmd(string id1, list<Exp *> *exps, Escopo *atual1){
    id = id1;
    expressoes = exps;
    atual = atual1;
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
        cout << "Erro Semantico: Procedimento (" << this->id << ") nao visivel ao escopo em que foi chamado!\n";
        ret = 0;
    } else {
        proc = this->atual->getElemTab(this->id);

        if(proc->numParams != this->expressoes->size()){
            cout << "Erro Semantico: Numero de parametros incompativel na chamada do procedimento ("<< this->id <<")!\n";
            ret = 0; 
        } else {
            j = proc->params->begin();

            for(i = this->expressoes->begin(); i != this->expressoes->end(); ++i){
                count++;
                if((*j) != (*i)->getTipo()){
                    igual = false;
                    cout << "Erro Semantico: Parametro #"<< count << " da chamada de procedimento '" << this->id << "' possui tipo incorreto!\n";
                }

                ++j;
            }

            if(!igual) ret = 0;
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

string ProcCmd::codeGen(){
    return "";
}


// -------------------------------------------- Programa
Programa::Programa(list<Decl *> *decl, Escopo *glob){
    declaracoes = decl;
    global = glob;
}

int Programa::eval(){
    list<Decl *>::iterator i = declaracoes->end();
    DeclSub *main;
    int ret = 1;

    if ((*i)->getTipo() == "funcao"){
        main = static_cast<DeclSub *>(*i);

        if(main->getId() != "main"){
            cout << "Erro: Ultima declaracao do programa deve ser a funcao main!\n";
            ret = 0;
        } else if(main->getTipoRetorno() != "main") {
            cout << "Erro: A funcao main deve retornar um tipo inteiro!\n";
            ret = 0;
        }
    } else {
        cout << "Erro: Ultima declaracao do programa deve ser a funcao main!\n";
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