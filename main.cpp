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
    cout << "EEET2482/COSC2082 ASSIGNMENT\n"
         << "TIME BANK APPLICATION\n"
         << "Instructor: Mr. Tran Duc Linh\n"
         << "Group: Group 16.\n"
         << "s3979802, NGUYEN HAI LAM\n"
         << "s3970891, PHAM QUANG HUY\n"
         << "s3993986, HONG THIEU KIET\n"
         << "s3932156, UNG XUAN DAT\n"
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
                registerMember(Guests);
            }

            else if (choice1 == 2)
            {
                viewSupporters(Guests);
            }
            else if (choice1 == 0)
            {
                break;
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
                    std::getline(myfile >> std::ws, phoneNumber);
                    std::getline(myfile >> std::ws, address);
                    std::getline(myfile >> std::ws, skillsInfo);
                    std::getline(myfile >> std::ws, creditPoint);
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
            string phoneNumberSup;
            std::string addressSup;
            string creditPointSup;
            string skillsInfoSup;
            std::vector<int> hostRatingScoreVal = {};
            string comsumingPointSup;
            bool availabilityVal = true;
            std::vector<std::string> reviewSup = {};
            int skillScore = 0;
            int supporterScore = 0;

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
                    std::getline(Supfile >> std::ws, userNameSup);
                    std::getline(Supfile >> std::ws, passwordSup);
                    std::getline(Supfile >> std::ws, idSup);
                    std::getline(Supfile >> std::ws, fullNameSup);
                    std::getline(Supfile >> std::ws, emailSup);
                    std::getline(Supfile >> std::ws, phoneNumberSup);
                    std::getline(Supfile >> std::ws, addressSup);
                    std::getline(Supfile >> std::ws, skillsInfoSup);
                    std::getline(Supfile >> std::ws, creditPointSup);
                    std::getline(Supfile >> std::ws, comsumingPointSup);
                    // Create a Supporter object and add it to the list
                    Supporter singleSupporter(userNameSup, passwordSup, idSup, fullNameSup, emailSup, std::stod(phoneNumberSup), addressSup, std::stod(creditPointSup), skillsInfoSup, hostRatingScoreVal, std::stod(comsumingPointSup), availabilityVal, reviewSup, skillScore, supporterScore);
                    ListofSup.push_back(singleSupporter);
                }

                Supfile.close();
            }

            // store all request
            string hostName;
            string supName;
            string title;
            string description;
            string time;
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
                    std::getline(myFile >> std::ws, time);
                }
                Request req(hostName, supName, title, description,time, status);
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
                    string usernameVal, passwordVal;
                    cout << "Enter your username: ";
                    std::getline(cin >> std::ws, usernameVal); // getusername
                    cout << "Enter your Password: ";
                    std::getline(cin >> std::ws, passwordVal);
                    int foundMemberIndex = loginMem(ListofMember, usernameVal, passwordVal);
                    // ListofMember[i].loginMem(userNameVal, passwordVal);
                    if (foundMemberIndex != -1)
                    {
                        Member foundMember = ListofMember[foundMemberIndex];
                        cout << "Login successful\n";
                        int choiceMem; // get choice from user
                        cout << "This is your menu:\n"
                             << "0. Exit\n"
                             << "1. Show Information\n"
                             << "2. Set Status\n"
                             << "3. Search Supporter\n"
                             << "4. Send Request\n"
                             << "5. View Request\n"
                             << "6. Check your Request\n"
                             << "7. Performe Top Up\n"
                             << "8. Rate Host\n"
                             << "9. Block Member\n"
                             << "10. View Specific Member\n"
                             << "11. Rate Supporter\n";
                        cout << "Enter your choice: ";
                        cin >> choiceMem;
                        // loop through all member in list
                        if (choiceMem == 7)
                        {
                            perfomeTopUp(foundMember);
                            
                        }
                        else if (choiceMem == 1)
                        {
                            foundMember.showInfo(); // call function
                        }
                        else if (choiceMem == 2)
                        {
                            int choice;
                            cout << "Set your status\n";
                            cout << "1 for On\n";
                            cout << "2 for Off\n";
                            cout << "Enter ur choice: ";
                            cin >> choice;
                            if (choice == 1)
                            {
                                setStatus(foundMember, ListofSup);
                            }
                            else if(choiceMem==2){
                                int SupIndex = unlist(foundMember, ListofSup);
                                ListofSup.erase(ListofSup.begin() + SupIndex);
                                 cout << "You turn off mode Supporter\n";
                            }
                            
                            
                        }

                        else if (choiceMem == 3)
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
                            search(cityName, foundMember, ListofSup); // call function
                        }
                        else if (choiceMem == 4)
                        {
                            sendRequest(ListofSup, foundMember); // call function
                        }
                        else if (choiceMem == 5)
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
                        else if (choiceMem == 6)
                        {
                            checkStatusRequest(foundMember, ListofSup);
                        }
                        else if (choiceMem == 8)
                        {
                            cout<<"Please rate your host from 1 to 5\n";
                            int score;
                            string nameOfHost;
                            cout << "Enter name of your host: ";
                            std::getline(cin >> std::ws, nameOfHost);
                            cout << "Enter the score for your host: ";
                            cin >> score;
                            for (int i = 0; i < ListofMember.size(); i++)
                            {
                                rateMember(ListofMember[i], nameOfHost, score);
                            }
                        }
                        else if (choiceMem == 9)
                        {
                            blockMember(foundMember, ListofMember);
                        }
                        else if (choiceMem == 10)
                        {
                            string nameOfMem;
                            cout << "Enter name of member: ";
                            std::getline(cin >> std::ws, nameOfMem);
                            for (int i = 0; i < ListofMember.size(); i++)
                            {
                                viewSpecificMem(nameOfMem, ListofMember[i]);
                            }
                        }
                        else if (choiceMem == 11)
                        {
                            string nameOfSup;
                            cout << "Enter name of member: ";
                            std::getline(cin >> std::ws, nameOfSup);
                            int skillScore, supporterScore;
                            string comment;
                            cout << "Enter the skill score: ";
                            cin >> skillScore;
                            cout << "Enter the Supporter's score: ";
                            cin >> supporterScore;
                            cout << "Enter your comment: ";
                            std::getline(cin >> std::ws, comment);
                            rateSupport(nameOfSup, skillScore, supporterScore, comment, ListofSup);
                        }
                        else if (choiceMem == 0)
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

                    int choice2;
                    cout << "This is your menu:\n"
                         << "0. Exit\n"
                         << "1. Modify member's password\n";
                    cout<<"Enter your choice: ";
                    cin >> choice2;
                    if (choice2 == 1)
                    {
                        modifyPassword();
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