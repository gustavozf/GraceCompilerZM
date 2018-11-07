#include <iostream>
#include <string>

using namespace std;

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
        NegExp(Exp* expr){
            e1 = expr;
        }

        int eval(){
            return 1;
        }

        string codeGen(){
            return "";
        }

        string getTipo(){
            return "";
        }
};

class TerExp : public Exp{
    private:
        Exp *e1, *e2, *e3;
    
    public:
        TerExp(Exp* expr1, Exp* expr2, Exp* expr3){
            e1 = expr1; 
            e2 = expr2; 
            e3 = expr3;
        }

        int eval(){
            return 1;
        }

        string codeGen(){
            return "";
        }
        
        string getTipo(){
            return "";
        }
};