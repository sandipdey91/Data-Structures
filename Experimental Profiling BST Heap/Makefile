output: main.o
				g++ -std=c++11 main.o bstClass.o minHeap.o maxHeap.o timerClass.o -o output

main.o: main.cpp bstClass.o minHeap.o maxHeap.o timerClass.o
				g++ -std=c++11 -g -c main.cpp

bstClass.o: bstClass.cpp bstClass.h
				g++ -std=c++11 -g -c bstClass.cpp

minHeap.o: minHeap.cpp minHeap.h
				g++ -std=c++11 -g -c minHeap.cpp

maxHeap.o: maxHeap.cpp maxHeap.h
				g++ -std=c++11 -g -c maxHeap.cpp

timerClass.o: timerClass.cpp
				g++ -std=c++11 -g -c timerClass.cpp

clean:
				rm *o output
