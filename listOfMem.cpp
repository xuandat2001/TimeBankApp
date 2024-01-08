#include <iostream>
#include <cstring>
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
    string phoneNumber;
    string address;
    string creditPoint;
    string skillsInfo;
    int hostRatingScore = 0;
    int comsumingPoint = 0;
    bool availability = false;
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
            Member mem(userName, password, id, fullName, email, std::stod(phoneNumber), address, std::stod(creditPoint), skillsInfo, hostRatingScore, comsumingPoint, availability, review);
            listofMember.push_back(mem);
        }
    }
    myfile.close();
}
void listofMem::showInfoMems()
{
    cout << "All the member: \n";
    for (int i = 0; i < listofMember.size(); i++)
    {

        listofMember[i].showInfo();
    }
};
bool listofMem::login()
{
    cout << "You must login your account: \n";
    string userName;
    string password;
    cout << "Enter your username: ";
    std::getline(cin >> std::ws, userName); // getusername
    cout << "Enter your Password: ";
    std::getline(cin >> std::ws, password); // get password
    for (int i = 0; i < listofMember.size(); i++)
    {

        if (listofMember[i].userName == userName && listofMember[i].password == password)
        {
            int choice; // get choice from user
            cout << "This is your menu:\n"
                 << "0. Exit\n"
                 << "1. Show Information\n"
                 << "2. Set Status\n"
                 << "3. Search Supporter\n";
            cout << "Enter ur choice";
            cin >> choice;
            if (choice == 1)
            {
                cout << "Login successfully\n";
                cout << "Username: " << listofMember[i].userName << "\n";
                cout << "Full name: " << listofMember[i].fullName << "\n";
                cout << "Email: " << listofMember[i].email << "\n";
                cout << "Phone number: " << listofMember[i].phoneNumber << "\n";
                cout << "Address: " << listofMember[i].address << "\n";
                cout << "Skills: " << listofMember[i].skillsInfo << "\n";
                cout << "Credit: " << listofMember[i].creditPoint << "\n";
                cout << "Consuming Point: " << listofMember[i].comsumingPoint << "\n";
                cout << "HostingScore: " << listofMember[i].hostRatingScore << "\n";
                cout << "review: " << listofMember[i].review << "\n";
                cout << endl;
            }
            else if (choice == 2)
            {
                listofMember[i].availability == true;
                fstream myfile;
                myfile.open("supporters.dat", std::ios::app | std::ios::out); // open a file
                myfile << " " << listofMember[i].userName << " " << listofMember[i].fullName << " " << listofMember[i].email << " "
                       << listofMember[i].phoneNumber << " " << listofMember[i].address << " " << listofMember[i].skillsInfo << " "<<listofMember[i].comsumingPoint<<" "<<listofMember[i].hostRatingScore
                       << "\n"; // save data to file
                myfile.close();
                cout << "You are a suporter. Ready to be booked\n";
            }

            return true;
            break;
        }
        else if (listofMember[i].userName == userName && listofMember[i].password != password)
        {
            cout << "Your password is not correct\n";
            return false;
        }
        else if (listofMember[i].userName != userName && listofMember[i].password == password)
        {
            cout << "Your username is not correct\n";
            return false;
        }
        else
        {
            cout << "Your username and password are not correct\n";
            return false;
        }
    }
    return 1;
};
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
