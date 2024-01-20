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
bool Member::block(){
    blockMem = true;
    return true;
}

