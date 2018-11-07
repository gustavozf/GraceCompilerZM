#include <iostream>
#include <string>

using namespace std;

class TipoVar{
    public:
        virtual string getTipo() = 0;
        virtual int getSize() = 0;
        virtual string codeGen() = 0;
};

class StringTipoVar : public TipoVar{
    private:
        string tipo;
        int tam;

    public:
        TipoVar(string tp, int tm){
            tipo = tp; 
            
            if (tam > 0){
                tam = tm;
            } else {
                tam = 256;
            }
        }

        string getTipo(){
            return "string";
        }

        int getSize(){
            return tam;
        }

        string codeGen(){
            return "";
        }
};