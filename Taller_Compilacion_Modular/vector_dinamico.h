#ifndef __VECTOR_DINAMICO_H_
#define __VECTOR_DINAMICO_H_

/**********************************************
* Autor: Samuel Gantiva
* Institución: Pontificia Universidad Javeriana
* Fecha: 16/03/2025
* Clase: Sistemas operativos
* Tema: Vectores dinámicos y programación modular
* Descripción: Interfaz para funciones de manejo de vectores dinámicos
***********************************************/

typedef struct vectorDinamico {
    int capacidad;         // Capacidad máxima del vector
    int totalElementos;    // Número actual de elementos
    void **elementos;      // Arreglo de punteros a elementos
} vectorDinamico;

// Inicializa un vector dinámico con capacidad inicial
void vectorInicio(vectorDinamico *V);
// Devuelve el número total de elementos
int totalVector(vectorDinamico *V);
// Añade un elemento al vector, redimensionando si es necesario
void addVector(vectorDinamico *V, void *elemento);
// Libera la memoria del vector
void freeVector(vectorDinamico *V);
// Obtiene un elemento en un índice dado
void *getVector(vectorDinamico *V, int indice);
// Establece un elemento en un índice dado
void setVector(vectorDinamico *V, int indice, void *elemento);
// Borra un elemento en un índice dado y ajusta el vector
void borrarVector(vectorDinamico *V, int indice);
//Imprime el vector
void imprimirVector(vectorDinamico *V);

#endif