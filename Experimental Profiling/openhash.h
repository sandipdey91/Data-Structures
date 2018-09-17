#ifndef OPENHASH_H
#define OPENHASH_H

class openhash{

    public:
        openhash();
        ~openhash();

   int  find_hash(int data_inserted);                                           //returns position no of the queried data from the list
   void insert_data(int dataInserted);                                          //inserts data to the list from behind
   void display_list();                                                         //prints data on screen
   void resetTable();								//reset table fore new set of entries

    private:
      struct node{                                                              //structure of each node in list
           int     data;
           node    *next;
      };

    node *prev;
    node *temp;

    int dataInserted, m = 1000003, position;                                              //data used to insert,delete or find
    node **table;                                                               //hash table to store pointers of the list

    int hash_function(int m, int dataInserted);                                 //prototype declaration for hash modular function

};



#endif // OPENHASH_H
