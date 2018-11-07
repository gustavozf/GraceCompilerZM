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

class MultExp : public Exp{
    private:
        Exp *e1, *e2;
        
    public:
        MultExp(Exp* expr1, Exp* expr2){
            e1 = expr1; e2 = expr2;
        }
    
        int eval(){
            
        }

        string codeGen(){
            // NoEsq = (x) No Dir = 49
            return "x * 49";
        }

};

