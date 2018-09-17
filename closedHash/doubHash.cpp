#include "doubHash.h"
#include <iostream>
#include <fstream>


using namespace std;

//constructor for Double Hashing Table
doubHash::doubHash(int argc, char *argv[])
{

 ifstream dataFile(argv[1]);						//passing filename to the ifstream

 doubTable = new int [53];						//allocating memory to the pointer array	
 flagTable = new int [53];						//allocating memory to the pointer for flag array

//initializing the arrays
 for(int i=0; i < m; i++){
    doubTable[i] = -1;
    flagTable[i] = -1;
 }

 int j;
 while(dataFile >> dataInserted){
//checking for duplicate records in the file
    if(findData(dataInserted) == -1){
        n = n + 1;
        for(int j=0; j<k; j++){
            position = hashFunction(j,m,dataInserted);
            if (doubTable[position] == -1){
                doubTable[position] = dataInserted;
                flagTable[position] = 1;
                break;
            }
        }
    }
 }

  loadFactor = (float)n/m;						//calculate the load factor
  cout << "Load Factor for Double Hash Table " << loadFactor << endl;
 }

//destructor to clear up memory
doubHash::~doubHash()
{

delete [] doubTable;
delete [] flagTable;

}

//double hash function
int doubHash::hashFunction(int i, int m, int dataInserted){
    const int p = 13;
    return (((dataInserted % m) + (i*(p - (dataInserted % p) )))% m);
}

//insert function
void doubHash::insertData(int dataInserted){
        int j;
        for(j=0; j<k; j++){
            position = hashFunction(j,m,dataInserted);
            if (doubTable[position] == -1){
                doubTable[position] = dataInserted;
                flagTable[position] = 1;
                n = n + 1;
                break;
            }
        }
        if(j>= k){
            cout << "\nData cannot be inserted in the Double Hash Table" << endl;
            loadFactor = (float)n/m;
            cout << "\nLoad Factor for Double Hash Table " << loadFactor << endl;
        }
        else{
            loadFactor = (float)n/m;
            cout << "\nLoad Factor for Double Hash Table " << loadFactor << endl;
        }
}

//find function
int doubHash::findData(int dataInserted){
    int l;
    for(l=0; l<k; l++){
         position = hashFunction(l,m,dataInserted);
         if(doubTable[position] == dataInserted){
            break;
         }
         if(flagTable[position] == 0){
            break;
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
void doubHash::deleteData(int dataInserted){
    for(int i=0; i<k; i++){
         position = hashFunction(i,m,dataInserted);
         if(doubTable[position] == dataInserted){
            doubTable[position] = -1;
            cout << "Data Successfully deleted from Double Hash Table" << endl;
            n = n-1;
            loadFactor = (float)n/m;
            cout << "Load Factor for Double Hash Table " << loadFactor << endl;
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
void doubHash::displayList(){
    cout << "\n\nDouble Hashing" << endl;
    for(int i=0;i<m;i++){
        if(doubTable[i]!= -1){
            cout << "\n" << i << ": ";
            cout << doubTable[i];
    	}
    }
 };

