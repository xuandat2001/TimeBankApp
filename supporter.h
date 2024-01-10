#ifndef SUPPORTER_H
#define SUPPORTER_H

#include<iostream>
#include<vector>
#include "ratingscore.h"

//#include "sendrequest.h"
using std::cin;
using std::cout;
using std::string;
class Supporter{
private: 
    string userNameSup;
    string idSup;
    string fullNameSup;
    string emailSup;
    int phoneNumberSup;
    string addressSup;
    int creditPointSup;
    string skillsInfoSup;
    int comsumingPointSup;
    string reviewSup;
    std::vector<RatingScore>ratingScoreSup;
public:
    //all declarations
    Supporter(string userNameVal = "",
           string idVal = "",
           string fullNameVal = "",
           string emailVal = "",
           int phoneNumberVal = 0,
           string addressVal = "",
           int creditPointVal = 0,
           string skillsInfoVal = "",
           int comsumingPointVal = 0,
           string reviewVal = "",
           std::vector<RatingScore>ratingScoreVal={});
           void showInfoSup();
           friend class Member;
    //friend void sendRequest(string userNameSup);
   // bool rateMember(Member &mem);
}; 
#endif