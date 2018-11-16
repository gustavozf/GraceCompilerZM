#include "prog.h"


// ------------------------------ VarSimples
VarSimples::VarSimples(string idName){
    id = idName;
}
int VarSimples::eval(){
    return 1;
}
string VarSimples::codeGen(){
    return "";
}


// ------------------------------ VarArranjo
VarArranjo::VarArranjo(string idName, Exp *pos){
    id = idName;
    position = pos;
}
int VarArranjo::eval(){
    return 1;
}
string VarArranjo::codeGen(){
    return "";
}