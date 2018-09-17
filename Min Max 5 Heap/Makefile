output: main.o
	g++ -std=c++11 main.o minHeap.o maxHeap.o -o output

main.o:	main.cpp minHeap.o maxHeap.o
	g++ -std=c++11 -c main.cpp

minHeap.o: minHeap.cpp minHeap.h
	g++ -std=c++11 -c minHeap.cpp

maxHeap.o: maxHeap.cpp maxHeap.h
	g++ -std=c++11 -c maxHeap.cpp

clean:
	rm *o output
