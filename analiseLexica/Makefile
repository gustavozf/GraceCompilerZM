all: ns.l
	flex ns.l
	g++ lex.yy.c -lfl -o nslex

clean:
	rm lex.yy.c
	rm nslex
