#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <vector>
#include "supporter.h"
#include "Member.h"

using std::cin;
using std::cout;
using std::string;
// Function declarations
void search(string cityName, int creditPointCondition, vector<Supporter> listSup);
void sendRequest(std::vector<Supporter> listSup,Member mem);
bool loginMem( Member &mem);
#endif