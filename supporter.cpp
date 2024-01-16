#include <iostream>
#include "supporter.h"
using std::cin;
using std::cout;
// all definations
Supporter::Supporter(string userNameVal,
                     string passwordVal,
                     string idVal,
                     string fullNameVal,
                     string emailVal,
                     int phoneNumberVal,
                     string addressVal,
                     int creditPointVal,
                     string skillsInfoVal,
                     std::vector<int> HostratingScoreVal,
                     int comsumingPointVal,
                     bool availabilitySup,
                     std::vector<string> reviewVal,
                     
                     std::vector<RatingScore> ratingScoreSupVal) : Member(userNameVal,
                                                                          passwordVal,
                                                                          idVal,
                                                                          fullNameVal,
                                                                          emailVal,
                                                                          phoneNumberVal,
                                                                          addressVal,
                                                                          creditPointVal,
                                                                          skillsInfoVal,
                                                                          HostratingScoreVal,
                                                                          comsumingPointVal,
                                                                          availabilitySup),
                                                                   reviewSup(reviewVal), ratingScoreSup(ratingScoreSupVal){};
void Supporter::showInfoSup()
{
    cout << "Name of Supporter: " << Member::userName << "\n";
    cout << "FullName of Supporter: " << Member::fullName << "\n";
    cout << "Email of Supporter: " << Member::email << "\n";
    cout << "Phone of Supporter: " << Member::phoneNumber << "\n";
    cout << "Address of Supporter: " << Member::address << "\n";
    cout << "Credit Point of Supporter: " << Member::creditPoint << "\n";
    cout << "Skills of Supporter: " << Member::skillsInfo << "\n";
    cout << "Consuming Point of Supporter: " << Member::comsumingPoint << "\n";
    for (int i = 0; i < reviewSup.size(); i++)
    {
        cout << "reviews of Supporter: " << reviewSup[i] << "\n";
    }

    for (int i = 0; i < ratingScoreSup.size(); i++)
    {
        ratingScoreSup[i].showScore();
        ratingScoreSup[i].showAveScore();
    }

    // cout<<"RatingScore of Supporter: " <<ratingScoreSup <<"\n";
}
void Supporter::requirementSup()
{
    cout << "There is a supporter with consuming point: " << Member::comsumingPoint << "credit points/hour and minimum required host-rating score is 3.";
}
/* void Supporter::rateMember(Member &host)
{
    int score;
    cout << "Enter the score for your host: ";
    cin >> score;
    host.hostRatingScore.push_back(score);
}
 bool Supporter::rateMember(Member &mem){
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