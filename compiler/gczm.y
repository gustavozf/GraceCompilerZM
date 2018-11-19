%error-verbose
%{
/* Declaracoes */
#include <iostream>
#include <list>
#include <string>
#include "./structs/exp.h"
#include "./structs/cmd.h"
#include "./structs/dec.h"
#include "./structs/prog.h"

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
	char *sval; // String
	
	// Nos AST
	TipoVar *tipoVar;
	Cmd *cmd;
	Exp *exp;
	Decl *decl;
	SpecVar *specVar;
	Param *param;
	SpecParam *specParam;

	// Listas
	list<Exp *> *cnjExp;
	list<Cmd *> *cnjCmd;
	list<SpecVar *> *cnjSpecVar;
	list<Param *> *cnjParam;
	list<SpecParam *> *cnjSpecParam;
	list<Decl *> *cnjDecl;
}

/* Tokens */
// constant-strings
%token <sval> T_BOOL
%token <sval> T_INT
%token <sval> T_STRING
%token <sval> T_IF
%token <sval> T_ELSE
%token <sval> T_FOR
%token <sval> T_WHILE
%token <sval> T_WRITE
%token <sval> T_READ
%token <sval> T_DEF
%token <sval> T_RETURN
%token <sval> T_VAR
%token <sval> T_SKIP
%token <sval> T_STOP
%token <sval> T_TRUE
%token <sval> T_FALSE
%token <sval> T_ABRE_PARENTESES  "("
%token <sval> T_FECHA_PARENTESES ")"
%token <sval> T_ABRE_COLCHETES   "["
%token <sval> T_FECHA_COLCHETES  "]"
%token <sval> T_ABRE_CHAVES      "{"
%token <sval> T_FECHA_CHAVES     "}"
%token <sval> T_VIRGULA          ","
%token <sval> T_PONTO_VIRGULA    ";"
%token <sval> T_ADICAO           "+"
%token <sval> T_SUBTRACAO        "-"
%token <sval> T_MULTIPLICACAO    "*"
%token <sval> T_DIVISAO          "/"
%token <sval> T_MODULO           "%"
%token <sval> T_EQ_LOGICA        "=="
%token <sval> T_DIF_LOGICA       "!="
%token <sval> T_MAIOR 		      ">"
%token <sval> T_MAIOR_IGUAL      ">="
%token <sval> T_MENOR            "<"
%token <sval> T_MENOR_IGUAL      "<="
%token <sval> T_OR               "||"
%token <sval> T_AND              "&&"
%token <sval> T_NOT              "!"
%token <sval> T_ATRIBUICAO       "="
%token <sval> T_ATRIB_SOMA       "+="
%token <sval> T_ATRIB_SUB        "-="
%token <sval> T_ATRIB_MULT       "*="
%token <sval> T_ATRIB_DIV        "/="
%token <sval> T_ATRIB_MOD        "%="
%token <sval> T_COND_OP_TER      "?"
%token <sval> T_DOIS_PON         ":"

// tokens que assumem valores
// %token <TIPO> <NOME>
%token <sval> T_ID
%token <sval> T_NUM
%token <sval> T_LIT_STRING

/* Ordem de precedencia */
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

/* Declaracao de Tipos */
%type <sval> tiposAtrib atribAgreg
%type <tipoVar> tipo
%type <cmd> cmdSimples cmdIf cmdAtrib cmdWhile cmdFor cmdStop cmdSkip
%type <cmd> cmdReturn cmdChamadaProc cmdRead cmdWrite comando bloco 
%type <exp> expressao atrib-ini atrib-passo valor variavel
%type <decl> decVar declaracao decSub decProc decFun
%type <param> param
%type <specVar> specVar
%type <specParam> specParams

%type <cnjSpecVar> listaSpecVars
%type <cnjExp> cnjExpr
%type <cnjParam> specParamsN
%type <cnjCmd> comandos
%type <cnjDecl> declaracoes programa
%type <cnjSpecParam> listaParametros

%%
	/* Gramatica */
programa: 
	declaracoes { $$ = $1; cout << "Programa Reconhecido!" << endl; }
	;

declaracoes: 
	  declaracoes declaracao	{ $$ = $1; $$->push_back($2); 					}
	| declaracao				{ $$ = new list<Decl *>(); $$->push_back($1);	}
	;

declaracao:
	decVar		{ $$ = $1; }
	| decSub	{ $$ = $1; }
	;

// ------------------------------- Declaracao de Variaveis
decVar:
	T_VAR listaSpecVars ":" tipo ";"		{ $$ = new DeclVar($2, $4); }
	//| T_VAR listaSpecVars ":" tipo		{cout << "Erro Sintatico (l: "<<num_linhas<< ", c: "<<num_carac<<"): Talvez esteja faltando um ; \n";}
	;

