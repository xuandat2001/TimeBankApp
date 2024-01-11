#include <iostream>
#include "ratingScore.h"
using std::cin;
using std::cout;
RatingScore::RatingScore(){};
int RatingScore::getSkillScore()
{
    return skillRatingScore;
}
int RatingScore::getSupporterScore()
{
    return supporterRatingScore;
}
void RatingScore::showScore()
{
    cout << "\n Skill score: " << skillRatingScore << "\n";
    cout << "\n Supporter score: " << supporterRatingScore << "\n";
}
void RatingScore::showAveScore()
{
    int averageScore = (skillRatingScore + supporterRatingScore) / 2;
    cout << "\nThe average score is: " << averageScore << "\n";
}