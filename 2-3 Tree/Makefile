output: main.o
	g++ -std=c++11 main.o twoThreeClass.o -o output

main.o:	main.cpp twoThreeClass.o
	g++ -std=c++11 -c main.cpp

twoThreeClass.o: twoThreeClass.cpp twoThreeClass.h
	g++ -std=c++11 -c twoThreeClass.cpp

clean:
	rm *o output

