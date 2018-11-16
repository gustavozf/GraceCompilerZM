#include <iostream>
#include <string>
#include "exp.h"

using namespace std;

#ifndef PROG_H
#define PROG_H

class Var{
    protected:
        string id;

    public:
        virtual int eval() = 0;
        virtual string codeGen() = 0;
};

class VarSimples : public Var{
    public:
        VarSimples(string idName);
        int eval();
        string codeGen();
};

class VarArranjo : public Var{
    private:
        Exp *position;

    public:
        VarArranjo(string idName, Exp *pos);
        int eval();
        string codeGen();
};

#endif