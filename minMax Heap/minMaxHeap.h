#ifndef MINMAXHEAP_H
#define MINMAXHEAP_H


class minMaxHeap
{
    public:
      minMaxHeap();                                                             //allocate memory to the Heap
      ~minMaxHeap();                                                            //deallocate memory from the Heap
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

      void bottomUp(int parentIndex);                                           //bottom up apprach to build the heap
      void updateAncestors(int presentIndex, int grandIndex);                   //update the ancestors of the newly inserted element
      void updateDescendantsMin(int currHole, int x);                           //recursive deleteMin by updating the heap rooted at the root
      void updateDescendantsMax(int currHole, int x);                           //recursive deleteMax by updating the heap rooted at one of the children
};

#endif
