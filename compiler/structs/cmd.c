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
    return (condicao->getTipo() == "bool");
}

string IfCmd::codeGen(){
    return "";
}

// ------------------------------------------- WhileCmd
WhileCmd::WhileCmd(Exp *cnd, Cmd *cmd){
    condicao = cnd; comando = cmd;
}

int WhileCmd::eval(){
    return (condicao->getTipo() == "bool");
}

string WhileCmd::codeGen(){
    return "";
}

//-------------------------------------------- StopSkipCmd
StopSkipCmd::StopSkipCmd(string comando){
    cmd = comando;
}

int StopSkipCmd::eval(){
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

    if(pilhaSubprog->size() == 0){
        cout << "Erro: retorno fora de subprograma!\n";
        return 0;
    } else {
        subprog = pilhaSubprog->top();

        if ((subprog->getTipo() == "procedimento") && (retorno != nullptr)){
            cout << "Erro: retorno de procedimento nao deve conter uma expressao!\n";
            return 0;
        } else {
            if ((subprog->getTipo() == "funcao")){
                if (retorno == nullptr){
                    cout << "Erro: retorno de funcao deve conter uma expressao!\n";
                    return 0;
                } else if ((subprog->getTipoRetorno() != retorno->getTipo())){
                    cout << "Erro: retorno de tipo incopativel com o tipo declarado na funcao!\n";
                    return 0;
                }
            }
        }
    }

    return 1;
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
    if(!var->isInEscopo()){
        cout << "Erro: Var (" << var->getId() << ") nao visivel ao escopo em que foi chamada!\n";

        return 0;
    }else{
        if(!(var->getEscopo()->getElemTab(var->getId())->tipo == exp->getTipo())){
            cout << "Erro: Atribuicao de tipos incompatíveis";
            return 0;
        }
    }
    return 1;
}

string AtribCmd::codeGen(){
    return "";
}

// --------------------------------------------WriteCmd
WriteCmd::WriteCmd(list<Exp *> *cnExp){
    cnjExp = cnExp;
}

int WriteCmd::eval(){
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
    if(!var->isInEscopo()){
        cout << "Erro: Var (" << var->getId() << ") nao visivel ao escopo em que foi chamada!\n";
    }

    return 1;
}

string ReadCmd::codeGen(){
    return "";
}
// ----------------------------------------------ForCmd
ForCmd::ForCmd(Exp *atriIni, Exp *ex, Exp *atriPasso, Cmd* cman){
    exp = ex;
    atribIni = static_cast<AtribFor *>(atriIni);
    atribPasso = static_cast<AtribFor *>(atriPasso);
    comando = cman;
}

int ForCmd::eval(){
    int cond[3] = {true, true, true};

    if (this->exp->getTipo() != "bool"){
        cout << "Erro! Expressao condicional do comando for deve retornar um tipo logico (encontrado: "<< this->exp->getTipo()  <<")!\n";
        cond[0] = false;
    }

    return cond[0] && cond[1] && cond[2];
}

string ForCmd::codeGen(){
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
    int count = 0;
    bool igual = true;
    
    if(!this->isInEscopo()){
        cout << "Erro: Procedimento (" << this->id << ") nao visivel ao escopo em que foi chamado!\n";
        return 0;
    } else {
        proc = this->atual->getElemTab(this->id);

        if(proc->numParams != this->expressoes->size()){
            cout << "Erro: Numero de parametros incompativel na chamada do procedimento ("<< this->id <<")!\n";
            return 0; 
        } else {
            j = proc->params->begin();

            for(i = this->expressoes->begin(); i != this->expressoes->end(); ++i){
                count++;
                if((*j) != (*i)->getTipo()){
                    igual = false;
                    cout << "Erro: Parametro #"<< count << " da chamada de procedimento '" << this->id << "' possui tipo incorreto!\n";
                }

                ++j;
            }

            if(!igual) return 0;
        }

    }

    return 1;
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

    if ((*i)->getTipo() == "funcao"){
        main = static_cast<DeclSub *>(*i);

        if(main->getId() != "main"){
            cout << "Erro: Ultima declaracao do programa deve ser a funcao main!\n";
            return 0;
        } else if(main->getTipoRetorno() != "main") {
            cout << "Erro: A funcao main deve retornar um tipo inteiro!\n";
            return 0;
        }
    } else {
        cout << "Erro: Ultima declaracao do programa deve ser a funcao main!\n";
        return 0;
    }

    return 1;
}

string Programa::codeGen(){
    return "";
}