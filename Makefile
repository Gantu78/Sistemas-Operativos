GCC = gcc
FLAGS = -lm

PROGRAMAS = matrizm

matrizm:
        $(GCC) $@.c modulo.c -o $@

clear:
        $(RM) $(PROGRAMAS)
