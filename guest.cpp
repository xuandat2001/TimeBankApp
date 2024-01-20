#include <iostream>
#include <fstream>
#include "guest.h"

using namespace std;
using std::cin;
using std::cout;
using std::string;

Guest::Guest() {}

string Guest::getUserName()
{
    return userName;
};
string Guest::getPassword()
{
    return password;
};

string Guest::getMemID()
{
    return memID;
};

string Guest::getFullName()
{
    return fullName;
};
string Guest::getEmail()
{
    return email;
};
int Guest::getPhoneNumber()
{
    return phoneNumber;
};
string Guest::getAddress()
{
    return address;
};
int Guest::getCreditPoint()
{
    return creditPoint;
};
/*bool Guest::getAvailability(){
    return Availability;
};*/
string Guest::getSkillsInfo()
{
    return skillsInfo;
};

