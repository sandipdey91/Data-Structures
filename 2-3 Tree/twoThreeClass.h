#ifndef TWOTHREECLASS_H
#define TWOTHREECLASS_H


class twoThreeClass
{
    public:
        twoThreeClass();				        //constructor
        ~twoThreeClass();                                       //destructore to deallocate memory

        void insertData(int dataInserted);                      //insert function
        void deleteData(int dataInserted);                      //delete function
        int  findData(int dataInserted);                        //find data for delete function
        void deleteMin();                                       //delete the min no from the tree
        void deleteMax();                                       //delete the max no from the tree
        int findMin();                                          //find the min no from the tree
        int findMax();                                          //find the max no from the tree
        void levelOrder();                                      //Levelorder traversal of the tree


    private:
//structure of every node in 2-3 tree
         struct node{
                int     minSecond;
                node    *parent;
                int     minThird;
		int 	key;
		bool    tag;
		node    *first;
		node    *second;
		node    *third;
               };

//structure of each node in Queue for Level Order Traversal
          struct nodeList{                                   
                node        *item;
                nodeList    *next;
                };

//root and traversal pointer declaration
    node *rootPtr, *travPtr;

//helper recursive functions
    void updateParentRecur(node* parent, node* &newLeafNode); ;          //helper recursive function for insert
    void updateAncestorRecur(node *ancestorPtr);		         //helper recursive function for delete
    int findDataRecur(node* &travPtr, int dataInserted);                 //helper recursive function for finding data
    int findMaxRecur(node *travPtr);					 //helpere recursive function for finding Max No
	
    void destructMem(node *travPtr);                                     //helper recursive function for destructing all memory allocation

};

#endif

