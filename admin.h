#include <iostream>
#include <fstream>

#ifndef _ADMIN_H
#define _ADMIN_H

using namespace std;
using std::string;
using std::cin;
using std::cout;

class Admin{
    private:
    string AuserName = "admin";
    string Apassword = "rmit1234";

    public:
    string getAuserName();

    string getApassword();
    friend void modifyPassword(Admin &admin);
};

#endif