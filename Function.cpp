#include "Function.h"

// LAm's Finctions
void registerMember(Guest &guest)
{
    fstream myfile;
    cout << "Member's information input: ";
    cout << "\nEnter your username: ";
    std::getline(cin >> std::ws, guest.userName);
    cout << "\nEnter your password: ";
    std::getline(cin >> std::ws, guest.password);
    cout << "\nEnter your ID: ";
    std::getline(cin >> std::ws, guest.memID);
    cout << "\nEnter your fullname: ";
    std::getline(cin >> std::ws, guest.fullName);
    cout << "\nEnter your email: ";
    std::getline(cin >> std::ws, guest.email);
    cout << "\nEnter your phoneNumber: ";
    cin >> guest.phoneNumber;
    cout << "\nEnter your address: ";
    std::getline(cin >> std::ws, guest.address);
    cout << "\nEnter your skills: ";
    std::getline(cin >> std::ws, guest.skillsInfo);
    guest.creditPoint = 20;

    myfile.open("member.dat", std::ios::app | std::ios::out); // open a file

    myfile << guest.password << "\n";
    myfile << guest.memID << "\n";
    myfile << guest.userName << "\n";
    myfile << guest.fullName << "\n";
    myfile << guest.email << "\n";
    myfile << guest.phoneNumber << "\n";
    myfile << guest.address << "\n";
    myfile << guest.skillsInfo << "\n";
    myfile << guest.creditPoint << "\n";
    // myfile << guest.password << " " << guest.memID << " " << guest.userName << " " << guest.fullName << " " << guest.email << " " << guest.phoneNumber << " " << guest.address << " " << guest.skillsInfo << " " << guest.creditPoint << "\n"; // save data to file
    myfile.close();

    cout << "Your credit points is added to a total of: " << guest.creditPoint << "\n"
         << "You have registered successfully.\n";
}

void viewSupporters(Guest &guest)
{

    int totalMembers = 0;
    int memNum1;
    int comsumingPoint;
    bool availability;
    fstream myfile;

    myfile.open("supporters.dat", std::ios::in);

    if (!myfile)
    {
        cout << " No data to be found\n";
    }
    else
    {
        std::string line;
        // myfile >> password >> memID >> userName >> fullName >> email >> phoneNumber >> address >> skillsInfo >> creditPoint; //take data from file and assign to variables
        while (!myfile.eof())
        { // if not at the end of file
            std::getline(myfile >> std::ws, guest.userName);
            std::getline(myfile >> std::ws, guest.password);
            std::getline(myfile >> std::ws, guest.memID);
            std::getline(myfile >> std::ws, guest.fullName);
            std::getline(myfile >> std::ws, guest.email);
            myfile >> guest.phoneNumber;
            std::getline(myfile >> std::ws, guest.address);
            std::getline(myfile >> std::ws, guest.skillsInfo);
            myfile >> guest.creditPoint;
            myfile >> comsumingPoint;

            // myfile >> guest.password >> guest.memID >> guest.userName >> guest.fullName >> guest.email >> guest.phoneNumber >> guest.address >> guest.skillsInfo >> guest.creditPoint >> comsumingPoint >> availability;
            cout << "Member No." << totalMembers++ << "\n"; // output to the terminal
            cout << "Username: " << guest.userName << "\n";
            cout << "Member ID: " << guest.memID << "\n";
            cout << "Full name: " << guest.fullName << "\n";
            cout << "Email: " << guest.email << "\n";
            cout << "Phone number: " << guest.phoneNumber << "\n";
            cout << "Address: " << guest.address << "\n";
            cout << "Skills: " << guest.skillsInfo << "\n";
            cout << "Credit points: " << guest.creditPoint << "\n";
            cout << endl;
            // myfile >> password >> memID >> userName >> fullName >> email >> phoneNumber >> address >> skillsInfo >> creditPoint; //assign again to terminate the loop
        }
        if (totalMembers == 0)
        { // check if there is no data input ever before
            cout << " No data to be found\n";
        }
    }
    myfile.close();
}

void modifyPassword(Admin &admin)
{
    Guest guest2;
    string userName2 = guest2.getUserName();
    string password2 = guest2.getPassword();
    string fullName2 = guest2.getFullName();
    string email2 = guest2.getEmail();
    int phoneNumber2 = guest2.getPhoneNumber();
    string address2 = guest2.getAddress();
    int creditPoints2 = guest2.getCreditPoint();
    string skillsInfo2 = guest2.getSkillsInfo();
    int memNum2;
    int found = 0; // variable to check for found result
    fstream myfile, myfile1;

    myfile.open("member.dat", std::ios::in);

    if (!myfile)
    {
        cout << " No data to be found\n";
        myfile.close();
    }
    else
    {
        int memNo;
        cout << "Enter the member number you want to modify: ";
        cin >> memNo;
        myfile1.open("Newmember.dat", std::ios::app | std::ios::out);
        std::getline(myfile >> std::ws, password2);
        myfile >> memNum2;
        std::getline(myfile >> std::ws, userName2);
        std::getline(myfile >> std::ws, fullName2);
        std::getline(myfile >> std::ws, email2);
        myfile >> phoneNumber2;
        std::getline(myfile >> std::ws, address2);
        std::getline(myfile >> std::ws, skillsInfo2);
        myfile >> creditPoints2;
        // myfile >> password2 >> memNum2 >> userName2 >> fullName2 >> email2 >> phoneNumber2 >> address2 >> skillsInfo2 >> creditPoints2;
        while (!myfile.eof())
        {
            if (memNo == memNum2)
            {
                cout << "Enter new password: ";
                cin >> password2;
                myfile1 << password2 << "\n";
                myfile1 << memNum2 << "\n";
                myfile1 << userName2 << "\n";
                myfile1 << fullName2 << "\n";
                myfile1 << email2 << "\n";
                myfile1 << phoneNumber2 << "\n";
                myfile1 << address2 << "\n";
                myfile1 << skillsInfo2 << "\n";
                myfile1 << creditPoints2 << "\n";
                found++;
            }
            // myfile >> password2 >> memNum2 >> userName2 >> fullName2 >> email2 >> phoneNumber2 >> address2 >> skillsInfo2 >> creditPoints2;
            if (found == 0)
            {
                cout << "Member not found.";
            }
        }
    }
    myfile1.close();
    myfile.close();
    remove("member.dat");
    rename("Newmember.dat", "member.dat");
}
// Huy's Funtions
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

