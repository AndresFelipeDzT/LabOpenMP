/******************************************************
* Fecha 6/11/2025
* Pontificia Universidad Javeriana
* Profesor: J. Corredor, PhD
* Autor: Andres Diaz
* Materia: Sistemas opertivos
* Temas: Laboratorio01 OpenMP
* Descripcion:
*    Introduccon a la programacion paralela mediante OpenMP para aprovechar 
*    los recursos y un mejor manejo de memoria. Asimismo, se utilizan multiples 
*    hilos que ejecutan la parte final del codigo un hola, permitiendo 
*    entender OpenMP.
******************************************************/


#include <omp.h> //Libreria para funciones de OpenMP
#include <stdio.h> //Libreria para mostrar informacion por pantalla
#include <stdlib.h> //Libreria de memoria dinamica

int main(int argc, char *argv[]) { //Recibe los argumentos
    // Muestra cuantos hilos tiene la maquina
    printf("OpenMP ejecutando con %d hilos\n", omp_get_max_threads());
    #pragma omp parallel //Que lo hacen paralelamente todos los hilos
    {
        int id = omp_get_thread_num();  // Obtiene el ID del hilo
        //Muestra en pantalla un saludo desde el hilo con su ID
        printf("Hello World desde el thread %d\n", id); 
    }

    return 0;
}

