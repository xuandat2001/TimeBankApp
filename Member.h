#include<iostream>
#include<vector>
#include "guest.h"
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
    //bool blockMember(Member &Mem); 
};