int setStatus(Member &mem, vector<Supporter> listSup)
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
    myfile << mem.userName << "\n";
    myfile << mem.password << "\n";
    myfile << mem.id << "\n";
    myfile << mem.fullName << "\n";
    myfile << mem.email << "\n";
    myfile << mem.phoneNumber << "\n";
    myfile << mem.address << "\n";
    myfile << mem.skillsInfo << "\n";
    myfile << mem.creditPoint << "\n";
    myfile << mem.comsumingPoint << "\n";
    // myfile << mem.userName << " " << mem.password << " " << mem.id << " "
    //<< mem.fullName << " " << mem.email << " " << mem.phoneNumber << " "
    //<< mem.address << " " << mem.skillsInfo << " " << mem.creditPoint << " "
    //<< mem.comsumingPoint << " " << mem.availability << "\n";
    myfile.close();
    cout << "You are ready to be booked\n";
    return 1;
};
int unlist(Member &mem, vector<Supporter> listSup)
{
    mem.availability == false; // mode off
    for (int i = 0; i < listSup.size(); i++)
    {
        if (mem.userName == listSup[i].userNameSup)
        {
            return i;
        }
    }
    cout << "You're a Supporter yet \n";
    return -1;
}
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

                auto currentTimePoint = std::chrono::system_clock::now();

                // Convert the time point to a time_t
                std::time_t currentTime = std::chrono::system_clock::to_time_t(currentTimePoint);

                // Convert time_t to string for display
                char *timeStr = std::ctime(&currentTime);
                //std::cout << "Current time: " << timeStr;
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
                myFile << timeStr << "\n";

                myFile.close();
                cout << "send request successfully";
                break;
            }
        }
    }
}

// Kiet's Function

bool viewRequest(Member &mem, std::vector<Request> ListofReq)

{
    string time;
    bool matchFound = false;
    for (int i = 0; i < ListofReq.size(); i++)
    {
        if (mem.userName == ListofReq[i].nameofSupport)
        {
            matchFound = true;
            cout << "You recieve a request from " << ListofReq[i].nameOfHost << "\n"
                 << "Title: " << ListofReq[i].title << "\n"
                 << "Description: " << ListofReq[i].description << "\n"
                  << "Time: " << ListofReq[i].time << "\n";
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

// Dat's Function
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

        string userNameNew;
        string passwordNew;
        string idNew;
        string fullNameNew;
        string emailNew;
        string phoneNumberNew;
        string addressNew;
        string creditPointNew;
        string skillsInfoNew;
        fstream newFile;
        // newFile.open("NewMember.dat", std::ios::app | std::ios::out);

        cout << "Payment successful\n";
        return true;
    }
    else
    {
        cout << "Invalid Value, Cancel Covert Money to Credit Point\n";
        return false;
    }
}

void rateMember(Member &mem, string &nameOfHost, int &score)
{
    if (nameOfHost == mem.userName)
    {
        mem.hostRatingScore.push_back(score);
        cout << "Rate Successfully\n";
    }
};

void viewSpecificMem(string &nameOfMem, Member &mem)
{
    if (mem.block() != true && nameOfMem == mem.userName)
    {
        cout << "Full name: " << mem.fullName << "\n";
        cout << "Email: " << mem.email << "\n";
        cout << "Phone number: " << mem.phoneNumber << "\n";
        cout << "Address: " << mem.address << "\n";
        cout << "Skills: " << mem.skillsInfo << "\n";
        cout << "Consuming Point: " << mem.comsumingPoint << "\n";
        for (int i = 0; i < mem.hostRatingScore.size(); i++)
        {
            cout << "HostScore: " << mem.hostRatingScore[i] << "\n";
        }
        cout << endl;
    }
    else
    {
        cout << "This member has block you!\n";
    }
};

bool blockMember(Member &mem, std::vector<Member> ListofMem)
{
    bool status = false;
    string nameOfMem;
    cout << "Enter name that you want to block: ";
    std::getline(cin >> std::ws, nameOfMem);
    for (int i = 0; i < ListofMem.size(); i++)
    {
        if (nameOfMem == ListofMem[i].userName)
        {
            mem.block();
            cout << "Block sucessfully, he/she can see your information\n";
            status = true;
        }
    }
    if (status == true)
    {
        return true;
    }
    return false;
}
void rateSupport(string nameOfSup, int &skillScore, int &supporterscore, string &comment, std::vector<Supporter> &listSup)
{
    for (int i = 0; i < listSup.size(); i++)
    {
        if (nameOfSup == listSup[i].userNameSup)
        {
            listSup[i].reviewSup.push_back(comment);
            listSup[i].skillScore = skillScore;
            listSup[i].supporterScore = supporterscore;
            cout << "Rate Successfully";
        }
    }
};