#include <iostream>
#include "guest.h"
#include "member.h"
#include "supporter.h"
#include "time.h"
#include "ratingScore.h"
#include "admin.h"
using std::cin;
using std::cout;
using std::string;
int main()
{
    int choice;
    cout << "Use a app as 1. Guest    2. Member     3. Admin\n";
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice == 1)
    {
        Guest guest;
        guest.registerMenber();
    }

    return 0;
}