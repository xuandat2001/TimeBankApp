#include <iostream>
#include "Admin.h"
#include "Guest.h"

using std::cin;
using std::cout;
using std::string;

string Admin::getAuserName()
{
    return this->AuserName;
}

string Admin::getApassword()
{
    return this->Apassword;
}

