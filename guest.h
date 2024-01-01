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
    Guest(string username = "", string password = "",
          string fullname = "", string email = "", string homeAddress = "", string skillInfo = "",
          string location = "", int phoneNumber = 0, int creditPoint = 0);
    bool registerMenber();
};