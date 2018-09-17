#ifndef BSTCLASS_H
#define BSTCLASS_H


class bstClass
{
    public:
        bstClass();                                                             //constructor passing command arguments
        ~bstClass();                                                            //destructore to deallocate memory

        void insertData(int dataInserted);                                      //insert function
        void deleteData(int dataInserted);                                      //delete function
        void deleteMin();                                                       //delete the min no from the tree
        void deleteMax();                                                       //delete the max no from the tree
        int findMin();                                                          //find the min no from the tree
        int findMax();                                                          //find the max no from the tree
        void clear();


    private:
//structure of every node in tree
         struct node{
                int    data;
                node  *lftchild;
                node  *rtchild;

            };

//root and traversal pointer declaration
    node *rootPtr, *travPtr;

//helper recursive functions
    void insertDataRecur(node* &travPtr, int dataInserted);                     //helper recursive function for insert
    void deleteDataRecur(node* &travPtr, int dataInserted);                     //helper recursive function for delete

    void destructMem(node *travPtr);                                            //helper recursive function for destructing all memory allocation

};

#endif
