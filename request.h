#ifndef _REQUEST_H
#define _REQUEST_H
#include <iostream>
using std::cin;
using std::cout;
using std::string;
class Request{
private:
    int id;
    string nameofSupport;
    string title;
    string description;
public:
    Request(int idVal = 0, string nameofSupportVal= "" ,string titleVal = "", string descriptionVal="");
    //void saveData();
    void showRequest();
};

#endif