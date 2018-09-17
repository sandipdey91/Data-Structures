output: main.o
	g++ -std=c++11 main.o list.o -o output

main.o: main.cpp list.o
	g++ -std=c++11 -c main.cpp

list.o: list.cpp list.h
	g++ -std=c++11 -c list.cpp

clean:
	rm *o output
