OBJ := main.o Cube.o Cylinder.o

STLLINKER: $(OBJ)
	g++ -g $(OBJ) -o stllinker

Cube.o: Cube.cc Cube.hh
	g++ -g -c Cube.cc
	
Cylinder.o: Cylinder.cc Cylinder.hh
	g++ -g -c Cylinder.cc

main.o: main.cc Cube.hh Cylinder.hh
	g++ -g -c main.cc
clean:
	rm *.o stllinker
