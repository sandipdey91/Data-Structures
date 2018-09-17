#include <iostream>
#include <fstream>
#include "twoThreeClass.h"

using namespace std;

//constrcutor to allocate memory
twoThreeClass::twoThreeClass(){

 rootPtr = NULL;
 int dataInserted;
 ifstream dataFile("data.txt");

while(dataFile >> dataInserted)
    insertData(dataInserted);
}

//destructor to deallocate memory
twoThreeClass::~twoThreeClass(){

  destructMem(rootPtr);				//using recursive function
}

//recursive function to deallocate memory
void twoThreeClass::destructMem(node *travPtr){
    if(travPtr==NULL)
        return;

    destructMem(travPtr->first);
    destructMem(travPtr->second);
    destructMem(travPtr->third);

    delete travPtr;
}

//insert function
void twoThreeClass::insertData(int dataInserted){

//if tree is empty
if(rootPtr == NULL){
    node *newLeafNode = new node;		//allocating memory to first leaf node

    newLeafNode->minSecond  = -1;
    newLeafNode->parent     = NULL;
    newLeafNode->minThird   = -1;
    newLeafNode->key        = dataInserted;
    newLeafNode->tag        = true;
    newLeafNode->first      = NULL;
    newLeafNode->second     = NULL;
    newLeafNode->third      = NULL;

    rootPtr = newLeafNode;
}

//if tree has only node	
else if(rootPtr->tag == true){

    node *newIntNode = new node;		//allocating memory to each interior node

    newIntNode->minSecond  = -1;
    newIntNode->parent     = NULL;
    newIntNode->minThird   = -1;
    newIntNode->key        = -1;
    newIntNode->tag        = false;
    newIntNode->first      = NULL;
    newIntNode->second     = NULL;
    newIntNode->third      = NULL;

    node *newLeafNode = new node;		//allocating memory to second leaf node

    newLeafNode->minSecond  = -1;
    newLeafNode->parent     = NULL;
    newLeafNode->minThird   = -1;
    newLeafNode->key        = dataInserted;
    newLeafNode->tag        = true;
    newLeafNode->first      = NULL;
    newLeafNode->second     = NULL;
    newLeafNode->third      = NULL;

//check newleaf node is greater or less than the existing node
    if(rootPtr->key > newLeafNode->key){	
        newIntNode->minSecond = rootPtr->key;
        newIntNode->first     = newLeafNode;
        newIntNode->second    = rootPtr;
    }
    else{
        newIntNode->minSecond  = newLeafNode->key;
        newIntNode->first      = rootPtr;
        newIntNode->second     = newLeafNode;
    }

    newLeafNode->parent   = newIntNode;
    rootPtr->parent       = newIntNode;
    rootPtr               = newIntNode;
}

//if more than one node is present
else{
//traverse to the interior node
   travPtr = rootPtr;
   while(travPtr->tag != true){
    if(dataInserted < travPtr->minSecond)
        travPtr = travPtr->first;
    else if((dataInserted >= travPtr->minSecond && dataInserted < travPtr->minThird) || travPtr->minThird == -1)
        travPtr = travPtr->second;
    else
        travPtr = travPtr->third;
   }

    travPtr = travPtr->parent;

    node *newLeafNode = new node;			//allocate memory to leaf node

    newLeafNode->minSecond  = -1;
    newLeafNode->parent     = NULL;
    newLeafNode->minThird   = -1;
    newLeafNode->key        = dataInserted;
    newLeafNode->tag        = true;
    newLeafNode->first      = NULL;
    newLeafNode->second     = NULL;
    newLeafNode->third      = NULL;

//if interior node has only two leaf nodes then attach to  it
    if(travPtr->minThird == -1){
       if(travPtr->minSecond < newLeafNode->key){
            travPtr->minThird = newLeafNode->key;
            travPtr->third    = newLeafNode;
       }
        else{
           travPtr->minThird  = travPtr->minSecond;
           travPtr->third     = travPtr->second;
           node* childPtr = travPtr->first;

            if(childPtr->key < newLeafNode->key){
                travPtr->minSecond = newLeafNode->key;
                travPtr->second    = newLeafNode;
            }
            else{
                travPtr->minSecond = childPtr->key;
                travPtr->second    = travPtr->first;
                travPtr->first     = newLeafNode;
            }
        }

      newLeafNode->parent = travPtr;
    }
//if ineterior node has three leaves already then split it
    else{
            node *newIntNode = new node;		//allocate a new interior node

            newIntNode->minSecond  = -1;
            newIntNode->parent     = NULL;
            newIntNode->minThird   = -1;
            newIntNode->key        = -1;
            newIntNode->tag        = false;
            newIntNode->first      = NULL;
            newIntNode->second     = NULL;
            newIntNode->third      = NULL;

            node *newIntNodeRoot = new node;		//allocate a new root node to the two split nodes

            newIntNodeRoot->minSecond  = -1;
            newIntNodeRoot->parent     = NULL;
            newIntNodeRoot->minThird   = -1;
            newIntNodeRoot->key        = -1;
            newIntNodeRoot->tag        = false;
            newIntNodeRoot->first      = NULL;
            newIntNodeRoot->second     = NULL;
            newIntNodeRoot->third      = NULL;

            node* parent = travPtr->parent;

//check if the datainserted is less than the minSecond
        if(newLeafNode->key < travPtr->minSecond){
            node *childPtr = travPtr->first;

             if(newLeafNode->key > childPtr->key){
                newIntNode->minSecond = newLeafNode->key;
                newIntNode->first     = travPtr->first;
                newIntNode->second    = newLeafNode;
             }
             else{
                newIntNode->minSecond = childPtr->key;
                newIntNode->first     = newLeafNode;
                newIntNode->second    = travPtr->first;
             }

             newLeafNode->parent  = newIntNode;
             childPtr->parent     = newIntNode;


             newIntNodeRoot->minSecond = travPtr->minSecond;
             newIntNodeRoot->first     = newIntNode;
             newIntNodeRoot->second    = travPtr;

             travPtr->minSecond = travPtr->minThird;
             travPtr->minThird  = -1;
             travPtr->first     = travPtr->second;
             travPtr->second    = travPtr->third;
             travPtr->third     = NULL;

             newIntNode->parent = newIntNodeRoot;
             travPtr->parent    = newIntNodeRoot;
        }

//check if the datainserted is between minSecond and minThird
        else if(newLeafNode->key < travPtr->minThird){
              newIntNode->minSecond = travPtr->minThird;
              newIntNode->first     = newLeafNode;
              newIntNode->second    = travPtr->third;

              newLeafNode->parent    = newIntNode;
              node* childPtr         = travPtr->third;
              childPtr->parent       = newIntNode;

              newIntNodeRoot->minSecond = newLeafNode->key;
              newIntNodeRoot->first     = travPtr;
              newIntNodeRoot->second    = newIntNode;

              travPtr->minThird     = -1;
              travPtr->third        = NULL;

              travPtr->parent    = newIntNodeRoot;
              newIntNode->parent = newIntNodeRoot;
        }
//else if it is greater than minThird
        else {
              newIntNode->minSecond = newLeafNode->key;
              newIntNode->first     = travPtr->third;
              newIntNode->second    = newLeafNode;

              newLeafNode->parent   = newIntNode;
              node* childPtr        = travPtr->third;
              childPtr->parent      = newIntNode;

              newIntNodeRoot->minSecond = travPtr->minThird;
              newIntNodeRoot->first     = travPtr;
              newIntNodeRoot->second    = newIntNode;

              travPtr->minThird = -1;
              travPtr->third   = NULL;

              travPtr->parent    = newIntNodeRoot;
              newIntNode->parent = newIntNodeRoot;
        }

        updateParentRecur(parent, newIntNodeRoot);			//update the parent of the existing interior nodes till the root
    }
  }
}

