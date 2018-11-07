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

class IfCmd : public Cmd{
    private:
        Exp *condicao;
        Cmd *then, *els;

    public:
        IfCmd(Exp *cnd, Cmd *thn, Cmd *elz){
            condicao = cnd; then = thn; els = elz;
        }

        int eval(){
            return 1;
        }
};

class WhileCmd : public Cmd{
    
};

class ForCmd : public Cmd{
    
};

/*
class StopCmd : public Cmd{
    
};

class SkipCmd : public Cmd{
    
};

class RetCmd : public Cmd{
    
};

class ProcCmd : public Cmd{

};

class ReadCmd : public Cmd{

};

class WriteCmd : public Cmd{

};  
*/