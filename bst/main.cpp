#include <iostream>
#include <fstream>
#include "bstClass.h"

using namespace std;

void printQuery();

int main(int argc, char *argv[]){						//passing file names through command line argument

int input, dataInserted,checkData, minNo, maxNo;				//variable declaration

bstClass bstObj(argc, argv);							//passing file names to the object

printQuery();									//calling print query function

cin >> input;

cout << "........................" << endl;

while(input != 10){

	switch(input){

		case 1: cout << "\nPlease enter the number to Insert" << endl;
                	cin >> dataInserted;
                	cout << "........................" << endl;
                	bstObj.insertData(dataInserted);				//Calling Insert Function
			break;

		case 2: cout << "\nPlease enter the number to Delete" << endl;
                	cin >> dataInserted;
                	cout << "........................" << endl;

                	checkData = bstObj.findData(dataInserted);			//Check if the data exist or not
                	if(checkData != -1){
                    		cout << "Data does not exist in the BST" << endl;
                	}
                	else{
                    		bstObj.deleteData(dataInserted);			//Else call delete function
                    		cout << "Data successfully deleted" << endl;
                    	}
			break;

		case 5: bstObj.deleteMin();						//Calling deleteMin function
			break;

		case 6: bstObj.deleteMax();						//Calling deleteMax function
			break;

		case 3: minNo = bstObj.findMin();					//Calling findMin function
                	if(minNo != -1)
                    		cout << "The minimum no is: " << minNo << endl;
                 	else
                    		cout << "The Tree is empty" << endl;
			break;

		case 4: maxNo = bstObj.findMax();					//Calling findMaz function
                	if(maxNo != -1)
                    		cout << "The maximum no is: " << maxNo << endl;
                	else
                    		cout << "The Tree is empty" << endl;
			break;

		case 7: bstObj.preOrder();						//preorder function
            		break;

		case 8: bstObj.postOrder();						//postorder function
			break;

		case 9: bstObj.inOrder();						//inorder function
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

        cout << "\n........................................." 	<< endl;

        cout << "Please choose one of the following commands" 	<< endl;

        cout << "1.Insert"  			    		<< endl;

        cout << "2.Delete" 		 	        	<< endl;

        cout << "3.Find Min"    		    		<< endl;

        cout << "4.Find Max"	   		    		<< endl;

        cout << "5.Delete Min"    		    		<< endl;

        cout << "6.Delete Max"			    		<<endl;

        cout << "7.Preorder Traversal"  			<<endl;

        cout << "8.Postorder Traversal"     			<<endl;

        cout << "9.Inorder Traversal"       			<<endl;

        cout << "10.Exit\n"			        	<<endl;


}
