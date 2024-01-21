#include<iostream>
#include<fstream>
#include "request.h"
using std::cin;
using std::cout;
using std::string;
Request::Request(string nameofHostVal= "", string nameofSupportVal= "" ,string titleVal = "", string descriptionVal="",string timeVal="",string statusVal=""){

    this->nameOfHost= nameofHostVal;
    this->nameofSupport= nameofSupportVal;
    this->title = titleVal;
    this->description = descriptionVal;
    this ->time= timeVal;
    this->status = statusVal;
};

void Request::showRequest(){
}
