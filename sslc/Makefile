all: compile

clean:
	rm -f *.o sslc sslc_f1

compile:
	gcc -c compile.c extra.c gencode.c lex.c mcpp_directive.c mcpp_eval.c mcpp_expand.c mcpp_main.c mcpp_support.c mcpp_system.c optimize.c parse.c parselib.c parseext.c linux.c
	gcc -osslc compile.o extra.o gencode.o lex.o mcpp_directive.o mcpp_eval.o mcpp_expand.o mcpp_main.o mcpp_support.o mcpp_system.o optimize.o parse.o parselib.o parseext.o linux.o