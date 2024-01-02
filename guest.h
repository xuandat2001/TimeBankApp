#include <iostream>
#include <fstream>

using namespace std;
using std::string;
using std::cin;
using std::cout;

class Guest{
    friend class Admin;

    protected:
    string password;
    int memNum = 0;

    private:
    string userName;
    string fullName;
    string email;
    int phoneNumber;
    string address;
    int creditPoint;
    int ratingScore;
    string skillsInfo;
    bool Availability;
    int creditPoints = 0;

    fstream myfile;
    
    public:
    void registerMember(){
        
        cout << "Member's information input: "; 
        cout << "\nEnter your username: ";
        cin >> userName;
        cout << "\nEnter your password: ";
        cin >> password;
        cout << "\nEnter your fullname: ";
        cin >> fullName;
        cout << "\nEnter your email: ";
        cin >> email;
        cout << "\nEnter your phoneNumber: ";
        cin >> phoneNumber;
        cout << "\nEnter your address: ";
        cin >> address;
        cout << "\nEnter your skills: ";
        cin >> skillsInfo;

        memNum += 1;

        myfile.open("pwd.dat", std::ios::app | std::ios::out); //open a file
        myfile << password << " " << memNum << " " << userName << " " << fullName << " " << email << " " << phoneNumber << " " << address << " " << skillsInfo << "\n"; //save data to file
        myfile.close();

        creditPoints += 20;
        cout << "Your credit points is added to a total of: " << creditPoints << "\n" << "You have registered successfully.\n";
    }

    void viewSupporters(){

        int totalMembers = 0;

        myfile.open("pwd.dat", std::ios::in);

        if (!myfile) {
            cout << " No data to be found\n";   
            
         } else {
            myfile >> password >> memNum >> userName >> fullName >> email >> phoneNumber >> address >> skillsInfo; //take data from file and assign to variables
            while (!myfile.eof()){ //if not at the end of file
                cout << "Member No." << totalMembers++ << "\n"; //output to the terminal
                cout << "Username: " << userName << "\n";
                cout << "Full name: " << fullName << "\n";
                cout << "Email: " << email << "\n";
                cout << "Phone number: " << phoneNumber << "\n";
                cout << "Address: " << address << "\n";
                cout << "Skills: " << skillsInfo << "\n";
                cout << endl;
            myfile >> password >> memNum >> userName >> fullName >> email >> phoneNumber >> address >> skillsInfo; //assign again to terminate the loop
            }
            if (totalMembers == 0){ //check if there is no data input ever before 
                cout << " No data to be found\n";
            }
        }
        myfile.close(); 
    }
};