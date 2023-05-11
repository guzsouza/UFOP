all: main.o f91.o
	@gcc f91.o main.o -o exe
main.o: main.c
	@gcc main.c -c
f91.o: f91.c
	@gcc f91.c -c
run:
	@./exe
