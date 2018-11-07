%{
/* Declaracoes */
#include <iostream>
#include <cstdio>
#include <string>

#include "./structs/exp.h"
#include "./structs/cmd.h"
#include "./structs/dec.h"

using namespace std;

// Coisas do Flex que o Bison precisa
extern int yylex();
extern int yyparse();
extern FILE *yyin;

extern int num_linhas;
extern int num_carac;

// Tratar Erros (aparentemente obrigatorio)
void yyerror(const char *s);
%}

%error-verbose

/* Uniao que representa o valores basicos possiveis.
   Utilizada pela ferramenta
*/
%union {
	int ival;   // Inteiro
	float fval; // Float
	char *sval; // String
}

/* Tokens */
// constant-strings
%token T_BOOL
%token T_INT
%token T_STRING
%token T_IF
%token T_ELSE
%token T_FOR
%token T_WHILE
%token T_WRITE
%token T_READ
%token T_DEF
%token T_RETURN
%token T_VAR
%token T_SKIP
%token T_STOP
%token T_TRUE
%token T_FALSE
%token T_ABRE_PARENTESES  "("
%token T_FECHA_PARENTESES ")"
%token T_ABRE_COLCHETES   "["
%token T_FECHA_COLCHETES  "]"
%token T_ABRE_CHAVES      "{"
%token T_FECHA_CHAVES     "}"
%token T_VIRGULA          ","
%token T_PONTO_VIRGULA    ";"
%token T_ADICAO           "+"
%token T_SUBTRACAO        "-"
%token T_MULTIPLICACAO    "*"
%token T_DIVISAO          "/"
%token T_MODULO           "%"
%token T_EQ_LOGICA        "=="
%token T_DIF_LOGICA       "!="
%token T_MAIOR 		      ">"
%token T_MAIOR_IGUAL      ">="
%token T_MENOR            "<"
%token T_MENOR_IGUAL      "<="
%token T_OR               "||"
%token T_AND              "&&"
%token T_NOT              "!"
%token T_ATRIBUICAO       "="
%token T_ATRIB_SOMA       "+="
%token T_ATRIB_SUB        "-="
%token T_ATRIB_MULT       "*="
%token T_ATRIB_DIV        "/="
%token T_ATRIB_MOD        "%="
%token T_COND_OP_TER      "?"
%token T_DOIS_PON         ":"

// tokens que assumem valores
// %token <TIPO> <NOME>
%token <sval> T_ID
%token <sval> T_NUM
%token <sval> T_LIT_STRING

%right T_NEG_UNAR
%right T_NOT
%left T_MULTIPLICACAO T_DIVISAO T_MODULO 
%left T_ADICAO T_SUBTRACAO
%left T_MENOR T_MENOR_IGUAL
%left T_MAIOR T_MAIOR_IGUAL
%left T_EQ_LOGICA T_DIF_LOGICA
%left T_AND
%left T_OR
%right T_COND_OP_TER T_DOIS_PON

%right T_THEN T_ELSE

%%
	/* Gramatica */
programa:
	programa declaracao 
	| declaracao {/**/}
	;

declaracao:
	decVar
	| decSub
	;

// ------------------------------- Declaracao de Variaveis
decVar:
	T_VAR listaSpecVars ":" tipo ";"
	| T_VAR listaSpecVars ":" tipo		{cout << "Erro Sintatico (l: "<<num_linhas<< ", c: "<<num_carac<<"): Talvez esteja faltando um ; \n"}
	;

tipo:
	T_BOOL							{$$ = new BoolTipoVar();}
	| T_INT							{$$ = new IntTipoVar();}
	| T_STRING						{$$ = new StringTipoVar();}
	| T_STRING "[" T_NUM "]"		{$$ = new StringTipoVar($3);}
	;

listaSpecVars:
	| listaSpecVars "," specVar
	| specVar
	;

specVar:
	T_ID 										 
	| T_ID "=" expressao 						 
	| T_ID "[" expressao "]" 					 
	| T_ID "[" expressao "]" "=" "{" decArran "}"
	;

decArran:
	decArran "," expressao
	| expressao
	;

valor:
	T_TRUE			{$$ = $1}
	| T_FALSE		{$$ = $1}
	| T_LIT_STRING	{$$ = $1}
	| T_NUM			{$$ = $1}
	;

// -------------------------------- Declaracao de Subprocessos
decSub:
	decProc
	| decFun
	;

decProc:
	T_DEF T_ID "(" listaParametros ")" bloco
	| T_DEF T_ID "(" ")" bloco
	;

decFun:
	T_DEF T_ID "(" listaParametros ")" ":" tipo bloco 
	| T_DEF T_ID "(" ")" ":" tipo bloco
	; 

listaParametros:
	listaParametros ";" specParams
	| specParams
	;

specParams:
	specParamsN ":" tipo
	;

specParamsN:
	specParamsN "," param 
	| param 
	;

param:
	T_ID
	| T_ID "[" "]"
	;

// ------------------------ Comandos
comando:
	cmdSimples
	| bloco
	;

cmdSimples:
	cmdAtrib			{$$ = $1}
	| cmdIf				{$$ = $1}
	| cmdWhile			{$$ = $1}
	| cmdFor			{$$ = $1}
	| cmdStop			{$$ = $1}
	| cmdSkip			{$$ = $1}
	| cmdReturn			{$$ = $1}
	| cmdChamadaProc	{$$ = $1}
	| cmdRead			{$$ = $1}
	| cmdWrite			{$$ = $1}
	;

// ------------------------------- Atribuicoes
cmdAtrib:
	variavel tiposAtrib expressao ";"
	| variavel tiposAtrib expressao 	{cout << "Erro Sintatico (l: "<<num_linhas<< ", c: "<<num_carac<<"): Talvez esteja faltando um ; \n"}
	;

