
#include <stdio.h>
#include <stdlib.h>

double promedio(double *vector, int n) {
  double total;
  for (int i = 0; i < n; i++) {
      total += vector[i];
  }
  return total / n;
}

int main(int argc, char *argv[]) {

    
  int n = atoi(argv[1]);

  // Variables para almacenar los valores
  double *vectorPunteros = (double *)malloc(n * sizeof(double));

  for (int i = 0; i < n; i++) {
      vectorPunteros[i] = (double) atoi(argv[i + 2]);
  }

  // Calcular el promedio
  double prom= promedio(vectorPunteros, n);
    printf("El promedio es %f\n",prom);

    free(vectorPunteros);

  return 0;
}
