#include "quadHash.h"
#include <iostream>
#include <fstream>


using namespace std;

//constructor for Quadratic Hashing table
quadHash::quadHash(int argc, char *argv[])
{

ifstream dataFile(argv[1]);						//passsing file name to the ifstream


quadTable = new int  [53];						//allocating memory to the array of values
flagTable = new int  [53];						//allocating memory to the array of flags

 for(int i=0; i < m; i++){
    quadTable[i] = -1;
    flagTable[i] = -1;
 }

 int j;
 while(dataFile >> dataInserted){
//checking for duplicate records in the file
    if(findData(dataInserted) == -1){
        n = n + 1;
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

    loadFactor = (float)n/m;								//calculating load factor							
    cout << "\nLoad Factor for Quadratic Probing Hash Table " << loadFactor << endl;
 }

//destructor to clear up memory
quadHash::~quadHash()
{

delete [] quadTable;
delete [] flagTable;

}

//Quadratic hash function
int quadHash::hashFunction(int i, int m, int dataInserted){
    return (((dataInserted%m) + (i*i))% m);
}

//insert function
void quadHash::insertData(int dataInserted){
     int j;
     for(j=0; j<k; j++){
        position = hashFunction(j,m,dataInserted);
          if (quadTable[position] == -1){
              quadTable[position] = dataInserted;
              flagTable[position] = 1;
                n = n + 1;
                break;
          }
     }
        
     if(j>= k){
        cout << "\nData cannot be inserted in the Quad Hash Table" << endl;
        loadFactor = (float)n/m;
        cout << "\nLoad Factor for Quadratic Probing Hash Table " << loadFactor << endl;
     }
     else{
        loadFactor = (float)n/m;
         cout << "\nLoad Factor for Quadratic Probing Hash Table " << loadFactor << endl;
     }
}

//find function
int quadHash::findData(int dataInserted){
    int l;
    for(l=0; l<k; l++){
         position = hashFunction(l,m,dataInserted);
         if(quadTable[position] == dataInserted){
            break;
         }
         else{
            if(flagTable[position] == 0){
            break;
            }
        }
    }

    if(l>=k)
        return -1;
    else{
        if(flagTable[position] == 0){
            return -1;
         }
        else
            return position;
    }
}

//delete function
void quadHash::deleteData(int dataInserted){
    for(int i=0; i<k; i++){
         position = hashFunction(i,m,dataInserted);
         if(quadTable[position] == dataInserted){
            quadTable[position] = -1;
            cout << "Data Successfully deleted from Quad Hash Table" << endl;
            n = n-1;
            loadFactor = (float)n/m;
            cout << "Load Factor for Quadratic Probing Hash Table " << loadFactor << endl;
            break;
         }
         else{
            if(flagTable[position] == 0){
            	break;
            }
         }
    }
};


//display function
void quadHash::displayList(){
    cout << "\nQuadratic Hashing" << endl;
    for(int i=0;i<m;i++){
        if(quadTable[i]!=-1){
            cout << "\n" << i << ": ";
            cout << quadTable[i];
    	}
    }
};

