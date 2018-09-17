#include <iostream>
#include <fstream>
#include "minMaxHeap.h"
#include "maxMinHeap.h"

using namespace std;

void printDS();                                                                 //function to select one Data Structure
void printQuery();                                                              //function for all operation for one particular DS

int main(){                                                                     //driving function
  int dataInserted, inputDS, input, minNo, maxNo;

  minMaxHeap minMaxHeapObj;                                                     //object declaration for minHeap class
  maxMinHeap maxMinHeapObj;                                                     //object declaration for maxHeap class

  printDS();
  cin >> inputDS;

while (inputDS!=3) {                                                            //terminate the program if user select exit
  switch (inputDS) {
    case 1:                                                                     //minHeap
            cout << "*************************" << endl;
            cout << "MinMax 2-Heap Data Structure" << endl;
            cout << "*************************" << endl;
            minMaxHeapObj.buildHeap();
            break;
    case 2:                                                                     //maxHeap
            cout << "*************************" << endl;
            cout << "MaxMin 2-Heap Data Structure" << endl;
            cout << "*************************" << endl;
            maxMinHeapObj.buildHeap();
            break;

    default: cout << "Incorrect Input" << endl;
  }

  printQuery();                                                                 //for each Heap perform below operation
  cin >> input;
  cout << "........................" << endl;

  while (input!=7) {
    switch (input) {
      case 1: cout << "Please insert the number to be inserted" << endl;        //insert
              cin >> dataInserted;
              if (inputDS==1)
                minMaxHeapObj.insertData(dataInserted);
              else
                maxMinHeapObj.insertData(dataInserted);

              cout << "........................" << endl;
              cout << "Data Successfully Inserted" << endl;
              break;

      case 2: if (inputDS==1)                                                   //deleteMin
                minMaxHeapObj.deleteMin();
              else
                maxMinHeapObj.deleteMin();
              break;

      case 3: if (inputDS==1)                                                   //findMin
                minNo = minMaxHeapObj.findMin();
              else
                minNo = maxMinHeapObj.findMin();

              if(minNo == -1)
                cout << "The Heap is empty" << endl;
              else
                cout << "The min no in the Heap is : " << minNo << endl;
              break;

      case 4: if (inputDS==1)                                                   //findMax
                maxNo = minMaxHeapObj.findMax();
              else
                maxNo = maxMinHeapObj.findMax();

              if(maxNo == -1)
                cout << "The Heap is empty" << endl;
              else
                cout << "The max no in the Heap is : " << maxNo << endl;
              break;

      case 5: if (inputDS==1)                                                   //deleteMax
                minMaxHeapObj.deleteMax();
              else
                maxMinHeapObj.deleteMax();
              break;

      case 6: if (inputDS==1)                                                   //levelOrder
                minMaxHeapObj.levelOrder();
              else
                maxMinHeapObj.levelOrder();
              break;

      default: cout << "Incorrect Input" << endl;
    }

    printQuery();
    cin >> input;
    cout << "........................" << endl;
    }

    if(inputDS==1)                                                              //after every Heap DS reset the Heap Structure
      minMaxHeapObj.clear();
    else
      maxMinHeapObj.clear();

    printDS();
    cin >> inputDS;
  }
  cout << "\nBYE BYE!!\n\n" << endl;
}

//options to select from one of the data structure
void printDS(){
  cout << "\n........................................."   << endl;
  cout << "Choose one of the following Data Structure or Exit" << endl;
  cout << "1. MinMax 2-Heap" << endl;
  cout << "2. MaxMin 2-Heap" << endl;
  cout << "3. Exit"       << endl;
}


//options to perform one of the operation in each DS
void printQuery(){
  cout << "\n........................................."   << endl;
  cout << "Please choose one of the following commands"   << endl;
  cout << "1.Insert"                                      << endl;
  cout << "2.Delete Min"                                  << endl;
  cout << "3.Find Min"                                    << endl;
  cout << "4.Find Max"                                    << endl;
  cout << "5.Delete Max"                                  << endl;
  cout << "6.Level Order Traversal"                       << endl;
  cout << "7.Exit\n"                                      << endl;
}