//recursively updates the parent of the existing tree			//it uses the same logic as the creation of a node in the 2-3 Tree	
void twoThreeClass::updateParentRecur(node* parent, node* &newIntNodeRoot){

if(parent==NULL){
    rootPtr = newIntNodeRoot;
    newIntNodeRoot->parent = NULL;
}

else if(parent->minThird == -1){
        if(newIntNodeRoot->minSecond < parent->minSecond){
            parent->minThird    = parent->minSecond;
            parent->minSecond   = newIntNodeRoot->minSecond;
            parent->third       = parent->second;
            parent->first       = newIntNodeRoot->first;
            parent->second      = newIntNodeRoot->second;
        }
        else{
            parent->minThird = newIntNodeRoot->minSecond;
            parent->second   = newIntNodeRoot->first;
            parent->third    = newIntNodeRoot->second;
        }

            node *fChild    = newIntNodeRoot->first;
            fChild->parent  = parent;
            node *sChild    = newIntNodeRoot->second;
            sChild->parent  = parent;

            delete newIntNodeRoot;
}
else{
            node *newIntNodeNew = new node;

            newIntNodeNew->minSecond  = -1;
            newIntNodeNew->parent     = NULL;
            newIntNodeNew->minThird   = -1;
            newIntNodeNew->key        = -1;
            newIntNodeNew->tag        = false;
            newIntNodeNew->first      = NULL;
            newIntNodeNew->second     = NULL;
            newIntNodeNew->third      = NULL;

            node *newIntNodeRootNew = new node;

            newIntNodeRootNew->minSecond  = -1;
            newIntNodeRootNew->parent     = NULL;
            newIntNodeRootNew->minThird   = -1;
            newIntNodeRootNew->key        = -1;
            newIntNodeRootNew->tag        = false;
            newIntNodeRootNew->first      = NULL;
            newIntNodeRootNew->second     = NULL;
            newIntNodeRootNew->third      = NULL;

            node* parentNew = parent->parent;

        if(newIntNodeRoot->minSecond < parent->minSecond){

             newIntNodeRootNew->minSecond = parent->minSecond;
             newIntNodeRootNew->first     = newIntNodeRoot;
             newIntNodeRootNew->second    = parent;

             parent->minSecond = parent->minThird;
             parent->minThird  = -1;
             parent->first     = parent->second;
             parent->second    = parent->third;
             parent->third     = NULL;

             parent->parent          = newIntNodeRootNew;
             newIntNodeRoot->parent  = newIntNodeRootNew;

		delete newIntNodeNew;
        }
        else if(newIntNodeRoot->minSecond < parent->minThird){

              newIntNodeNew->minSecond = parent->minThird;
              newIntNodeNew->first     = newIntNodeRoot->second;
              newIntNodeNew->second    = parent->third;

              node* childPtr         = parent->third;
              childPtr->parent       = newIntNodeNew;
              childPtr               = newIntNodeRoot->second;
              childPtr->parent       = newIntNodeNew;

              newIntNodeRootNew->minSecond = newIntNodeRoot->minSecond;
              newIntNodeRootNew->first     = parent;
              newIntNodeRootNew->second    = newIntNodeNew;

              parent->minThird     = -1;
              parent->third        = NULL;
              parent->second       = newIntNodeRoot->first;
              childPtr             = newIntNodeRoot->first;
              childPtr->parent     = parent;

              parent->parent        = newIntNodeRoot;
              newIntNodeNew->parent = newIntNodeRoot;

              delete newIntNodeRoot;

        }
        else {

              newIntNodeRootNew->minSecond = parent->minThird;
              newIntNodeRootNew->first     = parent;
              newIntNodeRootNew->second    = newIntNodeRoot;

              parent->minThird = -1;
              parent->third   = NULL;

              parent->parent         = newIntNodeRootNew;
              newIntNodeRoot->parent = newIntNodeRootNew;

		delete newIntNodeNew;
        }

        updateParentRecur(parentNew, newIntNodeRootNew);		//recursively call the same function to update the rest of the tree
}

}


