/**************************************************************
    Pontificia Universidad Javeriana
    Autor: Samuel Gantiva
    Profesor: J. Corredor
    Fecha: Febrero 2024
    Materia: Sistemas Operativos
    Tema: Taller de Evaluación de Rendimiento
    Fichero: Interfaz de multiplicacion de matrices clásica.
    Objetivo: Declarar las funciones necesarias para la
             multiplicación de matrices NxN usando hilos.
             Se implementa con la Biblioteca POSIX Pthreads
             y se utiliza un bloque de memoria compartido.
****************************************************************/
#ifndef MM_CLASICA_H
#define MM_CLASICA_H

#include <pthread.h>
#include <sys/time.h>

// Define el tamaño del buffer de memoria para las matrices
#define DATA_SIZE (1024*1024*64*3)

// Estructura para los parámetros de los hilos
struct parametros {
    int nH;  // Número de hilos
    int idH; // ID del hilo actual
    int N;   // Dimensión de la matriz
};

// Funciones exportadas
void llenar_matriz(int SZ, double *mA, double *mB, double *mC);
void print_matrix(int sz, double *matriz);
void inicial_tiempo(struct timeval *start);
void final_tiempo(struct timeval *start, struct timeval *stop);
void *mult_thread(void *variables);

#endif // MM_CLASICA_H