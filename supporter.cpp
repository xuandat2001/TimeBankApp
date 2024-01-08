#include<iostream>
#include "supporter.h"
using std::cin;
using std::cout;
   Supporter::Supporter(string userNameVal,
           string passwordVal,
           string idVal,
           string fullNameVal,
           string emailVal,
           int phoneNumberVal,
           string addressVal,
           int creditPointVal,
           string skillsInfoVal,
           int hostRatingScoreVal,
           int comsumingPointVal,
           bool availabilityVal,
           string reviewVal,
           std::vector<RatingScore>HostScoreVal):Member(userNameVal,passwordVal,
           idVal,fullNameVal,emailVal,phoneNumberVal,addressVal,
           creditPointVal,skillsInfoVal,hostRatingScoreVal,comsumingPointVal,
           availabilityVal,reviewVal), HostScore(hostRatingScoreVal){};
    /* bool Supporter::rateMember(Member &mem){
        string name;
        int id;
        int score;
        cout<<"Enter the name of Host: ";
        std::getline(cin>>std::ws, name);
        cout<<"Enter their id: ";
        cin >> id;
        // if (name == mem.getUserName() && id == mem.getMemID())
        // {
        
        // }
        
    }*/