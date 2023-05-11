all: pratica.o ordenacao_linear.o
	@gcc pratica.o ordenacao_linear.o -o exe -lm
ordenacao_linear.o: ordenacao_linear.c
	@gcc ordenacao_linear.c -c -Wall
pratica.o: pratica.c
	@gcc pratica.c -c -Wall
run:
	@./exe
