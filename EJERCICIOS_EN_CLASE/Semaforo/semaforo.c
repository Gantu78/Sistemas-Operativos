/**************************************************************
    Pontificia Universidad Javeriana
    Autor: Samuel Gantiva
    Profesor: J. Corredor
    Fecha: 9 Abril 2024
    Materia: Sistemas Operativos
    Tema: Semaforos
	  	  Hilos
	Descripcion: Ejemplo de uso de semaforos en C
****************************************************************/

#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>


//Semaforo mutuamente excluyente
sem_t mutex;

void* thread(){

	//Espera al semaforo
	sem_wait(&mutex);
	printf("\nEntrando..\n");
	sleep(4);
	printf("\nSaliendo...\n");
	//Libera el semaforo
	sem_post(&mutex);
}

int main()
{
	sem_init(&mutex, 0,1);
	pthread_t t1,t2;

	//Crea el primer hilo
	pthread_create(&t1,NULL,thread,NULL);

	//Espera 2 segundos para crear el segundo hilo
	sleep(2);
	pthread_create(&t2,NULL,thread,NULL);

	//Espera a que ambos hilos terminen
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	//Destruye el semaforo
	sem_destroy(&mutex);
	return 0;
}
