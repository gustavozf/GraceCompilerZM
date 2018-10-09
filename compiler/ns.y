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

extern int num_linhas;
extern int num_carac;

// Tratar Erros (aparentemente obrigatorio)
void yyerror(const char *s);
%}

/* Uniao que representa o valores basicos possiveis.
   Utilizada pela ferramenta
*/
%union {
	int ival;   // Inteiro
	float fval; // Float
	char *sval; // String
}

/* Tokens 
%token <TIPO> <NOME>
*/
%token <sval> t_id
%token <sval> t_num
%token <sval> t_lit_string
/*
%token <sval> t_bool
%token <sval> t_else
%token <sval> t_def
%token <sval> t_false
%token <sval> t_for
%token <sval> t_if
%token <sval> t_int
%token <sval> t_read
%token <sval> t_return
%token <sval> t_skip
%token <sval> t_stop
%token <sval> t_string
%token <sval> t_true
%token <sval> t_var
%token <sval> t_while
*/

%%
	/* Gramatica */ 
    identificador: 
		t_id identificador {cout << "Variavel identificada: " << $1 << endl;}
		| t_id {cout << "Variavel identificada: " << $1 << endl;}
		;
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
	cout<< "Erro Sintatico: " << s <<" (l: "<<num_linhas<< ", c: "<<num_carac<<")\n";

	exit(-1);
}