#ifndef _REQUEST_H
#define _REQUEST_H
#include <iostream>

#include "Function.h"
using std::cin;
using std::cout;
using std::string;
class Member;
class Request
{
private:
    string nameOfHost;
    string nameofSupport;
    string title;
    string description;
    string status;

public:
    Request(string nameofHostVal, string nameofSupportVal, string titleVal, string descriptionVal, string statusVal);
    // void saveData();
    void showRequest();

    friend class Member;
    friend bool viewRequest(Member &mem, std::vector<Request> ListofReq);
    friend int interactRequest(Member &mem, Request &req,std::vector<Supporter> &listSup);
    void rateMember(std::vector<Member> ListofMem);
};

#endif