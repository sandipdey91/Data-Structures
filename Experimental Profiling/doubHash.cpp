#include "doubHash.h"
#include <iostream>

using namespace std;

//constructor for Quadratic Hashing table
doubHash::doubHash(){

doubTable = new int  [m];						                                            //allocating memory to the array of values
flagTable = new int  [m];						                                            //allocating memory to the array of flags

 for(int i=0; i < m; i++){
    doubTable[i] = -1;
    flagTable[i] = -1;
 }
}

//destructor to clear up memory
doubHash::~doubHash(){
 delete [] doubTable;
 delete [] flagTable;
}


//double hash function
int doubHash::hashFunction(int i, int m, int dataInserted){
    const int p = 997;
    return (((dataInserted % m) + (i*(p - (dataInserted % p) )))% m);
}

//insert function
void doubHash::insertData(int dataInserted){
  if(findData(dataInserted) == -1){
     int j;
     for(j=0; j<k; j++){
        position = hashFunction(j,m,dataInserted);
          if (doubTable[position] == -1){
              doubTable[position] = dataInserted;
              flagTable[position] = 1;
                break;
          }
     }
   }
}

//find function
int doubHash::findData(int dataInserted){
    int l;
    for(l=0; l<k; l++){
         position = hashFunction(l,m,dataInserted);
         if(doubTable[position] == dataInserted)
            break;
         else if(flagTable[position] == 0)
             break;
    }

    if(l>=k)
        return -1;
    else{
        if(flagTable[position] == 0)
            return -1;
        else
            return position;
    }
}

//display function
void doubHash::displayList(){
    cout << "\n\nDouble Hashing" << endl;
    for(int i=0;i<m;i++){
        if(doubTable[i]!= -1){
            cout << "\n" << i << ": ";
            cout << doubTable[i];
    	}
    }
}

//reset Table
void doubHash::resetTable(){

 delete [] doubTable;
 delete [] flagTable;

doubTable = new int  [m];                                                                                           //allocating memory to the array of values
flagTable = new int  [m];                                                                                           //allocating memory to the array of flags

 for(int i=0; i < m; i++){
    doubTable[i] = -1;
    flagTable[i] = -1;
 }
}
 
