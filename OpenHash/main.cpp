#include <iostream>

#include "openhash.h"

#include <fstream>



using namespace std;



//declaration of function to Print Query on Screen for user

void print_query();



//main function

int main()

{

 int input, dataInserted, check = 0;

 openhash openhashObj;                                                      //object creation for hash class



 print_query();                                                             //calling the print query function

 cin >> input;



 while(input != 5){



    switch(input){

        case 1: cout << "\nPlease enter the No. to Insert" << endl;

                cin >> dataInserted;                                         //taking data input from user to insert

                check = openhashObj.find_hash(dataInserted);                 //check for duplicate entries

                if(check != -1){

                    cout << "Already exist at bucket : " << check << endl;

                }

                else{

                    openhashObj.insert_data(dataInserted);                   //calling insert function

                }

                break;

        case 2: cout << "\nPlease enter the No. to Delete" << endl;

                cin >> dataInserted;                                         //taking data input from user to delete

                check = openhashObj.find_hash(dataInserted);                 //check for non existing entries

                if(check == -1){

                    cout << "Data not found to delete" << endl;

                }

                else{

                    openhashObj.delete_data(dataInserted);                   //calling delete function

                }

                break;

        case 3:  cout << "\nPlease enter the no to Find" << endl;

                cin >> dataInserted;                                         //taking data input from user to find

                check = openhashObj.find_hash(dataInserted);                 //calling the find function

                if(check != -1){

                    cout << "Data exist at bucket: " << check << endl;

                }

                else{

                    cout << "Data not found" << endl;

                }

                break;

        case 4: openhashObj.display_list();                                  //calling the print function

                break;

        default:

            cout << "Incorrect input \n";                                    //for any other case make a default output

    }



    print_query();                                                           //keep running unless user calls for exit

    cin >> input;

    }

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



};
