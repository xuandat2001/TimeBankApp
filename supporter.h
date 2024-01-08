#ifndef _SUPPORTER_H
#define _SUPPORTER_H
#include<iostream>
#include<vector>
#include"ratingscore.h"
#include"Member.h"
using std::cin;
using std::cout;

class Supporter:private Member{
private: 
    std::vector<RatingScore>HostScore;
public:
    Supporter(string userNameVal = "",
           string passwordVal = "",
           string idVal = "",
           string fullNameVal = "",
           string emailVal = "",
           int phoneNumberVal = 0,
           string addressVal = "",
           int creditPointVal = 0,
           string skillsInfoVal = "",
           int hostRatingScoreVal = 0,
           int comsumingPointVal = 0,
           bool availabilityVal = false,
           string reviewVal = "",
           std::vector<RatingScore>HostScoreVal={});
    friend class Member;
   // bool rateMember(Member &mem);
}; 
#endif