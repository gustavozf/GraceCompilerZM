#include <iostream>
#include <string>
#include <list>
#include "exp.h"
#include "prog.h"
#include "dec.h"

using namespace std;

#ifndef CMD_H
#define CMD_H

class Cmd{
    public:
        virtual int eval() = 0;
        virtual string codeGen() = 0;
};

class IfCmd : public Cmd{
    private:
        Exp *condicao;
        Cmd *then, *els;

    public:
        IfCmd(Exp *cnd, Cmd *thn);
        IfCmd(Exp *cnd, Cmd *thn, Cmd *elz);
        int eval();
        string codeGen();
};

class WhileCmd : public Cmd{
    private:
        Exp *condicao;
        Cmd *comando;

    public:
        WhileCmd(Exp *cnd, Cmd *cmd);
        int eval();
        string codeGen();
};

class ForCmd : public Cmd{
    private:
        Exp *exp, *atribIni, *atribPasso;;
        Cmd* comando;

    public:
        ForCmd(Exp *atriIni, Exp *ex, Exp *atriPasso, Cmd* cman);
        int eval();
        string codeGen();
};

class StopSkipCmd : public Cmd{
    private:
        string cmd;

    public:
        StopSkipCmd(string comando);
        int eval();
        string codeGen();
};


class RetCmd : public Cmd{
    private:
        Exp *retorno;

    public:
        RetCmd(Exp *ret);
        RetCmd();
        int eval();
        string codeGen();    
};

class AtribCmd : public Cmd{
    private:
        string type;
        Exp *exp;
        Exp *var;

    public:
        AtribCmd(Exp *varia, string typ, Exp *ex);
        int eval();
        string codeGen();  
};

class ReadCmd : public Cmd{
    private:
        Exp* var;
    public:
        ReadCmd(Exp* varia);
        int eval();
        string codeGen();
};

class WriteCmd : public Cmd{
    private:
        list<Exp *> *cnjExp;
    public:
        WriteCmd(list<Exp *> *cnExp);
        int eval();
        string codeGen();
};  


class BlocoCmd : public Cmd{
    private:
        list<Decl *> *declaracoes;
        list<Cmd *> *comandos;
    public:
        BlocoCmd(list<Decl *> *decl);
        BlocoCmd(list<Cmd *> *com);
        BlocoCmd(list<Decl *> *decl, list<Cmd *> *com);

        int eval();
        string codeGen();
};


class ProcCmd : public Cmd{
    private:
        string id;
        list<Exp *> *expressoes;
        Escopo *atual;

    public:
        ProcCmd(string id1, Escopo *atual1);
        ProcCmd(string id1, list<Exp *> *exps, Escopo *atual1);
        bool isInEscopo();
        int eval();
        string codeGen();
};

class Programa{
    private:
        list<Decl *> *declaracoes;
        Escopo *global;
    public:
        Programa(list<Decl *> *decl, Escopo *glob);
        int eval();
        string codeGen();
};

#endif