tipo:
	T_BOOL							{$$ = new BoolTipoVar();	 }
	| T_INT							{$$ = new IntTipoVar();		 }
	| T_STRING						{$$ = new StringTipoVar();   }
	| T_STRING "[" T_NUM "]"		{$$ = new StringTipoVar($3); }
	;

listaSpecVars:
	 listaSpecVars "," specVar  { $$ = $1; $$->push_back($3); 					 }
	| specVar					{ $$ = new list<SpecVar *>(); $$->push_back($1); }
	;

specVar:
	T_ID 											{ $$ = new SpecVarSimples($1); 		   }					 
	| T_ID "=" expressao 						 	{ $$ = new SpecVarSimples($1, $3); 	   }
	| T_ID "[" expressao "]" 					 	{ $$ = new SpecVarArranjo($1, $3);	   }
	| T_ID "[" expressao "]" "=" "{" cnjExpr "}"	{ $$ = new SpecVarArranjo($1, $3, $7); } 
	;

cnjExpr:
	cnjExpr "," expressao { $$ = $1; $$->push_back($3); 			   }
	| expressao 		  { $$ = new list<Exp *>(); $$->push_back($1); }
	;

valor:
	T_TRUE			{ $$ = new ValExp($1, "bool");   }
	| T_FALSE		{ $$ = new ValExp($1, "bool");   }
	| T_LIT_STRING	{ $$ = new ValExp($1, "string"); }
	| T_NUM			{ $$ = new ValExp($1, "int");	 }
	;

// -------------------------------- Declaracao de Subprocessos
decSub:
	decProc		{ $$ = $1; }
	| decFun	{ $$ = $1; }
	;

decProc:
	T_DEF T_ID "(" listaParametros ")" bloco { $$ = new DeclSub($2, $4, $6); }
	| T_DEF T_ID "(" ")" bloco				 { $$ = new DeclSub($2, $5); }
	;

decFun:
	T_DEF T_ID "(" listaParametros ")" ":" tipo bloco	{ $$ = new DeclSub($2, $4, $7, $8); }
	| T_DEF T_ID "(" ")" ":" tipo bloco					{ $$ = new DeclSub($2, $6, $7); }
	; 

listaParametros:
	listaParametros ";" specParams  { $$ = $1; $$->push_back($3);					   }
	| specParams					{ $$ = new list<SpecParam *>(); $$->push_back($1); }
	;

specParams:
	specParamsN ":" tipo { $$ = new SpecParam($1, $3); } 
	;

specParamsN:
	specParamsN "," param 	{ $$ = $1; $$->push_back($3);				   }
	| param 				{ $$ = new list<Param *>(); $$->push_back($1); }
	;

param:
	T_ID			{ $$ = new Param($1, false); }
	| T_ID "[" "]"	{ $$ = new Param($1, true); }
	;

// ------------------------ Comandos
comando:
	cmdSimples { $$ = $1; }
	| bloco	   { $$ = $1; }
	;

cmdSimples:
	cmdAtrib			{$$ = $1;}
	| cmdIf				{$$ = $1;}
	| cmdWhile			{$$ = $1;}
	| cmdFor			{$$ = $1;}
	| cmdStop			{$$ = $1;}
	| cmdSkip			{$$ = $1;}
	| cmdReturn			{$$ = $1;}
	| cmdChamadaProc	{$$ = $1;}
	| cmdRead			{$$ = $1;}
	| cmdWrite			{$$ = $1;}
	;

// ------------------------------- Atribuicoes
cmdAtrib:
	variavel tiposAtrib expressao ";" 	{ $$ = new AtribCmd($1, $2, $3);}
	//| variavel tiposAtrib expressao 	{cout << "Erro Sintatico (l: "<<num_linhas<< ", c: "<<num_carac<<"): Talvez esteja faltando um ; \n";}
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
	T_IF "(" expressao ")" comando %prec T_THEN		{$$ = new IfCmd($3, $5);     }
	| T_IF "(" expressao ")" comando T_ELSE comando {$$ = new IfCmd($3, $5, $7); }
	;

cmdWhile:
	T_WHILE "(" expressao ")" comando {$$ = new WhileCmd($3, $5);}
	;

cmdFor:
	T_FOR "(" atrib-ini ";" expressao ";" atrib-passo ")" comando {$$ = new ForCmd($3, $5, $7, $9);}
	;

atrib-ini:
	T_ID "=" T_NUM 		 	{$$ = new AtribFor($1, $3);}
	;

atrib-passo:
	T_ID atribAgreg T_NUM 	{$$ = new AtribFor($1, $2, $3);}
	;

cmdStop:
	T_STOP ";"  {$$ = new StopSkipCmd($1);}
	//| T_STOP 	{cout << "Erro Sintatico (l: "<<num_linhas<< ", c: "<<num_carac<<"): Talvez esteja faltando um ; \n";}
	;

cmdSkip:
	T_SKIP ";"  {$$ = new StopSkipCmd($1);}
	//| T_SKIP 	{cout << "Erro Sintatico (l: "<<num_linhas<< ", c: "<<num_carac<<"): Talvez esteja faltando um ; \n";}
	;

