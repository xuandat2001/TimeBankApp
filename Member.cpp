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