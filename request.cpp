#include<iostream>
#include<fstream>
#include "request.h"
using std::cin;
using std::cout;
using std::string;
Request::Request(int idVal, string nameofSupportVal,string titleVal, string descriptionVal){

    this->id = idVal;
    this->nameofSupport= nameofSupportVal;
    this->title = titleVal;
    this->description = descriptionVal;
};

void Request::showRequest(){
    cout<<"RequestIndex: "<<id<<"\n";
    cout<<"RequestTitle: "<<title<<"\n";
    cout<<"RequestDescription: "<<description<<"\n";
}
