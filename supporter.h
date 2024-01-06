#ifndef _SUPPORTER_H
#define _SUPPORTER_H
#include<iostream>
#include<vector>
#include"ratingscore.h"
#include"Member.h"
using std::cin;
using std::cout;

class Supporter{
private: 
    std::vector<RatingScore>HostScore;
public:
    Supporter();
    bool rateMember(Member &mem);
}; 
#endif