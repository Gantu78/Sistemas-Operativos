#!/usr/bin/perl

#**************************************************************
#                       Pontificia Universidad Javeriana
#     Materia: Sistemas Operativos
#     Autor: Samuel Gantiva
#     Fichero: Lanzador de procesos por lotes
#         Descripcion: Automatización de ejecuciones para obtención de 30 resultados
#			de ejecuciones de los benchmarks con diferentes configuraciones
#			con el propósito de hacer experimentos
#			de caracter científico (fiabilidad y precisión)
#
#			El programa lanza el ejecutable con los argumentos
#                       de tamaño de matriz y número de hilos.
#                       Se lanza el ejecutable tantas veces como se
#                       indique en la variable $Repeticiones.
#                       Se guarda la salida en un fichero con el nombre
#                       del ejecutable seguido del tamaño de matriz y
#                       el número de hilos.
#****************************************************************/

$Path = `pwd`;
chomp($Path);

@Nombre_Ejecutable = ("mm_hilos");

@Size_Matriz = (500,1000,2000);

@Num_Hilos = (1,2,4);

$Repeticiones = 30;

foreach $Nombre_Ejecutable (@Nombre_Ejecutable) {
    foreach $size (@Size_Matriz) {
        foreach $hilo (@Num_Hilos) {

           $file = "$Path/$Nombre_Ejecutable-".$size."-Hilos-".$hilo.".dat";

            for ($i = 0; $i < $Repeticiones; $i++) {

                system("$Path/$Nombre_Ejecutable $size $hilo  >> $file");

                printf("$Path/$Nombre_Ejecutable $size $hilo \n");
            }

            close($file);

            $p = $p + 1;
        }
    }
}
