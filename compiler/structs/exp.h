#include <iostream>
#include <string>
#include <list>
#include "prog.h"

using namespace std;

#ifndef EXP_H
#define EXP_H

class Exp{
    public:
        // Pega o tipo da expressao
        virtual string getTipo() = 0;
        // Realiza a avaliacao da expressao
        virtual int eval() = 0;
        // Gera o codigo da expressao
        virtual string codeGen() = 0;
};

class AritmExp : public Exp{  
    private:
        Exp *e1, *e2;
        string op;
        
    public:
        AritmExp(Exp* expr1, Exp* expr2, string ope);
        int eval();
        string codeGen();
        string getTipo();

};

class RelExp : public Exp{
    private:
        Exp *e1, *e2;
        string op;
        
    public:
        RelExp(Exp* expr1, Exp* expr2, string ope);
        int eval();
        string codeGen();
        string getTipo();
};

class LogExp : public Exp{
    private:
        Exp *e1, *e2;
        string op;
        
    public:
        LogExp(Exp* expr1, Exp* expr2, string ope);
        int eval();
        string codeGen();
        string getTipo();
};


class IgExp : public Exp {
    private:
        Exp *e1, *e2;
        string op;
        
    public:
        IgExp(Exp* expr1, Exp* expr2, string ope);
        int eval();
        string codeGen();
        string getTipo();
};

class NegUnExp : public Exp {
    private:
        Exp *e1;

    public:
        NegUnExp(Exp* expr);
        int eval();
        string codeGen();
        string getTipo();
};

class NegExp : public Exp {
    private:
        Exp *e1;

    public:
        NegExp(Exp* expr);
        int eval();
        string codeGen();
        string getTipo();
};

class TerExp : public Exp{
    private:
        Exp *e1, *e2, *e3;
    
    public:
        TerExp(Exp* expr1, Exp* expr2, Exp* expr3);
        int eval();
        string codeGen();
        string getTipo();
};


class AtribFor : public Exp{
    private:
        string type, id, num;
        Escopo *atual;

    public:
        AtribFor(string id1, string typ, string nume, Escopo *atual1);
        AtribFor(string id1, string nume, Escopo *atual1);
        int eval();
        string codeGen();
        string getTipo();
};

class ValExp : public Exp{
    private:
        string valor, type;
    
    public:
        ValExp(string val, string typ);
        int eval();
        string codeGen();
        string getTipo();
};

class VarExp : public Exp{
    private:
        string id;
        Exp *position;
        Escopo *atual;

    public:
        VarExp(string id1, Exp *pos, Escopo* atual1);
        VarExp(string id2, Escopo* atual1);
        int eval();
        bool isInEscopo();
        string codeGen();
        string getTipo();
        string getId();
        Escopo* getEscopo();
};

class FuncExp : public Exp{
    private:
        string id;
        list<Exp *> *expressoes;
        Escopo *atual;

    public:
        FuncExp(string id1, Escopo *atual1);
        FuncExp(string id1, list<Exp *> *exps, Escopo *atual1);
        int eval();
        bool isInEscopo();
        string codeGen();
        string getTipo();
};

#endif