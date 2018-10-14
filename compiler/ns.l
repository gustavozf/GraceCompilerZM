%{
/* Declaracoes */
#include <iostream>

/* Arquivo gerado do Bison
   Usado para ler os tokens e etc.
 */
#include "ns.tab.h"

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
"bool"   { return T_BOOL;   } 
"def"    { return T_DEF;    } 
"else"   { return T_ELSE;   } 
"false"  { return T_FALSE;  } 
"for"    { return T_FOR;    } 
"if"     { return T_IF;     } 
"int"    { return T_INT;    } 
"read"   { return T_READ;   } 
"return" { return T_RETURN; } 
"skip"   { return T_SKIP;   } 
"stop"   { return T_STOP;   } 
"string" { return T_STRING; } 
"true"   { return T_TRUE;   } 
"var"    { return T_VAR;    } 
"while"  { return T_WHILE;  }
"write"  { return T_WRITE;  } 

	/* Simbolo */
\(    { return T_ABRE_PARENTESES;  }
\)    { return T_FECHA_PARENTESES; }
\[    { return T_ABRE_COLCHETES;   }
\]    { return T_FECHA_COLCHETES;  } 
"{"   { return T_ABRE_CHAVES;      }
"}"   { return T_FECHA_CHAVES;     }
","   { return T_VIRGULA;          }
";"   { return T_PONTO_VIRGULA;    }
"+"   { return T_ADICAO;           }
"-"   { return T_SUBTRACAO;        }
"*"   { return T_MULTIPLICACAO;    }
"/"   { return T_DIVISAO;          }
"%"   { return T_MODULO;           }
"=="  { return T_EQ_LOGICA;        }
"!="  { return T_DIF_LOGICA;       }
">"   { return T_MAIOR;            }
">="  { return T_MAIOR_IGUAL;      }
"<"   { return T_MENOR;            }
"<="  { return T_MENOR_IGUAL;      }
"||"  { return T_OR;               }
"&&"  { return T_AND;              }
"!"   { return T_NOT;              }
"="   { return T_ATRIBUICAO;       }
"+="  { return T_ATRIB_SOMA;       }
"-="  { return T_ATRIB_SUB;        }
"*="  { return T_ATRIB_MULT;       }
"/="  { return T_ATRIB_DIV;        }
"%="  { return T_ATRIB_MOD;        }
"?"   { return T_COND_OP_TER;      }
":"   { return T_DOIS_PON;         }


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
. {cout<<"Token Ilegal: "<<yytext <<"!";}
%%
