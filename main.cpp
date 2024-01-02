#include <iostream>
#include "Guest.h"

using namespace std;
using std::string;
using std::cin;
using std::cout;


int main(){
    int choice;

    Guest Guests;

    cout << "EEET2482/COSC2082 ASSIGNMENT\n" << "TIME BANK APPLICATION\n" << "Instructor: Mr. Tran Duc Linh\n" << "Group: Group No.\n" 
        << "sXXXXXXX, Student Name\n" << "sXXXXXXX, Student Name\n" << "sXXXXXXX, Student Name\n" << "sXXXXXXX, Student Name\n"
        << "Use the app as 1. Guest 2. Member 3. Admin\n"
        << "Enter your choice: ";

    cin >> choice;

    if (choice == 1){
        cout << "This is your menu:\n" << "0. Exit\n" << "1. Register for a Member account\n" << "2. View supporters' details\n";
        int choice1;
        cout <<"Enter your choice: ";
        cin >> choice1;

        if (choice1 == 1){
            Guests.registerMember();
            }

        else if (choice1 == 2){
            Guests.viewSupporters();

            } else {
        cout << "Invalid choice. Please choose 1\n";
        } 
        } else {
        cout << "Invalid choice. Please choose 1, 2 or 3\n";
    }
    return 0;
}