//find data function
int twoThreeClass::findData(int dataInserted){

if(rootPtr == NULL){
    cout << "The Tree is empty" << endl;
    return -1;
}
else{
    return findDataRecur(rootPtr, dataInserted);			//recusrive call to traverse the tree to find the desired  node
}
}


//recursive find function
int twoThreeClass::findDataRecur(node* &travPtr, int dataInserted){
   if(travPtr == NULL)
        return -1;
   else{
    if(travPtr->tag == true && travPtr->key == dataInserted)
        return 0;
    else if(dataInserted < travPtr->minSecond)
        return findDataRecur(travPtr->first, dataInserted);
    else if((dataInserted >= travPtr->minSecond && dataInserted < travPtr->minThird)|| travPtr->minThird == -1)
        return findDataRecur(travPtr->second, dataInserted);
    else
        return findDataRecur(travPtr->third, dataInserted);
   }
}


//delete function
void twoThreeClass::deleteData(int dataInserted){

if(rootPtr->tag == true && rootPtr->key == dataInserted){			//if the tree has only one node
    delete rootPtr;
    rootPtr = NULL;
}
else{										//else traverse to the desired node to delete
   travPtr = rootPtr;
   while(travPtr->tag != true){
    if(dataInserted < travPtr->minSecond)
        travPtr = travPtr->first;
    else if((dataInserted >= travPtr->minSecond && dataInserted < travPtr->minThird) || travPtr->minThird == -1)
        travPtr = travPtr->second;
    else
        travPtr = travPtr->third;
   }

    node* parentPtr = travPtr->parent;
    node* ancestorPtr = parentPtr->parent;

//check if the interior node containing the data has three leaf nodes then simply delete the leaf node
    if(parentPtr->minThird != -1){
        if(dataInserted <= parentPtr->minSecond){

            if(dataInserted < parentPtr->minSecond){
                parentPtr->first  = parentPtr->second;
                parentPtr->second = parentPtr->third;
            }
             else if(dataInserted == parentPtr->minSecond){
                parentPtr->second  = parentPtr->third;
             }

             parentPtr->minSecond = parentPtr->minThird;
             parentPtr->minThird = -1;
             parentPtr->third    = NULL;
        }
        else{
          parentPtr->minThird = -1;
          parentPtr->third    = NULL;

        }

        delete travPtr;
        updateAncestorRecur(ancestorPtr);			//update the rest of the interior node till root
    }
//else borrow or give away to the adjacent sibling node
    else{
//if the interior node is not the root node
        if(ancestorPtr != NULL){
                node *siblingPtr;

            if(dataInserted < ancestorPtr->minSecond)
                siblingPtr  = ancestorPtr->second;
            else if((dataInserted >= ancestorPtr->minSecond && dataInserted < ancestorPtr->minThird) || ancestorPtr->minThird == -1)
                siblingPtr = ancestorPtr->first;
            else
                siblingPtr = ancestorPtr->second;

//if the sibling node has three leaf nodes then borrow one from it
            if(siblingPtr->minThird != -1){

                if(parentPtr->minSecond == dataInserted){
                    if(dataInserted > siblingPtr->minThird){
                            node *tempPtr           = parentPtr->first;
                            parentPtr->minSecond    = tempPtr->key;
                            parentPtr->second       = parentPtr->first;
                            parentPtr->first        = siblingPtr->third;
                            tempPtr                 = siblingPtr->third;
                            tempPtr->parent         = parentPtr;

                            siblingPtr->minThird    = -1;
                            siblingPtr->third       = NULL;
                        }
                    else{
                            node *tempPtr           = siblingPtr->first;
                            parentPtr->minSecond    = tempPtr->key;
                            tempPtr->parent         = parentPtr;
                            parentPtr->second       = siblingPtr->first;

                            siblingPtr->first       = siblingPtr->second;
                            siblingPtr->second      = siblingPtr->third;
                            siblingPtr->minSecond   = siblingPtr->minThird;
                            siblingPtr->minThird    =  -1;
                            siblingPtr->third       = NULL;
                        }
                    }
                    else{
                        if(dataInserted > siblingPtr->minThird){
                            parentPtr->first = siblingPtr->third;
                            node *tempPtr    = siblingPtr->third;
                            tempPtr->parent  = parentPtr;

                            siblingPtr->minThird    = -1;
                            siblingPtr->third       = NULL;
                        }
                        else{
                            node *tempPtr = siblingPtr->first;
                            parentPtr->minSecond    = tempPtr->key;
                            tempPtr->parent         = parentPtr;
                            parentPtr->first        = parentPtr->second;
                            parentPtr->second       = siblingPtr->first;

                            siblingPtr->first       = siblingPtr->second;
                            siblingPtr->second      = siblingPtr->third;
                            siblingPtr->minSecond   = siblingPtr->minThird;
                            siblingPtr->minThird    =  -1;
                            siblingPtr->third       = NULL;
                        }
                    }
                    delete travPtr;						//delete the leaf node containing the data
                    updateAncestorRecur(ancestorPtr);				//then update the tree
                }
//if the sibling node has two leaf nodes then give away your one remaining leaf node 
                else{
                    if(dataInserted < siblingPtr->minSecond){
                        node *tempPtr = siblingPtr->first;
                        siblingPtr->minThird = siblingPtr->minSecond;
                        siblingPtr->minSecond = tempPtr->key;
                        siblingPtr->third      = siblingPtr->second;
                        siblingPtr->second     = siblingPtr->first;

                        if(parentPtr->minSecond == dataInserted){
                            siblingPtr->first   = parentPtr->first;
                            tempPtr = parentPtr->first;
                            tempPtr->parent     = siblingPtr;
                        }
                        else{
                            siblingPtr->first   = parentPtr->second;
                            tempPtr = parentPtr->second;
                            tempPtr->parent     = siblingPtr;
                        }
                   }
                   else{
                        node *tempPtr;
                        if(parentPtr->minSecond == dataInserted){
                            siblingPtr->third   = parentPtr->first;
                            tempPtr             = parentPtr->first;
                            tempPtr->parent     = siblingPtr;

                            siblingPtr->minThird = tempPtr->key;
                        }
                        else{
                            siblingPtr->third   = parentPtr->second;
                            tempPtr             = parentPtr->second;
                            tempPtr->parent     = siblingPtr;

                            siblingPtr->minThird   = tempPtr->key;
                        }
                   }

                   if(parentPtr->minSecond < ancestorPtr->minSecond){
                        if(ancestorPtr->minThird != -1){
                            ancestorPtr->first  = ancestorPtr->second;
                            ancestorPtr->second = ancestorPtr->third;
                            ancestorPtr->third  = NULL;
                        }
                        else{
                            ancestorPtr->first = ancestorPtr->second;
                            ancestorPtr->second = NULL;
                        }
                   }
                    else if((parentPtr->minSecond >= ancestorPtr->minSecond && parentPtr->minSecond < ancestorPtr->minThird) || ancestorPtr->minThird == -1){
                        if(ancestorPtr->minThird != -1){
                            ancestorPtr->second = ancestorPtr->third;
                            ancestorPtr->third  = NULL;
                        }
                        else
                            ancestorPtr->second = NULL;
                    }
                    else{
                        if(ancestorPtr->minThird != -1)
                            ancestorPtr->third  = NULL;
                        }
		
                delete travPtr;                         //delete the leaf node containing the data
                delete parentPtr;			//delete the parent node as it is not left with any more leaf nodes

                updateAncestorRecur(ancestorPtr);	//update the rest of the tree
            }
        }
//if the interior node is the root node then update the rootPtr
        else{
              if(dataInserted == parentPtr->minSecond){
                node *tempPtr = parentPtr->first;
                tempPtr->parent = NULL;
                rootPtr  = tempPtr;
              }
              else{
                node *tempPtr = parentPtr->second;
                tempPtr->parent = NULL;
                rootPtr = tempPtr;
              }
           delete travPtr;
           delete parentPtr;
        }
    }
}
}


