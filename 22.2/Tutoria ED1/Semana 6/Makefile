all: principal.o busca.o
	@gcc principal.o busca.o -o exe -lm
busca.o: busca.c
	@gcc busca.c -c -Wall
principal.o: principal.c
	@gcc principal.c -c -Wall
run:
	@./exe
