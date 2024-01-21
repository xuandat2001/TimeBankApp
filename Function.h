#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <vector>
#include <fstream>
#include <iostream>
#include <chrono>
#include <ctime>
#include "supporter.h"
#include "Member.h"
#include "request.h"
#include "admin.h"
using std::cin;
using std::cout;
using std::string;
// Function declarations
void registerMember(Guest &guest);
void viewSupporters(Guest &guest);
void modifyPassword();
void search(string cityName, Member &mem, vector<Supporter> listSup);
void sendRequest(std::vector<Supporter> &listSup, Member &mem);
int loginMem(std::vector<Member> ListofMem, string usernameVal, string passwordVal);
int setStatus(Member &mem, vector<Supporter> listSup);
int unlist(Member &mem, vector<Supporter> listSup);
bool viewRequest(Member &mem, std::vector<Request> ListofReq);
int interactRequest(Member &mem, Request &req,std::vector<Supporter> &listSup);
bool checkStatusRequest(Member &mem, std::vector<Supporter> &listSup);
bool perfomeTopUp(Member &mem);
void rateMember(Member &mem, string &nameOfHost, int &score);
void viewSpecificMem(string &nameOfMem, Member &mem);
bool blockMember(Member &mem,std::vector<Member> ListofMem);
void rateSupport(string nameOfSup, int &skillScore, int &supporterscore, string &comment, std::vector<Supporter> &listSup);
#endif