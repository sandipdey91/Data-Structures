#include "quadHash.h"
#include <iostream>

using namespace std;

//constructor for Quadratic Hashing table
quadHash::quadHash(){

quadTable = new int  [m];						                                            //allocating memory to the array of values
flagTable = new int  [m];						                                            //allocating memory to the array of flags

 for(int i=0; i < m; i++){
    quadTable[i] = -1;
    flagTable[i] = -1;
 }
}

//destructor to clear up memory
quadHash::~quadHash(){
 delete [] quadTable;
 delete [] flagTable;
}

//Quadratic hash function
int quadHash::hashFunction(int i, int m, int dataInserted){
    return (((dataInserted%m) + (i*i))% m);
}

//insert function
void quadHash::insertData(int dataInserted){
if(findData(dataInserted) == -1){
     int j;
     for(j=0; j<k; j++){
        position = hashFunction(j,m,dataInserted);
          if (quadTable[position] == -1){
              quadTable[position] = dataInserted;
              flagTable[position] = 1;
                break;
          }
     }
  }
}

//find function
int quadHash::findData(int dataInserted){
    int l;
    for(l=0; l<k; l++){
         position = hashFunction(l,m,dataInserted);
         if(quadTable[position] == dataInserted)
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

void quadHash::resetTable(){
 delete [] quadTable;
 delete [] flagTable;

quadTable = new int  [m];                                                                                           //allocating memory to the array of values
flagTable = new int  [m];                                                                                           //allocating memory to the array of flags

 for(int i=0; i < m; i++){
    quadTable[i] = -1;
    flagTable[i] = -1;

 }
}


