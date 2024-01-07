#ifndef _MEMBER_H
#define _MEMBER_H
#include<iostream>
#include<vector>
#include "guest.h"
using std::cin;
using std::cout;
using std::string;
class Member: private Guest{
private:
    int hostRatingScore= 0;
    int comsumingPoint = 0;
    bool availability;
    string review;
public:
    Member(string userNameVal="",
    string passwordVal = "",
    string idVal = "",
    string fullNameVal = "",
    string emailVal = "",
    int phoneNumberVal = 0,
    string addressVal = "",
    int creditPointVal = 0,
    string skillsInfoVal = "",
    int hostRatingScoreVal= 0,
    int comsumingPointVal = 0,
    bool availabilityVal = false,
    string reviewVal="");
    void getInfo();
    void showInfo();
    void showInfoVip();
    bool loginMem(string usernameVal, string passwordVal);
    int setStatus();
    //friend class Supporter{};
    //void search(string &condition);
    friend class listofMem;
    //bool blockMember(Member &Mem); 
};
#endif