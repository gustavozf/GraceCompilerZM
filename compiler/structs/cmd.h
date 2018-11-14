#include <iostream>
#include <string>
#include "exp.h"
#include "prog.h"

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
        Var *var;

    public:
        AtribCmd(Var *varia, string typ, Exp *ex);
        int eval();
        string codeGen();  
};

class ReadCmd : public Cmd{
    private:
        Var* var;
    public:
        ReadCmd(Var* varia);
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

#endif

/*
class Bloco : public Cmd{
    private:
        //list<> declaracoes;
        list<Cmd *> *comandos;


};

class ProcCmd : public Cmd{

};
*/