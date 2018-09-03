# Nome dos arquivos
NOME = ns
CC = g++

# ===============================================
# Nao eh necessario alterar as regras abaixo
# ===============================================

all: $(NOME).tab.c lex.yy.c
	$(CC) $(NOME).tab.c lex.yy.c -lfl -o $(NOME)Comp

# Flex (Analisador Lexico)
lex.yy.c: $(NOME).l
	flex $(NOME).l

# Bison (Analisador Sintatico)
$(NOME).tab.c: $(NOME).y
	bison -d $(NOME).y

# Para remover os arquivos
.PHONY: clean

clean:
	rm lex.yy.c
	rm $(NOME)Comp
	rm $(NOME).tab.c
	rm $(NOME).tab.h
