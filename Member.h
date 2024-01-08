#ifndef _MEMBER_H
#define _MEMBER_H
#include <iostream>
#include <vector>
#include "guest.h"
#include"supporter.h"
using std::cin;
using std::cout;
using std::string;
class Member
{
private:
    string userName;
    string password;
    string id;
    string fullName;
    string email;
    int phoneNumber;
    string address;
    int creditPoint;
    string skillsInfo;
    int hostRatingScore;
    int comsumingPoint;
    bool availability;
    string review;

public:
    Member(string userNameVal = "",
           string passwordVal = "",
           string idVal = "",
           string fullNameVal = "",
           string emailVal = "",
           int phoneNumberVal = 0,
           string addressVal = "",
           int creditPointVal = 0,
           string skillsInfoVal = "",
           int hostRatingScoreVal = 0,
           int comsumingPointVal = 0,
           bool availabilityVal = false,
           string reviewVal = "");

    void getInfo();
    void showInfo();
    void showInfoVip();
    bool loginMem(string usernameVal, string passwordVal);
    int setStatus();
    // friend class Supporter{};
    void search(string &condition,vector<Member>listMem);
    friend class listofMem;
    bool sendRequest( Supporter &sup);
    bool blockMember(Member &Mem);

};
#endif