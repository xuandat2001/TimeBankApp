#include <iostream>
#include "Admin.h"
#include "Guest.h"

using std::string;
using std::cin;
using std::cout;

    Guest guest2;
    string userName2 = guest2.getUserName();
    string password2 = guest2.getPassword();
    string fullName2 = guest2.getFullName();
    string email2 = guest2.getEmail();
    int phoneNumber2 = guest2.getPhoneNumber();
    string address2 =guest2.getAddress();
    int creditPoints2 = guest2.getCreditPoint();
    string skillsInfo2 =guest2.getSkillsInfo();

    string Admin::getAuserName(){
        return this->AuserName;
    }

    string Admin::getApassword(){
        return this->Apassword;
    }


    void Admin::modifyPassword(){
        
        int memNum2;
        int found = 0; //variable to check for found result
        fstream myfile, myfile1;

        myfile.open("pwd.dat", std::ios::in);

        if (!myfile) {
            cout << " No data to be found\n";
            myfile.close();

        } else {
            int memNo;
            cout << "Enter the member number you want to modify: ";
            cin >> memNo;
            myfile1.open("Newpwd.dat", std::ios::app | std::ios::out);
            myfile >> password2 >> memNum2 >> userName2 >> fullName2 >> email2 >> phoneNumber2 >> address2 >> skillsInfo2;
            while (!myfile.eof()){
                if (memNo != memNum2){
                    myfile1 << password2 << " " << memNum2 << " " << userName2 << " " << fullName2 << " " 
                                << email2 << " " << phoneNumber2 << " " << address2 << " " << skillsInfo2 << "\n";
                } else {
                    cout << "Enter new password :";
                    cin >> password2;
                    myfile1 << password2 << " " << memNum2 << " " << userName2 << " " << fullName2 << " " 
                                << email2 << " " << phoneNumber2 << " " << address2 << " " << skillsInfo2 << "\n";
                    found ++;
                }
                myfile >> password2 >> memNum2 >> userName2 >> fullName2 >> email2 >> phoneNumber2 >> address2 >> skillsInfo2;
                if (found == 0){
                cout << "Member not found.";
                }
            }
        }
        myfile1.close();
        myfile.close();
        remove("pwd.dat");
        rename("Newpwd.dat", "pwd.dat");
    }