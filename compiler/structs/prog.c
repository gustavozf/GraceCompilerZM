#include "prog.h"


// ------------------------------ Var
Var::Var(string id1, Exp *pos){
    id = id1;
    position = pos;
}
Var::Var(string id2){
    id = id2;
    position = NULL;
}
int Var::eval(){
    return 1;
}
string Var::codeGen(){
    return "";
}