GCC = gcc
CFLAGS = -fopenmp -Wall
TARGET = ompLab

all: $(TARGET)

$(TARGET): main.o ompLab.o
	$(GCC) $(CFLAGS) -o $(TARGET) main.o ompLab.o

main.o: main.c ompLab.h
	$(GCC) $(CFLAGS) -c main.c

ompLab.o: ompLab.c ompLab.h
	$(GCC) $(CFLAGS) -c ompLab.c

clean:
	rm -f *.o $(TARGET)
