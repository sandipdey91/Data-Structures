#include <iostream>

#include "list.h"

#include <fstream>



using namespace std;



//declaration of function to Print Query on Screen for user

void print_query();



//main function

int main()

{

    List listobj;                                                             //object creation for list class



    int input, data_inserted, check = 0;

    print_query();                                                            //calling the print query function

    cin >> input;



while(input != 5){

    switch(input){

        case 1: cout << "\nPlease enter the No. to Insert" << endl;

                cin >> data_inserted;                                         //taking data input from user to insert

                check = 0;

                check = listobj.find_list(data_inserted);                     //check for duplicate entries

                if(check > 0){

                 cout << "Already exist at position : " << check << endl;

                }

                else{

                listobj.insert_data(data_inserted);                           //calling insert function

                }

                break;

        case 2: cout << "\nPlease enter the No. to Delete" << endl;

                cin >> data_inserted;                                         //taking data input from user to delete

                check = 0;

                check = listobj.find_list(data_inserted);                     //check for non existing entries

                if(check == 0){

                 cout << "Data not found to delete" << endl;

                }

                else{
		
		if(check > 0){
                	listobj.delete_data(data_inserted);                           //calling insert function
		}
                }

                break;

        case 3: check = 0;

                cout << "\nPlease enter the no to Find" << endl;

                cin >> data_inserted;                                         //taking data input from user to find

                check = listobj.find_list(data_inserted);                     //calling the find function

                if(check != 0){

                cout << "Data exist at position : " << check << endl;

                }

                else{

                cout << "Data not found" << endl;

                }

                break;

        case 4: listobj.display_list();                                       //calling the print function

                break;

        default:

            cout << "Incorrect input \n";                                     //for any other case make a default output

    }



    print_query();                                                            //keep running unless user calls for exit

    cin >> input;

    }



    return 0;

}



//definition of function to Print Query on Screen for user

void print_query(){



        cout << "\n\nPlease choose one of the following commands\n";

        cout << "1.Insert \n";

        cout << "2.Delete \n";

        cout << "3.Find \n";

        cout << "4.Print \n";

        cout << "5.Exit \n";



};
