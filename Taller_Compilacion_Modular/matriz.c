/**********************************************
* Autor: Samuel Gantiva
* Institución: Pontificia Universidad Javeriana
* Fecha: 13/02/2025 (Archivo hecho en clase)
* Clase: Sistemas Operativos
* Tema: Memoria dinámica y programación modular
* Descripción: Implementación de funciones para manejo de matrices
***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

/*Inicializa la matriz*/
void iniMatriz(int *M1, int *M2, int N) {
    for (int i = 0; i < N * N; i++) {
        M1[i] = 2 + i;
        M2[i] = 3 * i;
    }
}
/*Funcion para imprimir una matriz desde un arreglo*/
void printMatriz(int *M, int N) {
    if (N < 100) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf(" %d ", M[i * N + j]);
            }
            printf("\n");
        }
    }
}
/*Funcion para multipliucar dos matrices y guardar el resultado en una tercera*/
void multMatriz(int *M1, int *M2, int *M3, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int sum = 0;
            int *pA = M1 + i * N;
            int *pB = M2 + j;
            for (int k = 0; k < N; k++, pA++, pB += N) {
                sum += (*pA * *pB);
            }
            M3[i * N + j] = sum;
        }
    }
}