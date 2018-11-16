#include "dec.h"

// ---------------------------------- StringTipoVar
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

// ---------------------------------- BoolTipoVar
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

// ---------------------------------- IntTipoVar
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

//------------------------------------ DecVarSimples
SpecVarSimples::SpecVarSimples(string id1, Exp *ini){
    inicializacao = ini;
    id = id1;
}

SpecVarSimples::SpecVarSimples(string id1){
    inicializacao = NULL;
    id = id1;
}

string SpecVarSimples::codeGen(){
    return "";
}

int SpecVarSimples::eval(){
    return 1;
}

// ------------------------------------- SpecVarArranjo
SpecVarArranjo::SpecVarArranjo(string id1, Exp *tama, list<Exp *> *ini){
    inicializacao = ini;
    tam = tama;
    id = id1;
}

SpecVarArranjo::SpecVarArranjo(string id1, Exp *tama){
    inicializacao = NULL;
    tam = tama;
    id = id1;
}

string SpecVarArranjo::codeGen(){
    return "";
}

int SpecVarArranjo::eval(){
    return 1;
}

// ---------------------------------- DeclVar
DeclVar::DeclVar(list<SpecVar *> *lista, TipoVar *type){
    listaSpecVar = lista;
    tipo = type;
}

string DeclVar::codeGen(){
    return "";
}

int DeclVar::eval(){
    return 1;
}