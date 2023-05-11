all: main.o r9.o
	@gcc r9.o main.o -o exe
main.o: main.c
	@gcc main.c -c
r9.o: r9.c
	@gcc r9.c -c
run:
	@./exe
