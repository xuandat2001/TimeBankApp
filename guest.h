#ifndef _GUEST_H_     
#define _GUEST_H_
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::string;
class Guest
{
private:
    string username, password, fullname, email, homeAddress, skillInfo, location, review;
    int phoneNumber, creditPoint;

public:
    Guest();  
    bool registerMenber();
};
#endif