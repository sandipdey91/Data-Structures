#include <iostream>
#include <fstream>
#include "bstClass.h"

using namespace std;
//constructor for creating the Tree from command line files
bstClass::bstClass()
{
  rootPtr = NULL;                                                               //initialize the root
}

//destructor to deallocate memory
bstClass::~bstClass()
{
if(rootPtr!=NULL)
        destructMem(rootPtr);                                                   //calling the resursive helper function
}

//recursive helper function for destructor
void bstClass::destructMem(node *travPtr){
    if(travPtr==NULL)
        return;

    destructMem(travPtr->lftchild);
    destructMem(travPtr->rtchild);
    delete travPtr;                                                             //dealloacate the memory from each node

}

//insert function
void bstClass::insertData(int dataInserted){
if(rootPtr == NULL){
    node *newNode = new node;                                                   //allocate the memory for the first node

    newNode->data = dataInserted;
    newNode->lftchild = NULL;
    newNode->rtchild = NULL;

    rootPtr = newNode;                                                          //assigning the address of first node to root
}
else
    insertDataRecur(rootPtr, dataInserted);
}
//recursive insert helper function
void bstClass::insertDataRecur(node* &travPtr, int dataInserted){

    if(travPtr == NULL){                                                        //allocate memory for the child nodes
        node *newNode = new node;
        newNode->data = dataInserted;
        newNode->lftchild = NULL;
        newNode->rtchild = NULL;

        travPtr = newNode;
    }
    else{
        if(travPtr->data > dataInserted)                                        //recursive call during traversal
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
    if(dataInserted < travPtr->data)                                            //traversal to the node where the data is present
            deleteDataRecur(travPtr->lftchild, dataInserted);

    else if(dataInserted > travPtr->data)
            deleteDataRecur(travPtr->rtchild, dataInserted);
     else{                                                                      //data is present in this node
        if(travPtr->lftchild == NULL && travPtr->rtchild == NULL){              //when it is a leaf node
            delete travPtr;
            travPtr = NULL;
        }
        else if(travPtr->rtchild == NULL || travPtr->lftchild == NULL){         //when it has only one child node
                node* prevPtr;
                prevPtr = travPtr;
                if(travPtr->lftchild != NULL)
                    travPtr = travPtr->lftchild;
                else
                    travPtr = travPtr->rtchild;
            delete prevPtr;
          }
          else if(travPtr->lftchild != NULL && travPtr->rtchild != NULL){       //when it has both the child node
                  node* currPtr, *prevPtr;
                  currPtr = travPtr->rtchild;
                if(currPtr->lftchild==NULL && currPtr->rtchild==NULL){          //the right subtree has no child
                      travPtr->data  = currPtr->data;
                      travPtr->rtchild = NULL;

                      delete currPtr;
                }
                else if(currPtr->lftchild==NULL && currPtr->rtchild!=NULL){     //the right subtree has only one child to the right
                      travPtr->data = currPtr->data;
                      travPtr->rtchild = currPtr->rtchild;

                      delete currPtr;
                     }
                else{
                      while(currPtr->lftchild != NULL){                         //else traverse to the min element in right subtree
                          prevPtr = currPtr;
                          currPtr = currPtr->lftchild;
                      }

                  travPtr->data = currPtr->data;                                //swap the min element with the data to be deleted
                  if(currPtr->rtchild != NULL)
                      prevPtr->lftchild = currPtr->rtchild;
                  else
                      prevPtr->lftchild = NULL;

                  delete currPtr;                                               //delete the node with the min element in right subtree
               }
          }
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
    else
        deleteData(maxNo);
}

//delete min no from the tree
void bstClass::deleteMin(){
    int minNo = findMin();
    if(minNo == -1)
        cout << "The Tree is already empty" << endl;
    else
        deleteData(minNo);
}

//clear the tree
void bstClass::clear(){
  if(rootPtr!=NULL)
        destructMem(rootPtr);                                                   //calling the resursive helper function
}
