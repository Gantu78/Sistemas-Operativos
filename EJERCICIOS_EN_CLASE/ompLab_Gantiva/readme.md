# Proyecto OpenMP - Sistemas Operativos

## Descripción
Este repositorio contiene un proyecto desarrollado para la asignatura de Sistemas Operativos en la Pontificia Universidad Javeriana. El proyecto demuestra el uso básico de OpenMP para configuraciones de hilos y cálculos paralelos. El código original (`ompLabGantiva.c`) ha sido modularizado en una interfaz (`ompLab.h`), una biblioteca (`ompLab.c`) y un programa principal (`main.c`). El cálculo de la variable `b` ha sido corregido para evitar condiciones de carrera.

## Estructura del Repositorio
- `ompLab.h`: Interfaz con las declaraciones de las funciones.
- `ompLab.c`: Biblioteca con las implementaciones de las funciones.
- `main.c`: Programa principal que utiliza las funciones de la biblioteca.
- `Makefile`: Archivo para compilar y gestionar el proyecto.
- `README.md`: Este archivo con la documentación del proyecto.

## Requisitos
- Compilador GCC con soporte para OpenMP.
- Sistema operativo compatible con OpenMP (Linux, macOS, o Windows con WSL).

## Instrucciones de Compilación
1. Clona el repositorio o copia los archivos en tu directorio de trabajo.
2. Ejecuta el siguiente comando para compilar:
   make
3. Ejecuta el programa con un número de hilos como argumento:
    bash
    ./ompLab 4
4. Para limpiar los archivos generados:
    bash
    make clean

Resultados Esperados

    El programa imprime el número máximo de hilos disponibles y el número de hilos configurados.
    Realiza un cálculo paralelo y muestra los valores de las variables a y b.
    El valor de b ahora es correcto: 1049 (calculado como a + (N-1)), gracias al uso de una sección crítica para evitar condiciones de carrera.

Conclusiones

    El programa demuestra el uso básico de OpenMP para gestionar hilos.
    La corrección del cálculo de b asegura que el valor sea el esperado (1049), usando una sección crítica.
    Este cálculo no aprovecha plenamente el paralelismo, ya que solo necesitamos el valor de la última iteración. Una reducción sería más útil para un cálculo acumulativo.
    La modularización facilita la reutilización y mantenimiento del código.

Autor

    Samuel Gantiva
    Fecha: 22 de mayo de 2025
    Materia: Sistemas Operativos
    Institución: Pontificia Universidad Javeriana