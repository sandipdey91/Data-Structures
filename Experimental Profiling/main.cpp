#include <iostream>
#include "quadHash.h"
#include "doubHash.h"
#include "openhash.h"
#include "timerClass.cpp"
#include <cstdlib>


using namespace std;

//declaration of function to Print Query on Screen for user
void printQuery();
void printTable(double open[][5], double quad[][5], double doub[][5]);

//main function
int main(){
   int input, data, n = 100000, q = 10000,  r = 5000000;                        //input variables

//arrays to store end result
   double open[3][5];
   double quad[3][5];
   double doub[3][5];

   printQuery();
   cin >> input;                                                                //take user input
   cout << "........................" << endl;

   openhash openhashObj;
   quadHash quadHashObj;
   doubHash doubHashObj;
   Timer timerObj;

   while(input != 2){
      switch(input){
          case 1:
            for(int k=1; k<=5; k++){                                            //Run the test for 5 sets of input 0.1m to 0.5m
              for(int j=1; j<=5; j++){                                          //Run the test for 5 sets of one particular input set
                  srand(j);                                                     //different random no for each set
                  for(int i=1; i<=(k*n); i++){                                  //Run the insertion test for different input size(0.1m to 0.5m)
                    data = (rand() % r) + 1;                                    //range should be from 1 to 5m

                    timerObj.start();                                           //start the CPU time
                    openhashObj.insert_data(data);                              //check insertion for open hash
                    open[0][k-1] = open[0][k-1] + timerObj.stop();              //count the duration

                    timerObj.start();                                           //start the CPU time
                    quadHashObj.insertData(data);                               //check insertion for quad hash
                    quad[0][k-1] = quad[0][k-1] + timerObj.stop();              //count the duration

                    timerObj.start();                                           //start the CPU time
                    doubHashObj.insertData(data);                               //check insertion for double hash
                    doub[0][k-1] = doub[0][k-1] + timerObj.stop();              //count the duration
                  }

                for(int i=1;i<=(k*q);i++){                                      //Run the find test for different input size(0.01m to 0.05m)
                    data = (rand() % r) + 1;                                    //range should be from 1 to 5m

                    timerObj.start();                                           //start the CPU time
                    if(openhashObj.find_hash(data) != -1)                       //if Found
                      open[1][k-1] = open[1][k-1] + timerObj.stop();            //count the found duration for open hash
                    else                                                        //if not Found
                      open[2][k-1] = open[2][k-1] + timerObj.stop();            //count the not found duartion for open hash

                    timerObj.start();                                           //start the CPU time
                    if(quadHashObj.findData(data) != -1)                        //if Found
                      quad[1][k-1] = quad[1][k-1] + timerObj.stop();            //count the found duration for quad hash
                    else                                                        //if not Found
                      quad[2][k-1] = quad[2][k-1] + timerObj.stop();            //count the not found duartion for quad hash

                    timerObj.start();                                           //start the CPU time
                    if(doubHashObj.findData(data) != -1)                        //if found
                      doub[1][k-1] = doub[1][k-1] + timerObj.stop();            //count the found duration for double hash
                    else                                                        //if not found
                      doub[2][k-1] = doub[2][k-1] + timerObj.stop();            //count the not found duration for double hash
                 }

			openhashObj.resetTable();				//clear the Open Hash Table for new set of data
			quadHashObj.resetTable();				//clear the Quad Hash Table for new set of data
			doubHashObj.resetTable();				//clear the Double Hash Table for new set of data

               }

             //take average of the each set of input range
               open[0][k-1] = ( open[0][k-1] / 5 );
               open[1][k-1] = ( open[1][k-1] / 5 );
               open[2][k-1] = ( open[2][k-1] / 5 );

               quad[0][k-1] = ( quad[0][k-1] / 5 );
               quad[1][k-1] = ( quad[1][k-1] / 5 );
               quad[2][k-1] = ( quad[2][k-1] / 5 );

               doub[0][k-1] = ( doub[0][k-1] / 5 );
               doub[1][k-1] = ( doub[1][k-1] / 5 );
               doub[2][k-1] = ( doub[2][k-1] / 5 );
             }

              //print the final table
               printTable(open,quad,doub);
               break;
        default:
              cout << "Incorrect input \n";                                     //for any other case make a default output
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
void printTable(double open[][5], double quad[][5], double doub[][5]){

  cout << "\n\n        ....................Performance(Open Hashing).................." << endl;
  cout << "              100,000   |   200,000   |   300,000   |   400,000   |   500,000 " << endl;

    for(int i=0; i<3; i++){
      if(i==0)
        cout << "Build       ";
      else if (i==1)
        cout << "Found       ";
      else
        cout << "Not Found   ";

     for(int j=0; j<5; j++)
       printf("\t%5.6f  |  ", open[i][j]);

    cout << "\n";
  }

    cout << "\n\n        ...................Performance(Quadratic Probing).............." << endl;
    cout << "              100,000   |   200,000   |   300,000   |   400,000   |   500,000 " << endl;

      for(int i=0; i<3; i++){
        if(i==0)
           cout << "Build       ";
         else if (i==1)
           cout << "Found       ";
         else
           cout << "Not Found   ";

        for(int j=0; j<5; j++)
          printf("\t%5.6f  |  ", quad[i][j]);

        cout << "\n";
      }

      cout << "\n\n        ...................Performance(Double Hashing)..............." << endl;
      cout << "              100,000   |   200,000   |   300,000   |   400,000   |   500,000 " << endl;

      for(int i=0; i<3; i++){
        if(i==0)
           cout << "Build       ";
         else if (i==1)
           cout << "Found       ";
         else
           cout << "Not Found   ";

        for(int j=0; j<5; j++)
          printf("\t%5.6f  |  ", doub[i][j]);

        cout << "\n";
      }

}
