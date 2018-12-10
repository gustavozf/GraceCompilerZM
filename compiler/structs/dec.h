#include "common.h"
#include "exp.h"
#include "prog.h"

#ifndef DEC_H
#define DEC_H

class Cmd;
class BlocoCmd;

class TipoVar{
    public:
        virtual string getTipo() = 0;
        virtual string getSize() = 0;
        virtual string codeGen(ofstream &output) = 0;
};

class StringTipoVar : public TipoVar{
    private:
        string tam;

    public:
        StringTipoVar();
        StringTipoVar(string tm);
        string getTipo();
        string getSize();
        string codeGen(ofstream &output);
};

class BoolTipoVar : public TipoVar{
    private:
        string tam;

    public:
        BoolTipoVar();
        string getTipo();
        string getSize();
        string codeGen(ofstream &output);
};

class IntTipoVar : public TipoVar{
    private:
        string tam;

    public:
        IntTipoVar();
        string getTipo();
        string getSize();
        string codeGen(ofstream &output);
};

class SpecVar {
    protected:
        string id;

    public:
        virtual string codeGen(ofstream &output) = 0;
        virtual int eval() = 0;
        virtual string getId() = 0;
        virtual bool isArranjo() = 0;
        virtual bool confereTipagem(string tipo) = 0;
};

class SpecVarSimples : public SpecVar {
    private:
        Exp *inicializacao;
        int line;

    public:
        SpecVarSimples(string id1, Exp *ini, int line1);
        SpecVarSimples(string id1, int line1);
        string codeGen(ofstream &output);
        int eval();
        string getId();
        bool isArranjo();
        bool confereTipagem(string tipo);
};

class SpecVarArranjo : public SpecVar {
    private:
        Exp *tam;
        list<Exp *> *inicializacao;
        int line;
    
    public:
        SpecVarArranjo(string id1, Exp *tama, list<Exp *> *ini, int line1);
        SpecVarArranjo(string id1, Exp *tama, int line1);
        string codeGen(ofstream &output);
        int eval();
        string getId();
        bool isArranjo();
        bool confereTipagem(string tipo);
};


class Param {
    private:
        string id;
        bool arranjo; 

    public:
        Param(string id1, bool arranj);
        string getId();
        bool getArranjo();
};

class SpecParam {
    private:
        list<Param *> *cnjParam;
        TipoVar *type;

    public:
        SpecParam(list<Param *> *lista, TipoVar *typ);
        list<Param *>* getCnjParam();
        string getTipo();
        int getSize();
};

class Decl{
    public:
        virtual string codeGen(ofstream &output) = 0;
        virtual int eval() = 0;
        virtual void addTabSimb(Escopo *atual) = 0;
        virtual string getTipo() = 0;
};

class DeclVar : public Decl{
    private:
        list<SpecVar *> *listaSpecVar;
        TipoVar *tipo;

    public:
        DeclVar(list<SpecVar *> *lista, TipoVar *type);
        string codeGen(ofstream &output);
        int eval();
        void addTabSimb(Escopo *atual);
        string getTipo();
};

class DeclSub : public Decl{
    private:
        string id, tipo;
        TipoVar *retorno;
        list<SpecParam *> *listaParam;
        BlocoCmd *bloco;
        stack<DeclSub *> *pilhaSubprog;
        
    public:
        // Declaracao de Procedimento
        DeclSub(string id1, list<SpecParam *> *lista, Cmd *block, stack<DeclSub *> *pilhaSub);
        DeclSub(string id1, Cmd *block, stack<DeclSub *> *pilhaSub);

        // Declaracao de Funcao
        DeclSub(string id1, list<SpecParam *> *lista, TipoVar *ret, Cmd *block, stack<DeclSub *> *pilhaSub);
        DeclSub(string id1, TipoVar *ret, Cmd *block, stack<DeclSub *> *pilhaSub);

        string codeGen(ofstream &output);
        int eval();
        void addTabSimb(Escopo *atual);
        string getTipo();
        string getId();
        string getTipoRetorno();
};

#endif