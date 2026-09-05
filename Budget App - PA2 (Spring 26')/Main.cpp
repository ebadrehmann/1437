#include <iostream>
#include "User.h"
using namespace std;

int main() {
    int choice = 0;

    while (true) {
        cout << "\n===========================" << endl;
        cout << "USER"<< endl;
        cout << "===========================" << endl;
        cout << "1. Load User Profile" << endl;
        cout << "2. Create New User" << endl;
        cout << "3. Exit" << endl;
        cout << "Choice: ";
        cin  >> choice;
        cin.ignore();

        if (choice == 1)
        {
            string filename;
            cout << "Enter filename to load: ";
            getline(cin, filename);
            User u;
            u.loadUserData(filename);
            u.startSession();
        } else if (choice == 2)
        {
            string name;
            double goal;
            cout << "Enter username: ";
            getline(cin, name);
            cout << "Enter savings goal: $";
            cin  >> goal;
            cin.ignore();
            User u(name, goal);
            cout << "Welcome, " << name << "!" << endl;
            u.startSession();

        } else if (choice == 3) 
        {
            cout << "Exiting the program..." << endl;
            break;

        } else 
        {
            cout << "Invalid choice. Try again." << endl;
        }
    }
    return 0;
}