/******************************************************
* Fecha 6/11/2025
* Pontificia Universidad Javeriana
* Profesor: J. Corredor, PhD
* Autor: Andres Diaz
* Materia: Sistemas opertivos
* Temas: Laboratorio05 OpenMP
* Descripcion:
*    Introduccon a la programacion paralela mediante OpenMP para aprovechar 
*    los recursos y un mejor manejo de memoria. Asimismo, se utilizan multiples 
*    indicados por el usuario para hacer una sumatoria de seno, restringiendo el
*    acceso en cada iteracion (suma) para evitar conflictos. Adicionalmente, 
*    se guarda el tiempo de ejecucion del proceso.
******************************************************/

#include <omp.h> //Libreria para funciones de OpenMP
#include <stdio.h> //Libreria para mostrar informacion por pantalla
#include <stdlib.h> //Libreria de memoria dinamica
#include <math.h> //Libreria para matematicas como seno
#include <time.h> //Libreria para medir el tiempo
//Indica cual es el menor entre x & y
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

double funcion(int i) {
    //Indica el rango del bucle
    int j, inicio = i * (i + 1) / 2, fin = inicio + 1;
    double valor = 0;

    for (j = inicio; j < fin; j++) {
        //Suma el seno en esta iteracion al acumulado
        valor += sin(j);
    }

    return valor; //Devuelve el acumulado
}

int main(int argc, char *argv[]) {

    // Verifica que le indico el numero de hilos y la cantidad de iteraciones
    if (argc != 3) {
        printf("Uso: %s <num_hilos> <num_iteraciones>\n", argv[0]);
        return 1;
    }

    // guarda el numero de hilos y las iteraciones como enteros
    int num_hilos = atoi(argv[1]);
    int n = atoi(argv[2]);
    //Inicializa la suma en 0 y crea las variables de inicio y fin del tiempo
    //Con estas se puede calcular el tiempo de ejecucion
    double suma = 0.0;
    double tiempo_inicio, tiempo_fin;

    // indica el numero de hilos a utilizar
    omp_set_num_threads(num_hilos);
    // obtiene el tiempo de inicio
    tiempo_inicio = omp_get_wtime();
    //Que lo hacen paralelamente todos los hilos
    #pragma omp parallel
    {
        int threads = omp_get_num_threads();
        //Define un hilo maestro en el que esta el print y solo aplica para el
        //La parte de mostrar solo la va a hacer el hilo maestro
        #pragma omp master
        printf("Número de Hilos: %d\n", threads);

        #pragma omp for reduction(+:suma)
        for (int i = 0; i <= n; i++) {
            suma += funcion(i); //Cada hilo hace una de las sumas de la sumatoria
        }
    }

    // obtiene el tiempo de fin
    tiempo_fin = omp_get_wtime();
    // obtiene el tiempo de ejecucion
    double tiempo_total = tiempo_fin - tiempo_inicio;

    // Muestra por pantalla los resultados
    printf("\n=====================================\n");
    printf("Cantidad de iteraciones: %d\n", n);
    printf("Número de hilos usados:  %d\n", num_hilos);
    printf("La sumatoria total es:   %.4f\n", suma);
    printf("Tiempo total de ejecución: %.6f segundos\n", tiempo_total);
    printf("=====================================\n");

    return 0;
}
