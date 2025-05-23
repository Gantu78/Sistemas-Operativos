/***********************************************************
 * Pontificia Universidad Javeriana
 * Fecha: 22 de mayo de 2025
 * Autor: Samuel Gantiva
 * Materia: Sistemas Operativos
 * Tópico: Uso de OpenMP
 * Descripción: Este archivo contiene las implementaciones de las funciones
 *              utilizadas para demostraciones con OpenMP. Incluye la gestión
 *              de hilos y cálculos paralelos.
 ************************************************************/

#include "ompLab.h"

/**
 * Función: initializeParallel
 * Descripción: Configura el número de hilos para la ejecución paralela
 *              e imprime información sobre los hilos disponibles.
 * Parámetros:
 *   - hilos: Número de hilos a configurar.
 * Retorno: 0 si es exitoso.
 */
int initializeParallel(int hilos) {
    int maxHilos = omp_get_max_threads();
    omp_set_num_threads(hilos);
    #pragma omp parallel
    {
        printf("MaxHilos %d \t Equipo de Hilos impuesto = %d\n", maxHilos, omp_get_num_threads());
    }
    return 0;
}

/**
 * Función: parallelSum
 * Descripción: Realiza un cálculo paralelo para asignar a b el valor de a + i
 *              en la última iteración (i = N-1).
 * Parámetros:
 *   - a: Valor base inicial.
 *   - b: Puntero al resultado.
 *   - N: Número de iteraciones.
 */
void parallelSum(int a, int *b, int N) {
    int i;
    #pragma omp parallel for private(i)
    for (i = 0; i < N; i++) {
        if (i == N - 1) { // Solo el último i actualiza b
            #pragma omp critical
            {
                *b = a + i;
            }
        }
    }
}
