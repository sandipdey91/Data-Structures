#include <iostream>
#include <fstream>
#include "minHeap.h"
#include <cmath>

using namespace std;

minHeap::minHeap(){
  heap = new int [arraySize];                                                    //allocating memory to the heap of size 500

  for(int i=0; i<arraySize; i++)                                                 //initializing the values in the Heap
     heap[i] = -1;

}

minHeap::~minHeap(){
  delete [] heap;                                                               //deallocating memory of the heap
  heap = NULL;
}

//storing the elements in an array first
void minHeap::storeElements(int dataInserted){
  heap[noOfElements] = dataInserted;                                            //initially putting all the elements in the array
  noOfElements++;                                                               //keeping count of element
}

//building the initial heap from text file
void minHeap::buildHeap(){
  int parentIndex = (((noOfElements-1)-1)/5);                                   //bottom up approach to build the actual Heap
    while(parentIndex>=0){
      topDownRecur(parentIndex);                                                //top down approach to adjust the descendants
      parentIndex--;
    }
}

//recursive top down approach to adjust the descendants
void minHeap::topDownRecur(int parentIndex){
  int minNo=0, minIndex;
  for(int j=1; j<=5; j++){
    int childIndex = (5*parentIndex)+j;
    if(childIndex <= arraySize && heap[childIndex] !=-1){
        if(j==1){
          minNo = heap[childIndex];
          minIndex = childIndex;
        }
        else if(heap[childIndex] < minNo){
          minNo = heap[childIndex];
          minIndex = childIndex;
        }
    }
  }
        if(minNo!= 0 && heap[parentIndex] > minNo){                             //else keep adjusting till the leaf node
            int temp = heap[parentIndex];
            heap[parentIndex] = heap[minIndex];
            heap[minIndex] = temp;
            topDownRecur(minIndex);
          }
}

//delete the min element from the Heap
void minHeap::deleteMin(){
  if(heap[0]==-1)
    cout << "The Heap is already empty" << endl;
  else{
    heap[0] = heap[noOfElements-1];                                             //replace A[0] by last element in the Heap
    heap[noOfElements-1] = -1;                                                  //delete the last element

    topDownRecur(0);                                                            //top down approach to adjust the heap now
    noOfElements--;                                                             //decrease the element count by one
  }
}

//deleting the max no from the Heap
void minHeap::deleteMax(){
  if(noOfElements==0)                                                           //if there is no element
    cout << "The Heap is already empty" << endl;
  else if(noOfElements==1){                                                     //if there is only one element in the Heap
      heap[0] = -1;
      noOfElements--;
  }
  else{
    int leafIndex =  (((noOfElements-1)-1)/5) + 1;
    int maxNo     = heap[leafIndex];
    int maxIndex  = leafIndex;

    while(leafIndex<=(noOfElements-1)){                                         //first find the max element from the Leaf nodes
        if(maxNo<heap[leafIndex]){
            maxNo = heap[leafIndex];
            maxIndex = leafIndex;                                               //find its index no
        }
        leafIndex++;
      }

      if(maxIndex!=(noOfElements-1)){
        heap[maxIndex] = heap[noOfElements-1];
        heap[noOfElements-1] = -1;
        int data = heap[maxIndex];

        int parentIndex = ((maxIndex-1)/5);                                     //heaplify till the root
          while(parentIndex>=0){
            if(heap[parentIndex]>data){
              heap[maxIndex] = heap[parentIndex];
              if(parentIndex==0){
                  heap[parentIndex] = data;
                  break;
              }

              maxIndex = parentIndex;
              parentIndex = (parentIndex-1)/5;
            }
            else{                                                               //if it bigger then now insert the new element
                heap[maxIndex] = data;
                break;
              }
        }
      }
      else
        heap[maxIndex] = -1;

        noOfElements--;                                                         //decrease the element count by one
   }
}

//reset the Heap after all its operation
void minHeap::clear(){
  for(int i=0; i<noOfElements; i++)
     heap[i] = -1;

    noOfElements = 0;
}
