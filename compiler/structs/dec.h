#include <iostream>
#include <string>
#include <list>
#include "exp.h"

using namespace std;

#ifndef DEC_H
#define DEC_H

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

class SpecVar {
    protected:
        string id;

    public:
        virtual string codeGen() = 0;
        virtual int eval() = 0;
};

class SpecVarSimples : public SpecVar {
    private:
        Exp *inicializacao;
    
    public:
        SpecVarSimples(string id1, Exp *ini);
        SpecVarSimples(string id1);
        string codeGen();
        int eval();
};

class SpecVarArranjo : public SpecVar {
    private:
        Exp *tam;
        list<Exp *> *inicializacao;
    
    public:
        SpecVarArranjo(string id1, Exp *tama, list<Exp *> *ini);
        SpecVarArranjo(string id1, Exp *tama);
        string codeGen();
        int eval();
};

class Decl{
    public:
        string codeGen();
        int eval();
};

class DeclVar : public Decl{
    private:
        list<SpecVar *> *listaSpecVar;
        TipoVar *tipo;
    public:
        DeclVar(list<SpecVar *> *lista, TipoVar *type);
        string codeGen();
        int eval();
};

#endif