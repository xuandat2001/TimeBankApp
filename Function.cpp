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
        listSup[i].showInfoSup();
        if (userNameSupVal == listSup[i].userNameSup)
        {
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
        else
        {
            cout << "could not find the username";
        }
    }
}

bool loginMem(Member &mem)
{
    string usernameVal, passwordVal;

    cout << "Enter your username: ";
    std::getline(cin >> std::ws, usernameVal); // getusername
    cout << "Enter your Password: ";
    std::getline(cin >> std::ws, passwordVal);                      // get password
    if (mem.userName == usernameVal && mem.password == passwordVal) // Check username and password
    {
        cout << "Login successfully\n";
        return true;
    }

    
    cout << "Login unsuccessfully. Please enter again";
    return false;
};