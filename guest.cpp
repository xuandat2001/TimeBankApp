#include <iostream>
#include <fstream>
#include "guest.h"

using namespace std;
using std::string;
using std::cin;
using std::cout;

    Guest::Guest(){}

    string Guest::getUserName(){
        return userName;
    };
    string Guest::getPassword(){
        return password;
    };

    string Guest::getMemID(){
        return memID;
    };
    
    string Guest::getFullName(){
        return fullName;
    };
    string Guest::getEmail(){
        return email;
    };
    int Guest::getPhoneNumber(){
        return phoneNumber;
    };
    string Guest::getAddress(){
        return address;
    };
    int Guest::getCreditPoint(){
        return creditPoint;
    };
    /*bool Guest::getAvailability(){
        return Availability;
    };*/
    string Guest::getSkillsInfo(){
        return skillsInfo;
    };

    void Guest::registerMember(){
        fstream myfile;
        cout << "Member's information input: "; 
        cout << "\nEnter your username: ";
        cin >> userName;
        cout << "\nEnter your password: ";
        cin >> password;
        cout << "\nEnter your ID: ";
        cin >> memID;
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
        creditPoint = 20;

        myfile.open("pwd.dat", std::ios::app | std::ios::out); //open a file
        myfile << password << " " << memID << " " << userName << " " << fullName << " " << email << " " 
                << phoneNumber << " " << address << " " << skillsInfo << " " << creditPoint << "\n"; //save data to file
        myfile.close();
           
        cout << "Your credit points is added to a total of: " << creditPoint << "\n" << "You have registered successfully.\n";
    }

    void Guest::viewSupporters(){

        int totalMembers = 0;
        int memNum1;
        fstream myfile;

        myfile.open("pwd.dat", std::ios::in);

        if (!myfile) {
            cout << " No data to be found\n";   
            
         } else {
            myfile >> password >> memID >> userName >> fullName >> email >> phoneNumber >> address >> skillsInfo >> creditPoint; //take data from file and assign to variables
            while (!myfile.eof()){ //if not at the end of file
                cout << "Member No." << totalMembers++ << "\n"; //output to the terminal
                cout << "Username: " << userName << "\n";
                cout << "Member ID: " << memID << "\n";
                cout << "Full name: " << fullName << "\n";
                cout << "Email: " << email << "\n";
                cout << "Phone number: " << phoneNumber << "\n";
                cout << "Address: " << address << "\n";
                cout << "Skills: " << skillsInfo << "\n";
                cout << "Credit points: " << creditPoint << "\n";
                cout << endl;
            myfile >> password >> memID >> userName >> fullName >> email >> phoneNumber >> address >> skillsInfo >> creditPoint; //assign again to terminate the loop
            }
            if (totalMembers == 0){ //check if there is no data input ever before 
                cout << " No data to be found\n";
            }
        }
        myfile.close(); 
    }
