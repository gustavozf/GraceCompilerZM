#include "cmd.h"

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
RetCmd::RetCmd(Exp *ret){
    retorno = ret;
}

RetCmd::RetCmd(){
    retorno = nullptr;
}

int RetCmd::eval(){
    return 1;
}

string RetCmd::codeGen(){
    return "";
}

// ----------------------------------------------AtribCmd
AtribCmd::AtribCmd(Exp *varia, string typ, Exp *ex){
    var = varia;
    type = typ;
    exp = ex;
}

int AtribCmd::eval(){
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
ReadCmd::ReadCmd(VarExp* varia){
    var = varia;
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
    atribIni = atriIni;
    atribPasso = atriPasso;
    comando = cman;
}

int ForCmd::eval(){
    return 1;
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
        }
    }

    return encontrado;
}

int ProcCmd::eval(){
    if(!this->isInEscopo()){
        cout << "Erro: Procedimento (" << this->id << ") nao visivel ao escopo em que foi chamado!\n";
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
    return 1;
}

string Programa::codeGen(){
    return "";
}