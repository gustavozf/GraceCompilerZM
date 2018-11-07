#include <iostream>
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