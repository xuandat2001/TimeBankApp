//#include<supporter.h>
#ifndef _GUEST_H
#define _GUEST_H
#include <iostream>
#include <fstream>
//#include<supporter.h>


using namespace std;
using std::string;
using std::cin;
using std::cout;

class Guest{
    
protected:
    string userName;
    string password;
    string memID;
    string fullName;
    string email;
    int phoneNumber;
    string address;
    int creditPoint;
    string skillsInfo;
public:
    
    Guest();

    string getUserName();
    
    string getPassword();

    string getMemID();

    string getFullName();

    string getEmail();

    int getPhoneNumber();

    string getAddress();

    int getCreditPoint();

    string getSkillsInfo();
    friend void registerMember(Guest &guest);
    friend void viewSupporters(Guest &guest);
};
#endif