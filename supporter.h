#ifndef SUPPORTER_H
#define SUPPORTER_H

#include <iostream>
#include <vector>
#include "ratingscore.h"
#include "Member.h"
// #include "sendrequest.h"
using std::cin;
using std::cout;
using std::string;
class Member;
class Supporter : public Member
{
private:
    std::vector<string> reviewSup;
    std::vector<RatingScore>ratingScoreSup;

public:
    // all declarations
    Supporter(string userNameVal = "",
              string passwordVal="",
              string idVal = "",
              string fullNameVal = "",
              string emailVal = "",
              int phoneNumberVal = 0,
              string addressVal = "",
              int creditPointVal = 0,
              string skillsInfoVal = "",
              std::vector<int> HostratingScoreVal = {},
              int comsumingPointVal = 0,
               bool availabilitySup = false,
              std::vector<string> reviewVal = {},
             
              std::vector<RatingScore>ratingScoreSupVal={});
    void showInfoSup();
    RatingScore getRatingScore();
    void requirementSup();
    void rateMember(Member &host);
    friend class Member;

    // friend void sendRequest(string userNameSup);
    // bool rateMember(Member &mem);
};
#endif