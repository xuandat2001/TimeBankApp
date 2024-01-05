#include <iostream>
#include "Guest.h"
#include "Admin.h"

using namespace std;
using std::string;
using std::cin;
using std::cout;


int main(){
    int choice;

    Guest Guests;
    Admin admin;

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
            Guests.registerMember();//cant call function
            }

        else if (choice1 == 2){
            Guests.viewSupporters();//cant call function

            } else {
        cout << "Invalid choice. Please choose 0, 1 or 2\n";
        } 
        } 

    else if (choice == 3) {
        string AuserName;
        string Apassword;
        cout << "Enter your Username: ";
        cin >>  AuserName;
        cout << "Enter your password: ";
        cin >> Apassword;

        string Auname = admin.getAuserName();
        string Apword = admin.getApassword();
        if (AuserName == Auname){
            if (Apassword == Apword){
                cout << "Sign in successfully \n";

                int memNumber;
                int memNum = Guests.getMemNum(); //cant call function
                cout << "Which member's password to change? \n" << "Input member number: ";
                cin >> memNumber;
                if (memNumber == memNum){
                    admin.modifyPassword();
                } else {
                    cout << "Member may not exist. Please enter again. \n";
                }
                
            } else {
                cout << "Wrong password. Please try again. \n";
            }

        }  else {
            cout << "User name or password is incorrect. Please try again. \n";
        }

    } else {
        cout << "Invalid choice. Please choose 1, 2 or 3\n";
    }
    return 0;
}