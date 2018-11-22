#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

#ifndef PROG_H
#define PROG_H

void teste();


/* 
var 
    - id
    - agregada?
    - inicializacao?
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
        string id, categoria;

        bool agreg;
        vector<string > *ini;
        vector<string > *typeParam;
        vector<string > *params;
    
        //var sem inicializacao, func sem param, proc sem param
        ElemTab(string id1, string type, string cat); 
        //var com inicializacao
        ElemTab(srting id1, string type, vector<string > *ini);
        //var agregada sem inicializacao
        ElemTab(string id1, string type, bool agreg1);
        //var agregada com inicializacao
        ElemTab(string id1, string type, bool agreg1, vector<string > *ini1);
        //func com params
        ElemTab(string id1, string type, vector<string > *params1, vector<string > *typeParam1);
        //proc com params
        ElemTab(string id1, vector<string > *params1, vector<string > *typeParam1);

};

class VarElemTab : public ElemTab{

};

class FuncElemTab : public ElemTab{

};

class ProcElemTab : public ElemTab{

};

class Escopo{
    private:
        map<string id, ElemTab *> tabelaSimbolos;

    public:
        addElem();
        addMultElem();
        buscaElem();
};

#endif