//recursively update the remaining tree using the same logic as deleting the leaf node
void twoThreeClass::updateAncestorRecur(node *parentPtr){

if(parentPtr != NULL){
 if(parentPtr->second != NULL){
    node *travPtr = parentPtr->second;
    while(travPtr->tag != true)
        travPtr = travPtr->first;

    if(travPtr->key != parentPtr->minSecond){
        parentPtr->minSecond = travPtr->key;

    }

    if(parentPtr->third != NULL){
        travPtr = parentPtr->third;
        while(travPtr->tag != true)
            travPtr = travPtr->first;

        if(travPtr->key != parentPtr->minThird){
            parentPtr->minThird = travPtr->key;
        }
    }
    else
        parentPtr->minThird = -1;
 }
 else{
        node* ancestorPtr = parentPtr->parent;

        if(ancestorPtr != NULL){
                node *siblingPtr;

            if(parentPtr->minSecond < ancestorPtr->minSecond)
                siblingPtr  = ancestorPtr->second;
            else if((parentPtr->minSecond >= ancestorPtr->minSecond && parentPtr->minSecond < ancestorPtr->minThird) || ancestorPtr->minThird == -1)
                siblingPtr = ancestorPtr->first;
            else
                siblingPtr = ancestorPtr->second;

            if(siblingPtr->minThird==-1){
               if(parentPtr->minSecond < siblingPtr->minSecond){
                    siblingPtr->minThird = siblingPtr->minSecond;
                    node *temp = siblingPtr->first;
                    while(temp->tag != true)
                        temp = temp->first;

                    siblingPtr->minSecond = temp->key;
                    siblingPtr->third = siblingPtr->second;
                    siblingPtr->second = siblingPtr->first;
                    siblingPtr->first = parentPtr->first;

                    temp = parentPtr->first;
                    temp->parent = siblingPtr;
               }
               else{
                    node *temp = parentPtr->first;
                    while(temp->tag != true)
                        temp = temp->first;
                    siblingPtr->minThird = temp->key;
                    
		    temp = parentPtr->first;
		    temp->parent = siblingPtr;
                    siblingPtr->third = parentPtr->first;
               }

               if(parentPtr->minSecond < ancestorPtr->minSecond){
                        if(ancestorPtr->minThird != -1){
                            ancestorPtr->first  = ancestorPtr->second;
                            ancestorPtr->second = ancestorPtr->third;
                            ancestorPtr->third  = NULL;
                        }
                        else{
                            ancestorPtr->first = ancestorPtr->second;
                            ancestorPtr->second = NULL;
                        }
               }
              else if((parentPtr->minSecond >= ancestorPtr->minSecond && parentPtr->minSecond < ancestorPtr->minThird) || ancestorPtr->minThird == -1){
                        if(ancestorPtr->minThird != -1){
                            ancestorPtr->second = ancestorPtr->third;
                            ancestorPtr->third  = NULL;
                        }
                        else
                            ancestorPtr->second = NULL;
                }
              else{
                        if(ancestorPtr->minThird != -1)
                            ancestorPtr->third  = NULL;
                        }

               delete parentPtr;
               updateAncestorRecur(ancestorPtr);
            }
            else{
                 if(parentPtr->minSecond < siblingPtr->minSecond){
                    node *temp = siblingPtr->first;
                    parentPtr->minSecond = temp->key;
                    temp->parent = parentPtr;
                    parentPtr->second = siblingPtr->first;
                    parentPtr->third  = NULL;
                    parentPtr->minThird = -1;

                    siblingPtr->minSecond = siblingPtr->minThird;
                    siblingPtr->minThird = -1;
                    siblingPtr->first = siblingPtr->second;
                    siblingPtr->second = siblingPtr->third;
                    siblingPtr->third = NULL;
                }
                else{
                        node *temp = parentPtr->first;
                        parentPtr->minSecond = temp->key;
                        parentPtr->minThird = -1;
                        parentPtr->second = parentPtr->first;
                        parentPtr->first = siblingPtr->third;
                        parentPtr->third = NULL;

                        temp= siblingPtr->third;
                        temp->parent = parentPtr;
                        siblingPtr->minThird = -1;
                        siblingPtr->third = NULL;
                }

              updateAncestorRecur(ancestorPtr);
            }
        }
        else{
                node *tempPtr = parentPtr->first;
                tempPtr->parent = NULL;
                rootPtr  = tempPtr;

               delete parentPtr;
        }
    }
}
}


