#include "prog.h"
// ---------------------------------- ElemTab
ElemTab::ElemTab(string cat, string type, bool agreg){
    categoria = cat;
    tipo = type;
    retorno = "";
    numParams = 0;
    agregado = agreg;
    params = new list<string >();
} 

ElemTab::ElemTab(string cat, string ret, int nParams, list<string > *tipos){
    categoria = cat;
    tipo = "";
    retorno = ret;
    numParams = nParams;
    agregado = false;
    params = tipos;
}

// ========================================= Escopo
Escopo::Escopo(Escopo *papi, int id1){
    pai = papi;
    idEsc = id1;
}
void Escopo::addElem(string id, ElemTab *elem){
    if (this->checkInserido(id)){
        cout << "Aviso: redeclaração de ID ('"<<id<<"') em um mesmo escopo ("<< getId() <<")!" <<endl;
    } else {
        //cout << "Novo elemento inserido na TS (Escopo " << getId() << "): '"<< id << "'" << endl;
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
        return nullptr;
    }
}

int Escopo::getId(){
    return idEsc;
}