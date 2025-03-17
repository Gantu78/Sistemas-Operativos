#ifndef __MATRIZM_
#define __MATRIZM_

/**********************************************
* Autor: Samuel Gantiva
* Institución: Pontificia Universidad Javeriana
* Fecha: 13/02/2025 (Archivo hecho en clase)
* Clase: Sistemas Operativos
* Tema: Memoria dinámica y programación modular
* Descripción: Interfaz para funciones de manejo de matrices
***********************************************/

// Inicializa dos matrices con valores predefinidos
void iniMatriz(int *M1, int *M2, int N);
// Imprime una matriz en formato legible
void printMatriz(int *M, int N);
// Multiplica dos matrices y guarda el resultado en una tercera
void multMatriz(int *M1, int *M2, int *M3, int N);

#endif