/**********************************************
* Autor: Samuel Gantiva
* Institución: Pontificia Universidad Javeriana
* Fecha: 16/03/2025
* Clase: Sistemas Operativos
* Tema: Vectores dinámicos y programación modular
* Descripción: Implementación de funciones para vectores dinámicos
***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include "vector_dinamico.h"

#define CAPACIDAD_INICIAL 4


// Inicializa un vector dinámico con capacidad inicial
void vectorInicio(vectorDinamico *V) {
    V->capacidad = CAPACIDAD_INICIAL;
    V->totalElementos = 0;
    V->elementos = malloc(sizeof(void *) * V->capacidad);
}
// Devuelve el número total de elementos
int totalVector(vectorDinamico *V) {
    return V->totalElementos;
}
// Añade un elemento al vector, redimensionando si es necesario
static void resizeVector(vectorDinamico *V, int capacidad) {
    printf("Redimensión: %d a %d\n", V->capacidad, capacidad);
    void **elementos = realloc(V->elementos, sizeof(void *) * capacidad);
    if (elementos) {
        V->elementos = elementos;
        V->capacidad = capacidad;
    }
}
// Añade un elemento al vector, redimensionando si es necesario
void addVector(vectorDinamico *V, void *elemento) {
    if (V->capacidad == V->totalElementos)
        resizeVector(V, V->capacidad * 2);
    V->elementos[V->totalElementos++] = elemento;
}
// Libera la memoria del vector
void freeVector(vectorDinamico *V) {
    free(V->elementos);
}
// Obtiene un elemento en un índice dado
void *getVector(vectorDinamico *V, int indice) {
    if (indice >= 0 && indice < V->totalElementos)
        return V->elementos[indice];
    return NULL;
}
// Establece un elemento en un índice dado
void setVector(vectorDinamico *V, int indice, void *elemento) {
    if (indice >= 0 && indice < V->totalElementos)
        V->elementos[indice] = elemento;
}
// Borra un elemento en un índice dado y ajusta el vector
void borrarVector(vectorDinamico *V, int indice) {
    if (indice < 0 || indice >= V->totalElementos)
        return;
    V->elementos[indice] = NULL;
    for (int i = indice; i < V->totalElementos - 1; i++) {
        V->elementos[i] = V->elementos[i + 1];
        V->elementos[i + 1] = NULL;
    }
    V->totalElementos--;
    if (V->totalElementos > 0 && V->totalElementos == V->capacidad / 4)
        resizeVector(V, V->capacidad / 2);
}
//Imprime el vector
void imprimirVector(vectorDinamico *V){
    for (int i = 0; i < totalVector(V); i++)
                    printf("%s ", (char *)getVector(V, i));
    printf("\n");
}