#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;

#ifndef PROG_H
#define PROG_H


/* 
var 
    - id
    - agregada?
func
    - id
    - params
    - tipos dos params
    - retorno
proc
    - id
    - params
    - tipos dos params
*/
class ElemTab{
    public:
        string categoria, tipo, retorno;

        int numParams;
        bool agregado;
        list<pair<int, string > > *params;

        //var simples e agreg
        ElemTab(string cat, string type, bool agreg); 
        //func com param
        ElemTab(string cat, string ret, int nParams, list<pair<int, string > > *tipos);
};


class Escopo{
    private:
        map<string, ElemTab *> tabelaSimbolos;
        Escopo *pai;

    public:
        Escopo(Escopo *papi);
        void addElem(string id, ElemTab *elem);
        Escopo* getPai();
        bool checkInserido(string id);
        ElemTab* getElemTab(string id);
};

#endif
