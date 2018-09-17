#include <iostream>
#include <fstream>
#include "minMaxHeap.h"
#include <cmath>

using namespace std;

minMaxHeap::minMaxHeap(){
  heap = new int [500];                                                         //allocating memory to the heap of size 500

  for(int i=0; i<500; i++)                                                      //initializing the values in the Heap
     heap[i] = -1;

}

minMaxHeap::~minMaxHeap(){
  delete [] heap;                                                               //deallocating memory of the heap
  heap = NULL;
}

//building the initial heap from text file
void minMaxHeap::buildHeap(){
  ifstream dataFile("data.txt");
  while(dataFile >> dataInserted){
    noOfElements++;
    heap[noOfElements] = dataInserted;                                          //initially putting all the elements in the array
  }

  int parentIndex = (noOfElements/2);                                           //find the first parent index from bottom
  while(parentIndex>0){
    bottomUp(parentIndex);                                                      //pass the parent index to the recursive function
    parentIndex--;                                                              //bottom up approach to build the actual Heap
  }
}

//recursive bottom up approach to adjust the descendants of the parent
void minMaxHeap::bottomUp(int parentIndex){
  int grandChild = (4*parentIndex);
  int k = log2(parentIndex);                                                    //determine if the parent is a min node or max node
    if(heap[grandChild]==-1){                                                   //if the parent has no grand children
      int child = (2*parentIndex);
      if(heap[child]!=-1){                                                      //if the parent is not a leaf node
        if(heap[child+1]==-1){                                                  //if it has one child at least
          if(k%2==0){                                                           //if parent is min node
            if(heap[parentIndex]>heap[child]){                                  //then swap with the lowest element in children
              int temp = heap[parentIndex];
              heap[parentIndex] = heap[child];
              heap[child] = temp;
            }
          }
          else{                                                                 //if parent is a max node
            if(heap[parentIndex]<heap[child]){                                  //then swap with the highest element in children
              int temp = heap[parentIndex];
              heap[parentIndex] = heap[child];
              heap[child] = temp;
            }
          }
        }
        else{                                                                   //if parent has two children
          if(k%2==0){                                                           //and it is a min node
            if(heap[child]<heap[child+1]){                                      //find the smallest children and swap with the parent
              if(heap[child]<heap[parentIndex]){
                int temp = heap[parentIndex];
                heap[parentIndex] = heap[child];
                heap[child] = temp;
              }
            }
            else{
              if(heap[child+1]<heap[parentIndex]){
                int temp = heap[parentIndex];
                heap[parentIndex] = heap[child+1];
                heap[child+1] = temp;
              }
            }
          }
          else{                                                                 //if parent is a max node
            if(heap[child]>heap[child+1]){
              if(heap[child]>heap[parentIndex]){                                //find the largest children and swap with the parent
                int temp = heap[parentIndex];
                heap[parentIndex] = heap[child];
                heap[child] = temp;
              }
            }
            else{
              if(heap[child+1]>heap[parentIndex]){
                int temp = heap[parentIndex];
                heap[parentIndex] = heap[child+1];
                heap[child+1] = temp;
              }
            }
          }
        }
      }
    }
    else{                                                                       //if the parent has grand children
      int index = grandChild;
      while(grandChild < ((4*parentIndex)+4)){
        if(k%2==0){                                                             //if the parent is a min node
          if(heap[index]>heap[grandChild])                                      //then find the smallest element from the grand children
            index = grandChild;
        }
        else{                                                                   //else if it is a max node
          if(heap[index]<heap[grandChild])                                      //then find the largest element from the grand children
            index = grandChild;
        }
        grandChild++;
      }
      if(k%2==0){                                                               //if the parent is a min node
        if(heap[parentIndex]>heap[index]){                                      //then swap with the smallest element from grand children
          int temp = heap[parentIndex];
          heap[parentIndex] = heap[index];
          heap[index] = temp;

          int pIndex = index/2;                                                 //after swapping check the current parent which will be a max node
          if(heap[pIndex]<heap[index]){                                         //if the parent is smaller then swap with the parent
            int temp = heap[index];
            heap[index] = heap[pIndex];
            heap[pIndex] = temp;
          }
        }
      }
      else{                                                                     //if the parent is a max node
        if(heap[parentIndex]<heap[index]){                                      ////then swap with the largest element from grand children
          int temp = heap[parentIndex];
          heap[parentIndex] = heap[index];
          heap[index] = temp;

          int pIndex = index/2;                                                 //after swapping check the current parent which will be a min node
          if(heap[pIndex]>heap[index]){                                         //if the parent is larger then swap with the parent
            int temp = heap[index];
            heap[index] = heap[pIndex];
            heap[pIndex] = temp;
          }
        }
      }
      bottomUp(index);                                                          //adjust the heap recursively rooted at the grand children position now
    }
}


//inserting elements into the heap
void minMaxHeap::insertData(int dataInserted){
  noOfElements++;
  heap[noOfElements] = dataInserted;                                            //insert at the end of the array

  if(noOfElements!=1){                                                          //if there are more than 1 element in the heap
    int parentIndex = (noOfElements/2);                                         //find the parent of the new element
    int k = log2(parentIndex);

    if(dataInserted<heap[parentIndex]){                                         //if the dataInserted < its parent
      if(k%2==0)                                                                //and if the parent is a min node
        updateAncestors(noOfElements, parentIndex);                             //then check all the min nodes from parent till root
      else{                                                                     //if the parent is a max node
        int grandParent = (noOfElements/4);
        if(grandParent>0)
          updateAncestors(noOfElements, grandParent);                           //then check all the min nodes from grandparent till root
      }
    }
    else{                                                                       //if the dataInserted > its parent
        if(k%2!=0)                                                              //and if the parent is a max node
          updateAncestors(noOfElements,parentIndex);                            //then check all the max nodes from parent till root
        else{                                                                   //if the parent is a min node
          int grandParent = (noOfElements/4);
          if(grandParent>0)
            updateAncestors(noOfElements, grandParent);                         //then check all the min nodes from grandparent till root
        }
    }
  }
}

