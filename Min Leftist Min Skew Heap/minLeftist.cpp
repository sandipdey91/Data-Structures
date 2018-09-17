#include <iostream>
#include <fstream>
#include "minLeftist.h"

using namespace std;

//constructor
minLeftist::minLeftist(){                                                       //reset the root
  rootPtr = NULL;
}

//destructor
minLeftist::~minLeftist(){                                                      //destroy the memory
    destructMem(rootPtr);
}

//build initial heap
void minLeftist::buildHeap(){
    ifstream dataFile("data.txt");

    while(dataFile >> dataInserted)
      rootPtr = concat(new node(dataInserted), rootPtr);                        //merge two heaps
}

//recursively destroy all memory
void minLeftist::destructMem(node *travPtr){
    if(travPtr==NULL)
        return;

    destructMem(travPtr->lftchild);
    destructMem(travPtr->rtchild);

    delete travPtr;
}


//merge two heaps
node* minLeftist::concat(node* H1, node* H2){
  if(H1==NULL)
    return H2;
  else if(H2==NULL)
          return H1;
  else if(H1->data > H2->data ){
          node* temp = H1;
          H1 = H2;
          H2 = temp;
      }

    H1->rtchild = concat(H1->rtchild,H2);

    node* lftchild = H1->lftchild;
    node* rtchild = H1->rtchild;
    if(lftchild == NULL && rtchild != NULL){
        H1->lftchild = H1->rtchild;
        H1->rtchild = NULL;
    }
    else{
        if(lftchild->rank < rtchild->rank){
            node* temp = H1->lftchild;
            H1->lftchild = H1->rtchild;
            H1->rtchild  = temp;
        }
        updateRank(H1);                                                         //update rank after each attachment
    }
    return H1;
}

//update rank for each node
void minLeftist::updateRank(node* H){
    H->rank = H->rtchild->rank + 1;
}

//insert function
void minLeftist::insertData(int dataInserted){
  rootPtr = concat(new node(dataInserted), rootPtr);                            //a single element is also a Leftist heap
}

//deleteMin function
void minLeftist::deleteMin(){
  if(rootPtr!= NULL){
    node* lftchild = rootPtr->lftchild;
    node* rtchild  = rootPtr->rtchild;

    delete rootPtr;

    rootPtr = concat(lftchild, rtchild);                                        //merge two child of the root node after deletion
    cout << "Min no has been deleted" << endl;
  }
  else
    cout << "The Leftist Heap is empty" << endl;
}

//findMin function
void minLeftist::findMin(){
  if(rootPtr!= NULL)
    cout << "The min no in the Leftist Heap is : " << rootPtr->data << endl;
  else
    cout << "The Leftist Heap is empty" << endl;
}


//inorder traversal
void minLeftist::inOrder(){
    if(rootPtr!=NULL)
    	inOrderRecur(rootPtr);
    else
	   cout << "The Leftist Heap is empty" << endl;
}

//recursive helper function for inorder traversal
void minLeftist::inOrderRecur(node* travptr){
    if(travptr==NULL){
        return;
    }

    inOrderRecur(travptr->lftchild);
    cout << travptr->data << " ";
    inOrderRecur(travptr->rtchild);
}

//preorder traversal
void minLeftist::preOrder(){
   if(rootPtr!=NULL)
   	 preOrderRecur(rootPtr);
   else
 	cout << "The Leftist Heap is empty" << endl;
}

//recursive helper function for preorder traversal
void minLeftist::preOrderRecur(node* travptr){
    if(travptr==NULL){
        return;
    }
    cout << travptr->data << " ";

    preOrderRecur(travptr->lftchild);
    preOrderRecur(travptr->rtchild);
}

//levelOrder function using a queue
void minLeftist::levelOrder(){
  if(rootPtr != NULL){
    nodeList *temp, *travList;

    nodeList *newNode = new nodeList;                                           //allocate memory to each node in the queue
    newNode->item = rootPtr;
    newNode->next = NULL;

    temp = newNode;
    travList = newNode;

    while(travList!=NULL){
      travPtr = travList->item;

      cout << travPtr->data << " ";

      if(travPtr->lftchild != NULL){                                            //enque the left child first
        nodeList *newNode = new nodeList;
        newNode->item = travPtr->lftchild;
        newNode->next = NULL;

        temp->next = newNode;
        temp = newNode;
      }

      if(travPtr->rtchild != NULL){                                             //then enque the right child
        nodeList *newNode = new nodeList;
        newNode->item = travPtr->rtchild;
        newNode->next = NULL;

        temp->next = newNode;
        temp = newNode;
      }

//dequeue the queue once traversed
           nodeList *destruct = travList;
           travList = travList->next;
           delete destruct;

    }
  }
  else
      cout << "The Leftist Heap is empty" << endl;
}

//reset the memory for recall
void minLeftist::clear(){
  destructMem(rootPtr);
  rootPtr = NULL;
}
