#include <iostream>
#include <fstream>
#include <cassert>
#include "calculation.h"
#include <stdlib.h>
#include<unistd.h> // preprocessor directive: provide access to "sleep()".
using namespace std;



int main() {
    InforXApp inforXApp;

    int choice,chances=0;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tWELCOME TO inforX APP";
    sleep(1.5);
    system("cls");
    

    do {
    	cout <<"\n\t --------------------------------\n" // menu
             <<"\t inforX app\n" 
        	 <<"\t --------------------------------\n"
        	 << "\t 1. Encrypt Text\n"
             << "\t 2. Decrypt Text\n"
             << "\t 3. Exit\n";
        cout << "\t Enter your choice: ";
        do {
        	cin >> choice;
        	cin.ignore();
        	if (cin.fail() || (choice < 1 || choice > 3)  ){
        		if(chances<2){
        			chances++;
            		cout << "\t Invalid choice. Please enter again: ";
				}
				else {
					cout <<"\n\t You already try 3 times, please restart again this app in 5 seconds..." << endl;  //tell user to restart app
			    	sleep(5);                                                                                     //delay for 5 second
			    	return 0;
				}
			}
        	
			else {
				chances=0;
				break;
			}
         } while (true);

        switch (choice) {
            case 1:
            	system("cls");
                inforXApp.encryptText();
                break;
            case 2:
            	system("cls");
                inforXApp.decryptText();
                break;
            case 3:
            	system("cls");
                cout << "\n\n\n\n\n\n\t\t\t\t\t\tExiting the program......\n";
                sleep(3);
                system("cls");
			    cout << "\n\n\n\n\n\n\t\t\t\t\t\tThank You for Using inforX App:)\n\n\n\n\n\n\n\n\n\n";
			    sleep(2);
                break;
            default:               
                break;
                
        }

    } while (choice != 3);

    return 0;
}
