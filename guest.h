#include <iostream>
#include <fstream>

#ifndef _GUEST_H
#define _GUEST_H
using namespace std;
using std::string;
using std::cin;
using std::cout;

class Guest{
    
    private:
    string userName;
    string password;
    int memNum = 0;
    string fullName;
    string email;
    int phoneNumber;
    string address;
    int creditPoint;
    int ratingScore;
    string skillsInfo;
    bool Availability;
    int creditPoints = 0;

    public:
    
    Guest();

    string getUserName();
        //return this-> userName;
    

    string getPassword();

    int getMemNum();

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