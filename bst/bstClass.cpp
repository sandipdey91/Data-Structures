#include <iostream>
#include <fstream>
#include "bstClass.h"

using namespace std;
//constructor for creating the Tree from command line files
bstClass::bstClass(int argc, char *argv[])
{
rootPtr = NULL;					//initialize the root
int dataInserted;
ifstream dataFile(argv[1]);

while(dataFile >> dataInserted){
    insertData(dataInserted);			//calling the Insert function for every data from file
}
}

//destructor to deallocate memory
bstClass::~bstClass()
{
if(rootPtr!=NULL)
	destructMem(rootPtr);			//calling the resursive helper function
}

//recursive helper function for destructor
void bstClass::destructMem(node *travPtr){
    if(travPtr==NULL)
        return;

    destructMem(travPtr->lftchild);
    destructMem(travPtr->rtchild);
    delete travPtr;				//dealloacate the memory from each node

}

//insert function
void bstClass::insertData(int dataInserted){
if(rootPtr == NULL){
    node *newNode = new node;			//allocate the memory for the first node

    newNode->data = dataInserted;
    newNode->lftchild = NULL;
    newNode->rtchild = NULL;

    rootPtr = newNode;				//assigning the address of first node to root
}
else
    insertDataRecur(rootPtr, dataInserted);
}

//recursive insert helper function
void bstClass::insertDataRecur(node* &travPtr, int dataInserted){

    if(travPtr == NULL){					//allocate memory for the child nodes
        node *newNode = new node;
        newNode->data = dataInserted;
        newNode->lftchild = NULL;
        newNode->rtchild = NULL;

        travPtr = newNode;
    }
    else{
        if(travPtr->data > dataInserted)			//recursive call during traversal
            insertDataRecur(travPtr->lftchild, dataInserted);
        else
            insertDataRecur(travPtr->rtchild, dataInserted);
    }
}

//delete function
void bstClass::deleteData(int dataInserted){
if(rootPtr !=NULL)
      deleteDataRecur(rootPtr, dataInserted);
}

//recursive delete helper function
void bstClass::deleteDataRecur(node* &travPtr, int dataInserted){
//traversal to the node where the data is present
    if(dataInserted < travPtr->data)
            deleteDataRecur(travPtr->lftchild, dataInserted);

    else if(dataInserted > travPtr->data)
            deleteDataRecur(travPtr->rtchild, dataInserted);
//data is present in this node
     else{
        if(travPtr->lftchild == NULL && travPtr->rtchild == NULL){		//when it is a leaf node
            delete travPtr;
            travPtr = NULL;
        }
        else if(travPtr->rtchild == NULL || travPtr->lftchild == NULL){		//when it has only one child node
                node* prevPtr;
                prevPtr = travPtr;
                if(travPtr->lftchild != NULL)
                    travPtr = travPtr->lftchild;
                else
                    travPtr = travPtr->rtchild;
            delete prevPtr;
        }
        else if(travPtr->lftchild != NULL && travPtr->rtchild != NULL){		//when it has both the child node
                node* currPtr, *prevPtr;
                currPtr = travPtr->rtchild;
              if(currPtr->lftchild==NULL && currPtr->rtchild==NULL){		//the right subtree has no child
                    travPtr->data  = currPtr->data;
                    travPtr->rtchild = NULL;

                    delete currPtr;
              }
	      else if(currPtr->lftchild==NULL && currPtr->rtchild!=NULL){	//the right subtree has only one child to the right
		    travPtr->data = currPtr->data;
		    travPtr->rtchild = currPtr->rtchild;

		    delete currPtr;
		   }
              else{
                    while(currPtr->lftchild != NULL){				//else traverse to the min element in right subtree
                        prevPtr = currPtr;
                        currPtr = currPtr->lftchild;
                    }

                travPtr->data = currPtr->data;					//swap the min element with the data to be deleted
                if(currPtr->rtchild != NULL)
                    prevPtr->lftchild = currPtr->rtchild;
                else
                    prevPtr->lftchild = NULL;

                delete currPtr;							//delete the node witn the min element in right subtree
             }
        }
     }
}


//find function to delete
int bstClass::findData(int dataInserted){
if(rootPtr == NULL){
    cout << "The Tree is empty" << endl;
    return 0;
}
else
    return findDataRecur(rootPtr, dataInserted);
}

//recursive helper function to find data
int bstClass::findDataRecur(node* &travPtr, int dataInserted){
   if(travPtr == NULL)
        return 0;
   else{
    if(dataInserted == travPtr->data)
        return -1;
    else if(dataInserted < travPtr->data)
        return findDataRecur(travPtr->lftchild, dataInserted);
    else
        return findDataRecur(travPtr->rtchild,dataInserted);
   }
}

//find min no from tree
int bstClass::findMin(){
travPtr = rootPtr;

if(travPtr == NULL){
    return -1;
}
else{
    while(travPtr->lftchild != NULL){
        travPtr = travPtr->lftchild;
    }
    return travPtr->data;
}
}

//find max no from tree
int bstClass::findMax(){
travPtr = rootPtr;

if(travPtr == NULL){
    return -1;
}
else{
    while(travPtr->rtchild != NULL){
        travPtr = travPtr->rtchild;
    }
    return travPtr->data;
}
}

//delete max no from the tree
void bstClass::deleteMax(){
    int maxNo = findMax();
    if(maxNo == -1){
        cout << "The Tree is already empty" << endl;
    }
    else{
        deleteData(maxNo);
        cout << "The max no " << maxNo << " is deleted" << endl;
    }
}

//delete min no from the tree
void bstClass::deleteMin(){
    int minNo = findMin();
    if(minNo == -1)
        cout << "The Tree is already empty" << endl;
    else{
        deleteData(minNo);
        cout << "The min no " << minNo << " is deleted" << endl;
    }
}

//preorder traversal
void bstClass::preOrder(){
   if(rootPtr!=NULL)
   	 preOrderRecur(rootPtr);
   else
 	cout << "The Tree is empty" << endl;
}

//recursive helper function for preorder traversal
void bstClass::preOrderRecur(node* travptr){
    if(travptr==NULL){
        return;
    }
    cout << travptr->data << " ";

    preOrderRecur(travptr->lftchild);
    preOrderRecur(travptr->rtchild);
}

//postorder traversal
void bstClass::postOrder(){
    if(rootPtr!=NULL)
    	postOrderRecur(rootPtr);
    else
	cout << "The Tree is empty" << endl;
}

//recursive helper function for postorder traversal
void bstClass::postOrderRecur(node* travptr){
    if(travptr==NULL){
        return;
    }

    postOrderRecur(travptr->lftchild);
    postOrderRecur(travptr->rtchild);
    cout << travptr->data << " ";
}

//inorder traversal
void bstClass::inOrder(){
    if(rootPtr!=NULL)
    	inOrderRecur(rootPtr);
    else
	cout << "The Tree is empty" << endl;
}

//recursive helper function for inorder traversal
void bstClass::inOrderRecur(node* travptr){
    if(travptr==NULL){
        return;
    }

    inOrderRecur(travptr->lftchild);
    cout << travptr->data << " ";
    inOrderRecur(travptr->rtchild);
}