//find the min no from the tree
int twoThreeClass::findMin(){
travPtr = rootPtr;

if(travPtr == NULL){
    return -1;
}
else{
    while(travPtr->first != NULL){
        travPtr = travPtr->first;
    }
    return travPtr->key;
}
}

//recursive call to the max no function
int twoThreeClass::findMax(){
    return findMaxRecur(rootPtr);
}

//recursive function to find the max no
int twoThreeClass::findMaxRecur(node *travPtr){

if(travPtr == NULL)
    return -1;
else if(travPtr->tag == true)
    return travPtr->key;
else{

    if(travPtr->third != NULL)
        travPtr = travPtr->third;
    else
        travPtr = travPtr->second;

        return findMaxRecur(travPtr);
}
}

//delete max no from the tree
void twoThreeClass::deleteMax(){
    int maxNo = findMax();
    if(maxNo == -1){
        cout << "The Tree is already empty" << endl;
    }
    else{
        deleteData(maxNo);
        cout << "The max no " << maxNo << " is deleted" << endl;
    }
}

//delete the min no from the tree
void twoThreeClass::deleteMin(){
    int minNo = findMin();
    if(minNo == -1)
        cout << "The Tree is already empty" << endl;
    else{
        deleteData(minNo);
        cout << "The min no " << minNo << " is deleted" << endl;
    }
}

