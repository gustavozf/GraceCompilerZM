#include "exp.h"

// ---------------------------------------------------- AritmExp
AritmExp::AritmExp(Exp* expr1, Exp* expr2, string ope){
    e1 = expr1; e2 = expr2; op = ope;
}
    
int AritmExp::eval(){
    int ret = 1;

    if (this->getTipo() == "error"){
        cout<<"Erro Semantico: Os tipos não são apropriados para a operação aritmética!\n";
        ret = 0;
    }

    e1->eval();
    e2->eval();

    return ret;
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
    int ret = 1;

    if (this->getTipo() == "error"){
        cout<<"Erro Semantico: Os tipos não são apropriados para a operação relacional!\n";
        ret = 0;
    }

    e1->eval();
    e2->eval();

    return ret;
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
    int ret = 1;

    if (this->getTipo() == "error"){
        cout<<"Erro Semantico: Os tipos não são apropriados para a operação lógica!\n";
        ret = 0;
    }

    e1->eval();
    e2->eval();

    return ret;
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
    int ret = 1;

    if (this->getTipo() == "error"){
        cout<<"Erro Semantico: Os tipos nao sao apropriados para a operação de igualdade!\n";
        ret = 0;
    }
    
    e1->eval();
    e2->eval();

    return ret;
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
    int ret = 1;

    if (this->getTipo() == "error"){
        cout<<"Erro Semantico: O tipo não eh apropriado para a operação de negação unária!\n";
        ret = 0;
    }
    
    e1->eval();

    return ret;
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
    int ret = 1;

    if (this->getTipo() == "error"){
        cout<<"Erro Semantico: O tipo não eh apropriado para a operação de negação!\n";
        ret = 0;
    }

    e1->eval();

    return ret;
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
    int ret = 1;

    if (this->getTipo() == "error"){
        cout<<"Erro: Uso inapropriado da operacao ternaria!\n";
        ret = 0;
    }

    e1->eval();
    e2->eval();
    e3->eval();

    return ret;
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
    int ret = 1;

    if(!this->isInEscopo()){
        cout << "Erro: Var (" << this->id << ") nao visivel ao escopo em que foi chamada!\n";
        ret = 0;
    }

    if(this->position != nullptr){
       if (this->position->getTipo() != "int"){
           cout << "Erro! Acesso de arranjo por meio de um valor não inteiro ("<< this->position->getTipo() <<")!\n";
           ret = 0;
       }

       this->position->eval();
    }
    
    return ret;
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
    tipo = "";
    this->isInEscopo();
}

bool FuncExp::isInEscopo(){
    bool encontrado = false;
    Escopo *i = this->atual;

    while((i != nullptr) && (!encontrado)){
        encontrado = i->checkInserido(id);

        if (!encontrado){
            i = i->getPai();
        } else {
            this->atual = i;
            this->tipo = i->getElemTab(this->id)->tipo;
        }
    }

    return encontrado;
}

int FuncExp::eval(){
    int ret = 1;

    if(!this->isInEscopo()){
        cout << "Erro: Funcao (" << this->id << ") nao visivel ao escopo em que foi chamada!\n";
        ret = 0;
    }

    if(expressoes != nullptr){
        list<Exp *>::iterator i;

        for(i = expressoes->begin(); i != expressoes->end(); ++i){
            (*i)->eval();
        }
    }

    return ret;
}

string FuncExp::codeGen(){
    return "";
}

string FuncExp::getTipo(){
    return this->tipo;
}