cmdReturn:
	T_RETURN ";"				{$$ = new RetCmd();}
	| T_RETURN expressao ";"	{$$ = new RetCmd($2);}
	//| T_RETURN 				{cout << "Erro Sintatico (l: "<<num_linhas<< ", c: "<<num_carac<<"): Talvez esteja faltando um ; \n";}
	//| T_RETURN expressao 		{cout << "Erro Sintatico (l: "<<num_linhas<< ", c: "<<num_carac<<"): Talvez esteja faltando um ; \n";}
	;

// ------------------------- Chamada Procedimento
cmdChamadaProc:
	T_ID "(" ")" ";"				{ $$ = new ProcCmd($1); 	}
	| T_ID "(" cnjExpr ")" ";"		{ $$ = new ProcCmd($1, $3); }
	//| T_ID "(" ")" 				{cout << "Erro Sintatico (l: "<<num_linhas<< ", c: "<<num_carac<<"): Talvez esteja faltando um ; \n";}
	//| T_ID "(" cnjExpr ")"	 	{cout << "Erro Sintatico (l: "<<num_linhas<< ", c: "<<num_carac<<"): Talvez esteja faltando um ; \n";}
	;

cmdRead:
	T_READ variavel ";"		{ $$ = new ReadCmd($2); }
	//| T_READ variavel 	{cout << "Erro Sintatico (l: "<<num_linhas<< ", c: "<<num_carac<<"): Talvez esteja faltando um ; \n";}
	;

cmdWrite:
	T_WRITE cnjExpr ";"		{ $$ = new WriteCmd($2); }
	//| T_WRITE cnjExpr		{cout << "Erro Sintatico (l: "<<num_linhas<< ", c: "<<num_carac<<"): Talvez esteja faltando um ; \n";}
	;

// ----------------------------------- Blocos
bloco:
	  "{" declaracoes "}"						{ $$ = new BlocoCmd($2); }
	| "{" comandos "}"							{ $$ = new BlocoCmd($2); }
	| "{" declaracoes comandos "}"				{ $$ = new BlocoCmd($2, $3); }
	//| "{" declaracoes 						{cout << "Erro Sintatico (l: "<<num_linhas<< ", c: "<<num_carac<<"): Talvez esteja faltando um } \n";}
	//| "{" comandos							{cout << "Erro Sintatico (l: "<<num_linhas<< ", c: "<<num_carac<<"): Talvez esteja faltando um } \n";}
	//| "{"declaracoes comandos					{cout << "Erro Sintatico (l: "<<num_linhas<< ", c: "<<num_carac<<"): Talvez esteja faltando um } \n";}
	;

comandos: 
	  comandos comando	{ $$ = $1; $$->push_back($2); 				 }
	| comando			{ $$ = new list<Cmd *>(); $$->push_back($1); }
	;

// ----------------------------------- Expressoes

expressao:
	valor										{	$$ = $1;						}
	| variavel									{	$$ = $1;						}
	| "(" expressao ")"							{	$$ = $2;						}
	| "-" expressao %prec T_NEG_UNAR  			{	$$ = new NegUnExp($2);		  	}
	| "!" expressao					 			{	$$ = new NegExp($2);			}
	| expressao "*" expressao		 			{	$$ = new AritmExp($1, $3, $2); 	}
	| expressao "/" expressao		 			{	$$ = new AritmExp($1, $3, $2); 	}
	| expressao "%" expressao		 			{	$$ = new AritmExp($1, $3, $2); 	}
	| expressao "+" expressao		 			{	$$ = new AritmExp($1, $3, $2); 	}
	| expressao "-" expressao		 			{	$$ = new AritmExp($1, $3, $2); 	}
	| expressao "<" expressao		 			{	$$ = new RelExp($1, $3, $2);	}
	| expressao "<=" expressao  	 			{	$$ = new RelExp($1, $3, $2);	}
	| expressao ">" expressao		 			{	$$ = new RelExp($1, $3, $2);	}
	| expressao ">=" expressao		 			{	$$ = new RelExp($1, $3, $2);	}
	| expressao "==" expressao		 			{	$$ = new IgExp($1, $3, $2);		}
	| expressao "!=" expressao		 			{	$$ = new IgExp($1, $3, $2);		}
	| expressao "&&" expressao		 			{	$$ = new LogExp($1, $3, $2);	}
	| expressao "||" expressao		 			{	$$ = new LogExp($1, $3, $2);	}
	| expressao "?" expressao ":" expressao		{	$$ = new TerExp($1, $3, $5);	}
	| T_ID "(" ")" 								{	$$ = new FuncExp($1); 			}
	| T_ID "(" cnjExpr ")"						{	$$ = new FuncExp($1, $3); 		}
	;

variavel:
	T_ID						{ $$ = new VarExp($1);     }
	| T_ID "[" expressao "]"	{ $$ = new VarExp($1, $3); }
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
