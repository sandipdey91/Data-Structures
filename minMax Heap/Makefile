output: main.o
	g++ -std=c++11 main.o minMaxHeap.o maxMinHeap.o -o output

main.o:	main.cpp minMaxHeap.o maxMinHeap.o
	g++ -std=c++11 -c main.cpp

minMaxHeap.o: minMaxHeap.cpp minMaxHeap.h
	g++ -std=c++11 -c minMaxHeap.cpp

maxMinHeap.o: maxMinHeap.cpp maxMinHeap.h
	g++ -std=c++11 -c maxMinHeap.cpp

clean:
	rm *o output
