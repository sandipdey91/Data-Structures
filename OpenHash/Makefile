output: main.o
	g++ -std=c++11 main.o openhash.o -o output

main.o:	main.cpp openhash.o
	g++ -std=c++11 -c main.cpp

openhash.o: openhash.cpp openhash.h
	g++ -std=c++11 -c openhash.cpp

clean:
	rm *o output
