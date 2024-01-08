#include <iostream>
#include "Member.h"
#include <fstream>
using std::cin;
using std::cout;
using std::string;
Member::Member(string userNameVal,
               string passwordVal,
               string idVal,
               string fullNameVal,
               string emailVal,
               int phoneNumberVal,
               string addressVal,
               int creditPointVal,
               string skillsInfoVal,
               int hostRatingScoreVal,
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

void Member::showInfo()
{
    cout << "Username: " << userName << "\n";
    cout << "Full name: " << fullName << "\n";
    cout << "Email: " << email << "\n";
    cout << "Phone number: " << phoneNumber << "\n";
    cout << "Address: " << address << "\n";
    cout << "Skills: " << skillsInfo << "\n";
    cout << "Credit: " << creditPoint << "\n";
    cout << "Consuming Point: " << comsumingPoint << "\n";
    cout << "HostingScore: " << hostRatingScore << "\n";
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

void Member::showInfoVip()
{
    cout << "Full name: " << this->fullName << "\n";
    cout << "Email: " << this->email << "\n";
    cout << "Phone number: " << this->phoneNumber << "\n";
    cout << "Address: " << this->address << "\n";
    cout << "Skills: " << this->skillsInfo << "\n";
    cout << "Consuming Point: " << this->comsumingPoint << "\n";
    cout << "Consuming Point: " << this->hostRatingScore << "\n";
    cout << endl;
}

bool Member::loginMem(string usernameVal, string passwordVal)
{
    if (userName == usernameVal && password == passwordVal) // Check username and password
    {
        cout << "Login successfully\n";
        return true;
    }
    else if (userName == usernameVal && password != passwordVal)
    {
        cout << "Your password is not correct\n";
        return false;
    }
    else if (userName != usernameVal && password == passwordVal)
    {
        cout << "Your username is not correct\n";
        return false;
    }
    else
    {
        cout << "Your username and password are not correct\n";
        return false;
    }
};

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
        availability == true;
        fstream myfile;
        myfile.open("supporters.dat", std::ios::out); // open a file
        if (!myfile)
        {
            cout << " Fail to open/create a file\n";
        }

        myfile << userName << " " << fullName << " " << email << " " << phoneNumber << " " << address << " " << skillsInfo << "\n";
        myfile.close();
        cout << "You are ready to be booked\n";
        return 1;
    }
    else if (choice == 2)
    {
        availability == false;
        cout << "do not disrupt";
        return 2;
    }
    else
    {
        cout << "Invalid value";
        return -1;
    }
};
void Member::search(string &condition, vector<Member> listMem)
{
    for (int i = 0; i < listMem.size(); i++)
    {
        if (listMem[i].address == condition)
        {
            cout << "Around you: \n";
            listMem[i].showInfo();
        }
    }
}
bool Member::sendRequest(Supporter &sup)
{
    string userNameSup;
    cout << "Enter the usernam of supporter: ";
    std::getline(cin >> std::ws, userNameSup);
    if (userNameSup == sup.userName)
    {
        string title;
        string description
        cout<< "Enter the title of Request";
        std::getline(cin >> std::ws, title);
        cout << "Enter the title of Request";
        std::getline(cin >> std::ws, title);
        std::fstream myFile;
        myFile.open("Request.dat", std::ios::app | std::ios::out);
        if (!myFile)
        {
            cout << "Fail to open or create file";
        }
        myFile << userNameSup << " " << title << " " << description << "\n";
        myFile.close();
        return true;
    }
    else
    {
        cout << "could not find the username";
        return false;
    }
}
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