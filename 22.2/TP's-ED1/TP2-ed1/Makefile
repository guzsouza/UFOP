all: main.o ponto.o
	@gcc -g main.o ponto.o -lm -o exe 
	@rm -r *.o
main.o: main.c
	@gcc main.c -c
ponto.o: ponto.c
	@gcc -lm ponto.c -c
run:
	@./exe

