%{
/* Declaracoes */
#include <iostream>
#include <list>
#include <string>
#include <stack>
#include "./structs/exp.h"
#include "./structs/cmd.h"
#include "./structs/dec.h"
#include "./structs/prog.h"

/* Arquivo gerado do Bison
   Usado para ler os tokens e etc.
 */
#include "gczm.tab.h"

using namespace std;

// Coisas do Flex que o Bison precisa
extern int yylex();
int num_linhas = 1;
int num_carac = 1;

%}

/* opcoes 
%option debug
%option noyywrap
*/

/* Expresssoes Regulares */
%%
	/* Elimina os Espacos em Branco*/
[ \t] {} 

	/* Palavras Reservadas */
"bool"   { num_carac += 4; return T_BOOL;   								} 
"def"    { num_carac += 3; return T_DEF;    								} 
"else"   { num_carac += 4; return T_ELSE;   								} 
"false"  { num_carac += 5; yylval.sval = strdup(yytext); return T_FALSE;  	} 
"for"    { num_carac += 3; return T_FOR;    								} 
"if"     { num_carac += 2; return T_IF;     								} 
"int"    { num_carac += 3; return T_INT;    								} 
"read"   { num_carac += 4; return T_READ;   								} 
"return" { num_carac += 6; return T_RETURN; 								} 
"skip"   { num_carac += 4; return T_SKIP;   								} 
"stop"   { num_carac += 4; return T_STOP;   								} 
"string" { num_carac += 6; return T_STRING; 								} 
"true"   { num_carac += 4; yylval.sval = strdup(yytext); return T_TRUE;   	} 
"var"    { num_carac += 3; return T_VAR;    								} 
"while"  { num_carac += 5; return T_WHILE;  								}
"write"  { num_carac += 5; return T_WRITE; 								 	} 

	/* Simbolo */
\(    { num_carac += 1; return T_ABRE_PARENTESES;  								 }
\)    { num_carac += 1; return T_FECHA_PARENTESES; 								 }
\[    { num_carac += 1; return T_ABRE_COLCHETES;   								 }
\]    { num_carac += 1; return T_FECHA_COLCHETES;  								 } 
"{"   { num_carac += 1; return T_ABRE_CHAVES;      								 }
"}"   { num_carac += 1; return T_FECHA_CHAVES;     								 }
","   { num_carac += 1; return T_VIRGULA;          								 }
";"   { num_carac += 1; return T_PONTO_VIRGULA;    								 }
"+"   { num_carac += 1; yylval.sval = strdup(yytext); return T_ADICAO;           }
"-"   { num_carac += 1; yylval.sval = strdup(yytext); return T_SUBTRACAO;        }
"*"   { num_carac += 1; yylval.sval = strdup(yytext); return T_MULTIPLICACAO;    }
"/"   { num_carac += 1; yylval.sval = strdup(yytext); return T_DIVISAO;          }
"%"   { num_carac += 1; yylval.sval = strdup(yytext); return T_MODULO;           }
"=="  { num_carac += 2; yylval.sval = strdup(yytext); return T_EQ_LOGICA;        }
"!="  { num_carac += 2; yylval.sval = strdup(yytext); return T_DIF_LOGICA;       }
">"   { num_carac += 1; yylval.sval = strdup(yytext); return T_MAIOR;            }
">="  { num_carac += 2; yylval.sval = strdup(yytext); return T_MAIOR_IGUAL;      }
"<"   { num_carac += 1; yylval.sval = strdup(yytext); return T_MENOR;            }
"<="  { num_carac += 2; yylval.sval = strdup(yytext); return T_MENOR_IGUAL;      }
"||"  { num_carac += 2; yylval.sval = strdup(yytext); return T_OR;               }
"&&"  { num_carac += 2; yylval.sval = strdup(yytext); return T_AND;              }
"!"   { num_carac += 1; yylval.sval = strdup(yytext); return T_NOT;              }
"="   { num_carac += 1; yylval.sval = strdup(yytext); return T_ATRIBUICAO;       }
"+="  { num_carac += 2; yylval.sval = strdup(yytext); return T_ATRIB_SOMA;       }
"-="  { num_carac += 2; yylval.sval = strdup(yytext); return T_ATRIB_SUB;        }
"*="  { num_carac += 2; yylval.sval = strdup(yytext); return T_ATRIB_MULT;       }
"/="  { num_carac += 2; yylval.sval = strdup(yytext); return T_ATRIB_DIV;        }
"%="  { num_carac += 2; yylval.sval = strdup(yytext); return T_ATRIB_MOD;        }
"?"   { num_carac += 1; return T_COND_OP_TER;     								 }
":"   { num_carac += 1; return T_DOIS_PON;       								 }


	/* trata um comentario */
"//"[^\n]*\n {
	num_linhas++;
	num_carac = 1;
}

	/* Identificador */
(\_|[a-zA-Z])([a-zA-Z]|[0-9]|\_)* {
	yylval.sval = strdup(yytext);
	num_carac += strlen(strdup(yytext));
	
	return T_ID;
}

	/* Numeros */
[0-9]+ {
	yylval.sval = strdup(yytext);
	num_carac += strlen(strdup(yytext));
	
	return T_NUM;
}
	/* Strings */
\"([^\"]|\\\")*\" {
	yylval.sval = strdup(yytext);
	num_carac += strlen(strdup(yytext));
	
	return T_LIT_STRING;
}

	/* Conta o numero de linhas */
\n {num_linhas++; num_carac = 1;}

	/* Elimina Demais Caracteres Indesejados */
. 						{cout<<"Erro léxico (l: "<< num_linhas <<", c: "<< num_carac <<"): token ilegal '"<<yytext <<"'!\n";}
%%
