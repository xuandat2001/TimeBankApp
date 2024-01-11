#ifndef _REQUEST_H
#define _REQUEST_H
#include <iostream>
using std::cin;
using std::cout;
using std::string;
class Request{
private:
    string nameOfHost;
    string nameofSupport;
    string title;
    string description;
    string status;
public:
    Request(string nameofHostVal, string nameofSupportVal ,string titleVal, string descriptionVal,string statusVal);
    //void saveData();
    void showRequest();
    friend class Member;
};

#endif