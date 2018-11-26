#include "prog.h"
// ---------------------------------- ElemTab
ElemTab::ElemTab(string cat, string type, bool agreg){
    categoria = cat;
    tipo = type;
    retorno = "";
    numParams = 0;
    agregado = agreg;
    tiposParams = nullptr;
} 

ElemTab::ElemTab(string cat){
    categoria = cat;
    tipo = "";
    retorno = "";
    numParams = 0;
    agregado = false;
    tiposParams = nullptr;
}

ElemTab::ElemTab(string cat, int nParams, vector<string > *tipos){
    categoria = cat;
    tipo = "";
    retorno = "";
    numParams = nParams;
    agregado = false;
    tiposParams = tipos;
}

ElemTab::ElemTab(string cat, string ret){
    categoria = cat;
    tipo = "";
    retorno = ret;
    numParams = 0;
    agregado = false;
    tiposParams = nullptr;
}

ElemTab::ElemTab(string cat, string ret, int nParams, vector<string > *tipos){
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
    tabelaSimbolos.insert(pair<string, ElemTab *>(id, elem));
}

Escopo* Escopo::getPai(){
    return pai;
}

bool Escopo::checkInserido(string id){
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