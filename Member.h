#ifndef _MEMBER_H
#define _MEMBER_H

#include <iostream>

#include <vector>
#include "guest.h"
#include "supporter.h"
#include "request.h"
using std::cin;
using std::cout;
using std::string;
class Supporter;
class Request;
class Member
{
protected:
    string userName;
    string password;
    string id;
    string fullName;
    string email;
    int phoneNumber;
    string address;
    int creditPoint;
    string skillsInfo;
    std::vector<int>hostRatingScore;
    int comsumingPoint;
    bool availability;
    

public:

//all declarations
    Member(string userNameVal = "",
           string passwordVal = "",
           string idVal = "",
           string fullNameVal = "",
           string emailVal = "",
           int phoneNumberVal = 0,
           string addressVal = "",
           int creditPointVal = 0,
           string skillsInfoVal = "",
           std::vector<int>hostRatingScoreVal={},
           int comsumingPointVal = 0,
           bool availabilityVal = false
           );
    void getInfo();
    void showInfo();
    void showInfoVip();
    bool loginMem(string usernameVal, string passwordVal);
    int setStatus();
    //void search(string cityName, int creditPointCondition, vector<Supporter> listSup);
    //void sendRequest( std::vector<Supporter>listSup);
    bool viewRequest(Request &req);
    int interactRequest(Request &req);
    bool checkStatusRequest();
    void viewSpecificMem(Member &mem);
    bool blockMember(Member &Mem);
    void rateSupport(Supporter &sup);
    void rateMember(Member &host);
    friend int loginMem(std::vector<Member> ListofMem, string usernameVal, string passwordVal);
    friend void sendRequest(std::vector<Supporter> listSup,Member mem);
    friend int setStatus(Member &mem);
    friend bool viewRequest(Member &mem, Request &req);
   
};
#endif