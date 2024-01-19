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

void sendRequest(std::vector<Supporter> &listSup, Member &mem)
{
    string userNameSupVal;
    cout << "Enter the username of supporter: ";
    std::getline(cin >> std::ws, userNameSupVal);
    for (int i = 0; i < listSup.size(); i++)
    {

        if (userNameSupVal == listSup[i].userNameSup)
        {
            listSup[i].requirementSup();
            if (listSup[i].comsumingPointSup > mem.creditPoint)
            {
                cout << "Your balance is not enough, Please add more credit";
            }
            else
            {
                string title;
                string description;

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
                myFile << mem.userName << "\n";
                myFile << userNameSupVal << "\n";
                myFile << title << "\n";
                myFile << description << "\n";

                myFile.close();
                cout << "send request successfully";
                break;
            }
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

bool viewRequest(Member &mem, std::vector<Request> ListofReq)

{
    bool matchFound = false;
    for (int i = 0; i < ListofReq.size(); i++)
    {
        if (mem.userName == ListofReq[i].nameofSupport)
        {
            matchFound = true;
            cout << "You recieve a request from " << ListofReq[i].nameOfHost << "\n"
                 << "Title: " << ListofReq[i].title << "\n"
                 << "Description: " << ListofReq[i].description << "\n";
        }
    }
    if (matchFound == true)
    {
        return true;
    }
    return false;
}
int interactRequest(Member &mem, Request &req, std::vector<Supporter> &listSup)
{
    cout << "\n 1 for Accept\n";
    cout << "2 for Deny\n";
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice == 1)
    {
        req.status = "Accpected";
        std::fstream myFile;
        myFile.open("AcceptedRequest.dat", std::ios::app | std::ios::out);
        if (!myFile)
        {
            cout << "Fail to open or create file";
        }
        myFile << req.nameOfHost << " " << req.nameofSupport << " " << req.title << " " << req.description << " "
               << req.status;
        myFile.close();
        remove("request.dat");
        cout << "Accepted Request\n";
        for (int i = 0; i < listSup.size(); i++)
        {
            if (listSup[i].userNameSup == req.nameofSupport)
            {
                mem.creditPoint += listSup[i].comsumingPointSup;
                cout << "You recieve " << listSup[i].comsumingPointSup << "CreditPoint\n";
            }
        }

        return 1;
    }
    else if (choice == 2)
    {
        remove("request.dat");
        cout << "Denied Request";
        return 2;
    }
    else
    {
        cout << "invalid value\n";
        return -1;
    }
}

void rateMember(std::vector<Member> ListofMem)
{
    for (int i = 0; i < ListofMem.size(); i++)
    {
        int score;
        string nameOfHost;
        cout << "Enter your host: ";
        std::getline(cin >> std::ws, nameOfHost);
        cout << "Enter the score for your host: ";
        cin >> score;
        if (nameOfHost == ListofMem[i].userName)
        {
            ListofMem[i].hostRatingScore.push_back(score);
        }
    }
}

bool checkStatusRequest(Member &mem, std::vector<Supporter> &listSup)
{
    string nameHostVal;
    string nameSupVal;
    fstream myFile;
    myFile.open("AcceptedRequest.dat", std::ios::in);

    if (!myFile)
    {
        cout << " No data to be found\n";
    }
    else
    {

        myFile >> nameHostVal >> nameSupVal;
    }
    myFile.close();
    if (nameHostVal == mem.userName)
    {
        remove("AcceptedRequest.dat");
        remove("request.dat");
        cout << "your request is accepted";
        for (int i = 0; i < listSup.size(); i++)
        {
            if (listSup[i].userNameSup == nameSupVal)
            {
                cout << "Your credit point is deducted: " << listSup[i].comsumingPointSup << "\n";
            }
        }

        return true;
    }
    return false;
};

bool perfomeTopUp(Member &mem)
{
    string userName;
    cout << "\n Convert from $->Credit Point: 1$->1 CreditPoint\n";
    int money;
    cout << "Enter the money: ";
    cin >> money;
    if (money > 0)
    {

        mem.creditPoint += money;
        cout << "Payment successful\n";

        return true;
    }
    else
    {
        cout << "Invalid Value, Cancel Covert Money to Credit Point\n";
        return false;
    }
}

void rateMember(std::vector<Member> ListofMem)
{
    int score;
    string nameOfHost;
    cout << "Enter your host: ";
    std::getline(cin >> std::ws, nameOfHost);
    for (int i = 0; i < ListofMem.size(); i++)
    {
        if (nameOfHost == ListofMem[i].userName)
        {
            cout << "Enter the score for your host: ";
            cin >> score;
            ListofMem[i].hostRatingScore.push_back(score);

        }
    }
};