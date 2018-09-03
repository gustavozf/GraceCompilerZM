%{
/* Declaracoes */
#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

// Coisas do Flex que o Biso precisa
extern int yylex();
extern int yyparse();
extern FILE *yyin;

// Tratar Erros (aparentemente obrigatorio)
void yyerror(const char *s);
%}

/* Uniao que representa o valores basicos possiveis.
   Utilizada pela ferramenta
*/
%union {
	int ival;
	float fval;
	char *sval;
}

/* Tokens 

%token <TIPO> <NOME>;

*/
%token <sval> t_id;

%%
    /* Gramatica */ 
    identificador: t_id {cout << "Variavel identificada: " << $1 << endl;}
%%

/* Codificacao C++ */
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

    yyparse();

	return 0;
}

void yyerror(const char *s){
	cout<< "Erro Sintatico! Mensagem: " << s << endl;

	exit(-1);
}