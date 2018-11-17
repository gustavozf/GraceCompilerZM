#include <iostream>
#include <string>
#include "exp.h"

using namespace std;

#ifndef PROG_H
#define PROG_H

class Var{
    private:
        string id;
        Exp *position;

    public:
        Var(string id1, Exp *pos);
        Var(string id2);
        int eval();
        string codeGen();
};

#endif