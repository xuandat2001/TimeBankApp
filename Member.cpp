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
               std::vector<int>hostRatingScoreVal,
               int comsumingPointVal,
               bool availabilityVal,
               string reviewVal) : // Guest(userNameVal,passwordVal,idVal,fullNameVal,emailVal,phoneNumberVal,addressVal,creditPointVal,skillsInfoVal),
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
                                   availability(availabilityVal),
                                   review(reviewVal){};

void Member::showInfo() // Show Info of each member
{
    cout << "Username: " << userName << "\n";
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
    
    cout << "review: " << review << "\n";
    cout << endl;
}

// Get infomation from the file
/*void Member::getInfo()
{
    fstream myfile;
    myfile.open("pwd.dat", std::ios::in);

    if (!myfile)
    {
        cout << " No data to be found\n";
    }
    else
    {
        myfile >> password >> id >> userName >> fullName >> email >> phoneNumber >> address >> skillsInfo >> creditPoint; // take data from file and assign to variables
        while (!myfile.eof())
        { // if not at the end of file
            myfile >> password >> id >> userName >> fullName >> email >> phoneNumber >> address >> skillsInfo >> creditPoint;
        }
    }
    myfile.close();
}*/

void Member::showInfoVip() // ignore it
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

// Login function
bool Member::loginMem(string usernameVal, string passwordVal)
{
    if (userName == usernameVal && password == passwordVal) // Check username and password
    {
        cout << "Login successfully\n";
        return true;
    }
    else if (userName == usernameVal && password != passwordVal) // other cases
    {
        cout << "Your password is not correct\n";
        return false;
    }
    else if (userName != usernameVal && password == passwordVal) // other cases
    {
        cout << "Your username is not correct\n";
        return false;
    }
    else // other cases
    {
        cout << "Your username and password are not correct\n";
        return false;
    }
};

// set avalablyty of each member
int Member::setStatus()
{
    int choice;
    cout << "Set your status\n";
    cout << "1 for On\n";
    cout << "2 for Off\n";
    cout << "Enter ur choice: ";
    cin >> choice;
    if (choice == 1)
    {
        availability == true;                                         // mode on
        fstream myfile;                                               // create a file to store all the infor of a member as a supporter
        myfile.open("supporters.dat", std::ios::app | std::ios::out); // open a file
        if (!myfile)
        {
            cout << " Fail to open/create a file\n";
        }
        myfile << userName << " " << id << " " << fullName << " " << email << " " << phoneNumber << " " << address << " " << skillsInfo << " " << creditPoint << " " << comsumingPoint << "\n";
        myfile.close();
        cout << "You are ready to be booked\n";
        return 1;
    }
    else if (choice == 2)
    {
        availability == false; // mode off
        cout << "do not disrupt";
        return 2;
    }
    else
    {
        cout << "Invalid value";
        return -1;
    }
};

// search Function
void Member::search(string &Namecondition, int creditPointCondition, vector<Supporter> listSup)
{
    for (int i = 0; i < listSup.size(); i++)
    {
        if (listSup[i].addressSup == Namecondition && creditPointCondition < listSup[i].creditPointSup) // compare the string input from user
        {
            cout << "Around you: \n";
            listSup[i].showInfoSup();
        }
        else
        {
            cout << "No one is suitable\n";
        }
    }
}

// send Request or Book a supporter
void Member::sendRequest(std::vector<Supporter> listSup)
{
    string userNameSup;
    cout << "Enter the username of supporter: ";
    std::getline(cin >> std::ws, userNameSup);
    for (int i = 0; i < listSup.size(); i++)
    {
        if (userNameSup == listSup[i].userNameSup)
        {
            string title;
            string description;
            string status = "";
            cout << "Enter the title of Request";
            std::getline(cin >> std::ws, title);
            cout << "Enter the description of Request";
            std::getline(cin >> std::ws, description);
            std::fstream myFile;
            myFile.open("Request.dat", std::ios::app | std::ios::out);
            if (!myFile)
            {
                cout << "Fail to open or create file";
            }
            myFile << userName << " " << userNameSup << " " << title << " " << description << " " << status << "\n";

            myFile.close();
            cout << "send request successfully";
            break;
        }
        else
        {
            cout << "could not find the username";
        }
    }
}

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

bool Member::viewSpecificMem(Member &mem){
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

void rateSupport(Supporter &sup)
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


//rate Member
void Member::rateMember(Member &host){
    int score;
    string nameOfHost;
    cout<<"Enter your host: ";
    std::getline(cin>>std::ws, nameOfHost);
    cout<<"Enter the score for your host: ";
    cin>>score;
    if (nameOfHost == host.userName)
    {
        host.hostRatingScore.push_back(score);
    } 
};