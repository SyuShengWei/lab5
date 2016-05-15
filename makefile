all: main.o HugeInt.o
	g++ main.o HugeInt.o  -o lab5
main.o: main.cpp HugeInt.h
	g++ -c  main.cpp
HugeInt.o: HugeInt.cpp HugeInt.h
	g++ -c  HugeInt.cpp
clean:
	rm **.o