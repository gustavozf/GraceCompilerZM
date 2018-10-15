%{
/* Declaracoes */
#include <iostream>
#include <cstdio>
#include <string>
#include <map>

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
%token T_BOOL T_INT T_STRING
%token T_IF T_ELSE T_FOR T_WHILE
%token T_WRITE T_READ
%token T_DEF T_RETURN T_VAR T_SKIP T_STOP
%token T_TRUE T_FALSE
%token T_ABRE_PARENTESES T_FECHA_PARENTESES T_ABRE_COLCHETES T_FECHA_COLCHETES T_ABRE_CHAVES T_FECHA_CHAVES
%token T_VIRGULA T_PONTO_VIRGULA
%token T_ADICAO T_SUBTRACAO T_MULTIPLICACAO T_DIVISAO T_MODULO
%token T_EQ_LOGICA T_DIF_LOGICA T_MAIOR T_MAIOR_IGUAL T_MENOR T_MENOR_IGUAL 
%token T_OR T_AND T_NOT
%token T_ATRIBUICAO T_ATRIB_SOMA T_ATRIB_SUB T_ATRIB_MULT T_ATRIB_DIV T_ATRIB_MOD T_COND_OP_TER T_DOIS_PON  

// tokens que assumem valores
// %token <TIPO> <NOME>
%token <sval> T_ID
%token <sval> T_NUM
%token <sval> T_LIT_STRING

%right T_NOT
%left T_MULTIPLICACAO T_DIVISAO T_MODULO 
%left T_ADICAO T_SUBTRACAO
%left T_MENOR T_MENOR_IGUAL
%left T_MAIOR T_MAIOR_IGUAL
%left T_EQ_LOGICA T_DIF_LOGICA
%left T_AND
%left T_OR
%right T_COND_OP_TER T_DOIS_PON

%%
	/* Gramatica */
programa:
	declaracao {/**/}
	;

declaracao:
	decVar
	| decSub
	;

decVar:
	T_VAR listaSpecVars T_DOIS_PON tipo T_PONTO_VIRGULA
	;

tipo:
	T_BOOL
	| T_INT
	| T_STRING
	| T_STRING T_ABRE_COLCHETES T_NUM T_FECHA_COLCHETES
	;

listaSpecVars:
	specVar
	| specVar T_VIRGULA listaSpecVars
	;

specVar:
	T_ID // specVarSimples
	| T_ID T_ATRIBUICAO valor // specVarSimplesIni
	| T_ID T_ABRE_COLCHETES T_NUM T_FECHA_COLCHETES // specVarArranjo
	| T_ID T_ABRE_COLCHETES T_NUM T_FECHA_COLCHETES T_ATRIBUICAO T_ABRE_CHAVES decArran T_FECHA_CHAVES // specVarArranjoIni
	;

decArran:
	valor
	| valor T_VIRGULA decArran
	;

valor:
	T_TRUE
	| T_FALSE
	| T_LIT_STRING
	| T_NUM
	;

decSub:
	T_DEF T_ID T_ABRE_PARENTESES listaParametros T_FECHA_PARENTESES bloco // decProc
	| T_DEF T_ID T_ABRE_PARENTESES listaParametros T_FECHA_PARENTESES T_DOIS_PON tipo bloco // decFun
	;

listaParametros:
	specParms
	| specParms T_PONTO_VIRGULA listaParametros
	;

specParms:
	param T_DOIS_PON tipo
	| param T_VIRGULA specParms
	;

param:
	T_ID
	| T_ID T_ABRE_COLCHETES T_FECHA_COLCHETES
	;

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

cmdAtrib:
	T_ID tiposAtrib expressao T_PONTO_VIRGULA
	;

tiposAtrib:
	atribAgreg
	| T_ATRIBUICAO
	;

atribAgreg:
	T_ATRIB_DIV
	| T_ATRIB_MOD
	| T_ATRIB_MULT
	| T_ATRIB_SOMA
	| T_ATRIB_SUB
	;

cmdIf:
	T_IF T_ABRE_PARENTESES expressao T_FECHA_PARENTESES comando
	| T_IF T_ABRE_PARENTESES expressao T_FECHA_PARENTESES comando T_ELSE comando
	;

cmdWhile:
	T_WHILE T_ABRE_PARENTESES expressao T_FECHA_PARENTESES comando
	;

cmdFor:
	T_FOR T_ABRE_PARENTESES atrib-ini T_PONTO_VIRGULA expressao T_PONTO_VIRGULA atrib-passo T_FECHA_PARENTESES comando
	;

atrib-ini:
	T_ID T_ATRIBUICAO T_NUM
	;

atrib-passo:
	T_ID atribAgreg T_NUM
	;

cmdStop:
	T_STOP T_PONTO_VIRGULA
	;

cmdSkip:
	T_SKIP T_PONTO_VIRGULA
	;

cmdReturn:
	T_RETURN T_PONTO_VIRGULA
	| T_RETURN expressao T_PONTO_VIRGULA
	;

cmdChamadaProc:
	T_ID T_ABRE_PARENTESES atribProc T_FECHA_PARENTESES T_PONTO_VIRGULA
	;

atribProc:/*vazio*/
	| cnjExpr
	;

cnjExpr:
	expressao
	| expressao T_VIRGULA cnjExpr
	;

cmdRead:
	T_READ usoVar T_PONTO_VIRGULA
	;

cmdWrite:
	T_WRITE cnjExpr T_PONTO_VIRGULA
	;

bloco:
	T_ABRE_CHAVES declaracoes comandos T_FECHA_CHAVES
	;

declaracoes: /*vazio*/
	| declaracao
	| declaracao declaracoes
	;

comandos: /*vazio*/
	| comando
	| comando comandos
	;

opTern:
	expressao T_COND_OP_TER expressao T_DOIS_PON expressao
	;

expressao:
	expression
	| T_ABRE_PARENTESES expressao T_FECHA_PARENTESES
	| expressao operador expressao
	| opTern
	;

operador:
	T_NOT
	| T_MULTIPLICACAO
	| T_DIVISAO
	| T_MODULO 
	| T_ADICAO
	| T_SUBTRACAO
	| T_MENOR
	| T_MENOR_IGUAL
	| T_MAIOR
	| T_MAIOR_IGUAL
	| T_EQ_LOGICA
	| T_DIF_LOGICA
	| T_AND
	| T_OR
	| T_COND_OP_TER
	| T_DOIS_PON
	;

expression:
	valor
	| usoVar
	| T_ID T_ABRE_PARENTESES atribProc T_FECHA_PARENTESES
	;

usoVar:
	T_ID
	| T_ID T_ABRE_COLCHETES expressao T_FECHA_COLCHETES
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
