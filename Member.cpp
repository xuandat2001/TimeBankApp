#include <iostream>
#include "Member.h"
#include <fstream>
using std::cin;
using std::cout;
using std::string;

// all definations
Member::Member(string userNameVal,
               string passwordVal,
               string idVal,
               string fullNameVal,
               string emailVal,
               int phoneNumberVal,
               string addressVal,
               int creditPointVal,
               string skillsInfoVal,
               std::vector<int> hostRatingScoreVal,
               int comsumingPointVal,
               bool availabilityVal) : // Guest(userNameVal,passwordVal,idVal,fullNameVal,emailVal,phoneNumberVal,addressVal,creditPointVal,skillsInfoVal),
                                   userName(userNameVal),
                                   password(passwordVal), id(idVal),
                                   fullName(fullNameVal),
                                   email(emailVal),
                                   phoneNumber(phoneNumberVal),
                                   address(addressVal),
                                   creditPoint(creditPointVal),
                                   skillsInfo(skillsInfoVal),
                                   hostRatingScore(hostRatingScoreVal),
                                   comsumingPoint(comsumingPointVal),
                                   availability(availabilityVal)
                                   {};

void Member::showInfo() // Show Info of each member
{
    cout << "Username: " << this->userName << "\n";
    cout << "Full name: " << fullName << "\n";
    cout << "Email: " << email << "\n";
    cout << "Phone number: " << phoneNumber << "\n";
    cout << "Address: " << address << "\n";
    cout << "Skills: " << skillsInfo << "\n";
    cout << "Credit: " << creditPoint << "\n";
    cout << "Consuming Point: " << comsumingPoint << "\n";

    for (int i = 0; i < hostRatingScore.size(); i++)
    {
        cout << "HostingScore: " << hostRatingScore[i] << " ";
    }
    cout << endl;
}
void Member::showInfoVip() 
{
    cout << "Full name: " << this->fullName << "\n";
    cout << "Email: " << this->email << "\n";
    cout << "Phone number: " << this->phoneNumber << "\n";
    cout << "Address: " << this->address << "\n";
    cout << "Skills: " << this->skillsInfo << "\n";
    cout << "Consuming Point: " << this->comsumingPoint << "\n";
    for (int i = 0; i < hostRatingScore.size(); i++)
    {
        cout << "HostScore: " << this->hostRatingScore[i] << "\n";
    }

    cout << endl;
}


// search Function
// void Member::search(string cityName, int creditPointCondition, vector<Supporter> listSup)
// {
    
//     for (int i = 0; i < listSup.size(); i++)
//     {
//         if (listSup[i].addressSup == cityName && creditPointCondition < listSup[i].creditPointSup) // compare the string input from user
//         {
//             cout << "Around you: \n";
//             listSup[i].showInfoSup();
//         }
//         else
//         {
//             cout << "No one is suitable\n";
//         }
//     }
// }

// send Request or Book a supporter
// void Member::sendRequest(std::vector<Supporter> listSup)
// {
//     string userNameSup;
//     cout << "Enter the username of supporter: ";
//     std::getline(cin >> std::ws, userNameSup);
//     for (int i = 0; i < listSup.size(); i++)
//     {
//         if (userNameSup == listSup[i].userNameSup)
//         {
//             string title;
//             string description;
//             string status = "";
//             cout << "Enter the title of Request";
//             std::getline(cin >> std::ws, title);
//             cout << "Enter the description of Request";
//             std::getline(cin >> std::ws, description);
//             std::fstream myFile;
//             myFile.open("Request.dat", std::ios::app | std::ios::out);
//             if (!myFile)
//             {
//                 cout << "Fail to open or create file";
//             }
//             myFile << userName << " " << userNameSup << " " << title << " " << description << " " << status << "\n";

//             myFile.close();
//             cout << "send request successfully";
//             break;
//         }
//         else
//         {
//             cout << "could not find the username";
//         }
//     }
// }

// view Request Functionality
bool Member::viewRequest(Request &req)
{
    if (userName != req.nameofSupport)
    {
        cout << "You do not have any request";
        return true;
    }
    else
    {
        cout << "You recieve a request from " << req.nameOfHost << "\n"
             << "Title: " << req.title << "\n"
             << "Description: " << req.description;
        return false;
    }
}

int Member::interactRequest(Request &req)
{
    cout << "\n 1 for Accept\n";
    cout << "2 for Deny\n";
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice == 1)
    {
        req.status = "Accpected";
        std::fstream myFile;
        myFile.open("AcceptedRequest.dat", std::ios::app | std::ios::out);
        if (!myFile)
        {
            cout << "Fail to open or create file";
        }
        myFile << " " << req.nameOfHost << " " << req.nameofSupport << " " << req.title << " " << req.description << " "
               << req.status;
        myFile.close();
        remove("request.dat");
        cout << "Accepted Request";
        return 1;
    }
    else if (choice == 2)
    {
        remove("request.dat");
        cout << "Denied Request";
        return 2;
    }
    else
    {
        cout << "invalid value\n";
        return -1;
    }
}

bool Member::checkStatusRequest()
{
    string nameHostVal;
    fstream myFile;
    myFile.open("AcceptedRequest.dat", std::ios::in);

    if (!myFile)
    {
        cout << " No data to be found\n";
    }
    else
    {
        while (!myFile.eof())
        {
            myFile >> nameHostVal;
        }
    }
    myFile.close();
    if (nameHostVal == userName)
    {
        remove("AcceptedRequest.dat");
        remove("request.dat");
        cout << "your request is accepted";
        return true;
    }
    else
    {
        return false;
    }
}

void Member::viewSpecificMem(Member &mem)
{
    cout << "Full name: " << mem.fullName << "\n";
    cout << "Email: " << mem.email << "\n";
    cout << "Phone number: " << mem.phoneNumber << "\n";
    cout << "Address: " << mem.address << "\n";
    cout << "Skills: " << mem.skillsInfo << "\n";
    cout << "Consuming Point: " << mem.comsumingPoint << "\n";
    for (int i = 0; i < hostRatingScore.size(); i++)
    {
        cout << "HostScore: " << mem.hostRatingScore[i] << "\n";
    }

    cout << endl;
};
// Block Member (have not completed)
bool Member::blockMember(Member &mem)
{
    string id;
    std::getline(cin >> std::ws, id);
    cin >> id;
    string userName;
    std::getline(cin >> std::ws, userName);
    if (userName == mem.userName && id == mem.id)
    {
        return true;
    }
    return false;
}

void Member::rateSupport(Supporter &sup)
{
    int skillScore, supporterScore;
    string comment;
    cout << "Enter the skill score: ";
    cin >> skillScore;
    cout << "Enter the Supporter's score: ";
    cin >> supporterScore;
    cout << "Enter your comment: ";
    std::getline(cin >> std::ws, comment);
    // sup.reviewSup.push_back(comment);
};

// rate Member
void Member::rateMember(Member &host)
{
    int score;
    string nameOfHost;
    cout << "Enter your host: ";
    std::getline(cin >> std::ws, nameOfHost);
    cout << "Enter the score for your host: ";
            cin >> score;
    if (nameOfHost == host.userName)
    {
        host.hostRatingScore.push_back(score);
        }
};