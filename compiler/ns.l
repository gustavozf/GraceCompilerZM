%{
/* Declaracoes */
#include <iostream>
#include <string>
#include <map>

/* Arquivo gerado do Bison
   Usado para ler os tokens e etc.
 */
#include "ns.tab.h"

using namespace std;

extern int yylex();

std::map<std::string, int> tokens_table;
%}

/* opcoes 
%option debug
%option noyywrap
*/

/* Expresssoes Regulares */
%%
	/* Elimina os Espacos em Branco*/
[ \t\n] {} 

	/* Palavras Reservadas */
	
	/* Simbolo */

	/* trata um comentario */
"//".*\n {cout << "COMENTARIO!\n";}

	/* Identificador */
(\_|[a-zA-Z])([a-zA-Z]|[0-9]|\_)* {
                                cout << "Id encontrado: " << yytext << endl;
                                // Converte o 'yytext' para uma string
								yylval.sval = strdup(yytext);
								return t_id;
				}

	/* Numeros */

	/* Strings */
	
	/* Elimina Demais Caracteres Indesejados */
	. ;
%%

/* Codificacao C++ */
/*
int main(int argc, char *argv[]){
	if(argc < 2){
		cout << "ERRO: Eh necessario passar o nome do arquivo de entrada!\n";

		return 0;
	}

	FILE *entrada = fopen(argv[1], "r");

	if (!entrada) {
		cout << "Erro ao abrir o arquivo: '" << argv[1] << "'!\n";
		return -1;
	}

	yyin = entrada;

    while(yylex());

	return 0;
}*/
