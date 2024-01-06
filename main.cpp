#include <iostream>
#include <vector>
#include "Guest.h"
#include "Admin.h"
#include "Member.h"
#include "listOfMem.h"
using namespace std;
using std::cin;
using std::cout;
using std::string;

int main()
{
    int choice;
    Member mem;
    std::vector<Member> listOfMem;
    Guest Guests;
    Admin admin;

    cout << "EEET2482/COSC2082 ASSIGNMENT\n"
         << "TIME BANK APPLICATION\n"
         << "Instructor: Mr. Tran Duc Linh\n"
         << "Group: Group No.\n"
         << "sXXXXXXX, Student Name\n"
         << "sXXXXXXX, Student Name\n"
         << "sXXXXXXX, Student Name\n"
         << "sXXXXXXX, Student Name\n"
         << "Use the app as 1. Guest 2. Member 3. Admin\n"
         << "Enter your choice: ";

    cin >> choice;

    if (choice == 1)
    {
        cout << "This is your menu:\n"
             << "0. Exit\n"
             << "1. Register for a Member account\n"
             << "2. View supporters' details\n";
        int choice1;
        cout << "Enter your choice: ";
        cin >> choice1;

        if (choice1 == 1)
        {
            Guests.registerMember();
        }

        else if (choice1 == 2)
        {
            Guests.viewSupporters();
        }
        else
        {
            cout << "Invalid choice. Please choose 0, 1 or 2\n";
        }
    }
    else if (choice == 2)
    {

        mem.getInfo(); // get information from the file
        listOfMem.push_back(mem);
        for (int i = 0; i < listOfMem.size(); i++)
        {
            string userName;
            string password;
            while (1)
            {
                cout << "Enter your username: ";
                std::getline(cin >> std::ws, userName); // getusername
                cout << "Enter your Password: ";
                std::getline(cin >> std::ws, password); // get password
                if (listOfMem[i].loginMem(userName, password) == true)
                {
                    int choice; // get choice from user
                    cout << "This is your menu:\n"
                         << "0. Exit\n"
                         << "1. Show Information\n"
                         << "2. Set Status\n"
                         << "3. Search Supporter\n";
                    cout << "Enter ur choice";
                    cin >> choice;
                    // loop through all member in list
                    if (choice == 1)
                    {
                        listOfMem[i].showInfo();
                        break;
                    }
                    else if (choice == 2)
                    {
                        if (listOfMem[i].setStatus() == 1)
                        {
                            listOfMem[i].showInfoVip();
                            break;
                        }
                        else
                        {
                            cout << "This Mem was unlisted";
                            break;
                        }
                    }
                    /*else if (choice == 3)
                    {
                        string condition;
                        cout << "Enter the city: ";
                        std::getline(cin >> std::ws, condition);
                        listOfMem[i].search(condition);
                    }*/
                    else
                    {
                        cout << "Exit";
                        break;
                    }
                }
                else
                {
                    cout << "Please Enter again \n";
                }
            }
        }
    }
    else if (choice == 3)
    {
        string AuserName;
        string Apassword;
        cout << "Enter your Username: ";
        cin >> AuserName;
        cout << "Enter your password: ";
        cin >> Apassword;

        string Auname = admin.getAuserName();
        string Apword = admin.getApassword();
        if (AuserName == Auname)
        {
            if (Apassword == Apword)
            {
                cout << "Sign in successfully \n";

                /*int memNumber;
                int memNum = Guests.getMemNum();
                cout << "Which member's password to change? \n" << "Input member number: ";
                cin >> memNumber;
                if (memNumber == memNum){
                    admin.modifyPassword();
                } else {
                    cout << "Member may not exist. Please enter again. \n";
                }*/
                int choice2;
                cout << "This is your menu:\n"
                     << "0. Exit\n"
                     << "1. Modify member's password\n";
                cin >> choice2;
                if (choice2 == 1)
                {
                    admin.modifyPassword();
                }
                else
                {
                    cout << "Invalid choice. Please select 0 or 1. \n";
                }
            }
            else
            {
                cout << "Wrong password. Please try again. \n";
            }
        }
        else
        {
            cout << "User name or password is incorrect. Please try again. \n";
        }
    }
    else
    {
        cout << "Invalid choice. Please choose 1, 2 or 3\n";
    }
    return 0;
}