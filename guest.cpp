#include <iostream>
#include <fstream>
#include <vector>
#include "guest.h"
using std::cin;
using std::cout;

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
        std::getline(memFile >> std::ws, username);

        // Get Password
        cout << "Enter your password: ";
        std::getline(memFile >> std::ws, password);

        // Get Fullname
        cout << "Enter your Fullname: ";
        std::getline(memFile >> std::ws, fullname);

        // Get email
        cout << "Enter your username: ";
        std::getline(memFile >> std::ws, email);

        // Get HomeAddress
        cout << "Enter your HomeAddress: ";
        std::getline(memFile >> std::ws, homeAddress);

        // Get Location
        cout << "Enter your Location: ";
        std::getline(memFile >> std::ws, location);

        // Get SkillInfo
        cout << "Enter your username: ";
        std::getline(memFile >> std::ws, skillInfo);

        // Get PhoneNumber
        cout << "Enter your username: ";
        memFile >> phoneNumber;

        // Get Creditpoint
        creditPoint = 20;
        memFile >> creditPoint;

        cout << "Register successfully";
        
    }
    memFile.close(); // close the file
    return true;
}
