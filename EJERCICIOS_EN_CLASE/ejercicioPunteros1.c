#include <stdlib.h>
#include <stdio.h>

#define size 10
int main(int argc, char *argv[]){
  int *vectorPunteros[3]; //-->vector de punteros
  int p=40, q=80, r=120; // variables  tipo entero

  vectorPunteros[0] = &p; //--> puntero a p
  vectorPunteros[1] = &q; //--> puntero a q
  vectorPunteros[2] = &r; //--> puntero a r

  printf("\nForma de acceso al vector de punteros\n");
  for(int i=0; i<3; i++){
    printf("Para la dirección %p \t el valor = %d\n", vectorPunteros[i],*vectorPunteros[i]);
  }
  return 0;
}
