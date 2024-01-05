#include <iostream>
#include <fstream>
#include "Guest.h"

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
    int Guest::getMemNum(){
        return memNum;
    }
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
    int Guest::getRatingScore(){
        return ratingScore;
    };
    /*bool Guest::getAvailability(){
        return Availability;
    };*/
    string Guest::getSkillsInfo(){
        return skillsInfo;
    };

    Guest guest1;
    string userName1 = guest1.getUserName();
    string password1 = guest1.getPassword();
    int memNum1 = guest1.getMemNum();
    string fullName1 = guest1.getFullName();
    string email1 = guest1.getEmail();
    int phoneNumber1 = guest1.getPhoneNumber();
    string address1 =guest1.getAddress();
    int creditPoints1 = guest1.getCreditPoint();
    string skillsInfo1 =guest1.getSkillsInfo();

    void Guest::registerMember(){
        fstream myfile;
        cout << "Member's information input: "; 
        cout << "\nEnter your username: ";
        cin >> userName1;
        cout << "\nEnter your password: ";
        cin >> password1;
        cout << "\nEnter your fullname: ";
        cin >> fullName1;
        cout << "\nEnter your email: ";
        cin >> email1;
        cout << "\nEnter your phoneNumber: ";
        cin >> phoneNumber1;
        cout << "\nEnter your address: ";
        cin >> address1;
        cout << "\nEnter your skills: ";
        cin >> skillsInfo1;

        memNum1 += 1;
        
        myfile.open("pwd.dat", std::ios::app | std::ios::out); //open a file
        myfile << password1 << " " << memNum1 << " " << userName1 << " " << fullName1 << " " << email1 << " " << phoneNumber1 << " " << address1 << " " << skillsInfo1 << "\n"; //save data to file
        myfile.close();

        creditPoints1 += 20;
        cout << "Your credit points is added to a total of: " << creditPoints1 << "\n" << "You have registered successfully.\n";
    }

    void Guest::viewSupporters(){

        int totalMembers = 0;
        fstream myfile;

        myfile.open("pwd.dat", std::ios::in);

        if (!myfile) {
            cout << " No data to be found\n";   
            
         } else {
            myfile >> password1 >> memNum1 >> userName1 >> fullName1 >> email1 >> phoneNumber1 >> address1 >> skillsInfo1; //take data from file and assign to variables
            while (!myfile.eof()){ //if not at the end of file
                cout << "Member No." << totalMembers++ << "\n"; //output to the terminal
                cout << "Username: " << userName1 << "\n";
                cout << "Full name: " << fullName1 << "\n";
                cout << "Email: " << email1 << "\n";
                cout << "Phone number: " << phoneNumber1 << "\n";
                cout << "Address: " << address1 << "\n";
                cout << "Skills: " << skillsInfo1 << "\n";
                cout << endl;
            myfile >> password1 >> memNum1 >> userName1 >> fullName1 >> email1 >> phoneNumber1 >> address1 >> skillsInfo1; //assign again to terminate the loop
            }
            if (totalMembers == 0){ //check if there is no data input ever before 
                cout << " No data to be found\n";
            }
        }
        myfile.close(); 
    }
