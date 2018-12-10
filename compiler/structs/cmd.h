#include "common.h"
#include "exp.h"
#include "prog.h"

#ifndef CMD_H
#define CMD_H

class Decl;
class DeclSub;

class Cmd{
    public:
        virtual int eval() = 0;
        virtual string codeGen(ofstream &output) = 0;
};

class IfCmd : public Cmd{
    private:
        Exp *condicao;
        Cmd *then, *els;
        int line;

    public:
        IfCmd(Exp *cnd, Cmd *thn, int line1);
        IfCmd(Exp *cnd, Cmd *thn, Cmd *elz, int line1);
        int eval();
        string codeGen(ofstream &output);
};

class WhileCmd : public Cmd{
    private:
        Exp *condicao;
        Cmd *comando;
        stack<Cmd *> *pilhaCmdRepet;
        int line;

    public:
        WhileCmd(Exp *cnd, Cmd *cmd, stack<Cmd *> *pilhaCmdRep, int line1);
        int eval();
        string codeGen(ofstream &output);
};

class AtribCmd : public Cmd{
    private:
        string type;
        Exp *exp;
        VarExp *var;
        int line;

    public:
        AtribCmd(Exp *varia, string typ, Exp *ex, int line1);
        int eval();
        string codeGen(ofstream &output);  
};

class ForCmd : public Cmd{
    private:
        Exp *exp;
        AtribCmd *atribIni, *atribPasso;
        Cmd* comando;
        stack<Cmd *> *pilhaCmdRepet;
        int line;

    public:
        ForCmd(Cmd *atriIni, Exp *ex, Cmd *atriPasso, Cmd* cman, stack<Cmd *> *pilhaCmdRep, int line1);
        int eval();
        string codeGen(ofstream &output);
};

class StopSkipCmd : public Cmd{
    private:
        string cmd;
        stack<Cmd *> *pilhaCmdRepet;
        int line;

    public:
        StopSkipCmd(string comando, stack<Cmd *> *pilhaCmdRep, int line1);
        int eval();
        string codeGen(ofstream &output);
};

class ReadCmd : public Cmd{
    private:
        VarExp* var;
        int line;

    public:
        ReadCmd(Exp* varia, int line1);
        int eval();
        string codeGen(ofstream &output);
};

class WriteCmd : public Cmd{
    private:
        list<Exp *> *cnjExp;

    public:
        WriteCmd(list<Exp *> *cnExp);
        int eval();
        string codeGen(ofstream &output);
};  

class ProcCmd : public Cmd{
    private:
        string id;
        list<Exp *> *expressoes;
        Escopo *atual;
        int line;

    public:
        ProcCmd(string id1, Escopo *atual1, int line1);
        ProcCmd(string id1, list<Exp *> *exps, Escopo *atual1, int line1);
        bool isInEscopo();
        int eval();
        string codeGen(ofstream &output);
        ElemTab* getElemTab();

};

class RetCmd : public Cmd{
    private:
        Exp *retorno;
        stack<DeclSub *> *pilhaSubprog;
        int line;

    public:
        RetCmd(Exp *ret, stack<DeclSub *> *pilhaSub, int line1);
        RetCmd(stack<DeclSub *> *pilhaSub, int line1);
        int eval();
        string codeGen(ofstream &output);    
};

class BlocoCmd : public Cmd{
    private:
        list<Decl *> *declaracoes;
        list<Cmd *> *comandos;
        Escopo *atual;

    public:
        BlocoCmd(list<Decl *> *decl, Escopo* at);
        BlocoCmd(list<Cmd *> *com, Escopo* at);
        BlocoCmd(list<Decl *> *decl, list<Cmd *> *com, Escopo* at);

        Escopo* getEscopo();

        int eval();
        string codeGen(ofstream &output);
};

class Programa{
    private:
        list<Decl *> *declaracoes;
        Escopo *global;
        int line;

    public:
        Programa(list<Decl *> *decl, Escopo *glob, int line1);
        int eval();
        string codeGen(ofstream &output);
};

#endif