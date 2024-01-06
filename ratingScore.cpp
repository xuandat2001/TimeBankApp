#include<iostream>
#include "ratingScore.h"
using std::cin;
using std::cout;
    RatingScore::RatingScore(){};
    int RatingScore::showScore(){
        int averageScore = (skillRatingScore + supporterRatingScore )/2;
        return averageScore;
    }