#include <iostream>
#include <fstream>
#include <vector>
#include "guest.h"
using std::cin;
using std::cout;
using std::string;
// Constructor of Guest class
Guest::Guest(string username = "", string password = "",
             string fullname = "", string email = "", string homeAddress = "", string skillInfo = "",
             string location = "", int phoneNumber = 0, int creditPoint = 0)
{
    this->username = username;
    this->password = password;
    this->fullname = fullname;
    this->email = email;
    this->homeAddress = homeAddress;
    this->skillInfo = skillInfo;
    this->location = location;
    this->phoneNumber = phoneNumber;
    this->creditPoint = creditPoint;
}

// Method

bool Guest::registerMenber()
{
    cout << "You have to fill fully infomation to become a menber\n";
    std::fstream memFile;
    memFile.open("Member.dat", std::ios::out);
    if (!memFile)
    {
        std::cerr << "Fail to open/create the file";
        return false;
    }
    else
    {
        // Get Username
            cout << "Enter your username: ";
            std::getline(cin >> std::ws, username);
            memFile<<"username: "<<username <<"\n";

            // Get Password
            cout << "Enter your password: ";
            std::getline(cin >> std::ws, password);
            memFile<<"password: "<<password <<"\n";

            // Get Fullname
            cout << "Enter your Fullname: ";
            std::getline(cin >> std::ws, fullname);
            memFile<<"FullName: "<<fullname <<"\n";

            // Get email
            cout << "Enter your email: ";
            std::getline(cin >> std::ws, email);
            memFile<<"email: "<<email <<"\n";

            // Get HomeAddress
            cout << "Enter your HomeAddress: ";
            std::getline(cin >> std::ws, homeAddress);
            memFile<<"HomeAddress: "<<homeAddress <<"\n";

            // Get Location
            cout << "Enter your Location: ";
            std::getline(cin >> std::ws, location);
            memFile<<"location: "<<location <<"\n";

            // Get SkillInfo
            cout << "Enter your SkillInfo: ";
            std::getline(cin >> std::ws, skillInfo);
            memFile<<"skillInfomation: "<<skillInfo <<"\n";

            // Get PhoneNumber
            cout << "Enter your PhoneNumber: ";
            cin >> phoneNumber;
            memFile<<"PhoneNumber: "<<phoneNumber <<"\n";

            // Get Creditpoint
            creditPoint = 20;
            memFile<<"creditPoint: "<<creditPoint <<"\n";

            memFile<<"\n";
            cout << "Register successfully";
        
    }
    memFile.close(); // close the file
    return true;
}
