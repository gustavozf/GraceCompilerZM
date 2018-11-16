#include "cmd.h"

// ------------------------------------------- IfCmd
IfCmd::IfCmd(Exp *cnd, Cmd *thn){
    condicao = cnd; then = thn; els = NULL;
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
    retorno = NULL;
}

int RetCmd::eval(){
    return 1;
}

string RetCmd::codeGen(){
    return "";
}

// ----------------------------------------------AtribCmd
AtribCmd::AtribCmd(Var *varia, string typ, Exp *ex){
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
ReadCmd::ReadCmd(Var* varia){
    var = varia;
}

int ReadCmd::eval(){
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