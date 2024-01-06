#include <iostream>

#include "Member.h"
#include <fstream>
using std::cin;
using std::cout;
using std::string;
Member::Member(){};
// Get infomation from the file
void Member::getInfo()
{
    fstream myfile;

    myfile.open("pwd.dat", std::ios::in);

    if (!myfile)
    {
        cout << " No data to be found\n";
    }
    else
    {
        myfile >> password >> id >> userName >> fullName >> email >> phoneNumber >> address >> skillsInfo >> creditPoint; // take data from file and assign to variables
        while (!myfile.eof())
        { // if not at the end of file
            myfile >> password >> id >> userName >> fullName >> email >> phoneNumber >> address >> skillsInfo >> creditPoint;
        }
    }
    myfile.close();
}
void Member::showInfo()
{
    cout << "Username: " << userName << "\n";
    cout << "Full name: " << fullName << "\n";
    cout << "Email: " << email << "\n";
    cout << "Phone number: " << phoneNumber << "\n";
    cout << "Address: " << address << "\n";
    cout << "Skills: " << skillsInfo << "\n";
    cout << "Credit: " << creditPoint << "\n";
    cout << "Consuming Point: " << comsumingPoint << "\n";
    cout << "HostingScore: " << hostRatingScore << "\n";
    cout << "review: " << review << "\n";
    cout << endl;
}
void Member::showInfoVip()
{
    cout << "Full name: " << this->fullName << "\n";
    cout << "Email: " << this->email << "\n";
    cout << "Phone number: " << this->phoneNumber << "\n";
    cout << "Address: " << this->address << "\n";
    cout << "Skills: " << this->skillsInfo << "\n";
    cout << "Consuming Point: " << this->comsumingPoint << "\n";
    cout << "Consuming Point: " << this->hostRatingScore << "\n";
    cout << endl;
}
bool Member::loginMem(string usernameVal, string passwordVal)
{
    if (userName == usernameVal && password == passwordVal) // Check username and password
    {
        cout << "Login successfully\n";
        return true;
    }
    else if (userName == usernameVal && password != passwordVal)
    {
        cout << "Your password is not correct\n";
        return false;
    }
    else if (userName != usernameVal && password == passwordVal)
    {
        cout << "Your username is not correct\n";
        return false;
    }
    else
    {
        cout << "Your username and password are not correct\n";
        return false;
    }
};
int Member::setStatus()
{
    int choice;
    cout << "Set your status\n";
    cout << "1 for On\n";
    cout << "2 for Off\n";
    cout << "Enter ur choice: ";
    cin >> choice;
    if (choice == 1)
    {
        availability == true;
        fstream myfile;
        myfile.open("supporters.dat", std::ios::app | std::ios::out); // open a file
        myfile << " " << userName << " " << fullName << " " << email << " "
               << phoneNumber << " " << address << " " << skillsInfo << " "  << "\n"; // save data to file
        myfile.close();
         cout << "You are a suporter. Ready to be booked\n";
        return 1;
    }
    else if (choice == 2)
    {
        availability == false;
        cout << "dont distrup";
        return 2;
    }
    else
    {
        cout << "invalid value";
        return -1;
    }
};
/*void Member::search(string &condition, vector<Member>listMem){
    for (int i = 0; i < listMem.size(); i++)
    {
        if (listMem[i].address == condition)
        {
            cout<<"Around you: \n";
            listMem[i].showInfo();
        }

    }

}*/

// bool Member::blockMember(Member &mem){
//     int id;
//     string userName;

// }