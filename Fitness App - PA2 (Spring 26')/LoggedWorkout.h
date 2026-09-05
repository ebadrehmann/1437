#ifndef LOGGEDWORKOUT_H
#define LOGGEDWORKOUT_H

#include "Workout.h"
#include <fstream>
#include <iostream>
using namespace std;

class LoggedWorkout : public Workout {
private:
    string date;
    string notes;

public:
    LoggedWorkout(string title, string category, int totalTime,
                  bool isFavorite, string date, string notes)
        : Workout(title, category, totalTime, isFavorite) {
        this->date = date;
        this->notes = notes;
    }

    void display() override;
    string getType() override;

    // Overrides Workout::saveData() to also write date and notes.
    // Calls Workout::saveData() first so base fields are written too.
    void saveData(ofstream& output) override;

    // Getters
    string getDate()  { return date; }
    string getNotes() { return notes; }

    // Setters
    void setDate(string d)  { date = d; }
    void setNotes(string n) { notes = n; }
};

#endif