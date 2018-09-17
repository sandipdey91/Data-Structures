#ifndef MAXHEAP_H
#define MAXHEAP_H


class maxHeap
{
    public:
      maxHeap();                                                                //allocate memory to the Heap
      ~maxHeap();                                                               //deallocate memory from the Heap
      void buildHeap();                                                         //build the initial heap from file
      void insertData(int dataInserted);                                        //insert data into the Heap
      void deleteMin();                                                         //delete the min element from the Heap
      int findMin();                                                            //find the min element from the Heap
      int findMax();                                                            //find the max element from the Heap
      void deleteMax();                                                         //delete the max element from the Heap
      void levelOrder();                                                        //levelOrder trversal to display the Heap
      void clear();                                                             //reset the Heap after all operation

    private:
      int *heap = NULL;                                                         //heap structure in array
      int noOfElements = 0, dataInserted;

      void topDownRecur(int parentIndex);                                       //recursive function to adjust the Heap
};

#endif
