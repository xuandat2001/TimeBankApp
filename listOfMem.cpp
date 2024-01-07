#include <iostream>
#include <fstream>
#include "listOfMem.h"
using std::cin;
using std::cout;
using std::string;
listofMem::listofMem(){};
void listofMem::getInforMems()
{

    string userName;
    string password;
    string id;
    string fullName;
    string email;
    int phoneNumber;
    string address;
    int creditPoint;
    string skillsInfo;
    int hostRatingScore = 0;
    int comsumingPoint = 0;
    bool availability;
    string review;
    fstream myfile;
    myfile.open("pwd.dat", std::ios::in);

    if (!myfile)
    {
        cout << " No data to be found\n";
    }
    else
    {
        // myfile >> password >> id >> userName >> fullName >> email >> phoneNumber >> address >> skillsInfo >> creditPoint; // take data from file and assign to variables
        while (!myfile.eof())
        { // if not at the end of file
            myfile >> password >> id >> userName >> fullName >> email >> phoneNumber >> address >> skillsInfo >> creditPoint;
            listofMember.push_back(Member(userName,password,id, fullName,
            phoneNumber , address,skillsInfo,creditPoint, hostRatingScore,comsumingPoint,availability,review));
        }
    }
    myfile.close();
}
/*bool listofMem::blockMem(string &username, int &id){
    
       cout << "Enter your member u wanna to block: ";
       std::getline(cin >> std::ws, username);
       cout << "Enter their Id: ";
       cin >> id;
       for (int i = 0; i < listofMember.size(); i++)
       {
           if (listofMember[i].userName == username && listofMember[i].id == id)
           {
               this->
           }
       }

};*/
