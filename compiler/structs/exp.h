#include "common.h"
#include "prog.h"

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
        int line;
        
    public:
        AritmExp(Exp* expr1, Exp* expr2, string ope, int line1);
        int eval();
        string codeGen();
        string getTipo();

};

class RelExp : public Exp{
    private:
        Exp *e1, *e2;
        string op;
        int line;

    public:
        RelExp(Exp* expr1, Exp* expr2, string ope, int line1);
        int eval();
        string codeGen();
        string getTipo();
};

class LogExp : public Exp{
    private:
        Exp *e1, *e2;
        string op;
        int line;

    public:
        LogExp(Exp* expr1, Exp* expr2, string ope, int line1);
        int eval();
        string codeGen();
        string getTipo();
};


class IgExp : public Exp {
    private:
        Exp *e1, *e2;
        string op;
        int line;
    
    public:
        IgExp(Exp* expr1, Exp* expr2, string ope, int line1);
        int eval();
        string codeGen();
        string getTipo();
};

class NegUnExp : public Exp {
    private:
        Exp *e1;
        int line;

    public:
        NegUnExp(Exp* expr, int line1);
        int eval();
        string codeGen();
        string getTipo();
};

class NegExp : public Exp {
    private:
        Exp *e1;
        int line;

    public:
        NegExp(Exp* expr, int line1);
        int eval();
        string codeGen();
        string getTipo();
};

class TerExp : public Exp{
    private:
        Exp *e1, *e2, *e3;
        int line;

    public:
        TerExp(Exp* expr1, Exp* expr2, Exp* expr3, int line1);
        int eval();
        string codeGen();
        string getTipo();
};

class ValExp : public Exp{
    private:
        string valor, type;
        int line;
    
    public:
        ValExp(string val, string typ, int line1);
        int eval();
        string codeGen();
        string getTipo();
};

class VarExp : public Exp{
    private:
        string id; //, tipo;
        Exp *position;
        Escopo *atual;
        int line;

    public:
        VarExp(string id1, Exp *pos, Escopo* atual1, int line1);
        VarExp(string id2, Escopo* atual1, int line1);
        int eval();
        bool isInEscopo();
        string codeGen();
        string getTipo();
        string getId();
};

class FuncExp : public Exp{
    private:
        string id;
        list<Exp *> *expressoes;
        Escopo *atual;
        int line;
        //string tipo;

    public:
        FuncExp(string id1, Escopo *atual1, int line1);
        FuncExp(string id1, list<Exp *> *exps, Escopo *atual1, int line1);
        int eval();
        bool isInEscopo();
        string codeGen();
        string getTipo();
        ElemTab* getElemTab();
};

#endif