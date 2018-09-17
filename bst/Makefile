output: main.o
	g++ -std=c++11 main.o bstClass.o -o output

main.o:	main.cpp bstClass.o
	g++ -std=c++11 -c main.cpp

bstClass.o: bstClass.cpp bstClass.h
	g++ -std=c++11 -c bstClass.cpp

clean:
	rm *o output
