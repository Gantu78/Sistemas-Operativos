/*******************************************************
* PONTIFICIA UNIVERSIDAD JAVERIANA
* Autor : Samuel Gantiva
* Materia: Sistemas Operativos
* Clase: 2154
* Descripción: Archivo Cliente - Consumidor

* Descripción: Este archivo es el cliente que se conecta al servidor
* y envía mensajes. El cliente envía un mensaje al servidor y espera
* a que el servidor le envíe una respuesta. El cliente termina
* cuando el usuario ingresa "end". El cliente utiliza un FIFO
* para la comunicación con el servidor. 
*******************************************************/


/*############################

# CLIENTE
#############
*/

#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

#define FIFO_FILE "/tmp/fifo_twoway"
int main() {
   int fd;
   int end_process;
   int stringlen;
   int read_bytes;
   char readbuf[80];  // Bus de lectura en char, lectura de palabra hasta 80 caracteres
   char end_str[5];    //   Bus Palabra de fin
   printf("FIFO_CLIENT: Send messages, infinitely, to end enter \"end\"\n");
   fd = open(FIFO_FILE, O_CREAT|O_RDWR);
   strcpy(end_str, "end");
   
   while (1) {
      printf("Enter string: ");
      fgets(readbuf, sizeof(readbuf), stdin);
      stringlen = strlen(readbuf);
      readbuf[stringlen - 1] = '\0';
      end_process = strcmp(readbuf, end_str);
      
      //printf("end_process is %d\n", end_process);
      if (end_process != 0) {
         write(fd, readbuf, strlen(readbuf));
         printf("FIFOCLIENT: Sent string: \"%s\" and string length is %d\n", readbuf, (int)strlen(readbuf));
         read_bytes = read(fd, readbuf, sizeof(readbuf));
         readbuf[read_bytes] = '\0';
         printf("FIFOCLIENT: Received string: \"%s\" and length is %d\n", readbuf, (int)strlen(readbuf));
      } else {
         write(fd, readbuf, strlen(readbuf));
         printf("FIFOCLIENT: Sent string: \"%s\" and string length is %d\n", readbuf, (int)strlen(readbuf));
         close(fd);
         break;
      }
   }
   return 0;
}
