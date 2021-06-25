CXX = g++
CXXFLAGS = -g3 -Wall
MKDIR = mkdir -p

LIBS = -lm

directorios:
	$(MKDIR) build dist

main.o: directorios main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o build/main.o

Venta.o: directorios Venta.cpp Venta.h
	$(CXX) $(CXXFLAGS) -c Venta.cpp -o build/Venta.o

Funciones.o: directorios Funciones.cpp Funciones.h
	$(CXX) $(CXXFLAGS) -c Funciones.cpp -o build/Funciones.o

all: clean main.o Funciones.o Venta.o
	$(CXX) $(CXXFLAGS) -o dist/programa build/main.o build/Funciones.o build/Venta.o $(LIBS)
	rm -fr build

clean:
	rm -fr *.o a.out core programa dist build
.DEFAULT_GOAL := all
