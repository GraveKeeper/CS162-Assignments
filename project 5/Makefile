all: main

main: CarList.o CarType.o project4.o
	g++ project4.o CarList.o CarType.o -o main
project4.o: project4.cpp
	g++ -c project4.cpp
CarType.o: CarType.cpp
	g++ -c CarType.cpp
CarList.o: CarList.cpp
	g++ -c CarList.cpp
clean:
	rm *o main
