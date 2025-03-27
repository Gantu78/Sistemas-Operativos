/*******************************************************
* PONTIFICIA UNIVERSIDAD JAVERIANA
* Autor : Samuel Gantiva
* Materia: Sistemas Operativos
* Clase: 2154
* Descripción: Archivo Servidor - Productor
*
* Descripción: Este archivo es el servidor que recibe mensajes
* del cliente y responde a ellos. El servidor recibe un mensaje
* del cliente y lo invierte. El servidor termina cuando el
* cliente envía "end". El servidor utiliza un FIFO para la
* comunicación con el cliente.
*******************************************************/

#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

#define FIFO_FILE "/tmp/fifo_twoway"


//Servidor

void reverse_string(char *);
int main() {
   int fd;
   char readbuf[80];  // Bus de lectura en char, lectura de palabra hasta 80 caracteres
   char end[10];      //   Bus Palabra de fin
   int to_end;
   int read_bytes;
   
   /* Create the FIFO if it does not exist */
   mkfifo(FIFO_FILE, S_IFIFO|0640); //Crea un ducto o conducto de comunicacion
   strcpy(end, "end");              //Se copia al final del vector el string "end"
   fd = open(FIFO_FILE, O_RDWR);
   while(1) {  
      read_bytes = read(fd, readbuf, sizeof(readbuf));
      readbuf[read_bytes] = '\0';
      printf("FIFOSERVER: Received string: \"%s\" and length is %d\n", readbuf, (int)strlen(readbuf));
      to_end = strcmp(readbuf, end);
      
      if (to_end == 0) {
         close(fd);
         break;
      }
      reverse_string(readbuf);
      printf("FIFOSERVER: Sending Reversed String: \"%s\" and length is %d\n", readbuf, (int) strlen(readbuf));
      write(fd, readbuf, strlen(readbuf));
      /*
      sleep - This is to make sure other process reads this, otherwise this
      process would retrieve the message
      */
      sleep(2);
   }
   return 0;
}

void reverse_string(char *str) {
   int last, limit, first;
   char temp;
   last = strlen(str) - 1;    
   limit = last/2;
   first = 0;
   /*
   * El bucle while intercambia los caracteres de la cadena
   * de la primera mitad con los de la segunda mitad.
   * Por ejemplo, si la cadena es "abcd", el bucle intercambia
   * 'a' con 'd' y 'b' con 'c', resultando en "dcba".
   */
   while (first < last) {
      temp = str[first];      
      str[first] = str[last];
      str[last] = temp;
      first++;
      last--;
   }
   return;
}
