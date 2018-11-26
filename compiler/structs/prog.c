#include "prog.h"

void teste(){
    cout << "Eita" << endl;
}

// ========================================= Escopo
Escopo::Escopo(){
    pai = nullptr;
}
void Escopo::addElem(ElemTab *){

}

void Escopo::addPai(Escopo *){

}

Escopo* Escopo::getPai(){

}

bool Escopo::checkInserted(strin id){
    bool ret = false;

    map<string, ElemTab *>::iterator i;
    for(i = tabelaSimbolos.begin(); i != tabelaSimbolos.end(); ++i){
        if (i->first == id){
            ret = true;
            break;
        }
    }

    return ret;
}