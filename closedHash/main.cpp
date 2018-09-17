#include <iostream>
#include "quadHash.h"
#include "doubHash.h"
#include <fstream>
#include <math.h>

using namespace std;

//declaration of function to Print Query on Screen for user
void print_query();

//main function
int main(int argc, char *argv[])
{
 int input, dataInserted, checkQuad = 0, checkDoub = 0;

 quadHash quadHashObj(argc, argv);                                                      	//object creation for quadratic hash class
 doubHash doubHashObj(argc, argv);								//object creation for double hash class


 print_query();                                                             	            	//calling the print query function

 cin >> input;

 while(input != 5){

    switch(input){

        case 1: cout << "\nPlease enter the No. to Insert" << endl;

                cin >> dataInserted;                                         		        //taking data input from user to insert

                checkQuad = quadHashObj.findData(dataInserted);
                if(checkQuad == -1){
               		quadHashObj.insertData(dataInserted);                   		//calling insert function for Quadratic Hashing
                }
                else{
                cout << "Data exist in Quadratic Hash Table" << endl;
                }

                checkDoub = doubHashObj.findData(dataInserted);
                if(checkDoub == -1){
                    doubHashObj.insertData(dataInserted);					//calling insert function for Double Hashing
                }
                else{
                    cout << "Data exist in Double Hash Table" << endl;
                }
                break;


        case 2: cout << "\nPlease enter the No. to Delete" << endl;

                cin >> dataInserted;                                         			//taking data input from user to delete

                checkQuad = quadHashObj.findData(dataInserted);
                if(checkQuad != -1){
                        quadHashObj.deleteData(dataInserted);                          		//calling insert function for Quadratic Hashing
                }
                else{
                        cout << "Data does not exist in Quadratic Hash Table" << endl;
                }

                checkDoub = doubHashObj.findData(dataInserted);
                if(checkDoub != -1){
                        doubHashObj.deleteData(dataInserted);                          		//calling insert function for Double Hashing
                }
                else{
                        cout << "Data does not exist in Double Hash Table" << endl;
                }
                break;


        case 3:  cout << "\nPlease enter the no to Find" << endl;

                cin >> dataInserted;                                         			//taking data input from user to find

                checkQuad = quadHashObj.findData(dataInserted);                 		//calling the find function
                if(checkQuad != -1){

                    cout << "Data exist at bucket: " << checkQuad << " in Quadratic Hash Table"  << endl;

                }

                else{

                    cout << "Data not found in Quadratic Hash Table" << endl;

                }

		checkDoub = doubHashObj.findData(dataInserted);
		if(checkDoub != -1){
			cout << "Data exist at bucket: " << checkDoub << " in Double Hash Table" << endl;
            }
		else{
			cout << "Data not found in Double Hash Tabke" << endl;
            }
                break;


        case 4: quadHashObj.displayList();                                  			//calling the print function
		doubHashObj.displayList();							//calling the double hash table print function
                break;

        default:

            cout << "Incorrect input \n";                                    			//for any other case make a default output

    }



    print_query();                                                           			//keep running unless user calls for exit

    cin >> input;

    }

    cout << "\nBYE BYE!!" << endl;
}



//definition of function to Print Query on Screen for user

void print_query(){

        cout << "\n........................................." << endl;

        cout << "Please choose one of the following commands" << endl;

        cout << "1.Insert"  << endl;

        cout << "2.Delete"  << endl;

        cout << "3.Find"    << endl;

        cout << "4.Print"   << endl;

        cout << "5.Exit\n"    << endl;



}
