#include <iostream>
#include <string>
#include <vector>
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
        vector<string > *tiposParams;

        //var simples e agreg
        ElemTab(string cat, string type, bool agreg); 
        //proc sem param
        ElemTab(string cat);
        //proc com param
        ElemTab(string cat, int nParams, vector<string > *tipos);
        //func sem param
        ElemTab(string cat, string ret);
        //func com param
        ElemTab(string cat, string ret, int nParams, vector<string > *tipos);
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
};

#endif