tiposAtrib:
	atribAgreg	{$$ = $1;}
	| "="		{$$ = $1;}
	;

atribAgreg:
	"/="	{$$ = $1;}
	| "%="	{$$ = $1;}
	| "*="	{$$ = $1;}
	| "+="	{$$ = $1;}
	| "-="	{$$ = $1;}
	;

// ------------------------------ Estruturas Basicas
cmdIf:
	T_IF "(" expressao ")" comando %prec T_THEN		{$$ = new IfCmd($3, $5);}
	| T_IF "(" expressao ")" comando T_ELSE comando {$$ = new IfCmd($3, $5, $7);}
	;

cmdWhile:
	T_WHILE "(" expressao ")" comando {$$ = new WhileCmd($3, $5);}
	;

cmdFor:
	T_FOR "(" atrib-ini ";" expressao ";" atrib-passo ")" comando
	;

atrib-ini:
	T_ID "=" T_NUM
	;

atrib-passo:
	T_ID atribAgreg T_NUM
	;

cmdStop:
	T_STOP ";"
	| T_STOP 	{cout << "Erro Sintatico (l: "<<num_linhas<< ", c: "<<num_carac<<"): Talvez esteja faltando um ; \n"}
	;

cmdSkip:
	T_SKIP ";"
	| T_SKIP 	{cout << "Erro Sintatico (l: "<<num_linhas<< ", c: "<<num_carac<<"): Talvez esteja faltando um ; \n"}
	;

cmdReturn:
	T_RETURN ";"
	| T_RETURN expressao ";"
	| T_RETURN 					{cout << "Erro Sintatico (l: "<<num_linhas<< ", c: "<<num_carac<<"): Talvez esteja faltando um ; \n"}
	| T_RETURN expressao 		{cout << "Erro Sintatico (l: "<<num_linhas<< ", c: "<<num_carac<<"): Talvez esteja faltando um ; \n"}
	;

// ------------------------- Chamada Procedimento
cmdChamadaProc:
	T_ID "(" ")" ";"
	| T_ID "(" cnjExpr ")" ";"
	| T_ID "(" ")" 				{cout << "Erro Sintatico (l: "<<num_linhas<< ", c: "<<num_carac<<"): Talvez esteja faltando um ; \n"}
	| T_ID "(" cnjExpr ")"	 	{cout << "Erro Sintatico (l: "<<num_linhas<< ", c: "<<num_carac<<"): Talvez esteja faltando um ; \n"}
	;

cnjExpr:
	cnjExpr "," expressao
	| expressao
	;

cmdRead:
	T_READ variavel ";"
	| T_READ variavel 		{cout << "Erro Sintatico (l: "<<num_linhas<< ", c: "<<num_carac<<"): Talvez esteja faltando um ; \n"}
	;

cmdWrite:
	T_WRITE cnjExpr ";"
	| T_WRITE cnjExpr		{cout << "Erro Sintatico (l: "<<num_linhas<< ", c: "<<num_carac<<"): Talvez esteja faltando um ; \n"}
	;

// ----------------------------------- Blocos
bloco:
	  "{" declaracoes "}"
	| "{" comandos "}"
	| "{" declaracoes comandos "}"
	| "{" declaracoes 						{cout << "Erro Sintatico (l: "<<num_linhas<< ", c: "<<num_carac<<"): Talvez esteja faltando um } \n"}
	| "{" comandos							{cout << "Erro Sintatico (l: "<<num_linhas<< ", c: "<<num_carac<<"): Talvez esteja faltando um } \n"}
	| "{"declaracoes comandos				{cout << "Erro Sintatico (l: "<<num_linhas<< ", c: "<<num_carac<<"): Talvez esteja faltando um } \n"}
	;

declaracoes: 
	  declaracoes declaracao
	| declaracao
	;

comandos: 
	  comandos comando
	| comando
	;

// ----------------------------------- Expressoes

expressao:
	valor
	| variavel
	| "(" expressao ")"
	| "-" expressao %prec T_NEG_UNAR  			{$$ = new NegUnExp($2);}
	| "!" expressao					 			{$$ = new NegExp($2);}
	| expressao "*" expressao		 			{$$ = new AritmExp($1, $3, $2);}
	| expressao "/" expressao		 			{$$ = new AritmExp($1, $3, $2);}
	| expressao "%" expressao		 			{$$ = new AritmExp($1, $3, $2);}
	| expressao "+" expressao		 			{$$ = new AritmExp($1, $3, $2);}
	| expressao "-" expressao		 			{$$ = new AritmExp($1, $3, $2);}
	| expressao "<" expressao		 			{$$ = new RelExp($1, $3, $2);}
	| expressao "<=" expressao  	 			{$$ = new RelExp($1, $3, $2);}
	| expressao ">" expressao		 			{$$ = new RelExp($1, $3, $2);}
	| expressao ">=" expressao		 			{$$ = new RelExp($1, $3, $2);}
	| expressao "==" expressao		 			{$$ = new IgExp($1, $3, $2);}
	| expressao "!=" expressao		 			{$$ = new IgExp($1, $3, $2);}
	| expressao "&&" expressao		 			{$$ = new LogExp($1, $3, $2);}
	| expressao "||" expressao		 			{$$ = new LogExp($1, $3, $2);}
	| expressao "?" expressao ":" expressao		{$$ = new TerExp($1, $3, $5);}
	| T_ID "(" ")" 
	| T_ID "(" cnjExpr ")"
	;

variavel:
	T_ID
	| T_ID "[" expressao "]"
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
	cout<< "Erro Sintatico (l: "<<num_linhas<< ", c: "<<num_carac<<"): "<< s <<"\n";

	exit(-1);
}
