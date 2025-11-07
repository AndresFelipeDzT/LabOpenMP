/******************************************************
* Fecha 6/11/2025
* Pontificia Universidad Javeriana
* Profesor: J. Corredor, PhD
* Autor: Andres Diaz
* Materia: Sistemas opertivos
* Temas: Laboratorio02 OpenMP
* Descripcion:
*    Introduccon a la programacion paralela mediante OpenMP para aprovechar 
*    los recursos y un mejor manejo de memoria. Asimismo, se utilizan multiples 
*    hilos indicados por el usuario como parametro que ejecutan la parte final
*    del codigo un hola, permitiendo entender OpenMP. 
******************************************************/

#include <omp.h> //Libreria para funciones de OpenMP
#include <stdio.h> //Libreria para mostrar informacion por pantalla
#include <stdlib.h> //Libreria de memoria dinamica

int main (int argc, char *argv[]) {
    // Verifica que le pase el numero de hilos como parametro
    if (argc != 2) {     
        printf("ERROR\n\tUso: ./Lab01 numHilos\n");
        exit(0); //Sino recibe el parametro termina el proceso
    }
    // Se asegura que el numero de hilos quede como entero
    int numHilos = atoi(argv[1]);
    // Muestra cuantos hilos tiene la maquina
    int maxHilos = omp_get_max_threads();
    printf("OpenMP ejecutando en cores = %d hilos disponibles\n", maxHilos);
    // indica el numero de hilos a utilizar
    omp_set_num_threads(numHilos);
    #pragma omp parallel //Que lo hacen paralelamente todos los hilos
    {
        int id = omp_get_thread_num(); // Obtiene el ID del hilo
        //Muestra en pantalla un saludo desde el hilo con su ID
        printf("Hola mundo desde el thread %d\n", id);
    }

    return 0;
}
