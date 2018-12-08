# Nome dos arquivos
NOME = gczm
CC = g++
HEADERS = ./structs/cmd.o ./structs/exp.o ./structs/prog.o ./structs/dec.o
# ===============================================
# Nao eh necessario alterar as regras abaixo
# ===============================================

all: $(NOME).tab.c lex.yy.c
	cd structs && make
	cd ..
	$(CC) -DYYDEBUG=1 $(NOME).tab.c lex.yy.c -ll -o $(NOME) $(HEADERS)

# Flex (Analisador Lexico)
lex.yy.c: $(NOME).l
	flex $(NOME).l

# Bison (Analisador Sintatico)
$(NOME).tab.c: $(NOME).y
	bison -dt --debug --verbose -Dparse.trace $(NOME).y

# Para remover os arquivos
.PHONY: clean

clean:
	rm lex.yy.c
	rm lex.yy.o
	rm $(NOME).tab.h
	rm $(NOME).tab.o
	rm $(NOME).tab.c
	rm $(NOME).output
	rm $(NOME)

	cd structs && make clean
	cd ..