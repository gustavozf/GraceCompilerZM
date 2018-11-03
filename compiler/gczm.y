%{
/* Declaracoes */
#include <iostream>
#include <cstdio>
#include <string>

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
	programa declaracao {/**/}
	| declaracao
	;

declaracao:
	decVar
	| decSub
	;

// ------------------------------- Declaracao de Variaveis
decVar:
	T_VAR listaSpecVars ":" tipo ";"
	;

tipo:
	T_BOOL
	| T_INT
	| T_STRING
	| T_STRING "[" expressao "]"
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
	T_TRUE
	| T_FALSE
	| T_LIT_STRING
	| T_NUM
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
	cmdAtrib
	| cmdIf
	| cmdWhile
	| cmdFor
	| cmdStop
	| cmdSkip
	| cmdReturn
	| cmdChamadaProc
	| cmdRead
	| cmdWrite
	;

// ------------------------------- Atribuicoes
cmdAtrib:
	variavel tiposAtrib expressao ";"
	;

tiposAtrib:
	atribAgreg
	| "="
	;

atribAgreg:
	"/="
	| "%="
	| "*="
	| "+="
	| "-="
	;

// ------------------------------ Estruturas Basicas
cmdIf:
	T_IF "(" expressao ")" comando %prec T_THEN
	| T_IF "(" expressao ")" comando T_ELSE comando
	;

cmdWhile:
	T_WHILE "(" expressao ")" comando
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
	;

cmdSkip:
	T_SKIP ";"
	;

cmdReturn:
	T_RETURN ";"
	| T_RETURN expressao ";"
	;

// ------------------------- Chamada Procedimento
cmdChamadaProc:
	T_ID "(" ")" ";"
	| T_ID "(" cnjExpr ")" ";"
	;

cnjExpr:
	cnjExpr "," expressao
	| expressao
	;

cmdRead:
	T_READ variavel ";"
	;

cmdWrite:
	T_WRITE cnjExpr ";"
	;

// ----------------------------------- Blocos
bloco:
	  "{" declaracoes "}"
	| "{" comandos "}"
	| "{" declaracoes comandos "}"
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
opTern:
	expressao "?" expressao ":" expressao
	;

expressao:
	tipoExpressao
	| "(" expressao ")"
	| "-" expressao %prec T_NEG_UNAR
	| "!" expressao
	| expressao "*" expressao  
	| expressao "/" expressao
	| expressao "%" expressao
	| expressao "+" expressao
	| expressao "-" expressao
	| expressao "<" expressao
	| expressao "<=" expressao
	| expressao ">" expressao
	| expressao ">=" expressao
	| expressao "==" expressao
	| expressao "!=" expressao
	| expressao "&&" expressao
	| expressao "||" expressao
	| opTern
	;

tipoExpressao:
	valor
	| variavel
	| T_ID "(" ")" // FUNCAO
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
