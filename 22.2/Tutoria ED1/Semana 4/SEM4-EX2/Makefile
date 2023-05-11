all: main.o ordenacao.o
	@gcc ordenacao.o main.o -o exe
main.o: main.c
	@gcc main.c -c
ordenacao.o: ordenacao.c
	@gcc ordenacao.c -c
run:
	@./exe
