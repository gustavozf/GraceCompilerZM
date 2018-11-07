#include "cmd.h"

// ------------------------------------------- IfCmd
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
