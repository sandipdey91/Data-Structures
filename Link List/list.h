#ifndef LIST_H

#define LIST_H





class List

{

    public:

        List();                                         //constructor to create link list from file

        ~List();                                        //destructor to free up space after execution







   bool isempty();                                      //returns T/F depending on the availability of data in list



   int  find_list(int data_inserted);                   //returns position no of the queried data from the list

   void insert_data(int data_inserted);                 //inserts data to the list from behind

   void delete_data(int data_inserted);                 //deletes data from the list

   void display_list();                                 //prints data on screen



    private:

        struct node{                                    //structure of each node in list

                int     data;

                node    *next;

                };

        node *head;                                     //pointer declaration to store location of first data

        node *prev;

        node *temp;



        int data_inserted;                                              //data used to insert,delete or find



        void insert_list(node *temp, int data_inserted);                //helper function to insert data in the list

        void delete_list(node *temp, node *prev, int data_inserted);    //helper function to delete data in the list

};



#endif // LIST_H
