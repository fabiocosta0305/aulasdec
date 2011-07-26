#
# Primeira tentativa de Makefile
#

all: roletrando
    
roletrando: main.o regras.o letras.o
	gcc -o roletrando main.o regras.o letras.o

main.o: main.c roletrando.h
	gcc -o main.o -c main.c 

regras.o: regras.c roletrando.h
	gcc -o regras.o -c regras.c 

letras.o: letras.c roletrando.h
	gcc -o letras.o -c letras.c
