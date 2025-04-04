#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mm_clasica.h"


// Declaración del mutex para sincronización
static pthread_mutex_t MM_mutex;


/**
 * Rellena las matrices mA y mB con valores predefinidos y mC con ceros.
 * @param SZ Tamaño de la matriz
 * @param mA Puntero a la matriz A
 * @param mB Puntero a la matriz B
 * @param mC Puntero a la matriz C (resultado)
 */
void llenar_matriz(int SZ, double *mA, double *mB, double *mC) {
    srand48(time(NULL));
    for (int i = 0; i < SZ * SZ; i++) {
        mA[i] = 1.1 * i; // Valores para matriz A
        mB[i] = 2.2 * i; // Valores para matriz B
        mC[i] = 0;       // Inicializa matriz C en cero
    }
}

/**
 * Imprime una matriz en la consola si el tamaño es pequeño.
 * @param sz Tamaño de la matriz
 * @param matriz Puntero a la matriz a imprimir
 */
void print_matrix(int sz, double *matriz) {
    if (sz < 12) {
        for (int i = 0; i < sz * sz; i++) {
            if (i % sz == 0) printf("\n");
            printf(" %.3f ", matriz[i]); // Imprime el elemento de la matriz
        }
        printf("\n>-------------------->\n");
    }
}

/**
 * Inicia la medición del tiempo.
 * @param start Puntero a la estructura timeval para almacenar el tiempo inicial
 */
void inicial_tiempo(struct timeval *start) {
    gettimeofday(start, NULL); // Obtiene el tiempo inicial
}

/**
 * Finaliza la medición del tiempo e imprime el resultado.
 * @param start Puntero a la estructura timeval con el tiempo inicial
 * @param stop Puntero a la estructura timeval con el tiempo final
 */
void final_tiempo(struct timeval *start, struct timeval *stop) {
    gettimeofday(stop, NULL); // Obtiene el tiempo final
    stop->tv_sec -= start->tv_sec; // Resta los segundos
    printf("\n:-> %9.0f µs\n", (double)(stop->tv_sec * 1000000 + stop->tv_usec)); // Calcula el tiempo total en microsegundos
}

/**
 * Multiplica matrices usando el método clásico en hilos.
 * @param variables Puntero a la estructura de parámetros
 * @return NULL
 */
void *mult_thread(void *variables) {
    struct parametros *data = (struct parametros *)variables;
    int idH = data->idH;
    int nH = data->nH;
    int N = data->N;
    // Calcular el rango de filas que le corresponde al hilo
    // idH: ID del hilo
    // nH: Número de hilos
    // N: Dimensión de la matriz
    // ini: Índice inicial de la fila
    // fin: Índice final de la fila

    extern double *mA, *mB, *mC; // Matrices definidas en main.c

    int ini = (N / nH) * idH;
    int fin = (N / nH) * (idH + 1);

    for (int i = ini; i < fin; i++) {
        for (int j = 0; j < N; j++) {
            double *pA = mA + (i * N); // Puntero a la fila i de mA
            double *pB = mB + j; // Puntero a la columna j de mB
            // sumaTemp: Variable para almacenar el resultado de la multiplicación
            double sumaTemp = 0.0;
            for (int k = 0; k < N; k++, pA++, pB += N) {
                sumaTemp += (*pA * *pB); // Multiplicación de elementos
            }
            mC[i * N + j] = sumaTemp; // Almacena el resultado en mC
        }
    }

    pthread_mutex_lock(&MM_mutex); // Bloquea el mutex
    pthread_mutex_unlock(&MM_mutex);// Desbloquea el mutex
    pthread_exit(NULL);// Termina el hilo
}