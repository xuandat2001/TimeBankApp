#include<iostream>

#ifndef _MEMBER_H
#define _MEMBER_H

using std::cin;
using std::cout;
using std::string;

class Member{

private: 
    string userName;
    string password;

public:
    void displayInformation();
    void setAvailability();
    void searchSupporters();
    void bookSupporters();
    void viewRequests();
    void blockMembers();
    void rateSupporters();
};
#endif