#include "common.h"

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
        list<string > *params;

        // var/param simples e agreg
        ElemTab(string cat, string type, bool agreg); 
        // func e proc
        ElemTab(string cat, string ret, int nParams, list<string > *tipos);
};


class Escopo{
    private:
        map<string, ElemTab *> tabelaSimbolos;
        Escopo *pai;
        int idEsc;

    public:
        Escopo(Escopo *papi, int id1);
        void addElem(string id, ElemTab *elem);
        Escopo* getPai();
        bool checkInserido(string id);
        ElemTab* getElemTab(string id);
        int getId();
};

#endif
