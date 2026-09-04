#include "User.h"
#include <iostream>
#include <fstream>
using namespace std;

User::User() : username(""), age(0), weight(0.0), fitnessGoal("") {}

User::User(string username, int age, double weight, string fitnessGoal) {
    this->username = username;
    this->age = age;
    this->weight = weight;
    this->fitnessGoal = fitnessGoal;
}

void User::display() {
    cout << "============================" << endl;
    cout << "        USER PROFILE        " << endl;
    cout << "============================" << endl;
    cout << "Username:     " << username << endl;
    cout << "Age:          " << age << endl;
    cout << "Weight:       " << weight << " lbs" << endl;
    cout << "Fitness Goal: " << fitnessGoal << endl;
    cout << "============================" << endl;
}

void User::saveUserData(string filename) {
    ofstream output(filename);
    if (!output.is_open()) {
        cout << "Error: Could not open file for saving." << endl;
        return;
    }
    output << username << "\n";
    output << age << "\n";
    output << weight << "\n";
    output << fitnessGoal << "\n";
    myFitness.saveToFile(output);
    output.close();
    cout << "Data saved to \"" << filename << "\"." << endl;
}

void User::loadUserData(string filename) {
    ifstream input(filename);
    if (!input.is_open()) {
        cout << "Error: Could not open file for loading." << endl;
        return;
    }
    getline(input, username);
    input >> age >> weight;
    input.ignore();
    getline(input, fitnessGoal);
    myFitness.loadFromFile(input);
    input.close();
    cout << "Data loaded from \"" << filename << "\"." << endl;
}

void User::startSession() {
    int choice;
    do {
        cout << "\n============================" << endl;
        cout << "         MAIN MENU          " << endl;
        cout << "============================" << endl;
        cout << "1.  Create Workout" << endl;
        cout << "2.  View All Workouts" << endl;
        cout << "3.  View by Category" << endl;
        cout << "4.  View Favorites" << endl;
        cout << "5.  Log Workout" << endl;
        cout << "6.  Delete Workout" << endl;
        cout << "7.  Save" << endl;
        cout << "8.  Load" << endl;
        cout << "9.  View User Profile" << endl;
        cout << "10. Return to Main Menu" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                myFitness.createWorkout();
                break;
            case 2:
                myFitness.viewAllWorkouts();
                break;
            case 3: {
                string category;
                cout << "Enter category (Upper Body, Lower Body, Full Body, Cardio): ";
                getline(cin, category);
                myFitness.viewByCategory(category);
                break;
            }
            case 4:
                myFitness.viewFavorites();
                break;
            case 5:
                myFitness.createLoggedWorkout();
                break;
            case 6:
                myFitness.deleteWorkout();
                break;
            case 7: {
                string filename;
                cout << "Enter filename to save to: ";
                getline(cin, filename);
                saveUserData(filename);
                break;
            }
            case 8: {
                string filename;
                cout << "Enter filename to load from: ";
                getline(cin, filename);
                loadUserData(filename);
                break;
            }
            case 9:
                display();
                break;
            case 10:
                cout << "Returning to user menu..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 10);
}