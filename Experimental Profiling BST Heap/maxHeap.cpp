#include <iostream>
#include <fstream>
#include "maxHeap.h"
#include <cmath>

using namespace std;

maxHeap::maxHeap(){
  heap = new int [arraySize];                                                   //allocating memory to the heap of size 500

  for(int i=0; i<arraySize; i++)                                                //initializing the values in the Heap
     heap[i] = -1;
}

maxHeap::~maxHeap(){                                                            //deallocating memory of the heap
  delete [] heap;
  heap = NULL;
}


//storing the elements in an array first
void maxHeap::storeElements(int dataInserted){
  heap[noOfElements] = dataInserted;                                            //initially putting all the elements in the array
  noOfElements++;                                                               //keeping count of element
}

//building the initial heap from text file
void maxHeap::buildHeap(){
  int parentIndex = (((noOfElements-1)-1)/5);                                   //bottom up approach to build the actual Heap
    while(parentIndex>=0){
      topDownRecur(parentIndex);                                                //top down approach to adjust the descendant
      parentIndex--;
    }
}

//recursive top down approach to adjust the descendants
void maxHeap::topDownRecur(int parentIndex){
  int maxNo=0, maxIndex;
  for(int j=1; j<=5; j++){
    int childIndex = (5*parentIndex)+j;
    if(childIndex <= arraySize && heap[childIndex] !=-1){
        if(j==1){
          maxNo = heap[childIndex];
          maxIndex = childIndex;
        }
        else if(heap[childIndex] > maxNo){
          maxNo = heap[childIndex];
          maxIndex = childIndex;
        }
    }
  }
        if(maxNo!= 0 && heap[parentIndex] < maxNo){                             //else keep adjusting till the leaf node
            int temp = heap[parentIndex];
            heap[parentIndex] = heap[maxIndex];
            heap[maxIndex] = temp;
            topDownRecur(maxIndex);
          }
}

//delete the max element from the Heap
void maxHeap::deleteMax(){
  if(heap[0]==-1)
    cout << "The Heap is already empty" << endl;
  else{
    heap[0] = heap[noOfElements-1];                                             //replace A[0] by last element in the Heap
    heap[noOfElements-1] = -1;                                                  //delete the last element

    topDownRecur(0);                                                            //top down approach to adjust the heap now
    noOfElements--;                                                             //decrease the element count by one
  }
}

//deleting the min no from the Heap
void maxHeap::deleteMin(){
  if(noOfElements==0)                                                           //if there is no element
    cout << "The Heap is already empty" << endl;
  else if(noOfElements==1){                                                     //if there is only one element in the Heap
      heap[0] = -1;
      noOfElements--;
  }
  else{
    int leafIndex =  (((noOfElements-1)-1)/5) + 1;
    int minNo     = heap[leafIndex];
    int minIndex  = leafIndex;

    while(leafIndex<=(noOfElements-1)){                                         //first find the max element from the Leaf nodes
        if(minNo>heap[leafIndex]){
            minNo = heap[leafIndex];
            minIndex = leafIndex;                                               //find its index no
        }
        leafIndex++;
      }

      if(minIndex!=(noOfElements-1)){
        heap[minIndex] = heap[noOfElements-1];
        heap[noOfElements-1] = -1;
        int data = heap[minIndex];

        int parentIndex = ((minIndex-1)/5);                                     //heaplify till the root
          while(parentIndex>=0){
            if(heap[parentIndex]<data){
              heap[minIndex] = heap[parentIndex];
              if(parentIndex==0){
                  heap[parentIndex] = data;
                  break;
              }

              minIndex = parentIndex;
              parentIndex = (parentIndex-1)/5;
            }
            else{                                                               //if it bigger then now insert the new element
                heap[minIndex] = data;
                break;
              }
        }
      }
      else
        heap[minIndex] = -1;

        noOfElements--;                                                         //decrease the element count by one
   }
}

//reset the Heap after all its operation
void maxHeap::clear(){
  for(int i=0; i<noOfElements; i++)
     heap[i] = -1;

    noOfElements = 0;
}
