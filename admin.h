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
    string AuserName = "given";
    string Apassword = "given";

    public:
    string getAuserName();

    string getApassword();

    void modifyPassword();
};

#endif