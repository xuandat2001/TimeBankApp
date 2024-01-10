#include <iostream>
#include <vector>
#include "Guest.h"
#include "Admin.h"
#include "Member.h"
#include "supporter.h"
using namespace std;
using std::cin;
using std::cout;
using std::string;

int main()
{
    int choice;
    std::vector<Member> ListofMember;
    std::vector<Supporter> ListofSup;
    Guest Guests;
    Admin admin;
    // ListofMember.push_back(mem.getInfo())
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
        //store all the infomation of guest when they register to a member
        string userName;
        string password;
        string id;
        string fullName;
        string email;
        string phoneNumber;
        string address;
        string creditPoint;
        string skillsInfo;
        int hostRatingScore = 0;
        int comsumingPoint = 0;
        bool availability = false;
        string review;
        fstream myfile;
        myfile.open("pwd.dat", std::ios::in);

        if (!myfile)
        {
            cout << " No data to be found\n";
        }
        else
        {
             
            while (!myfile.eof())
            { // if not at the end of file
                myfile >> password >> id >> userName >> fullName >> email >> phoneNumber >> address >> skillsInfo >> creditPoint;
                Member mem(userName, password, id, fullName, email, std::stod(phoneNumber), address,
                 std::stod(creditPoint), skillsInfo, hostRatingScore, comsumingPoint, availability, review);// take data from file and assign to variables
                ListofMember.push_back(mem); //push each member to a vector
            }
        }
        myfile.close();



        //store all member when they turn on supporter mode
        string userNameSup;
        string idSup;
        string fullNameSup;
        string emailSup;
        string phoneNumberSup;
        string addressSup;
        string creditPointSup;
        string skillsInfoSup;
        string comsumingPointSup;
        string reviewSup = "";
        std::vector<RatingScore> ratingScoreSup = {};
        myfile.open("supporters.dat", std::ios::in);

        if (!myfile)
        {
            cout << " No data to be found\n";
        }
        else
        {
            // myfile >> password >> id >> userName >> fullName >> email >> phoneNumber >> address >> skillsInfo >> creditPoint; // take data from file and assign to variables
            while (!myfile.eof())
            { // if not at the end of file
                myfile >> userNameSup >> idSup >> fullNameSup >> emailSup >> phoneNumberSup >> addressSup >> skillsInfoSup >> creditPointSup >> comsumingPointSup;
                Supporter singleSupporter(userNameSup, idSup, fullNameSup, emailSup, std::stod(phoneNumberSup),
                                          addressSup, std::stod(creditPointSup), skillsInfoSup, std::stod(comsumingPointSup), reviewSup, ratingScoreSup);
                ListofSup.push_back(singleSupporter);
            }
        }
        myfile.close();


        //login section
        string userNameVal;
        string passwordVal;
        cout << "Enter your username: ";
        std::getline(cin >> std::ws, userNameVal); // getusername
        cout << "Enter your Password: ";
        std::getline(cin >> std::ws, passwordVal); // get password

        for (int i = 0; i < ListofMember.size(); i++)
        {
            if (ListofMember[i].loginMem(userNameVal, passwordVal) == true)
            {
                int choice; // get choice from user
                cout << "This is your menu:\n"
                     << "0. Exit\n"
                     << "1. Show Information\n"
                     << "2. Set Status\n"
                     << "3. Search Supporter\n"
                     << "4. Send Request\n"
                     << "5. View Request\n";
                cout << "Enter ur choice";
                cin >> choice;
                // loop through all member in list
                if (choice == 1)
                {
                    ListofMember[i].showInfo(); //call function
                    break;
                }
                else if (choice == 2)
                {
                    if (ListofMember[i].setStatus() == 1) //call function
                    {
                        ListofMember[i].showInfoVip();//call function
                        break;
                    }
                    else if (ListofMember[i].setStatus() == 2)//call function
                    {
                        cout << "This Mem was unlisted";
                        break;
                    }
                }

                else if (choice == 3)
                {
                    string condition;
                    int creditPoint;
                    // int hostscore;
                    cout << "Enter the city: ";
                    std::getline(cin >> std::ws, condition);
                    cout << "Enter the credit requirement: ";
                    cin >> creditPoint;
                    // cout << "Enter the hosting score requirement: ";
                    // cin >> hostRatingScore;
                    ListofMember[i].search(condition, creditPoint, ListofSup);//call function
                }
                else if (choice == 4)
                {
                    ListofMember[i].sendRequest(ListofSup);//call function
                }
                else if (choice == 5)
                {
                    ListofMember[i].viewRequest();//call function
                }
                else
                {
                    cout << "Exit";
                }
                break;
            }
            else
            {
                cout << "Please Enter again \n";
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