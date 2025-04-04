/**************************************************************
    Pontificia Universidad Javeriana
    Autor: Samuel Gantiva
    Profesor: J. Corredor
    Fecha: Febrero 2024
    Materia: Sistemas Operativos
    Tema: Taller de Evaluación de Rendimiento
    Fichero: fuente de multiplicación de matrices (mm) NxN por hilos.
    Objetivo: Evaluar el tiempo de ejecución del
            algoritmo clásico de multiplicación de matrices.
            Se implementa con la Biblioteca POSIX Pthreads
****************************************************************/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "mm_clasica.h"


// Declaración del mutex para sincronización
static pthread_mutex_t MM_mutex;
// Definición del tamaño del buffer de memoria para las matrices
#define DATA_SIZE (1024*1024*64*3)


// Reservas estáticas de memoria para las matrices
static double MEM_CHUNK[DATA_SIZE];
double *mA, *mB, *mC;

// Variables para medir el tiempo
struct timeval start, stop;


int main(int argc, char *argv[]){
        if (argc < 3){
                printf("Ingreso de argumentos \n $./ejecutable tamMatriz numHilos\n");
                return -1;
        }

        int SZ = atoi(argv[1]);      // Tamaño de la matriz
        int n_threads = atoi(argv[2]); // Número de hilos

        pthread_t p[n_threads];       // Array de identificadores de hilos
        pthread_attr_t atrMM;         // Atributos de los hilos

        // Inicializa las matrices en un bloque de memoria compartido
        mA = MEM_CHUNK;
        mB = mA + SZ * SZ;
        mC = mB + SZ * SZ;

        // Rellena las matrices con datos
        llenar_matriz(SZ, mA, mB, mC);
        print_matrix(SZ, mA);
        print_matrix(SZ, mB);

        // Inicia la medición del tiempo
        inicial_tiempo(&start);

        // Inicializa los atributos y el mutex
        pthread_mutex_init(&MM_mutex, NULL);
        pthread_attr_init(&atrMM);
        pthread_attr_setdetachstate(&atrMM, PTHREAD_CREATE_JOINABLE);

        // Crea los hilos para la multiplicación de matrices
        for (int j = 0; j < n_threads; j++){
                struct parametros *datos = (struct parametros *) malloc(sizeof(struct parametros));
                datos->idH = j;
                datos->nH  = n_threads;
                datos->N   = SZ;
                pthread_create(&p[j], &atrMM, mult_thread, (void *)datos);
        }

        // Espera que todos los hilos terminen
        for (int j = 0; j < n_threads; j++)
                pthread_join(p[j], NULL);

        // Finaliza la medición del tiempo
        final_tiempo(&start, &stop);

        // Imprime la matriz resultante
        print_matrix(SZ, mC);

        // Limpia recursos
        pthread_attr_destroy(&atrMM);
        pthread_mutex_destroy(&MM_mutex);
        pthread_exit(NULL);

	return 0;
}
