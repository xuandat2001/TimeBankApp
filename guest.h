#include <iostream>
#include <fstream>

#ifndef _GUEST_H
#define _GUEST_H
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
    int ratingScore;
    string skillsInfo;
    //bool Availability;
    int creditPoints = 0;

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

    int getRatingScore();

    /*bool getAvailability(){
        return this->Availability;
    }*/

    string getSkillsInfo();
    
    void registerMember();

    void viewSupporters();
};
#endif