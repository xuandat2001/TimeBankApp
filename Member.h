#ifndef _MEMBER_H
#define _MEMBER_H
#include<iostream>
#include<vector>
#include "guest.h"
#include "supporter.h"
#include "listOfMem.h"
using std::cin;
using std::cout;
using std::string;
class Member: private Guest{
private:
    int id;
    int hostRatingScore= 0;
    int comsumingPoint = 0;
    bool availability;
    string review;
public:
    Member();
    void getInfo();
    void showInfo();
    void showInfoVip();
    bool loginMem(string usernameVal, string passwordVal);
    int setStatus();
    friend class Supporter{};
    //void search(string &condition);
    //friend class listofMem{};
    //bool blockMember(Member &Mem); 
};
#endif