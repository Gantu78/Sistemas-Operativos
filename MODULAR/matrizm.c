/**********************************************
* Autor: Samuel Gantiva
* Institución: Pontificia Universidad Javeriana
* Fecha: 13/02/2025
* Clase: Sistemas Operativos
* Tema: - Memoria dinámica, programación modular
	- Compilación Automática
		Programa Principal Multiplicación Matrices
***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "modulo.h"

int main(int argc, char *argv[]){

	int N = (int) atoi(argv[1]);    // Variables entera de valor 5
	/* Crear punteros de memoria para las matrices */
	int *mA = (int *) malloc(sizeof(int) * N * N);     // Reserva de tamaño N*N de tipo entero para la matriz A
	int *mB = (int *) malloc(sizeof(int) * N * N);     // Reserva de tamaño N*N de tipo entero para la matriz B
	int *mC = (int *) calloc(sizeof(int), N * N);     // Reserva de tamaño N*N de tipo entero para la matriz C

	/************ Inicializando las matrices ************/
	iniMatriz(mA, mB, N);

	printf("************************************\n");
	/************ Imprimir Matriz A ************/
	printf("Matriz A\n");
	printMatriz(mA, N);
	printf("************************************\n");
	/************ Imprimir Matriz B ************/
	printf("Matriz B\n");
	printMatriz(mB,N);

	//Toma de tiempo inicial
	struct timeval  tv1, tv2;
	gettimeofday(&tv1, NULL);
	multMatriz(mA,mB,mC,N);
	//Toma de tiempo final
	gettimeofday(&tv2, NULL);

	printf ("Tiempo total = %f segundos\n",
					 (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
					 (double) (tv2.tv_sec - tv1.tv_sec));
	
	

	/************ Imprimir Matriz C ************/
	printf("************************************\n");
	printf("Matriz C\n");
	printMatriz(mC, N);
	printf("\n Fin del programa\n");

	free(mA);																		// Liberar memoria de la matriz A
	free(mB);																		// Liberar memoria de la matriz B	
	free(mC);																		// Liberar memoria de la matriz C

		return 0;
}
