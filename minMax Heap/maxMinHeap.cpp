#include <iostream>
#include <fstream>
#include "maxMinHeap.h"
#include <cmath>

using namespace std;

maxMinHeap::maxMinHeap(){
  heap = new int [500];                                                         //allocating memory to the heap of size 500

  for(int i=0; i<500; i++)                                                      //initializing the values in the Heap
     heap[i] = -1;

}

maxMinHeap::~maxMinHeap(){
  delete [] heap;                                                               //deallocating memory of the heap
  heap = NULL;
}

//building the initial heap from text file
void maxMinHeap::buildHeap(){
  ifstream dataFile("data.txt");
  while(dataFile >> dataInserted){
    insertData(dataInserted);                                                   //using the insert operation to build the heap
  }
}

//inserting elements into the heap
void maxMinHeap::insertData(int dataInserted){
  noOfElements++;
  heap[noOfElements] = dataInserted;                                            //insert at the end of the array

  if(noOfElements!=1){                                                          //if there are more than 1 element in the heap
    int parentIndex = (noOfElements/2);                                         //find the parent of the new element
    int k = log2(parentIndex);

    if(dataInserted<heap[parentIndex]){                                         //if the dataInserted < its parent
      if(k%2!=0)                                                                //and if the parent is a max node
        updateAncestors(noOfElements, parentIndex);                             //then check all the max nodes from parent till root
      else{                                                                     //if the parent is a min node
        int grandParent = (noOfElements/4);
        if(grandParent>0)
          updateAncestors(noOfElements, grandParent);                           //then check all the min nodes from grandparent till root
      }
    }
    else{                                                                       //if the dataInserted > its parent
        if(k%2==0)                                                              //and if the parent is a min node
          updateAncestors(noOfElements,parentIndex);                            //then check all the min nodes from parent till root
        else{                                                                   //if the parent is a max node
          int grandParent = (noOfElements/4);
          if(grandParent>0)
            updateAncestors(noOfElements, grandParent);                         //then check all the max nodes from grandparent till root
        }
    }
  }
}

//update the ancestors of the new element till the root
void maxMinHeap::updateAncestors(int presentIndex, int grandIndex){
  int grandParent = (grandIndex/4);
  int k = log2(grandIndex);

  if(k%2!=0){
    if(heap[presentIndex]<heap[grandIndex]){                                    //if the element is less than its parent
      int temp = heap[presentIndex];                                            //then update all the min nodes till root
      heap[presentIndex] = heap[grandIndex];
      heap[grandIndex] = temp;
      if(grandParent>0)
        updateAncestors(grandIndex,grandParent);
    }
  }
  else{                                                                         //if the element is greater than its parent
    if(heap[presentIndex]>heap[grandIndex]){                                    //then update all the max nodes till root
      int temp = heap[presentIndex];
      heap[presentIndex] = heap[grandIndex];
      heap[grandIndex] = temp;
      if(grandParent>0)
        updateAncestors(grandIndex,grandParent);
    }
  }
}

//deleting the max element from the heap
void maxMinHeap::deleteMax(){
  if(heap[1]==-1)                                                               //if the heap is already empty
    cout << "The Heap is already empty" << endl;
  else if(noOfElements==1){                                                     //if the heap has one element
    heap[1] = -1;
    noOfElements--;
    cout << "Max no has been deleted"  << endl;
  }
  else if(noOfElements==2){                                                     //if the heap has two elements
    heap[1] = heap[2];                                                          //replace the root with the only children
    heap[2] =-1;
    noOfElements--;
    cout << "Max no has been deleted"  << endl;
  }
  else{                                                                         //if the heap has more than two nodes
    heap[1] = -1;
    updateDescendantsMax(1,heap[noOfElements]);
    heap[noOfElements] = -1;
    noOfElements--;
    cout << "Max no has been deleted"  << endl;
  }
}

