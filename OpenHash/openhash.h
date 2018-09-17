#ifndef OPENHASH_H

#define OPENHASH_H





class openhash

{

    public:

        openhash();

        ~openhash();



   int  find_hash(int data_inserted);                   //returns position no of the queried data from the list

   void insert_data(int dataInserted);                  //inserts data to the list from behind

   void delete_data(int dataInserted);                  //deletes data from the list

   void display_list();                                 //prints data on screen



    private:



    struct node{                                        //structure of each node in list

           int     data;

           node    *next;

               };



    node *prev;

    node *temp;



    int dataInserted, m, position;                      //data used to insert,delete or find

    node **table;                                       //hash table to store pointers of the list



    int hash_function(int m, int dataInserted);         //prototype declaration for hash modular function

    void delete_hash(node *temp, node *prev, int data_inserted, int position);  //prototype declaration for delete helper function



};



#endif // OPENHASH_H
