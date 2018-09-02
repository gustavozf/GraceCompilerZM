%{
    /* Declaracoes */
	#include <iostream>
    #include <string>

    using namespace std;

    extern int yylex();
%}

/* opcoes */
%option debug
%option noyywrap

/* Expresssoes Regulares */
%%
	/* trata um comentario */
"//".*\n {cout << "COMENTARIO!\n";}

	/* Identificador */
(\_|[a-zA-Z])([a-zA-Z]|[0-9]|\_)* {
                                cout << "Id encontrado: " << yytext << endl;
                                //return ID;
				}
	/* Elimina os Espacos em branco*/
[ \t\n] {} 
%%

/* Codificacao C++ */

int main(int argc, char **argv){
    while(yylex());
}
