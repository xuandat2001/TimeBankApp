#ifndef _MEMBER_H
#define _MEMBER_H

#include <iostream>

#include <vector>
#include "guest.h"
#include "supporter.h"

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
    std::vector<int> hostRatingScore;
    int comsumingPoint;
    bool availability;
    bool blockMem = false;

public:
    // all declarations
    Member(string userNameVal = "",
           string passwordVal = "",
           string idVal = "",
           string fullNameVal = "",
           string emailVal = "",
           int phoneNumberVal = 0,
           string addressVal = "",
           int creditPointVal = 0,
           string skillsInfoVal = "",
           std::vector<int> hostRatingScoreVal = {},
           int comsumingPointVal = 0,
           bool availabilityVal = false);
    bool block();
    void showInfo();
    void showInfoVip();
    friend int loginMem(std::vector<Member> ListofMem, string usernameVal, string passwordVal);
    friend void search(string cityName, Member &mem, vector<Supporter> listSup);
    friend void sendRequest(std::vector<Supporter> &listSup, Member &mem);
    friend int setStatus(Member &mem, vector<Supporter> listSup);
    friend int unlist(Member &mem, vector<Supporter> listSup);
    friend bool viewRequest(Member &mem, std::vector<Request> ListofReq);
    friend int interactRequest(Member &mem, Request &req,std::vector<Supporter> &listSup);
    friend bool checkStatusRequest(Member &mem, std::vector<Supporter> &listSup);
    friend bool perfomeTopUp(Member &mem);
    friend void rateMember(Member &mem, string &nameOfHost, int &score);
    friend void viewSpecificMem(string &nameOfMem, Member &mem);
    friend bool blockMember(Member &mem,std::vector<Member> ListofMem);
};
#endif