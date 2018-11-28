#include "prog.h"
// ---------------------------------- ElemTab
ElemTab::ElemTab(string cat, string type, bool agreg){
    categoria = cat;
    tipo = type;
    retorno = "";
    numParams = 0;
    agregado = agreg;
    tiposParams = new list<pair<int, string > >();
} 

ElemTab::ElemTab(string cat, string ret, int nParams, list<pair<int, string > > *tipos){
    categoria = cat;
    tipo = "";
    retorno = ret;
    numParams = nParams;
    agregado = false;
    tiposParams = tipos;
}

// ========================================= Escopo
Escopo::Escopo(Escopo *papi){
    pai = papi;
}
void Escopo::addElem(string id, ElemTab *elem){
    if (this->checkInserido(id)){
        cout << "Aviso: redeclaração de ID ("<<id<<") em um mesmo escopo!" <<endl;
    } else {
        tabelaSimbolos[id] = elem;
    }
}

Escopo* Escopo::getPai(){
    return pai;
}

bool Escopo::checkInserido(string id){
    return tabelaSimbolos.count(id);
}

ElemTab* Escopo::getElemTab(string id){
    if(this->checkInserido(id)){
        return tabelaSimbolos[id];
    }else{
        return "null"
    }
}