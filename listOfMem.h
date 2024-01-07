#ifndef _LISTOFMEM_H
#define _LISTOFMEM_H
#include <iostream>
#include "Member.h"
using std::cin;
using std::cout;

class listofMem
{
private:
    std::vector<Member> listofMember;

public:
    listofMem();
    void getInforMems();
    bool blockMem(string &username, int &id);
};
#endif