//update the ancestors of the new element till the root
void minMaxHeap::updateAncestors(int presentIndex, int grandIndex){
  int grandParent = (grandIndex/4);
  int k = log2(grandIndex);

  if(k%2==0){                                                                   //if the element is less than its parent
    if(heap[presentIndex]<heap[grandIndex]){                                    //then update all the min nodes till root
      int temp = heap[presentIndex];
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

//deleting the min element from the heap
void minMaxHeap::deleteMin(){
  if(heap[1]==-1)                                                               //if the heap is already empty
    cout << "The Heap is already empty" << endl;
  else if(noOfElements==1){                                                     //if the heap has one element
    heap[1] = -1;                                                               //just delete the root
    noOfElements--;
    cout << "Min no has been deleted" << endl;
  }
  else if(noOfElements==2){                                                     //if the heap has two elements
    heap[1] = heap[2];                                                          //replace the root with the only children
    heap[2] =-1;
    noOfElements--;
    cout << "Min no has been deleted" << endl;
  }
  else{                                                                         //if the heap has more than two nodes
    heap[1] = -1;
    updateDescendantsMin(1,heap[noOfElements]);
    heap[noOfElements] = -1;
    noOfElements--;
    cout << "Min no has been deleted" << endl;
  }
}

//recursively update the heap rooted at root till its leaf node
void minMaxHeap::updateDescendantsMin(int currHole, int x){
    int s, minIndex;
    int grandChild = (4*currHole);

    if(heap[grandChild]==-1){                                                   //find the second smallest element from children or grandchildren
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


    if(x<=s || s==-1)                                                           //if the last element in the heap is smaller than the second smallest element
      heap[currHole] = x;                                                       //then replace the root with the last element
    else{                                                                       //else
      heap[currHole] = s;                                                       //replace the root with the second smallest element
      heap[minIndex] = -1;

      int child = (2*currHole);
      if(minIndex==child || minIndex==(child+1))
          heap[minIndex] = x;
      else{
        int parent = (minIndex/2);                                              //find the parent of the smallest element
        if(x<=heap[parent])                                                     //if the last element is smaller than the parent
          updateDescendantsMin(minIndex,x);                                     //recursively update the heap rooted at the smallest element
        else{
          int temp = heap[parent];
          heap[parent] = x;
          updateDescendantsMin(minIndex,temp);                                  //recursively update the heap rooted at the smallest element with the parent
        }
      }
    }
}

//deleting the max element from the heap
void minMaxHeap::deleteMax(){                                                   //using the same deleteMin operation but rooted at one of the children
  if(heap[1]==-1)
    cout << "The Heap is already empty" << endl;
  else if(noOfElements==1){
    heap[1] = -1;
    noOfElements--;
    cout << "Max no has been deleted"  << endl;
  }
  else if(noOfElements==2){
    heap[2] =-1;
    noOfElements--;
    cout << "Max no has been deleted"  << endl;
  }
  else{
    if(heap[2]>heap[3]){
      heap[2] = -1;
      updateDescendantsMax(2,heap[noOfElements]);
    }
    else{
      heap[3] = -1;
      updateDescendantsMax(3,heap[noOfElements]);
    }

    heap[noOfElements] = -1;
    noOfElements--;
    cout << "Max no has been deleted"  << endl;
  }
}

//recursively update the heap rooted at root till its leaf node
void minMaxHeap::updateDescendantsMax(int currHole, int x){
   int s, maxIndex;
   int grandChild = (4*currHole);

   if(heap[grandChild]==-1){
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

   if(x>=s || s==-1)
     heap[currHole] = x;
   else{
     heap[currHole] = s;
     heap[maxIndex] = -1;

       int child = (2*currHole);
       if(maxIndex==child || maxIndex==(child+1))
         heap[maxIndex] = x;
       else{
         int parent = (maxIndex/2);
         if(x>heap[parent])
           updateDescendantsMax(maxIndex,x);
         else{
           int temp = heap[parent];
           heap[parent] = x;
           updateDescendantsMax(maxIndex,temp);
         }
       }
     }
 }

//finding min element from the Heap
int minMaxHeap::findMin(){
  return heap[1];                                                               //just return A[1] for min Heap
}

//finding the max element from the Heap
int minMaxHeap::findMax(){
  if(heap[2]==-1)                                                               //if there is only one element in the Heap
    return heap[1];                                                             //root is the max element
  else if(heap[3]==-1)                                                          //if there is only two element in the Heap
    return heap[2];                                                             //first child is the max element
  else {
    if(heap[2]>heap[3])
      return heap[2];                                                           //return the max no from one of the children
    else
      return heap[3];
  }
}

//traversing the heap by levelOrder
void minMaxHeap::levelOrder(){
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
      if(arrayIndex>4 && count >> 0 && count%2==0)
        cout << " || ";
    arrayIndex++;
    count ++;
    }
  }
}

//reset the Heap after all its operation
void minMaxHeap::clear(){
  for(int i=1; i<noOfElements; i++)
     heap[i] = -1;

    noOfElements = 0;
}
