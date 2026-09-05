#include "User.h"
#include <iostream>
using namespace std;

int main() {
    User user;
    int choice;

    do {
        cout << "\n============================" << endl;
        cout << "        FITNESS APP         " << endl;
        cout << "============================" << endl;
        cout << "1. Load User Profile" << endl;
        cout << "2. Create New User" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string filename;
            cout << "Enter filename to load: ";
            getline(cin, filename);
            user.loadUserData(filename);
            user.startSession();

        } else if (choice == 2) {
            string username, fitnessGoal;
            int age;
            double weight;

            cout << "Username: ";
            getline(cin, username);
            cout << "Age: ";
            cin >> age;
            cin.ignore();
            cout << "Weight (lbs): ";
            cin >> weight;
            cin.ignore();
            cout << "Fitness goal (Lose Weight, Build Muscle, Endurance, etc.): ";
            getline(cin, fitnessGoal);

            user = User(username, age, weight, fitnessGoal);
            user.startSession();
        }

    } while (choice != 3);

    cout << "Goodbye!" << endl;
    return 0;
}