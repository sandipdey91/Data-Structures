#include <iostream>
#include "openhash.h"

using namespace std;

//constructor function to create the hash table
openhash::openhash(){

 table = new node *[m];                                       		              //memory allocation for the hash table

//declaring pointers as NULL
 for(int i=0; i < m; i++)
    table[i]= NULL;
}

//destructor to clear memory after execution
openhash::~openhash(){
 for(int i=0; i<m; i++){
    temp = table[i];
    while(temp != NULL){
        prev = temp;
        temp = temp->next;
        delete prev;
    }
    delete temp;
 }

 delete [] table;
}

 //insert function
void openhash::insert_data(int dataInserted){
if(find_hash(dataInserted) == -1){
    position = hash_function(m, dataInserted);

    node *newNode = new node;                                  		              //memory allocation for new node
    newNode->data = dataInserted;

    if(table[position] == NULL)
        newNode->next = NULL;
    else
        newNode->next = table[position];

    table[position] = newNode;                                		              //assign address of the first node to the table
 }
}


//hash function
int openhash::hash_function(int m, int dataInserted){
    return dataInserted % m;
}

//find function
int openhash::find_hash(int dataInserted){
 position = hash_function(m, dataInserted);
 temp = NULL;

 if(table[position]!= NULL){
    temp = table[position];

    while(temp->next != NULL && temp->data != dataInserted)
        temp = temp->next;

    if(dataInserted == temp->data)
       return  position;                                                        //if found return bucket no
     else
        return -1;
  }
 else
    return -1;

}

//reset table for new entries
void openhash::resetTable(){
 for(int i=0; i<m; i++){
    temp = table[i];
    while(temp != NULL){
        prev = temp;
        temp = temp->next;
        delete prev;
    }
    delete temp;
 }

 delete [] table;

 table = new node *[m];                                                               //memory allocation for the hash table

//declaring pointers as NULL
 for(int i=0; i < m; i++)
    table[i]= NULL;

}

