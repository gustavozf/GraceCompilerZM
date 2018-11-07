#include <iostream>
#include <map>
#include <list>
#include <string>
#include "exp.h"

using namespace std;

class Cmd{
    public:
        virtual int eval() = 0;
        virtual string codeGen() = 0;
};



class IfCmd{
    private:
        Exp *condicao;
        Cmd *then, *els;

    public:
        IfCmd(Exp *cnd, Cmd *thn, Cmd *elz){
            condicao = cnd; then = thn; els = elz;
        }

        int eval(){
            
        }
};

class WhileCmd{
    
};

class ForCmd{
    
};

/*
class StopCmd{
    
};

class SkipCmd{
    
};

class RetCmd{
    
};

class ProcCmd{

};

class ReadCmd{

};

class WriteCmd{

};  
*/