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

int eval(){
    return 1;
}

string codeGen(){
    return "";
}

string getTipo(){
    return "";
}