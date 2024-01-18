#include "Function.h"


void search(string cityName, int creditPointCondition, vector<Supporter> listSup)
{

    for (int i = 0; i < listSup.size(); i++)
    {
        if (listSup[i].addressSup == cityName && creditPointCondition < listSup[i].creditPointSup) // compare the string input from user
        {
            cout << "Around you: \n";
            listSup[i].showInfoSup();
        }
        else
        {
            cout << "No one is suitable\n";
        }
    }
}



void sendRequest(std::vector<Supporter> listSup, Member mem)
{
    string userNameSupVal;
    cout << "Enter the username of supporter: ";
    std::getline(cin >> std::ws, userNameSupVal);
    for (int i = 0; i < listSup.size(); i++)
    {
        
        if (userNameSupVal == listSup[i].userNameSup)
        {
            listSup[i].requirementSup();
            string title;
            string description;
            string status = "";
            cout << "Enter the title of Request";
            std::getline(cin >> std::ws, title);
            cout << "Enter the description of Request";
            std::getline(cin >> std::ws, description);
            std::fstream myFile;
            myFile.open("Request.dat", std::ios::app | std::ios::out);
            if (!myFile)
            {
                cout << "Fail to open or create file";
            }
            myFile << mem.userName << " " << userNameSupVal << " " << title << " " << description << " " << status << "\n";

            myFile.close();
            cout << "send request successfully";
            break;
        }
    }
}




int loginMem(std::vector<Member> ListofMem, string usernameVal, string passwordVal)
{
    for (size_t i = 0; i < ListofMem.size(); i++)
    {

        if (ListofMem[i].userName == usernameVal && ListofMem[i].password == passwordVal) // Check username and password
        {
            return static_cast<int>(i);
        }
    }
    return -1;
};




int setStatus(Member &mem)
{
    int choice;
    cout << "Set your status\n";
    cout << "1 for On\n";
    cout << "2 for Off\n";
    cout << "Enter ur choice: ";
    cin >> choice;
    if (choice == 1)
    {
        mem.availability == true; // mode on
        cout << "Enter your consuming point: ";
        cin >> mem.comsumingPoint;
        fstream myfile;                                               // create a file to store all the infor of a member as a supporter
        myfile.open("supporters.dat", std::ios::app | std::ios::out); // open a file
        if (!myfile)
        {
            cout << " Fail to open/create a file\n";
        }
        myfile << mem.userName << " " << mem.password << " " << mem.id << " " << mem.fullName << " " << mem.email << " " << mem.phoneNumber << " " << mem.address << " " << mem.skillsInfo << " " << mem.creditPoint << " " << mem.comsumingPoint << " " << mem.availability << "\n";
        myfile.close();
        cout << "You are ready to be booked\n";
        return 1;
    }
    else if (choice == 2)
    {
        mem.availability == false; // mode off
        cout << "You turn off mode Supporter";
        return 2;
    }
    else
    {
        cout << "Invalid value";
        return -1;
    }
};


bool viewRequest(Member &mem, Request &req){
        if (mem.userName != req.nameofSupport)
    {
        cout << "You do not have any request";
        return true;
    }
    else
    {
        cout << "You recieve a request from " << req.nameOfHost << "\n"
             << "Title: " << req.title << "\n"
             << "Description: " << req.description;
        return false;
    }
}