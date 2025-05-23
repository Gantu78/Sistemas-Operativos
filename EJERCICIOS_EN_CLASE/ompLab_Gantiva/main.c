/***********************************************************
 * Pontificia Universidad Javeriana
 * Fecha: 22 de mayo de 2025
 * Autor: Samuel Gantiva
 * Materia: Sistemas Operativos
 * Tópico: Uso de OpenMP
 * Descripción: Este archivo contiene el programa principal que
 *              demuestra el uso de OpenMP para configuraciones
 *              de hilos y cálculos paralelos.
 ************************************************************/

#include "ompLab.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Entrada por consola \n\t $./ejecutable NumHilos\n");
        exit(0);
    }

    int hilos = (int)atoi(argv[1]);
    int a = 50;
    int b = 0;
    const int N = 1000;

    // Inicializa la configuración paralela
    initializeParallel(hilos);

    // Realiza el cálculo paralelo
    parallelSum(a, &b, N);

    // Imprime los resultados
    printf("El valor de a = %d \t el valor de b = %d (se espera 50 y 1049)\n", a, b);

    return 0;
}

/***********Conclusiones*************
 * - El programa ahora calcula correctamente b como a + (N-1) usando una
 *   sección crítica para evitar condiciones de carrera.
 * - El valor esperado de b es 1049, que coincide con la última iteración.
 * - Este cálculo no aprovecha el paralelismo de manera significativa, ya que
 *   solo necesitamos el valor de la última iteración. Una reducción sería más
 *   útil para un cálculo acumulativo.
 *************************************/
