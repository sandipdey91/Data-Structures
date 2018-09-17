#include <iostream>
#include "node.h"
#include "minLeftist.h"
#include "minSkew.h"

using namespace std;

void printDS();                                                                 //function to select one Data Structure
void printQuery();                                                              //function for all operation for one particular DS

int main(){                                                                     //driving function
  int dataInserted, inputDS, input;

  minLeftist minLeftistObj;                                                     //object declaration for minHeap class
  minSkew minSkewObj;                                                           //object declaration for maxHeap class

  printDS();
  cin >> inputDS;

while (inputDS!=3) {                                                            //terminate the program if user select exit
  switch (inputDS) {
  case 1:                                                                       //Leftist Heap
            cout << "*************************" << endl;
            cout << "Min Leftist Data Structure" << endl;
            cout << "*************************" << endl;
            minLeftistObj.buildHeap();
            break;
    case 2:                                                                     //Skew Heap
            cout << "*************************" << endl;
            cout << "Min Skew Data Structure" << endl;
            cout << "*************************" << endl;
            minSkewObj.buildHeap();
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
                minLeftistObj.insertData(dataInserted);
              else
                minSkewObj.insertData(dataInserted);

              cout << "........................" << endl;
              cout << "Data Successfully Inserted" << endl;
              break;

      case 2: if (inputDS==1)                                                   //deleteMin
                minLeftistObj.deleteMin();
              else
                minSkewObj.deleteMin();
              break;

      case 3: if (inputDS==1)                                                   //findMin
                minLeftistObj.findMin();
              else
                minSkewObj.findMin();
              break;

      case 4: if (inputDS==1)                                                   //levelOrder
                minLeftistObj.preOrder();
              else
                minSkewObj.preOrder();
              break;

      case 5: if (inputDS==1)                                                   //levelOrder
                minLeftistObj.inOrder();
              else
                minSkewObj.inOrder();
              break;

      case 6: if (inputDS==1)                                                   //levelOrder
                minLeftistObj.levelOrder();
              else
                minSkewObj.levelOrder();
              break;

      default: cout << "Incorrect Input" << endl;
    }

    printQuery();
    cin >> input;
    cout << "........................" << endl;
    }

    if(inputDS==1)                                                              //after every Heap DS reset the Heap Structure
      minLeftistObj.clear();
    else
      minSkewObj.clear();

    printDS();
    cin >> inputDS;
  }
  cout << "\nBYE BYE!!\n\n" << endl;
}

//options to select from one of the data structure
void printDS(){
  cout << "\n........................................."   << endl;
  cout << "Choose one of the following Data Structure or Exit" << endl;
  cout << "1. Min Leftist Heap"     << endl;
  cout << "2. Min Skew Heap"        << endl;
  cout << "3. Exit"                 << endl;
}


//options to perform one of the operation in each DS
void printQuery(){
  cout << "\n........................................."   << endl;
  cout << "Please choose one of the following commands"   << endl;
  cout << "1.Insert"                                      << endl;
  cout << "2.Delete Min"                                  << endl;
  cout << "3.Find Min"                                    << endl;
  cout << "4.PrOrderTraversal"                            << endl;
  cout << "5.InOrder Traversal"                           << endl;
  cout << "6.Level Order Traversal"                       << endl;
  cout << "7.Exit\n"                                      << endl;
}
