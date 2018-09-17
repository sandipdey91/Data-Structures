#include "list.h"

#include <iostream>

#include <fstream>



using namespace std;



List::List()                                                            //constructor to create list

{

    ifstream datafile("data.txt");                                      //reading data from external file

    head = NULL;                                                        //declaring pointers as NULL

    prev = NULL;



//creating the list after reading the data from file

    while(datafile >> data_inserted){



            node *temp = new node;

            temp->data = data_inserted;

            temp->next = NULL;



        if (head == NULL){

            head = temp;

            prev = temp;

        }

        else{

            prev->next = temp;

            prev = temp;

        }

    }

}



//destructor to clear memory after execution

List::~List()

{

if(isempty() != true){

temp = head;


while(temp != NULL){

    prev = temp;

   temp = temp->next;
   
    delete prev;

}
	
delete temp;
delete head;

}



}



//check if the list is empty

bool List::isempty(){

    if (head == NULL)

        return true;

    else

        return false;



};



//print function

 void List::display_list(){

    temp = head;



if(isempty() == true){                                                 //check if the list is empty

    cout << "The List is empty" << endl;

    }

else{

 while(temp !=NULL){

    cout << temp->data << ' ';

    temp = temp->next;

  }

}

 }



 //find function

 int List::find_list(int data_inserted){

 if(isempty() == false)

    {

        int i = 1;                                                      //variable to determine position of the data in the list

        temp = head;

       while(temp->next != NULL && data_inserted != temp->data){

        temp = temp->next;

        i++;

        }

        if( data_inserted == temp->data){

            return i;                                                   //return position no.

        }

        else{

            return 0;

        }

    }

else{

      cout << "The List is empty" << endl;
	return -1;	

    }

}



//insert function

void List::insert_data(int data_inserted){

temp = head;

insert_list(temp, data_inserted);                                      //call insert helper function

}



//insert helper function

void List::insert_list(node *temp, int data_inserted){

    if(isempty() == true){                                             //base case when the list is empty

        node *newnode = new node;

        newnode->data = data_inserted;

        newnode->next = NULL;

        head = newnode;

    }

    else{

        if(temp->next == NULL){                                        //base case when reaches the end of the list

            node *newnode = new node;

            newnode->data = data_inserted;

            newnode->next = NULL;

            temp->next = newnode;

    }

        else{

            temp = temp->next;

            insert_list(temp, data_inserted);                           //recursive call to the insert function

    }

    }

}



//delete function

void List::delete_data(int data_inserted){

temp = head;

prev = NULL;

delete_list(temp, prev, data_inserted);                                 //call delete helper function

}



//delete helper function

void List::delete_list(node *temp, node *prev, int data_inserted){

    if(temp->data == data_inserted){                                     //base case when there is only one entry in list

        if (prev == NULL && temp->next == NULL){

            head = NULL;

            delete temp;

      }

        else{                                                             //base case when it is the first entry in the list

            if(prev == NULL && temp->next != NULL){

                head = temp->next;

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

        delete_list(temp, prev, data_inserted);                           //recursive call to the insert function

    }

}