//level order traversal using Link List as queue
void twoThreeClass::levelOrder(){

//if the tree is not empty
if(rootPtr != NULL){
 node *travPtrFirst, *travPtrSecond, *travPtrThird;
 nodeList* temp, *travList;

 nodeList *newNode = new nodeList;		//allocate memory to the leaf node
 newNode->item = rootPtr;
 newNode->next = NULL;

 temp = newNode;
 travList = newNode;

//traverse the queue till its empty
 while(travList!= NULL){

   travPtr = travList->item;

//if there is only one leaf in the tree
   if(travPtr->parent == NULL && travPtr->tag == true)
       cout << travPtr->key << " ";

//enqueue the first child
   if(travPtr->first != NULL){
        travPtrFirst = travPtr->first;
        nodeList *newNode = new nodeList;
        newNode->item = travPtr->first;
        newNode->next = NULL;
        temp->next = newNode;
        temp = newNode;

        if(travPtrFirst != NULL && travPtrFirst->tag == true)
            cout << travPtrFirst->key << " ";
   }

//enqueue the second child
   if(travPtr->second != NULL){
        travPtrSecond = travPtr->second;
        nodeList *newNode = new nodeList;
        newNode->item = travPtr->second;
        newNode->next = NULL;
        temp->next = newNode;
        temp = newNode;

        if(travPtrSecond != NULL && travPtrSecond->tag == true)
            cout << travPtrSecond->key << " ";
   }

//enqueue the third child
   if(travPtr->third != NULL){
        travPtrThird = travPtr->third;
        nodeList *newNode = new nodeList;
        newNode->item = travPtr->third;
        newNode->next = NULL;
        temp->next = newNode;
        temp = newNode;

        if(travPtrThird != NULL && travPtrThird->tag == true)
            cout << travPtrThird->key << " ";
   }

//dequeue the queue once traversed
     nodeList *destruct = travList;		
     travList = travList->next;
     delete destruct;	 
  }
}

//if the tree is empty
else
    cout << "The 2-3 Tree is empty" << endl;
}




