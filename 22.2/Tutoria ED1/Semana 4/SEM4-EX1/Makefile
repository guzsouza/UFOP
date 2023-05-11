all: principal.o ordenacao.o
	@gcc ordenacao.o principal.o -o exe
principal.o: principal.c
	@gcc principal.c -c
ordenacao.o: ordenacao.c
	@gcc ordenacao.c -c
run:
	@./exe
