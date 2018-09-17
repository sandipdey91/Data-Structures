#ifndef MINLEFTIST_H
#define MINLEFTIST_H
#include "node.h"


class minLeftist{
    public:
      minLeftist();                                                             //allocate memory to the Heap
      ~minLeftist();                                                            //deallocate memory from the Heap
      void buildHeap();                                                         //build the initial heap from file
      void insertData(int dataInserted);                                        //insert data into the Heap
      void deleteMin();                                                         //delete the min element from the Heap
      void findMin();                                                           //find the min element from the Heap
      void inOrder();                                                           //InOrder trversal to display the Heap
      void preOrder();                                                          //PreOrder trversal to display the Heap
      void levelOrder();                                                        //LevelOrder trversal to display the Heap
      void clear();                                                             //reset the Heap after all operation


    private:

      int dataInserted;
      node *rootPtr, *travPtr;

      struct nodeList{                                                          //structure of each node in queue
            node        *item;
            nodeList    *next;
            };


      node* concat(node* H1, node* H2);                                         //merge the two heaps
      void updateRank(node* H);                                                 //update the rank of each node after attachment
      void preOrderRecur(node* travptr);                                        //recursive function for preOrder traversal
      void inOrderRecur(node* travptr);                                         //recursive function for inOrder traversal
      void destructMem(node *travPtr);                                          //destruct all the memory for each node
};
#endif
