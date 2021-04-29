OBJ := main.o Cube.o Cylinder.o

STLLINKER: $(OBJ)
	g++ $(OBJ) -o stllinker

Cylinder.o: Cylinder.cc Cylinder.hh
	g++ -c Cylinder.cc

Cube.o: Cube.cc Cube.hh
	g++ -c Cube.cc
	
main.o: main.cc Cube.hh Cylinder.hh
	g++ -c main.cc
clean:
	rm *.o stllinker
