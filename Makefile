############################################################
# Fecha: 6/11/2025
# Pontificia Universidad Javeriana
# Profesor: J. Corredor, PhD
# Autor: Andres Diaz
# Materia: Sistemas Operativos
# Tema: Makefile OpenMP
# Descripción:
#    Archivo que facilita compilar el codigo
############################################################

# Compilador gcc
CC = gcc
CFLAGS = -fopenmp -O2 -Wall

# Archivos que se van a compilar
SRCS = Lab01.c Lab02.c Lab03.c Lab04.c Lab05.c

# nombres de los ejecutables
EXES = Lab01 Lab02 Lab03 Lab04 Lab05

# Que los compile todos
all: $(EXES)

# Comando individual para que compile cada uno
Lab01: Lab01.c
	$(CC) $(CFLAGS) -o Lab01 Lab01.c

Lab02: Lab02.c
	$(CC) $(CFLAGS) -o Lab02 Lab02.c

Lab03: Lab03.c
	$(CC) $(CFLAGS) -o Lab03 Lab03.c

Lab04: Lab04.c
	$(CC) $(CFLAGS) -o Lab04 Lab04.c

Lab05: Lab05.c
	$(CC) $(CFLAGS) -o Lab05 Lab05.c -lm

# Limpieza
clean:
	rm -f $(EXES)
