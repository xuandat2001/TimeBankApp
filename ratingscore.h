#include<iostream>

using std::cin;
using std::cout;

class RatingScore{
private: 
    int skillRatingScore;
    int supporterRatingScore;
public:
    RatingScore();
    int getSkillScore();
    int getSupporterScore();
    void showScore();
    void showAveScore();
};