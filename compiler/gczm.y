%error-verbose
%debug
%{
#define YYDEBUG 1
/* Declaracoes */
#include <iostream>
#include <list>
#include <string>
#include <string.h>
#include <stack>
#include <fstream>
#include "./structs/exp.h"
#include "./structs/cmd.h"
#include "./structs/dec.h"
#include "./structs/prog.h"

using namespace std;

// Coisas do Flex que o Bison precisa
extern int yylex();
extern int yyparse();
extern int yydebug;
extern FILE *yyin;

extern int num_linhas;
extern int num_carac;

// Tratar Erros (aparentemente obrigatorio)
void yyerror(const char *s);

Programa *raiz = nullptr;
Escopo *escopoAtual = new Escopo(nullptr, 0);
int countEscopos = 1;
stack<DeclSub *> *pilhaSubprog = new stack<DeclSub *>();
stack<Cmd *> *pilhaCmdRepet = new stack<Cmd *>();

string nomeSaida;//"./compiledOutputs/graceOut.cpp";
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
	VarExp* varExp;
	Decl *decl;
	SpecVar *specVar;
	Param *param;
	SpecParam *specParam;
	Programa *programa;
	Escopo *escopo;

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
%right T_COND_OP_TER T_DOIS_PON // 10
%left T_OR // 9
%left T_AND // 8
%left T_EQ_LOGICA T_DIF_LOGICA // 7
%left T_MAIOR T_MAIOR_IGUAL // 6
%left T_MENOR T_MENOR_IGUAL // 5
%left T_ADICAO T_SUBTRACAO // 4
%left T_MULTIPLICACAO T_DIVISAO T_MODULO // 3
%right T_NOT // 2
%right T_NEG_UNAR  // 1

%right T_THEN T_ELSE

/* Declaracao de Tipos */
%type <sval> tiposAtrib atribAgreg
%type <tipoVar> tipo
%type <cmd> cmdSimples cmdIf cmdAtrib cmdWhile cmdFor cmdStop cmdSkip
%type <cmd> cmdReturn cmdChamadaProc cmdRead cmdWrite comando bloco cmdAtribFor
%type <exp> expressao valor variavel
%type <decl> decVar declaracao decSub decProc decFun
%type <param> param
%type <specVar> specVar
%type <specParam> specParams
%type <programa>  programa

%type <cnjSpecVar> listaSpecVars
%type <cnjExp> cnjExpr
%type <cnjParam> specParamsN
%type <cnjCmd> comandos
%type <cnjDecl> declaracoes
%type <cnjSpecParam> listaParametros

%type <escopo> blocoBegin

%%
	/* Gramatica */
programa: 
	declaracoes { $$ = new Programa($1, escopoAtual, num_linhas); 
				  raiz = $$; 
				  cout << "\nPrograma reconhecido!\nRealizando Análise Semântica...\n";
				  int semanticaCorreta = raiz->eval();
				  cout << "Análise Semântica Realizada!\n";

				  if (semanticaCorreta){
					cout << "Gerando código...\n";
					ofstream saida(string("./compiledOutputs/") + nomeSaida + string(".cpp"));
					raiz->codeGen(saida);
					saida.close();

					system((string("clang -S -emit-llvm ./compiledOutputs/") + nomeSaida + 
							string(".cpp --output ./compiledOutputs/") + nomeSaida + 
							string(".ll")).c_str());
					system((string("llc -filetype=obj ./compiledOutputs/") + nomeSaida + string(".ll")).c_str());
					//system("gcc ./compiledOutputs/graceOut.o -fPIC -o ./compiledOutputs/graceOut");
					system((string("g++ ./compiledOutputs/") + nomeSaida + string(".cpp -o ./compiledOutputs/") + nomeSaida).c_str());
				  }
				  
				}
	;

declaracoes: 
	  declaracoes declaracao	{ $$ = $1; $$->push_back($2); 					}
	| declaracao				{ $$ = new list<Decl *>(); $$->push_back($1);	}
	;

declaracao:
	decVar		{ $$ = $1; 
				  $$->addTabSimb(escopoAtual);
				}
	| decSub	{ $$ = $1; 
				  $$->addTabSimb(escopoAtual);
				}
	;

// ------------------------------- Declaracao de Variaveis
decVar:
	T_VAR listaSpecVars ":" tipo ";"		{ $$ = new DeclVar($2, $4); }
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
	T_ID 											{ $$ = new SpecVarSimples($1, num_linhas); 		   }					 
	| T_ID "=" expressao 						 	{ $$ = new SpecVarSimples($1, $3, num_linhas); 	   }
	| T_ID "[" expressao "]" 					 	{ $$ = new SpecVarArranjo($1, $3, num_linhas);	   }
	| T_ID "[" expressao "]" "=" "{" cnjExpr "}"	{ $$ = new SpecVarArranjo($1, $3, $7, num_linhas); } 
	;

cnjExpr:
	cnjExpr "," expressao { $$ = $1; $$->push_back($3); 			   }
	| expressao 		  { $$ = new list<Exp *>(); $$->push_back($1); }
	;

valor:
	T_TRUE			{ $$ = new ValExp($1, "bool", num_linhas);   }
	| T_FALSE		{ $$ = new ValExp($1, "bool", num_linhas);   }
	| T_LIT_STRING	{ $$ = new ValExp($1, "string", num_linhas); }
	| T_NUM			{ $$ = new ValExp($1, "int", num_linhas);	 }
	;

// -------------------------------- Declaracao de Subprocessos
decSub:
	decProc		{ $$ = $1; }
	| decFun	{ $$ = $1; }
	;

decProc:
	T_DEF T_ID "(" listaParametros ")" bloco { $$ = new DeclSub($2, $4, $6, pilhaSubprog); }
	| T_DEF T_ID "(" ")" bloco				 { $$ = new DeclSub($2, $5, pilhaSubprog); }
	;

decFun:
	T_DEF T_ID "(" listaParametros ")" ":" tipo bloco	{ $$ = new DeclSub($2, $4, $7, $8, pilhaSubprog); }
	| T_DEF T_ID "(" ")" ":" tipo bloco					{ $$ = new DeclSub($2, $6, $7, pilhaSubprog); }
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
	variavel tiposAtrib expressao ";" 	{ $$ = new AtribCmd($1, $2, $3, num_linhas);}
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
	T_IF "(" expressao ")" comando %prec T_THEN		{$$ = new IfCmd($3, $5, num_linhas);     }
	| T_IF "(" expressao ")" comando T_ELSE comando {$$ = new IfCmd($3, $5, $7, num_linhas); }
	;

cmdWhile:
	T_WHILE "(" expressao ")" comando {$$ = new WhileCmd($3, $5, pilhaCmdRepet, num_linhas);}
	;

cmdFor:
	T_FOR "(" cmdAtribFor ";" expressao ";" cmdAtribFor ")" comando {$$ = new ForCmd($3, $5, $7, $9, pilhaCmdRepet, num_linhas);}
	;

cmdAtribFor:
	variavel tiposAtrib expressao	{ $$ = new AtribCmd($1, $2, $3, num_linhas); }
	;

cmdStop:
	T_STOP ";"  {$$ = new StopSkipCmd($1, pilhaCmdRepet, num_linhas);}
	;

cmdSkip:
	T_SKIP ";"  {$$ = new StopSkipCmd($1, pilhaCmdRepet, num_linhas);}
	;

cmdReturn:
	T_RETURN ";"					{$$ = new RetCmd(pilhaSubprog, num_linhas);}
	| T_RETURN expressao ";"		{$$ = new RetCmd($2, pilhaSubprog, num_linhas);}
	;

// ------------------------- Chamada Procedimento
cmdChamadaProc:
	T_ID "(" ")" ";"				{ $$ = new ProcCmd($1, escopoAtual, num_linhas);     }
	| T_ID "(" cnjExpr ")" ";"		{ $$ = new ProcCmd($1, $3, escopoAtual, num_linhas); }
	;

cmdRead:
	T_READ variavel ";"		{ $$ = new ReadCmd($2, num_linhas); }
	;

cmdWrite:
	T_WRITE cnjExpr ";"		{ $$ = new WriteCmd($2); }
	;

// ----------------------------------- Blocos
bloco:
	  blocoBegin declaracoes blocoEnd				{	$$ = new BlocoCmd($2, $1);		}
	| blocoBegin comandos blocoEnd					{	$$ = new BlocoCmd($2, $1);		}
	| blocoBegin declaracoes comandos blocoEnd		{	$$ = new BlocoCmd($2, $3, $1);	}
	;

blocoBegin:
	"{" { 
			escopoAtual = new Escopo(escopoAtual, countEscopos);
			countEscopos++;
			$$ = escopoAtual;
		}
	;

blocoEnd:
	"}" {escopoAtual = escopoAtual->getPai(); }
	;	

comandos: 
	  comandos comando	{ $$ = $1; $$->push_back($2); 				 }
	| comando			{ $$ = new list<Cmd *>(); $$->push_back($1); }
	;

// ----------------------------------- Expressoes

expressao:
	 variavel									{	$$ = $1;											}
	| valor										{	$$ = $1;											}
	|  "(" expressao ")"						{	$$ = $2;											}
	| "-" expressao %prec T_NEG_UNAR  			{	$$ = new NegUnExp($2, num_linhas);		  			}
	| "!" expressao					 			{	$$ = new NegExp($2, num_linhas);					}
	| expressao "*" expressao		 			{	$$ = new AritmExp($1, $3, $2, num_linhas);			}
	| expressao "/" expressao		 			{	$$ = new AritmExp($1, $3, $2, num_linhas);		 	}
	| expressao "%" expressao		 			{	$$ = new AritmExp($1, $3, $2, num_linhas);		 	}
	| expressao "+" expressao		 			{	$$ = new AritmExp($1, $3, $2, num_linhas);		 	}
	| expressao "-" expressao		 			{	$$ = new AritmExp($1, $3, $2, num_linhas);		 	}
	| expressao "<" expressao		 			{	$$ = new RelExp($1, $3, $2, num_linhas);			}
	| expressao "<=" expressao  	 			{	$$ = new RelExp($1, $3, $2, num_linhas);			}
	| expressao ">" expressao		 			{	$$ = new RelExp($1, $3, $2, num_linhas);			}
	| expressao ">=" expressao		 			{	$$ = new RelExp($1, $3, $2, num_linhas);			}
	| expressao "==" expressao		 			{	$$ = new IgExp($1, $3, $2, num_linhas);				}
	| expressao "!=" expressao		 			{	$$ = new IgExp($1, $3, $2, num_linhas);				}
	| expressao "&&" expressao		 			{	$$ = new LogExp($1, $3, $2, num_linhas);			}
	| expressao "||" expressao		 			{	$$ = new LogExp($1, $3, $2, num_linhas);			}
	| expressao "?" expressao ":" expressao		{	$$ = new TerExp($1, $3, $5, num_linhas);			}
	| T_ID "(" ")" 								{	$$ = new FuncExp($1, escopoAtual, num_linhas); 		}
	| T_ID "(" cnjExpr ")"						{	$$ = new FuncExp($1, $3, escopoAtual, num_linhas);  }
	;

variavel:
	T_ID						{ $$ = new VarExp($1, escopoAtual, num_linhas);     }
	| T_ID "[" expressao "]"	{ $$ = new VarExp($1, $3, escopoAtual, num_linhas); }
	;

%%

/* Codificacao C++ */
int main(int argc, char *argv[]){
	yydebug = 0;
	char *pch, *aux;

	if(argc < 2){
		cout << "ERRO: Eh necessario passar o nome do arquivo de entrada!\n";

		return 0;
	}

	FILE *entrada = fopen(argv[1], "r");

	pch = strtok (argv[1], "/ ");
	while (pch != NULL){
		aux = pch;
	    pch = strtok(NULL, "/");
	}

	printf("Compilando Arquivo: %s\n",aux);
	aux = strtok(aux, ".grc");
	nomeSaida.assign(aux);

	if (!entrada) {
		cout << "Erro ao abrir o arquivo: '" << argv[1] << "'!\n";
		return -1;
	}

	yyin = entrada;

    yyparse();

	fclose(entrada);

	return 0;
}

void yyerror(const char *s){
	cout<< "Erro Sintático (l: "<<num_linhas<< ", c: "<<num_carac<<"): "<< s <<"\n";

	exit(-1);
}
