#include <iostream>
#include <map>
#include <list>
#include <string>
#include "exp.h"

using namespace std;

class CmdSimp{
    public:
        virtual int eval() = 0;
        virtual string codeGen() = 0;
};



class IfCmd : public CmdSimp{
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

class WhileCmd : public CmdSimp{
    
};

class ForCmd : public CmdSimp{
    
};

/*
class StopCmd : public CmdSimp{
    
};

class SkipCmd : public CmdSimp{
    
};

class RetCmd : public CmdSimp{
    
};

class ProcCmd : public CmdSimp{

};

class ReadCmd : public CmdSimp{

};

class WriteCmd : public CmdSimp{

};  
*/