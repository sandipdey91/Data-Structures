output: main.o
	g++ -std=c++11 main.o quadHash.o doubHash.o -o output

main.o:	main.cpp quadHash.o doubHash.o
	g++ -std=c++11 -c main.cpp

quadHash.o: quadHash.cpp quadHash.h
	g++ -std=c++11 -c quadHash.cpp

doubHash.o: doubHash.cpp doubHash.h
	g++ -std=c++11 -c doubHash.cpp

clean:
	rm *o output
