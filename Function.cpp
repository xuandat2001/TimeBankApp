#include "Function.h"

// LAm's Functions
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

void modifyPassword()
{
    string userName2;
    string password2;
    string fullName2;
    string email2;
    int phoneNumber2;
    string address2;
    int creditPoints2;
    string skillsInfo2;
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

        while (myfile >> password2 >> memNum2 >> userName2 >> fullName2 >> email2 >> phoneNumber2 >> address2 >> skillsInfo2 >> creditPoints2)
        {
            if (memNo == memNum2)
            {
                string password3;
                cout << "Enter new password: ";
                cin >> password3;

                myfile1 << password3 << "\n";
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
            else
            {
                // If the member number does not match, write the data back to the new file
                myfile1 << password2 << "\n";
                myfile1 << memNum2 << "\n";
                myfile1 << userName2 << "\n";
                myfile1 << fullName2 << "\n";
                myfile1 << email2 << "\n";
                myfile1 << phoneNumber2 << "\n";
                myfile1 << address2 << "\n";
                myfile1 << skillsInfo2 << "\n";
                myfile1 << creditPoints2 << "\n";
            }
        }

        if (found == 0)
        {
            cout << "Member not found.";
        }

        myfile.close();
        myfile1.close();

        remove("member.dat");
        rename("Newmember.dat", "member.dat");
    }
}
// Huy's Funtions
int loginMem(std::vector<Member> ListofMem, string usernameVal, string passwordVal)
{
    for (int i = 0; i < ListofMem.size(); i++)
    {

        if (ListofMem[i].userName == usernameVal && ListofMem[i].password == passwordVal) // Check username and password
        {
            return i;
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
void search(string cityName, Member &mem, vector<Supporter> listSup)
{

    for (int i = 0; i < listSup.size(); i++)
    {
        if (listSup[i].addressSup == cityName && mem.creditPoint > listSup[i].comsumingPointSup) // compare the string input from user
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
// Kiet's Function
void sendRequest(std::vector<Supporter> &listSup, Member &mem) // Function to send request to the chosen supporter
{
    string userNameSupVal;
    cout << "Enter the username of supporter: ";
    std::getline(cin >> std::ws, userNameSupVal);
    for (int i = 0; i < listSup.size(); i++)
    {

        if (userNameSupVal == listSup[i].userNameSup) // Check for correct supporter to retrieve information from
        {
            listSup[i].requirementSup();
            if (listSup[i].comsumingPointSup > mem.creditPoint) // Check for valid credit Points to send request
            {
                cout << "Your balance is not enough, Please add more credit";
            }
            else
            {
                string title;
                string description;

                cout << "Enter the title of Request"; // Title of request input from user
                std::getline(cin >> std::ws, title);
                cout << "Enter the description of Request"; // Description of request input from user
                std::getline(cin >> std::ws, description);
                std::fstream myFile;
                myFile.open("Request.dat", std::ios::app | std::ios::out); // Open a file to save request's information and later used for viewRequest function
                if (!myFile)
                {
                    cout << "Fail to open or create file";
                }
                myFile << mem.userName << "\n"; // Write information into the Request.dat file
                myFile << userNameSupVal << "\n";
                myFile << title << "\n";
                myFile << description << "\n";

                myFile.close(); // Close and save file
                cout << "Send request successfully"; // Notify user that the request is sent successfully
                break;
            }
        }
    }
}




bool viewRequest(Member &mem, std::vector<Request> ListofReq) // Function to view incoming Requests

{
    bool matchFound = false;
    for (int i = 0; i < ListofReq.size(); i++) // Loop to check for requests
    {
        if (mem.userName == ListofReq[i].nameofSupport) // Condition to check if the request is sent to the right person and notify them
        {
            matchFound = true;
            cout << "You receive a request from " << ListofReq[i].nameOfHost << "\n" // Print out request information for the supporter
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
int interactRequest(Member &mem, Request &req, std::vector<Supporter> &listSup) // Function to accept or deny request
{
    cout << "\n 1 for Accept\n";
    cout << "2 for Deny\n";
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice == 1) // Condition to check for accepted request
    {
        req.status = "Accepted";
        std::fstream myFile;
        myFile.open("AcceptedRequest.dat", std::ios::app | std::ios::out); // Open a file and save information for requesting person to check if the supporter has accepted or not
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
                cout << "You receive " << listSup[i].comsumingPointSup << "CreditPoint\n"; // Notify users how many credit Points they received for completing the request
            }
        }

        return 1;
    }
    else if (choice == 2) // Condition to check for denied request
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

bool checkStatusRequest(Member &mem, std::vector<Supporter> &listSup) // Function to check for request's status (denied or accepted)
{
    string nameHostVal;
    string nameSupVal;
    fstream myFile;
    myFile.open("AcceptedRequest.dat", std::ios::in); // Open AcceptedRequest.dat that is made if the supporter accepted the request

    if (!myFile) // Condition to check if file existed or not
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
        cout << "your request is accepted"; // Notify user that their request is accepted
        for (int i = 0; i < listSup.size(); i++)
        {
            if (listSup[i].userNameSup == nameSupVal)
            {
                cout << "Your credit point is deducted: " << listSup[i].comsumingPointSup << "\n"; // Reduce user's credit Points by the supporter's charge rate
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
        mem.showInfo();
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
            cout << "Rate Successfully\n";
        }
    }
};