#ifndef MAXHEAP_H
#define MAXHEAP_H


class maxHeap
{
    public:
      maxHeap();                                                                //allocate memory to the Heap
      ~maxHeap();                                                               //deallocate memory from the Heap
      void storeElements(int dataInserted);
      void buildHeap();                                                         //build the initial heap from file
      void deleteMin();                                                         //delete the min element from the Heap
      void deleteMax();                                                         //delete the max element from the Heap
      void clear();                                                             //reset the Heap after all operation

    private:
      int *heap = NULL;                                                         //heap structure in array
      int noOfElements = 0, dataInserted, arraySize = 10000000;

      void topDownRecur(int parentIndex);                                       //recursive function to adjust the Heap
};

#endif
