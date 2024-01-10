#include<iostream>
#include "supporter.h"
using std::cin;
using std::cout;
//all definations
   Supporter::Supporter(string userNameVal,
           string idVal,
           string fullNameVal,
           string emailVal,
           int phoneNumberVal,
           string addressVal,
           int creditPointVal,
           string skillsInfoVal,
           int comsumingPointVal,
           string reviewVal,
           std::vector<RatingScore>ratingScoreVal):userNameSup(userNameVal),
           idSup(idVal),fullNameSup(fullNameVal),emailSup(emailVal),phoneNumberSup(phoneNumberVal),addressSup(addressVal),
           creditPointSup(creditPointVal),skillsInfoSup(skillsInfoVal),comsumingPointSup(comsumingPointVal),
           reviewSup(reviewVal), ratingScoreSup(ratingScoreVal){};
    void Supporter::showInfoSup(){
        cout<<"Name of Supporter: "<<userNameSup<<"\n";
        cout<<"FullName of Supporter: "<<fullNameSup<<"\n";
        cout<<"Email of Supporter: "<<emailSup<<"\n";
        cout<<"Phone of Supporter: "<<phoneNumberSup<<"\n";
        cout<<"Address of Supporter: "<<addressSup<<"\n";
        cout<<"Credit Point of Supporter: "<<creditPointSup<<"\n";
        cout<<"Skills of Supporter: "<<skillsInfoSup<<"\n";
        cout<<"Consuming Point of Supporter: "<<comsumingPointSup<<"\n";
        cout<<"reviews of Supporter: "<<reviewSup<<"\n";
        cout<<"\n";
       // cout<<"RatingScore of Supporter: " <<ratingScoreSup <<"\n";
    }
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