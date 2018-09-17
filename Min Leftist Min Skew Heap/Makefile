output: main.o
	g++ -std=c++11 main.o minLeftist.o minSkew.o node.o -o output

main.o:	main.cpp minLeftist.o minSkew.o node.o
	g++ -std=c++11 -g -c main.cpp

minLeftist.o: minLeftist.cpp minLeftist.h
	g++ -std=c++11 -g -c minLeftist.cpp

minSkew.o: minSkew.cpp minSkew.h
	g++ -std=c++11 -g -c minSkew.cpp

node.o: node.cpp node.h
	g++ -std=c++11 -g -c node.cpp

clean:
	rm *o output
