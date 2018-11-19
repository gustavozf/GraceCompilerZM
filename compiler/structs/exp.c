#include "exp.h"

// ---------------------------------------------------- AritmExp
AritmExp::AritmExp(Exp* expr1, Exp* expr2, string ope){
    e1 = expr1; e2 = expr2; op = ope;
}
    
int AritmExp::eval(){
    return 1;
}

string AritmExp::codeGen(){
    return "";
}

string AritmExp::getTipo(){
    return "";
}

// ------------------------------------------------------ RelExp
RelExp::RelExp(Exp* expr1, Exp* expr2, string ope){
    e1 = expr1; e2 = expr2; op = ope;
}
    
int RelExp::eval(){
    return 1;
}

string RelExp::codeGen(){
    return "";
}
        
string RelExp::getTipo(){
    return "";
}

// ------------------------------------------------------- LogExp
LogExp::LogExp(Exp* expr1, Exp* expr2, string ope){
    e1 = expr1; e2 = expr2; op = ope;
}
    
int LogExp::eval(){
    return 1;
}

string LogExp::codeGen(){
    return "";
}

string LogExp::getTipo(){
    return "";
}

// ------------------------------------------------------- IgExp
IgExp::IgExp(Exp* expr1, Exp* expr2, string ope){
    e1 = expr1; e2 = expr2; op = ope;
}
    
int IgExp::eval(){
    return 1;
}

string IgExp::codeGen(){
    return "";
}

string IgExp::getTipo(){
    return "";
}

// ------------------------------------------------------- NegUnExp
NegUnExp::NegUnExp(Exp* expr){
    e1 = expr;
}

int NegUnExp::eval(){
    return 1;
}

string NegUnExp::codeGen(){
    return "";
}

string NegUnExp::getTipo(){
    return "";
}

// -------------------------------------------------------- NegExp
NegExp::NegExp(Exp* expr){
    e1 = expr;
}

int NegExp::eval(){
    return 1;
}

string NegExp::codeGen(){
    return "";
}

string NegExp::getTipo(){
    return "";
}

// ----------------------------------------------------------- TerExp

TerExp::TerExp(Exp* expr1, Exp* expr2, Exp* expr3){
    e1 = expr1; 
    e2 = expr2; 
    e3 = expr3;
}

int TerExp::eval(){
    return 1;
}

string TerExp::codeGen(){
    return "";
}
        
string TerExp::getTipo(){
    return "";
}

// ---------------------------------------------------------- AtribFor
AtribFor::AtribFor(string id1, string typ, string nume){
    id = id1;
    type = typ;
    num = nume;
}

AtribFor::AtribFor(string id1, string nume){
    id = id1;
    type = "=";
    num = nume;
}

int AtribFor::eval(){
    return 1;
}

string AtribFor::codeGen(){
    return "";
}

string AtribFor::getTipo(){
    return "";
}

// ---------------------------------------------------------- ValExp
ValExp::ValExp(string val, string typ){
    valor = val;
    type = typ;
}

int ValExp::eval(){
    return 1;
}

string ValExp::codeGen(){
    return "";
}

string ValExp::getTipo(){
    return type;
}

// ---------------------------------------------------------- ValExp
VarExp::VarExp(string id1, Exp *pos){
    id = id1;
    position = pos;
}

VarExp::VarExp(string id2){
    id = id2;
    position = NULL;
}

int VarExp::eval(){
    return 1;
}

string VarExp::codeGen(){
    return "";
}

string VarExp::getTipo(){
    return "";
}

// -------------------------------------------------- FuncExp
FuncExp::FuncExp(string id1){
    id = id1;
    expressoes = NULL;
}

FuncExp::FuncExp(string id1, list<Exp *> *exps){
    id = id1;
    expressoes = exps;
}

int FuncExp::eval(){
    return 1;
}

string FuncExp::codeGen(){
    return "";
}

string FuncExp::getTipo(){
    return "";
}