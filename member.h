#include<iostream>
#include<vector>
#include "guest.h"
using std::cin;
using std::cout;
using std::string;
class Member: private Guest{
private: 
    std::vector<int>hostRatingScore;
    bool availability;
    string review;
public:
    Member(){};
    void getInfo();
    
};