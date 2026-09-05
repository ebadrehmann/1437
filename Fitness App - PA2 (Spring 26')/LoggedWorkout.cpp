#include "LoggedWorkout.h"
#include <iostream>
using namespace std;

void LoggedWorkout::display() {
    Workout::display();
    cout << "Date:  " << date << endl;
    cout << "Notes: " << notes << endl;
    cout << "============================" << endl;
}

string LoggedWorkout::getType() {
    return "Logged";
}

// Calls base to write shared fields, then appends date and notes.
// No cast needed anywhere — polymorphism handles routing to this method.
void LoggedWorkout::saveData(ofstream& output) {
    Workout::saveData(output);  // writes type, title, category, time, favorite, exercises, sets
    output << date << "\n";
    output << notes << "\n";
}