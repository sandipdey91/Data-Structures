#include <iostream>
#include "bstClass.h"
#include "minHeap.h"
#include "maxHeap.h"
#include "timerClass.cpp"
#include <cstdlib>


using namespace std;

//declaration of function to Print Query on Screen for user
void printQuery();
void printTable(double open[][5], double quad[][5], double doub[][5]);

//main function
int main(){
   int input, data, m = 1000000;                                                //input variable

//arrays to store end result
   double bst[3][5];
   double minHeap[3][5];
   double maxHeap[3][5];

//initializing the arrays
   for(int i=0;i<3;i++){
     for(int j=0;j<5;j++){
       bst[i][j] = 0;
       minHeap[i][j] = 0;
       maxHeap[i][j] = 0;
     }
   }

   printQuery();
   cin >> input;
   cout << "........................" << endl;

   class bstClass bstClassObj;
   class minHeap minHeapObj;
   class maxHeap maxHeapObj;
   class Timer timerObj;

   while(input != 2){
      switch(input){
          case 1:
            for(int k=1; k<=5; k++){                                            //Run the test for 5 sets of input 0.1m to 0.5m
              for(int j=1; j<=5; j++){                                          //Run the test for 5 sets of one particular input set
                  srand(j);                                                     //different random no for each set
                  for(int i=1; i<=(k*m); i++){                                  //Run the insertion test for different input size(0.1m to 0.5m)
                    data = (rand() % (5*m)) + 1;                                //range should be from 1 to 5m

                    timerObj.start();                                           //start the CPU time
                    bstClassObj.insertData(data);                               //check insertion for bst
                    bst[0][k-1] = bst[0][k-1] + timerObj.stop();                //count the duration

                    timerObj.start();                                           //start the CPU time
                    minHeapObj.storeElements(data);                             //check insertion for min heap
                    minHeap[0][k-1] = minHeap[0][k-1] + timerObj.stop();        //count the duration

                    timerObj.start();                                           //start the CPU time
                    maxHeapObj.storeElements(data);                             //check insertion for max heap
                    maxHeap[0][k-1] = maxHeap[0][k-1] + timerObj.stop();        //count the duration
                  }

                  timerObj.start();                                             //start the CPU time
                  minHeapObj.buildHeap();                                       //check insertion for min heap
                  minHeap[0][k-1] = minHeap[0][k-1] + timerObj.stop();          //count the duration

                  timerObj.start();                                             //start the CPU time
                  maxHeapObj.buildHeap();                                       //check insertion for max heap
                  maxHeap[0][k-1] = maxHeap[0][k-1] + timerObj.stop();          //count the duration

                for(int i=1;i<=(0.001*k*m);i++){                                //Run the find test for different input size(0.01m to 0.05m)
                    timerObj.start();                                           //start the CPU time
                    bstClassObj.deleteMin();                                    //deleteMin operation for bst
                    bst[1][k-1] = bst[1][k-1] + timerObj.stop();                //count the deleteMin duration for bst

                    timerObj.start();                                           //start the CPU time
                    minHeapObj.deleteMin();                                     //deleteMin operation for min heap
                    minHeap[1][k-1] = minHeap[1][k-1] + timerObj.stop();        //count the deleteMin duration for min heap

                    timerObj.start();                                           //start the CPU time
                    maxHeapObj.deleteMin();                                     //deleteMin operation for max heap
                    maxHeap[1][k-1] = maxHeap[1][k-1] + timerObj.stop();        //count the deleteMin duration for max heap

                    timerObj.start();                                           //start the CPU time
                    bstClassObj.deleteMax();                                    //deleteMax operation for bst
                    bst[2][k-1] = bst[2][k-1] + timerObj.stop();                //count the deleteMin duration for bst

                    timerObj.start();                                           //start the CPU time
                    minHeapObj.deleteMax();                                     //deleteMax operation for min heap
                    minHeap[2][k-1] = minHeap[2][k-1] + timerObj.stop();        //count the deleteMax duration for min heap

                    timerObj.start();                                           //start the CPU time
                    maxHeapObj.deleteMax();                                     //deleteMax operation for max heap
                    maxHeap[2][k-1] = maxHeap[2][k-1] + timerObj.stop();        //count the deleteMax duration for max heap

                 }

                 bstClassObj.clear();                                           //clear the bst for new set of data
                 minHeapObj.clear();                                            //clear the min heap for new set of data
                 maxHeapObj.clear();                                            //clear the max heap for new set of data

        }

      //take average of the each set of input range
        bst[0][k-1]     = ( bst[0][k-1] / 5 );
        bst[1][k-1]     = ( bst[1][k-1] / 5 );
        bst[2][k-1]     = ( bst[2][k-1] / 5 );

        minHeap[0][k-1] = ( minHeap[0][k-1] / 5 );
        minHeap[1][k-1] = ( minHeap[1][k-1] / 5 );
        maxHeap[2][k-1] = ( maxHeap[2][k-1] / 5 );

        maxHeap[0][k-1] = ( maxHeap[0][k-1] / 5 );
        maxHeap[1][k-1] = ( maxHeap[1][k-1] / 5 );
        maxHeap[2][k-1] = ( maxHeap[2][k-1] / 5 );

      }

       //print the final table
        printTable(bst,minHeap,maxHeap);
        break;
 default:
       cout << "Incorrect input \n";                                            //for any other case make a default output
}

printQuery();
cin >> input;
cout << "........................" << endl;
}

cout << "\nBYE BYE!!\n\n" << endl;
}

//definition of function to Print Query on Screen for user
void printQuery(){

 cout << "\n........................................." << endl;
 cout << "Please choose one of the following commands" << endl;
 cout << "1.Performance Comparison"  << endl;
 cout << "2.Exit"                    << endl;
}
//print function for the final table of time duration
void printTable(double bst[][5], double minHeap[][5], double maxHeap[][5]){

  cout << "\n\n        ....................Performance(BST).................." << endl;
  cout << "              1,000,000   |   2,000,000   |   3,000,000   |   4,000,000   |   5,000,000 " << endl;

    for(int i=0; i<3; i++){
      if(i==0)
        cout << "Build       ";
      else if (i==1)
        cout << "deleteMin   ";
      else
        cout << "deleteMax   ";

     for(int j=0; j<5; j++)
       printf("\t%5.6f  |  ", bst[i][j]);

    cout << "\n";
  }

    cout << "\n\n        ...................Performance(Min 5-Heap).............." << endl;
    cout << "              1,000,000   |   2,000,000   |   3,000,000   |   4,000,000   |   5,000,000 " << endl;

      for(int i=0; i<3; i++){
        if(i==0)
           cout << "Build       ";
         else if (i==1)
           cout << "deleteMin   ";
         else
           cout << "deleteMax   ";

        for(int j=0; j<5; j++)
          printf("\t%5.6f  |  ", minHeap[i][j]);

        cout << "\n";
      }

      cout << "\n\n        ...................Performance(Max 5-Heap)..............." << endl;
      cout << "              1,000,000   |   2,000,000   |   3,000,000   |   4,000,000   |   5,000,000 " << endl;

      for(int i=0; i<3; i++){
        if(i==0)
           cout << "Build       ";
         else if (i==1)
         cout << "deleteMin   ";
       else
         cout << "deleteMax   ";

      for(int j=0; j<5; j++)
        printf("\t%5.6f  |  ", maxHeap[i][j]);

      cout << "\n";
    }

}
