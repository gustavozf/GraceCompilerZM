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
int num_linhas = 1;
int num_carac = 1;

/*
std::unordered_map<string, int> tokens_table;
tokens_table["bool"]   = t_bool  ;
tokens_table["else"]   = t_else  ;
tokens_table["def"]    = t_def   ;
tokens_table["false"]  = t_false ;
tokens_table["for"]    = t_for   ;
tokens_table["if"]     = t_if    ;
tokens_table["int"]    = t_int   ;
tokens_table["read"]   = t_read  ;
tokens_table["return"] = t_return;
tokens_table["skip"]   = t_skip  ;
tokens_table["stop"]   = t_stop  ;
tokens_table["string"] = t_string;
tokens_table["true"]   = t_true  ;
tokens_table["var"]    = t_var   ;
tokens_table["while"]  = t_while ;
tokens_table["(" ] = "t_abre_parenteses";
tokens_table[")" ] = "t_fecha_parenteses";
tokens_table["[" ] = "t_abre_colchetes";
tokens_table["]" ] = "t_fecha_colchetes";
tokens_table["{" ] = "t_abre_chaves";
tokens_table["}" ] = "t_fecha_chaves";
tokens_table["," ] = "t_virgula";
tokens_table[";" ] = "t_ponto_virgula";
tokens_table["+" ] = "t_adicao";
tokens_table["-" ] = "t_subtracao";
tokens_table["*" ] = "t_multiplicacao";
tokens_table["/" ] = "t_divisao";
tokens_table["%" ] = "t_modulo";
tokens_table["=="] = "t_eq_logica";
tokens_table["!="] = "t_dif_logica";
tokens_table[">" ] = "t_maior";
tokens_table[">="] = "t_maior_igual";
tokens_table["<" ] = "t_menor";
tokens_table["<="] = "t_menor_igual";
tokens_table["||"] = "t_or";
tokens_table["&&"] = "t_and";
tokens_table["!" ] = "t_not";
tokens_table["=" ] = "t_atribuicao";
tokens_table["+="] = "t_atrib_soma";
tokens_table["-="] = "t_atrib_sub";
tokens_table["*="] = "t_atrib_mult";
tokens_table["/="] = "t_atrib_div";
tokens_table["%="] = "t_atrib_mod";
tokens_table["?" ] = "t_cond_op_ter";
tokens_table[":" ] = "t_sep_op_ter";
*/
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
("bool"|"def"|"else"|"false"|"for"|"if"|"int"|"read"|"return"|"skip"|"stop"|"string"|"true"|"var"|"while") {
	cout <<"Palavra reservada: "<< yytext << endl;

	yylval.sval = strdup(yytext);
	
	num_carac += strlen(strdup(yytext));

	return yytext[0];
}
	
	/* Simbolo */
("("|")"|"["|"]"|"{"|"}"|","|";"|"+"|"-"|"*"|"/"|"%"|"=="|"!="|">"|">="|"<"|"<="|"||"|"&&"|"!"|"="|"+="|"-="|"*="|"/="|"%="|"?"|":") {
	cout << yytext << endl;
	yylval.sval = strdup(yytext);

	num_carac += strlen(strdup(yytext));

	return yytext[0];
}

	/* trata um comentario */
"//"[^\n]*\n {
	cout << "COMENTARIO!\n";
	num_linhas++;
	num_carac = 1;
}

	/* Identificador */
(\_|[a-zA-Z])([a-zA-Z]|[0-9]|\_)* {
    cout << "Id encontrado: " << yytext << endl;
    // Converte o 'yytext' para uma string
	yylval.sval = strdup(yytext);
	num_carac += strlen(strdup(yytext));
	return t_id;
}

	/* Numeros */
[0-9]+ {
	yylval.sval = strdup(yytext);
	cout << yytext<< endl;
	num_carac += strlen(strdup(yytext));
	return t_num; // < -- colocar no bison
}
	/* Strings */
\"[^\"]*\" {
	cout  << yytext << endl;
	yylval.sval = strdup(yytext);
	num_carac += strlen(strdup(yytext));
	return t_lit_string; // < -- colocar no bison
}

	/* Conta o numero de linhas */
\n {num_linhas++; num_carac = 1;}

	/* Elimina Demais Caracteres Indesejados */
. {}
%%

