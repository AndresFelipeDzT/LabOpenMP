/******************************************************
* Fecha 6/11/2025
* Pontificia Universidad Javeriana
* Profesor: J. Corredor, PhD
* Autor: Andres Diaz
* Materia: Sistemas opertivos
* Temas: Laboratorio03 OpenMP
* Descripcion:
*    Introduccon a la programacion paralela mediante OpenMP para aprovechar 
*    los recursos y un mejor manejo de memoria. Asimismo, se utilizan multiples 
*    hilos dentro de un bucle indicados por el usuario como parametro que 
*    ejecutan una suma cuyo valor se ve afectado por el orden de los hilos, 
*    al ser variables privadas (que no se comparten entre los hilos).
******************************************************/

#include <omp.h> //Libreria para funciones de OpenMP
#include <stdio.h> //Libreria para mostrar informacion por pantalla
#include <stdlib.h> //Libreria de memoria dinamica

int main() {
    int i;    //Variable para el inicio bucle
    const int N = 1000; //Variable a alcanzar en el bucle, crece hasta N
    int a = 50; //Entero que es un valor a sumar
    int b = 0;  // Entero que guarda el resultado de la suma
    //Que lo hacen paralelamente todos los hilos
    //En este caso i y a son privadas para cada hilo
    #pragma omp parallel for private(i) firstprivate(a)
    for (i = 0; i < N; i++) {
        b = a + i;   // Suma dentro del hilo
    }
    //Se muestra el valor de a y b, pero b es variable ya que dependiendo
    // del orden en el que finalicen los hilos,  
    printf("a = %d, b = %d (Se espera a = 50, b = 1049)\n", a, b);

    return 0;
}
