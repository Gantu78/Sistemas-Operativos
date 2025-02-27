#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv){
	int var = 480;
	int *varPtr = &var;
	int **doublePtr = &varPtr;
	printf("Valor de la variable \t\t= %d\n",var);
	printf("Valor del puntero \t\t= %d\n",*varPtr);
	printf("Valor del puntero doble \t= %d\n",**doublePtr);
	printf("Dirección de la variable \t= %p\n",&var);
	printf("Dirección del puntero \t\t= %p\n",&varPtr);
	printf("Valor en el puntero \t\t= %p\n",varPtr);
	printf("Dirección del puntero doble \t= %p\n", *doublePtr);
	printf("Valor en el puntero doble \t= %p\n", doublePtr);

	return 0;
}