//recursively update the heap rooted at root till its leaf node
void maxMinHeap::updateDescendantsMax(int currHole, int x){
    int s, maxIndex;
    int grandChild = (4*currHole);

    if(heap[grandChild]==-1){                                                   //find the second largest element from children or grandchildren
      int child = (2*currHole);
      if(heap[child]!=-1 && heap[child+1]==-1){
          s = heap[child];
          maxIndex = child;
      }
      else if(heap[child]==-1)
        s = -1;
      else if(heap[child]>heap[child+1]){
          s = heap[child];
          maxIndex = child;
      }
      else{
          s = heap[child+1];
          maxIndex = (child+1);
      }
    }
    else{
      s = heap[grandChild];
      maxIndex = grandChild;
      while(grandChild < ((4*currHole)+4)){
        if(heap[grandChild]!= -1 && s<heap[grandChild]){
          s = heap[grandChild];
          maxIndex = grandChild;
        }
        grandChild++;
      }
    }

    if(x>=s || s==-1)                                                           //if the last element in the heap is greater than the second smallest element
      heap[currHole] = x;                                                       //then replace the root with the last element
    else{                                                                       //else
      heap[currHole] = s;                                                       //replace the root with the second largest element
      heap[maxIndex] = -1;

      int child = (2*currHole);
        if(maxIndex==child || maxIndex==(child+1))
          heap[maxIndex] = x;
        else{
          int parent = (maxIndex/2);                                            //find the parent of the largest element
          if(x>heap[parent])                                                    //if the last element is greater than the parent
            updateDescendantsMax(maxIndex,x);                                    //recursively update the heap rooted at the largest element
          else{
            int temp = heap[parent];
            heap[parent] = x;
            updateDescendantsMax(maxIndex,temp);                                //recursively update the heap rooted at the largest element with the parent
          }
        }
      }
  }

//deleting the min element from the heap
void maxMinHeap::deleteMin(){                                                   //using the same deleteMax operation but rooted at one of the children
  if(heap[1]==-1)
    cout << "The Heap is already empty" << endl;
  else if(noOfElements==1){
    heap[1] = -1;
    noOfElements--;
    cout << "Min no has been deleted"  << endl;
  }
  else if(noOfElements==2){
    heap[2] =-1;
    noOfElements--;
    cout << "Min no has been deleted"  << endl;
  }
  else{
    if(heap[2]<heap[3]){
      heap[2] = -1;
      updateDescendantsMin(2,heap[noOfElements]);
    }
    else{
      heap[3] = -1;
      updateDescendantsMin(3,heap[noOfElements]);
    }

    heap[noOfElements] = -1;
    noOfElements--;
    cout << "Min no has been deleted"  << endl;
  }
}

//recursively update the heap rooted at root till its leaf node
void maxMinHeap::updateDescendantsMin(int currHole, int x){
    int s, minIndex;
    int grandChild = (4*currHole);

    if(heap[grandChild]==-1){
      int child = (2*currHole);
      if(heap[child]!=-1 && heap[child+1]==-1){
          s = heap[child];
          minIndex = child;
      }
      else if(heap[child]==-1)
        s = -1;
      else if(heap[child]<heap[child+1]){
          s = heap[child];
          minIndex = child;
      }
      else{
          s = heap[child+1];
          minIndex = (child+1);
      }
    }
    else{
      s = heap[grandChild];
      minIndex = grandChild;
      while(grandChild < ((4*currHole)+4)){
        if(heap[grandChild]!= -1 && s>heap[grandChild]){
          s = heap[grandChild];
          minIndex = grandChild;
        }
        grandChild++;
      }
    }

    if(x<=s || s==-1)
      heap[currHole] = x;
    else{
      heap[currHole] = s;
      heap[minIndex] = -1;

        int child = (2*currHole);
        if(minIndex==child || minIndex==(child+1))
          heap[minIndex] = x;
        else{
          int parent = (minIndex/2);
          if(x<=heap[parent])
            updateDescendantsMin(minIndex,x);
          else{
            int temp = heap[parent];
            heap[parent] = x;
            updateDescendantsMin(minIndex,temp);
          }
        }
      }
  }

//finding max element from the Heap
int maxMinHeap::findMax(){
  return heap[1];                                                               //just return A[1] for min Heap
}

//finding the max element from the Heap
int maxMinHeap::findMin(){
  if(heap[2]==-1)                                                               //if there is only one element in the Heap
    return heap[1];                                                             //root is the min element
  else if(heap[3]==-1)                                                          //if there is only two element in the Heap
    return heap[2];                                                             //first child is the min element
  else {
    if(heap[2]>heap[3])
      return heap[3];                                                           //return the max no from one of the children
    else
      return heap[2];
  }
}

//traversing the heap by levelOrder
void maxMinHeap::levelOrder(){
  int arrayIndex = 1, i=0, count = 0;
  if(heap[arrayIndex]==-1)
    cout << "The Heap is empty" << endl;
  else{
    while(heap[arrayIndex]!=-1){
      cout << heap[arrayIndex] << " " ;                                         //print per level
      int k = pow(2,i);
      if (count%k==0){
        cout << "\n";
        i++;
        count = 0;
      }
      if(arrayIndex>4 && count >0 && count%2==0)
        cout << " || ";
    arrayIndex++;
    count ++;
    }
  }
}

//reset the Heap after all its operation
void maxMinHeap::clear(){
  for(int i=1; i<noOfElements; i++)
     heap[i] = -1;

    noOfElements = 0;
}
