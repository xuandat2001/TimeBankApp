#include <iostream>
#include <fstream>
#include <vector>
#include "Guest.h"
#include "Admin.h"
#include "Member.h"
#include "supporter.h"
#include "request.h"
#include "Function.h"
using std::cin;
using std::cout;
using std::string;

int main()
{
    int choice;
    std::vector<Member> ListofMember;
    std::vector<Supporter> ListofSup;
    std::vector<Request> ListofReq;
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
         << "\n\nWELLCOME TO TIME BANK APP\n";
    while (1)
    {

        cout << "\nUse the app as      1. Guest 2. Member 3. Admin 4. Exit\n"
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
            // store all the infomation of guest when they register to a member
            string userName;
            string password;
            string id;
            string fullName;
            string email;
            string phoneNumber;
            string address;
            string creditPoint;
            string skillsInfo;
            std::vector<int> hostRatingScore = {};
            int comsumingPoint = 0;
            bool availability = false;
            string review;
            fstream myfile;
            myfile.open("member.dat", std::ios::in);
            if (!myfile)
            {
                std::cerr << "Fail to open/create file";
            }
            else
            {
                while (!myfile.eof())
                { // if not at the end of file
                    // if not at the end of file
                    std::getline(myfile >> std::ws, password);
                    std::getline(myfile >> std::ws, id);
                    std::getline(myfile >> std::ws, userName);
                    std::getline(myfile >> std::ws, fullName);
                    std::getline(myfile >> std::ws, email);
                    myfile >> phoneNumber;
                    std::getline(myfile >> std::ws, address);
                    std::getline(myfile >> std::ws, skillsInfo);
                    myfile >> creditPoint;
                    Member mem(userName, password, id, fullName, email, std::stod(phoneNumber), address,
                               std::stod(creditPoint), skillsInfo, hostRatingScore, comsumingPoint, availability); // take data from file and assign to variables
                    ListofMember.push_back(mem);
                    // push each member to a vector
                }
            }
            myfile.close();

            // store all member when they turn on supporter mode

            std::string userNameSup;
            std::string passwordSup; // Assuming you read the password from the file
            std::string idSup;
            std::string fullNameSup;
            std::string emailSup;
            double phoneNumberSup;
            std::string addressSup;
            double creditPointSup;
            std::string skillsInfoSup;
            std::vector<int> hostRatingScoreVal = {};
            double comsumingPointSup;
            bool availabilityVal;
            std::vector<std::string> reviewSup = {};
            std::vector<RatingScore> ratingScoreSup = {};

            fstream Supfile;
            Supfile.open("supporters.dat", std::ios::in);
            if (!Supfile)
            {
                std::cerr << "Fail to open or create the file";
            }

            else
            {
                while (!Supfile.eof())
                {
                    Supfile >> userNameSup >> passwordSup >> idSup >> fullNameSup >> emailSup >> phoneNumberSup >> addressSup >> skillsInfoSup >> creditPointSup >> comsumingPointSup >> availabilityVal;
                    // Create a Member object
                    // Member baseMember(userNameSup, passwordSup, idSup, fullNameSup, emailSup, phoneNumberSup, addressSup, creditPointSup, skillsInfoSup, hostRatingScoreVal, comsumingPointSup, availabilityVal);

                    // Create a Supporter object and add it to the list
                    Supporter singleSupporter(userNameSup, passwordSup, idSup, fullNameSup, emailSup, phoneNumberSup, addressSup, creditPointSup, skillsInfoSup, hostRatingScoreVal, comsumingPointSup, availabilityVal, reviewSup, ratingScoreSup);
                    ListofSup.push_back(singleSupporter);
                }

                Supfile.close();
            }

            // store all request
            string hostName;
            string supName;
            string title;
            string description;
            string status = "";
            fstream myFile;
            myFile.open("Request.dat", std::ios::in);

            if (!myFile)
            {
                cout << " No data to be found\n";
            }
            else
            {
                while (!myFile.eof())
                {
                    std::getline(myFile >> std::ws, hostName);
                    std::getline(myFile >> std::ws, supName);
                    std::getline(myFile >> std::ws, title);
                    std::getline(myFile >> std::ws, description);
                }
                Request req(hostName, supName, title, description, status);
                ListofReq.push_back(req);
            }
            myFile.close();

            // login section
            while (1)
            {
                cout << "1. Login  2. Return to the Main Menu \n ";
                int choice;
                cout << "Enter your choice: ";
                cin >> choice;

                if (choice == 1)
                {
                    for (int i = 0; i < ListofMember.size(); i++)
                    {
                        ListofMember[i].showInfo();
                    }

                    string usernameVal, passwordVal;
                    cout << "Enter your username: ";
                    std::getline(cin >> std::ws, usernameVal); // getusername
                    cout << "Enter your Password: ";
                    std::getline(cin >> std::ws, passwordVal);
                    int foundMemberIndex = loginMem(ListofMember, usernameVal, passwordVal);
                    // ListofMember[i].loginMem(userNameVal, passwordVal);
                    if (foundMemberIndex != -1)
                    {
                        Member foundMember = ListofMember[static_cast<size_t>(foundMemberIndex)];
                        cout << "Login successful\n";
                        int choice; // get choice from user
                        cout << "This is your menu:\n"
                             << "0. Exit\n"
                             << "1. Show Information\n"
                             << "2. Set Status\n"
                             << "3. Search Supporter\n"
                             << "4. Send Request\n"
                             << "5. View Request\n"
                             << "6. Check your Request\n"
                             << "7. Performe Top Up\n";
                        cout << "Enter your choice: ";
                        cin >> choice;
                        // loop through all member in list
                        if (choice == 7)
                        {
                            perfomeTopUp(foundMember);
                        }
                        else if (choice == 1)
                        {
                            foundMember.showInfo(); // call function
                        }
                        else if (choice == 2)
                        {
                            setStatus(foundMember);
                        }

                        else if (choice == 3)
                        {
                            string cityName;
                            int creditPoint;
                            // int hostscore;
                            cout << "Enter the city: ";
                            std::getline(cin >> std::ws, cityName);
                            cout << "Enter the credit requirement: ";
                            cin >> creditPoint;
                            // cout << "Enter the hosting score requirement: ";
                            // cin >> hostRatingScore;
                            search(cityName, creditPoint, ListofSup); // call function
                        }
                        else if (choice == 4)
                        {
                            sendRequest(ListofSup, foundMember); // call function
                        }
                        else if (choice == 5)
                        {
                            for (int i = 0; i < ListofReq.size(); i++)
                            {
                                if (viewRequest(foundMember, ListofReq) == true)
                                // call function
                                {
                                    interactRequest(foundMember, ListofReq[i], ListofSup);
                                }
                                else
                                {
                                    cout << "You dont have any request";
                                }
                            }
                        }
                        else if (choice == 6)
                        {
                            checkStatusRequest(foundMember, ListofSup);
                        }

                        else if (choice == 0)
                        {
                            cout << "\nExit. Return to the Login Section!\n";
                            break;
                        }
                        else
                        {
                            cout << "\nInvalid value, Please follow the guide above";
                        }
                    }
                    else
                    {
                        cout << "username and password do not exit";
                    }

                    break;
                }
                else if (choice == 2)
                {
                    break;
                }
                else
                {
                    cout << "invalid Value";
                    break;
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
        else if (choice == 4)
        {
            cout << "\nEnd of Program. Have a nice day";
            break;
        }
        else
        {
            cout << "Invalid choice. Please choose 1, 2, 3 or 4!\n";
        }
    }
    return 0;
}