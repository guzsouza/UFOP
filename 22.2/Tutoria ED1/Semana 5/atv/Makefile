all: main.o ordenacao.o
	@gcc main.o ordenacao.o -o exe -lm
ordenacao.o: ordenacao.c
	@gcc ordenacao.c -c -Wall
main.o: main.c
	@gcc main.c -c -Wall
run:
	@./exe
