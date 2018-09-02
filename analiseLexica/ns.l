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
    [ \t\n] // Se houverem espacos em branco, fazer nada
    "//".*\n {cout << "COMENTARIO!";} // Trata um comentario
    (\_|[a-zA-Z])([a-zA-Z]|[0-9]|\_)* {
                                    cout << "Id encontrado: " << yytext << endln;
                                    return ID;}
%%

/* Codificacao C++ */

int main(){
    while(yylex());
}