/**********************************************
* Autor: Samuel Gantiva
* Institución: Pontificia Universidad Javeriana
* Fecha: 16/03/2025
* Clase: Sistemas Operativos
* Tema: Vectores dinámicos y matrices con menú
* Descripción: Programa principal con menú interactivo
***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector_dinamico.h"
#include "matriz.h"

void vectorMenu(vectorDinamico *V) {
    int opcion, indice;
    char buffer[100];
    while (1) {
        printf("\n--- Menú Vectores ---\n");
        printf("1. Añadir elemento\n2. Borrar elemento\n3. Modificar elemento\n4. Mostrar vector\n5. Volver\nOpción: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                printf("Ingrese texto: ");
                scanf("%s", buffer);
                addVector(V, strdup(buffer));
                break;
            case 2:
                printf("Índice a borrar: ");
                scanf("%d", &indice);
                borrarVector(V, indice);
                break;
            case 3:
                printf("Indice a modificar: ");
                scanf("%d", &indice);
                printf("Indique el texto: ");
                scanf("%s", buffer);
                setVector(V, indice, strdup(buffer));
                break;
            case 4:
                imprimirVector(V);
                break;
            case 5:
                return;
        }
    }
}

void matrizMenu() {
    int N;
    int opcion;
    printf("Tamaño de la matriz (menor a 100): ");
    scanf("%d", &N);
    int *mA = malloc(sizeof(int) * N * N);
    int *mB = malloc(sizeof(int) * N * N);
    int *mC = calloc(N * N, sizeof(int));
    iniMatriz(mA, mB, N);
    while (2) {
        printf("\n--- Menú Matrices ---\n");
        printf("1. Imprimir matrices\n2. Multiplicar matrices para ver resultado en matriz C\n3. Volver\nOpción: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                printf("Matriz A:\n");
                printMatriz(mA, N);
                printf("Matriz B:\n");
                printMatriz(mB, N);
                printf("Matriz C (A x B):\n");
                printMatriz(mC, N);
                break;
            case 2:
                multMatriz(mA, mB, mC, N);
                printf("Matrices multiplicadas correctamente (vuelve a imprimir las matrices para ver el resultado en matriz C :) )\n");
                break;
            case 3:
                return;
        }
    }
    
    free(mA);
    free(mB);
    free(mC);
}

int main() {
    vectorDinamico V;
    vectorInicio(&V);
    int opcion;
    while (1) {
        printf("\n--- Menú Principal ---\n");
        printf("1. Jugar con vectores (strings) \n2. Jugar con matrices (multiplicar dos matrices de un tamaño especificado)\n3. Salir\nOpción: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                vectorMenu(&V);
                break;
            case 2:
                matrizMenu();
                break;
            case 3:
                freeVector(&V);
                return 0;
        }
    }
}