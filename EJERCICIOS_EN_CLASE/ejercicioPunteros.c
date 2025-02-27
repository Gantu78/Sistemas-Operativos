#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
  int variable = 123;
  int *ptr = &variable;
  printf("Valor de variable: %d\n", variable);
  printf("Dirección de variable: %p\n", &variable);
  printf("Valor de ptr: %p\n", (void *)ptr);
  printf("Valor al que apunta ptr: %i\n", *ptr);

  return 0;
}
