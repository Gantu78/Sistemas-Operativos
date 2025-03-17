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
/*Funcion para mostrar el menu para jugar con un vector de strings*/
void vectorMenu(vectorDinamico *V) {
    int opcion, indice;
    char buffer[100];
    while (1) {
        printf("\n--- Menú Vectores ---\n");
        printf("1. Añadir elemento\n2. Borrar elemento\n3. Modificar elemento\n4. Mostrar vector\n5. Volver\nOpción: "); //Mostrar las opciones en pantalla
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:                                                     //Caso para añadir elemento (opcion 1)
                printf("Ingrese texto: ");
                scanf("%s", buffer);
                addVector(V, strdup(buffer));
                break;
            case 2:                                                     //Caso para borrar elemento (opcion 2)
                printf("Índice a borrar: ");
                scanf("%d", &indice);
                borrarVector(V, indice);
                break;
            case 3:             //Caso para modificar elemento (opcion 2), necesita el indice que modificará y el texto por el que cambiará el elemento
                printf("Indice a modificar: ");
                scanf("%d", &indice);
                printf("Indique el texto: ");
                scanf("%s", buffer);
                setVector(V, indice, strdup(buffer));
                break;
            case 4:             // Caso para imprimir el vector
                imprimirVector(V);
                break;
            case 5:
                return;
        }
    }
}

/*Funcion para mostrar el menu de las matrices*/
void matrizMenu() {
    int N;
    int opcion;
    printf("Tamaño de la matriz (menor a 100): ");
    scanf("%d", &N);
    /*Inicializar matrices A,B,C, C en 0*/
    int *mA = malloc(sizeof(int) * N * N);
    int *mB = malloc(sizeof(int) * N * N);
    int *mC = calloc(N * N, sizeof(int));
    iniMatriz(mA, mB, N);
    while (2) {
        printf("\n--- Menú Matrices ---\n");
        printf("1. Imprimir matrices\n2. Multiplicar matrices para ver resultado en matriz C\n3. Volver\nOpción: "); //Imprimir opciones de menu para matrices
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:                     //Imprimirá todas las matrices, en caso de no haber multiplicado previamente la matriz C será 0 en todas sus posiciones
                printf("Matriz A:\n");
                printMatriz(mA, N);
                printf("Matriz B:\n");
                printMatriz(mB, N);
                printf("Matriz C (A x B):\n");
                printMatriz(mC, N);
                break;
            case 2:           //Caso para multiplicar las matrices y guardar el resultado en la matriz C, una vez multiplicado volver a imprimir matrices para visualizar el resultado
                multMatriz(mA, mB, mC, N);
                printf("Matrices multiplicadas correctamente (vuelve a imprimir las matrices para ver el resultado en matriz C :) )\n");
                break;
            case 3:
                return;
        }
    }
    /*Liberar memoria de todas las matrices*/
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
        printf("1. Jugar con vectores (strings) \n2. Jugar con matrices (multiplicar dos matrices de un tamaño especificado)\n3. Salir\nOpción: ");//Opciones menu principal
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:             //En caso de seleccionar la opcion 1 llamar al menu de vectores
                vectorMenu(&V);
                break;
            case 2:             //En caso de seleccionar la opcion 2 llamar al menu de matrices
                matrizMenu();
                break;
            case 3:             //En caso de salir, asegurarse de liberar la memoria del vector inicializado previamente
                freeVector(&V);
                return 0;
        }
    }
}