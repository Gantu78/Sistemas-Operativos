/***********************************************************
 * Pontificia Universidad Javeriana
 * Fecha: 22 de mayo de 2025
 * Autor: Samuel Gantiva
 * Materia: Sistemas Operativos
 * Tópico: Uso de OpenMP
 * Descripción: Este archivo define la interfaz de las funciones
 *              utilizadas para demostraciones con OpenMP.
 *              Incluye declaraciones de funciones para la gestión
 *              de hilos y cálculos paralelos.
 ************************************************************/

#ifndef OMPLAB_H
#define OMPLAB_H

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

/**
 * Función: initializeParallel
 * Descripción: Inicializa y configura el número de hilos para la ejecución paralela.
 * Parámetros:
 *   - hilos: Número de hilos a configurar.
 * Retorno: 0 si es exitoso.
 */
int initializeParallel(int hilos);

/**
 * Función: parallelSum
 * Descripción: Realiza un cálculo paralelo sumando un valor base con un índice.
 * Parámetros:
 *   - a: Valor base inicial.
 *   - b: Puntero al resultado acumulado.
 *   - N: Número de iteraciones.
 */
void parallelSum(int a, int *b, int N);

#endif // OMPLAB_H
