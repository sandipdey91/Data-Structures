#include <iostream>

#include "openhash.h"

#include <fstream>



using namespace std;



//constructor function to create the hash table

openhash::openhash()

{

 ifstream datafile("data.txt");                              		//reading data from external file

 datafile >> m;



 table = new node*[m];                                       		//memory allocation for the hash table



//declaring pointers as NULL

 for(int i=0; i < m; i++){

    table[i]= NULL;

 }

 temp = NULL;



 while(datafile >> dataInserted){

//checking for duplicate records in the file

    if(find_hash(dataInserted) == -1){

       insert_data(dataInserted);                          		//insert function is call to create the hash table

    }

 }

}



//hash function

int openhash::hash_function(int m, int dataInserted){

    return dataInserted % m;

}



//destructor to clear memory after execution

openhash::~openhash()

{

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



//print function

void openhash::display_list(){

 for(int i=0;i<m;i++){

    if(table[i]==NULL){

       cout << "\n" << i << ": ";

    }

    else{

       cout << "\n" << i << ": ";

       temp = table[i];

       while(temp != NULL){

          cout << temp->data << ' ';

          temp = temp->next;

       }

    }

 }

}



//find function

int openhash::find_hash(int dataInserted){



 position = hash_function(m, dataInserted);

 temp = NULL;



 if(table[position]!= NULL){

    temp = table[position];



    while(temp->next != NULL && temp->data != dataInserted){

        temp = temp->next;

    }



    if(dataInserted == temp->data){

       return  position;                                   		//if found return bucket no

    }

     else

        return -1;

 }

 else

    return -1;

}



 //find function

void openhash::insert_data(int dataInserted){



 position = hash_function(m, dataInserted);



 node *temp = new node;                                  		//memory allocation for new node

 temp->data = dataInserted;



 if(table[position] == NULL){

   temp->next = NULL;

 }

 else{

    temp->next = table[position];

 }



 table[position] = temp;                                		//assign address of the first node to the table

}



//delete function

void openhash::delete_data(int dataInserted){



 position = hash_function(m, dataInserted);

 temp = table[position];

 prev = NULL;

 delete_hash(temp, prev, dataInserted, position);           		//call delete helper function

}



//delete helper function

void openhash::delete_hash(node *temp, node *prev, int dataInserted, int position){

 if(temp->data == dataInserted){                                       //base case when there is only one entry in list

    if (prev == NULL && temp->next == NULL){

        table[position] = NULL;

        delete temp;

    }

    else{                                                             	//base case when it is the first entry in the list

         if(prev == NULL && temp->next != NULL){

            table[position] = temp->next;

            delete temp;

          }

          else{

             prev->next = temp->next;

             delete temp;

            }

        }

    }

  else{

    prev = temp;

    temp = temp->next;

    delete_hash(temp, prev, dataInserted, position);                   	//recursive call to the insert function

    }

}






