/**********************************************
* Autor: Samuel Gantiva
* Institución: Pontificia Universidad Javeriana
* Fecha: 13/02/2025
* Clase: Sistemas Operativos
* Tema: - Memoria dinámica, programación modular
	- Compilación Automática
***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include "modulo.h"

//Funcion para inicializar la matriz
void iniMatriz(int *M1, int *M2, int N){
	for(int i = 0; i < N * N; i++){
		M1[i] = 2+i;
		M2[i] = 3*i;
	}
}

//Funcion para imprimir la matriz
void printMatriz(int *M, int N){
	if(N<6){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			printf(" %d ", M[i * N + j]);      // Se imprime la matriz A en la posicion [i][j]
			}
			printf("\n");														// Salto de linea marcando el final de la fila
		}
	}
}

//Funcion para multiplicar dos matrices
void multMatriz(int *M1, int *M2, int *M3, int N){
	/****** Multiplicación de mAxmB = mC (Filas por Columnas) *******/
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){	
			int sum = 0;  // Declara la suma dentro del segundo for
			int *pA, *pB;
			pA= M1 + i*N;
			pB= M2 + j;
			for(int k = 0; k < N; k++, pA++, pB +=N){
				sum += (*pA * *pB);      // Se multiplica la matriz A por la matriz B y se suma en la matriz C
				}
				M3[i * N + j] = sum;
			}
	}
}

