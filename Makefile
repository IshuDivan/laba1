all: laba clean
laba: main.o funclaba1.o 
	g++ main.o funclaba1.o -o laba
main.o: main.cpp
	g++ -c main.cpp
funclaba1.o: funclaba1.cpp
	g++ -c funclaba1.cpp
clean:
	rm -rf *.o laba

