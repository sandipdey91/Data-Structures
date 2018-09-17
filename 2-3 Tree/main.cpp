#include <iostream>
#include <fstream>
#include "twoThreeClass.h"

using namespace std;

void printQuery();

int main()
{
int input, dataInserted,checkData, minNo, maxNo;                                        //variable declaration

twoThreeClass treeObj;                                                                  //calling the tree object

printQuery();                                                                           //calling print query function

cin >> input;

cout << "........................" << endl;

while(input != 9){

        switch(input){

                case 1: cout << "\nPlease enter the number to Insert" << endl;
                        cin >> dataInserted;
                        cout << "........................" << endl;
                        checkData = treeObj.findData(dataInserted);                      //Check for duplicacy
                        if(checkData != -1){
                                cout << "Data exist in the 2-3 Tree" << endl;
                        }
                        else{
                                treeObj.insertData(dataInserted);                        //Else call insert function
                                cout << "Data successfully Inserted" << endl;
                        }
                        break;

                case 7: cout << "\nPlease enter the number to Delete" << endl;
                        cin >> dataInserted;
                        cout << "........................" << endl;

                        checkData = treeObj.findData(dataInserted);                      //Check if the data exist or not
                        if(checkData == -1){
                                cout << "Data does not exist in the BST" << endl;
                        }
                        else{
                                treeObj.deleteData(dataInserted);                        //Else call delete function
                                cout << "Data successfully deleted" << endl;
                        }
                        break;

                case 2: treeObj.deleteMin();                                             //Calling deleteMin function
                        break;

                case 3: treeObj.deleteMax();                                             //Calling deleteMax function
                        break;

                case 4: minNo = treeObj.findMin();                                       //Calling findMin function
                        if(minNo != -1)
                                cout << "The minimum no is: " << minNo << endl;
                        else
                                cout << "The Tree is empty" << endl;
                        break;

                case 5: maxNo = treeObj.findMax();                                       //Calling findMaz function
                        if(maxNo != -1)
                                cout << "The maximum no is: " << maxNo << endl;
                        else
                                cout << "The Tree is empty" << endl;
                        break;

                case 6: cout << "\nPlease enter the number to Find" <<endl;
                        cin >> dataInserted;
                        cout << "........................" << endl;

                        checkData = treeObj.findData(dataInserted);                      //Check if the data exist or not
                        if(checkData == -1){
                                cout << "Data does not exist in the 2-3 Tree" << endl;
                        }
                        else{
                                cout << "Data exist in the 2-3 Tree" << endl;
                        }
                        break;

                case 8: treeObj.levelOrder();						 //Level Order Traversal
                        break;

                default:
                        cout << "Incorrect Input" << endl;
                }

        printQuery();
        cin >> input;
        cout << "........................" << endl;
        }
         cout << "\nBYE BYE!!\n\n" << endl;
}



//Prints Query on Command Screen
void printQuery(){
   cout << "\n........................................."   << endl;
   cout << "Please choose one of the following commands"   << endl;
   cout << "1.Insert"                                      << endl;
   cout << "2.Delete Min"                                  << endl;
   cout << "3.Delete Max"                                  << endl;
   cout << "4.Find Min"                                    << endl;
   cout << "5.Find Max"                                    << endl;
   cout << "6.Find"                                        <<endl;
   cout << "7.Delete"                                      <<endl;
   cout << "8.Level Order Traversal"                       <<endl;
   cout << "9.Exit\n"                                      <<endl;
}




