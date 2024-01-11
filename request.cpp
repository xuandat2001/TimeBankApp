#include<iostream>
#include<fstream>
#include "request.h"
using std::cin;
using std::cout;
using std::string;
Request::Request(string nameofHostVal= "", string nameofSupportVal= "" ,string titleVal = "", string descriptionVal="",string statusVal=""){

    this->nameOfHost= nameofHostVal;
    this->nameofSupport= nameofSupportVal;
    this->title = titleVal;
    this->description = descriptionVal;
    this->status = statusVal;
};

void Request::showRequest(){
}
