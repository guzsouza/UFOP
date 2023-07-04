gcc -Wall main.c -c
gcc -Wall criaArq.c -c
gcc -Wall arvoreb.c -c
gcc -Wall ASI.c -c
gcc -Wall arvoreBinaria.c -c
gcc -Wall arvorebe.c -c
gcc main.o criaArq.o arvoreb.o ASI.o arvoreBinaria.o arvorebe.o -o exe
rm *.o
./exe 3 20 3 20