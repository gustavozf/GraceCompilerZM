#include <iostream>
#include <string>
#include "exp.h"

using namespace std;

class TipoVar{
    public:
        virtual string getTipo() = 0;
        virtual string getSize() = 0;
        virtual string codeGen() = 0;
};

class StringTipoVar : public TipoVar{
    private:
        string tam;

    public:
        StringTipoVar();
        StringTipoVar(string tm);
        string getTipo();
        string getSize();
        string codeGen();
};

class BoolTipoVar : public TipoVar{
    private:
        string tam;

    public:
        BoolTipoVar();
        string getTipo();
        string getSize();
        string codeGen();
};

class IntTipoVar : public TipoVar{
    private:
        string tam;

    public:
        IntTipoVar();
        string getTipo();
        string getSize();
        string codeGen();
};

class Spec{
    private:
        string id;

    public:
        virtual string codeGen() = 0;
}

class SpecVarSimples : public SpecVar{
    private:
        Exp *inicializacao;
    
    public:
        DecVarSimples(Exp *ini);
        DecVarSimples();
        string codeGen();
        int eval();
}