#include "exp.h"

// ---------------------------------------------------- AritmExp
AritmExp::AritmExp(Exp* expr1, Exp* expr2, string ope, int line1){
    e1 = expr1; e2 = expr2; op = ope;
    line = line1;
}
    
int AritmExp::eval(){
    int ret = 1;

    if (this->getTipo() == "error"){
        cout<<"Erro Semantico (l: " << line <<"): Os tipos não são apropriados para a operação aritmética!\n";
        ret = 0;
    }

    ret &= e1->eval();
    ret &= e2->eval(); 

    return ret;
}

string AritmExp::codeGen(ofstream &output){
    e1->codeGen(output);
    output << " " << op << " ";
    e2->codeGen(output);

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
RelExp::RelExp(Exp* expr1, Exp* expr2, string ope, int line1){
    e1 = expr1; e2 = expr2; op = ope;
    line = line1;
}
    
int RelExp::eval(){
    int ret = 1;

    if (this->getTipo() == "error"){
        cout<<"Erro Semantico (l: " << line <<"): Os tipos não são apropriados para a operação relacional!\n";
        ret = 0;
    }

    ret &= e1->eval();
    ret &= e2->eval();

    return ret;
}

string RelExp::codeGen(ofstream &output){
    e1->codeGen(output);
    output << " " << op << " ";
    e2->codeGen(output);

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
LogExp::LogExp(Exp* expr1, Exp* expr2, string ope, int line1){
    e1 = expr1; e2 = expr2; op = ope;
    line = line1;
}
    
int LogExp::eval(){
    int ret = 1;

    if (this->getTipo() == "error"){
        cout<<"Erro Semantico (l: " << line <<"): Os tipos não são apropriados para a operação lógica!\n";
        ret = 0;
    }

    ret &= e1->eval();
    ret &= e2->eval();

    return ret;
}

string LogExp::codeGen(ofstream &output){
    e1->codeGen(output);
    output << " " << op << " ";
    e2->codeGen(output);

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
IgExp::IgExp(Exp* expr1, Exp* expr2, string ope, int line1){
    e1 = expr1; e2 = expr2; op = ope;
    line = line1;
}
    
int IgExp::eval(){
    int ret = 1;

    if (this->getTipo() == "error"){
        cout<<"Erro Semantico (l: " << line <<"): Os tipos não são apropriados para a operação de igualdade!\n";
        ret = 0;
    }
    
    ret &= e1->eval();
    ret &= e2->eval();

    return ret;
}

string IgExp::codeGen(ofstream &output){
    e1->codeGen(output);
    output << " " << op << " ";
    e2->codeGen(output);

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
NegUnExp::NegUnExp(Exp* expr, int line1){
    e1 = expr;
    line = line1;
}

int NegUnExp::eval(){
    int ret = 1;

    if (this->getTipo() == "error"){
        cout<<"Erro Semântico (l: " << line <<"): O tipo não é apropriado para a operação de negação unária!\n";
        ret = 0;
    }
    
    ret &= e1->eval();

    return ret;
}

string NegUnExp::codeGen(ofstream &output){
    output << "-";
    e1->codeGen(output);

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
NegExp::NegExp(Exp* expr, int line1){
    e1 = expr;
    line = line1;
}

int NegExp::eval(){
    int ret = 1;

    if (this->getTipo() == "error"){
        cout<<"Erro Semantico (l: " << line <<"): O tipo não é apropriado para a operação de negação!\n";
        ret = 0;
    }

    ret &= e1->eval();

    return ret;
}

string NegExp::codeGen(ofstream &output){
    output << "!";
    e1->codeGen(output);

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

TerExp::TerExp(Exp* expr1, Exp* expr2, Exp* expr3, int line1){
    e1 = expr1; 
    e2 = expr2; 
    e3 = expr3;
    line = line1;
}

int TerExp::eval(){
    int ret = 1;

    if (this->getTipo() == "error"){
        cout<<"Erro Semântico (l: " << line <<"): Uso inapropriado da operação ternária!\n";
        ret = 0;
    }

    ret &= e1->eval();
    ret &= e2->eval();
    ret &= e3->eval();

    return ret;
}

string TerExp::codeGen(ofstream &output){
    output << "(";
    e1->codeGen(output);
    output << ") ? ";
    e2->codeGen(output);
     output << " : ";
    e3->codeGen(output);

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
ValExp::ValExp(string val, string typ, int line1){
    valor = val;
    type = typ;
    line = line1;
}

int ValExp::eval(){
    return 1;
}

string ValExp::codeGen(ofstream &output){
    output << valor;

    return valor;
}

string ValExp::getTipo(){
    return type;
}

// ---------------------------------------------------------- ValExp
VarExp::VarExp(string id1, Exp *pos, Escopo* atual1, int line1){
    id = id1;
    position = pos;
    atual = atual1;
    line = line1;
    //tipo = "";
}

VarExp::VarExp(string id2, Escopo* atual1, int line1){
    id = id2;
    position = nullptr;
    atual = atual1;
    line = line1;
    //tipo = "";
}

bool VarExp::isInEscopo(){
    bool encontrado = false;
    Escopo* i = this->atual;

    while((!encontrado) && (i != nullptr)){
        //i->printId();
        encontrado = i->checkInserido(this->id);
        
        if(!encontrado){
            i = i->getPai();
        } /*else{
            this->atual = i; // PROAVELMENTE ESTA ERRADO
            //this->tipo = i->getElemTab(this->id)->tipo;
        }*/
    }

    return encontrado;
}


int VarExp::eval(){
    int ret = 1;

    if(!this->isInEscopo()){
        cout << "Erro Semântico (l: " << line <<"): Variável '" << this->id << "' não visível ao escopo em que foi chamada!\n";
        ret = 0;
    }

    if(this->position != nullptr){
       if (this->position->getTipo() != "int"){
           cout << "Erro Semântico (l: " << line <<"): Acesso de arranjo por meio de um valor não inteiro ("<< this->position->getTipo() <<")!\n";
           ret = 0;
       }

       ret &= this->position->eval();
    }
    
    return ret;
}

string VarExp::getId(){
    return id;
}

string VarExp::codeGen(ofstream &output){
    output << id;

    if(position != nullptr){
        output << "[";
        position->codeGen(output);
        output << "]";
    }

    return "";
}

string VarExp::getTipo(){
    bool encontrado = false;
    Escopo* i = this->atual;
    ElemTab *aux;

    //cout << "\nIncio do while, VarExp::getTipo\n";
    while((!encontrado) && (i != nullptr)){
        //i->printId();
        encontrado = i->checkInserido(this->id);
        
        if(!encontrado){
            i = i->getPai();
        }else{
            aux = i->getElemTab(this->id);
            // Se a variavel for de tipo agregado, e estiver sendo chamada
            // sem acesso, ela é do tipo "array(tipo)"
            if (aux->agregado && (this->position == nullptr)){
                return string("array(") + aux->tipo + string(")");
            } else {
                // caso contrario é somente "tipo"
                return aux->tipo;
            }
        }
    }

    return "error";

}

// -------------------------------------------------- FuncExp
FuncExp::FuncExp(string id1, Escopo *atual1, int line1){
    id = id1;
    expressoes = nullptr;
    atual = atual1;
    line = line1;
}

FuncExp::FuncExp(string id1, list<Exp *> *exps, Escopo *atual1, int line1){
    id = id1;
    expressoes = exps;
    atual = atual1;
    line = line1;
    //tipo = "";
}

bool FuncExp::isInEscopo(){
    bool encontrado = false;
    Escopo *i = this->atual;

    while((i != nullptr) && (!encontrado)){
        //i->printId();
        encontrado = i->checkInserido(id);

        if (!encontrado){
            i = i->getPai();
        } /*else {
            this->atual = i;
            //this->tipo = i->getElemTab(this->id)->tipo;
        }*/
    }

    return encontrado;
}

int FuncExp::eval(){
    list<Exp *>::iterator i;
    list<string >::iterator j;
    ElemTab* proc;
    int count = 0;
    bool igual = true;
    int ret = 1;

    if(!this->isInEscopo()){
        cout << "Erro Semântico (l: "<<line<<"): Função '" << this->id << "' não visível ao escopo em que foi chamada!\n";
        ret = 0;
    } else {
        proc = this->getElemTab();
        if (this->expressoes != nullptr){
            if(proc->numParams != this->expressoes->size()){
                cout << "Erro Semântico (l: "<<line<<"): Número de parâmetros incompatível na chamada da função '"<< this->id 
                        <<"' (Quantidade esperada: "<< proc->numParams  << ")!\n";
                ret = 0; 
            } else {
                j = proc->params->begin();
                for(i = this->expressoes->begin(); i != this->expressoes->end(); ++i){
                    count++;
                    if((*j) != (*i)->getTipo()){
                        igual = false;
                        cout << "Erro Semântico (l: "<<line<<"): Parâmetro #"<< count << " da chamada da função'" <<
                                 this->id << "' possui tipo incorreto (" << (*j) << " != " << (*i)->getTipo() << ")!\n";
                    }
                    ++j;
                }
            }
            if(!igual) ret = 0;
        } else if (proc->numParams > 0){
            cout << "Erro Semântico (l: "<<line<<"): Número de parâmetros incompatível na chamada da função '"<< this->id 
                    <<"' (Quantidade esperada: "<< proc->numParams  << ")!\n";
            ret = 0;
        }
    }

    if(expressoes != nullptr){
        list<Exp *>::iterator i;

        for(i = expressoes->begin(); i != expressoes->end(); ++i){
            ret &= (*i)->eval();
        }
    }

    return ret;
}

ElemTab* FuncExp::getElemTab(){
    bool encontrado = false;
    Escopo *i = this->atual;

    while((i != nullptr) && (!encontrado)){
        //i->printId();
        encontrado = i->checkInserido(id);

        if (!encontrado){
            i = i->getPai();
        } else {
            return i->getElemTab(this->id);
        }
    }


    return nullptr;    
}

string FuncExp::getTipo(){
    bool encontrado = false;
    Escopo *i = this->atual;

    while((i != nullptr) && (!encontrado)){
        //i->printId();
        encontrado = i->checkInserido(id);

        if (!encontrado){
            i = i->getPai();
        } else {
            return i->getElemTab(this->id)->retorno;
        }
    }


    return "error";
}

string FuncExp::codeGen(ofstream &output){
    output << id << "(";

    if(expressoes != nullptr){
        list<Exp *>::iterator i = expressoes->begin();

        (*i)->codeGen(output);
        ++i;

        while( i != expressoes->end()){
            output << ", ";
            (*i)->codeGen(output);
            ++i;
        }
    }

    output << ")";

    return "";
}