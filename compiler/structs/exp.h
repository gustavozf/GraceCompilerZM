#include <iostream>
#include <map>
#include <list>
#include <string>

using namespace std;

class Exp{
    public:
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
        AritmExp(Exp* expr1, Exp* expr2, string ope){
            e1 = expr1; e2 = expr2; op = ope;
        }
    
        int eval(){
            
        }

        string codeGen(){
            // NoEsq = (x) No Dir = 49
            return "x * 49";
        }

};

class RelExp : public Exp{
    private:
        Exp *e1, *e2;
        string op;
        
    public:
        RelExp(Exp* expr1, Exp* expr2, string ope){
            e1 = expr1; e2 = expr2; op = ope;
        }
    
        int eval(){
            
        }

        string codeGen(){
            
        }
        
};

class LogExp : public Exp{
    private:
        Exp *e1, *e2;
        string op;
        
    public:
        LogExp(Exp* expr1, Exp* expr2, string ope){
            e1 = expr1; e2 = expr2; op = ope;
        }
    
        int eval(){
            
        }

        string codeGen(){
            
        }
};


class IgExp : public Exp {
    private:
        Exp *e1, *e2;
        string op;
        
    public:
        IgExp(Exp* expr1, Exp* expr2, string ope){
            e1 = expr1; e2 = expr2; op = ope;
        }
    
        int eval(){
            
        }

        string codeGen(){
            
        }
};

class NegUnExp : public Exp {
    private:
        Exp *e1;
        string op;

    public:
        NegUnExp(Exp* expr, string ope){
            e1 = expr; op = ope;
        }

        int eval(){

        }

        string codeGen(){
            
        }
};

class NegExp : public Exp {
    private:
        Exp *e1;
        string op;

    public:
        NegExp(Exp* expr, string ope){
            e1 = expr; op = ope;
        }

        int eval(){

        }

        string codeGen(){
            
        }
};

class TerExp : public Exp{
    private:
        Exp *e1, *e2, *e3;
        string op1, op2;
    
    public:
        TerExp(Exp* expr1, Exp* expr2, Exp* expr3, string ope1, string ope2){
            e1 = expr1; e2 = expr2; e3 = expr3; op1 = ope1; op2 = ope2;
        }

        int eval(){

        }

        string codeGen(){
            
        }
};