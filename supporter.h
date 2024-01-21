#ifndef SUPPORTER_H
#define SUPPORTER_H
#include <iostream>
#include <vector>
#include "Member.h"
// #include "sendrequest.h"
using std::cin;
using std::cout;
using std::string;
class Request;
class Member;
class Supporter
{
private:
    string userNameSup;
    string passwordSup;
    string idSup;
    string fullNameSup;
    string emailSup;
    int phoneNumberSup;
    string addressSup;
    int creditPointSup;
    string skillsInfoSup;
    std::vector<int> HostratingScoreSup;
    int comsumingPointSup;
    bool availabilitySup;
    std::vector<string> reviewSup;
    int skillScore;
    int supporterScore ;

public:
    // all declarations
    Supporter(string userNameVal = "",
              string passwordVal = "",
              string idVal = "",
              string fullNameVal = "",
              string emailVal = "",
              int phoneNumberVal = 0,
              string addressVal = "",
              int creditPointVal = 0,
              string skillsInfoVal = "",
              std::vector<int> HostratingScoreVal = {},
              int comsumingPointVal = 0,
              bool availabilityVal = false,
              std::vector<string> reviewVal = {},
                int skillScoreVal = 0,
                int supporterScoreVal = 0
              );
  
    void showInfoSup();
    void requirementSup();
    // void rateMember(Member &host);
    friend class Member;
    friend void search(string cityName, Member &mem, vector<Supporter> listSup);
    friend int setStatus(Member &mem, vector<Supporter> listSup);
    friend int unlist(Member &mem, vector<Supporter> listSup);
    friend void sendRequest(std::vector<Supporter> &listSup, Member &mem);
    friend int interactRequest(Member &mem, Request &req, std::vector<Supporter> &listSup);
    friend bool checkStatusRequest(Member &mem, std::vector<Supporter> &listSup);
    friend void rateSupport(string nameOfSup, int &skillScore, int &supporterscore, string &comment, std::vector<Supporter> &listSup);
    // friend void sendRequest(string userNameSup);
    // bool rateMember(Member &mem);
};
#endif