#include "exp.h"

// ---------------------------------------------------- AritmExp
AritmExp::AritmExp(Exp* expr1, Exp* expr2, string ope){
    e1 = expr1; e2 = expr2; op = ope;
}
    
int AritmExp::eval(){
    if (this->getTipo() == "error"){
        cout<<"Erro: Pode ser que os tipos não sejam apropriados para a operação aritmética!\n";
        return 0;
    }

    return 1;
}

string AritmExp::codeGen(){
    return "";
}

string AritmExp::getTipo(){
    if ((e1->getTipo() == "int") && (e2->getTipo() == "int")){
        return "int";
    }else{
        return "error";
    }
}

// ------------------------------------------------------ RelExp
RelExp::RelExp(Exp* expr1, Exp* expr2, string ope){
    e1 = expr1; e2 = expr2; op = ope;
}
    
int RelExp::eval(){
    if (this->getTipo() == "error"){
        cout<<"Erro: Pode ser que os tipos não sejam apropriados para a operação relacional!\n";
        return 0;
    }
    return 1;
}

string RelExp::codeGen(){
    return "";
}
        
string RelExp::getTipo(){
    if ((e1->getTipo() == "int") && (e2->getTipo() == "int")){
        return "bool";
    }else{
        return "error";
    }
}

// ------------------------------------------------------- LogExp
LogExp::LogExp(Exp* expr1, Exp* expr2, string ope){
    e1 = expr1; e2 = expr2; op = ope;
}
    
int LogExp::eval(){
    if (this->getTipo() == "error"){
        cout<<"Erro: Pode ser que os tipos não sejam apropriados para a operação lógica!\n";
        return 0;
    }
    return 1;
}

string LogExp::codeGen(){
    return "";
}

string LogExp::getTipo(){
    if ((e1->getTipo() == "bool") && (e2->getTipo() == "bool")){
        return "bool";
    }else{
        return "error";
    }
}

// ------------------------------------------------------- IgExp
IgExp::IgExp(Exp* expr1, Exp* expr2, string ope){
    e1 = expr1; e2 = expr2; op = ope;
}
    
int IgExp::eval(){
    if (this->getTipo() == "error"){
        cout<<"Erro: Pode ser que os tipos não sejam apropriados para a operação de igualdade!\n";
        return 0;
    }
    
    return 1;
}

string IgExp::codeGen(){
    return "";
}

string IgExp::getTipo(){
    if (e1->getTipo() == e2->getTipo()){
        return "bool";
    }else{
        return "error";
    }
}

// ------------------------------------------------------- NegUnExp
NegUnExp::NegUnExp(Exp* expr){
    e1 = expr;
}

int NegUnExp::eval(){
    if (this->getTipo() == "error"){
        cout<<"Erro: Pode ser que o tipo não seja apropriado para a operação de negação unária!\n";
        return 0;
    }
    
    return 1;
}

string NegUnExp::codeGen(){
    return "";
}

string NegUnExp::getTipo(){
    if (e1->getTipo() == "int"){
        return "int";
    }else{
        return "error";
    }
}

// -------------------------------------------------------- NegExp
NegExp::NegExp(Exp* expr){
    e1 = expr;
}

int NegExp::eval(){
    if (this->getTipo() == "error"){
        cout<<"Erro: Pode ser que o tipo não seja apropriado para a operação de negação!\n";
        return 0;
    }

    return 1;
}

string NegExp::codeGen(){
    return "";
}

string NegExp::getTipo(){
    if (e1->getTipo() == "bool"){
        return "bool";
    }else{
        return "error";
    }
}

// ----------------------------------------------------------- TerExp

TerExp::TerExp(Exp* expr1, Exp* expr2, Exp* expr3){
    e1 = expr1; 
    e2 = expr2; 
    e3 = expr3;
}

int TerExp::eval(){
    if (this->getTipo() == "error"){
        cout<<"Erro: Uso inapropriado da operacao ternaria!\n";
        return 0;
    }

    return 1;
}

string TerExp::codeGen(){
    return "";
}
        
string TerExp::getTipo(){
    if((e1->getTipo() == "bool") && (e2->getTipo() == e3->getTipo())){
        return e2->getTipo();
    }else{
        return "error";
    }
}

// ---------------------------------------------------------- AtribFor
AtribFor::AtribFor(string id1, string typ, string nume, Escopo *atual1){
    id = id1;
    type = typ;
    num = nume;
    atual = atual1;
}

AtribFor::AtribFor(string id1, string nume, Escopo *atual1){
    id = id1;
    type = "=";
    num = nume;
    atual = atual1;
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
    return valor;
}

string ValExp::getTipo(){
    return type;
}

// ---------------------------------------------------------- ValExp
VarExp::VarExp(string id1, Exp *pos, Escopo* atual1){
    id = id1;
    position = pos;
    atual = atual1;
    tipo = "";
    this->isInEscopo();
}

VarExp::VarExp(string id2, Escopo* atual1){
    id = id2;
    position = nullptr;
    atual = atual1;
    tipo = "";
    this->isInEscopo();
}

bool VarExp::isInEscopo(){
    bool encontrado = false;
    Escopo* i = this->atual;

    while((!encontrado) && (i != nullptr)){
        encontrado = i->checkInserido(this->id);
        
        if(!encontrado){
            i = i->getPai();
        }else{
            this->atual = i;
            this->tipo = i->getElemTab(this->id)->tipo;
        }
    }

    return encontrado;
}


int VarExp::eval(){
    int cond1 = 1, cond2 = 1;

    if(!this->isInEscopo()){
        cout << "Erro: Var (" << this->id << ") nao visivel ao escopo em que foi chamada!\n";
        cond1 = 0;
    }

    if(this->position != nullptr){
        cond2 = (this->position->getTipo() == "int") ? 1 : 0;
    }
    
    return cond1 && cond2;
}

string VarExp::getId(){
    return id;
}

Escopo* VarExp::getEscopo(){
    return this->atual;
}

string VarExp::codeGen(){
    return "";
}

string VarExp::getTipo(){
    return this->tipo;
}

// -------------------------------------------------- FuncExp
FuncExp::FuncExp(string id1, Escopo *atual1){
    id = id1;
    expressoes = nullptr;
    atual = atual1;
}

FuncExp::FuncExp(string id1, list<Exp *> *exps, Escopo *atual1){
    id = id1;
    expressoes = exps;
    atual = atual1;
}

bool FuncExp::isInEscopo(){
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

int FuncExp::eval(){
    if(!this->isInEscopo()){
        cout << "Erro: Funcao (" << this->id << ") nao visivel ao escopo em que foi chamada!\n";
    }

    return 1;
}

string FuncExp::codeGen(){
    return "";
}

string FuncExp::getTipo(){
    return "";
}