#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <vector>
#include "supporter.h"
#include "Member.h"
#include "request.h"

using std::cin;
using std::cout;
using std::string;
// Function declarations
void search(string cityName, int creditPointCondition, vector<Supporter> listSup);
void sendRequest(std::vector<Supporter> listSup,Member mem);
int loginMem(std::vector<Member> ListofMem, string usernameVal, string passwordVal);
int setStatus(Member &mem);
bool viewRequest(Member &mem, Request &req);
#endif