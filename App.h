#ifndef APP_H
#define APP_H

#include "Workout.h"
#include "LoggedWorkout.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class App {
private:
    vector<Workout*> workouts;

public:
    ~App();

    void createWorkout();
    void createLoggedWorkout();
    void viewAllWorkouts();
    void viewByCategory(string category);
    void viewFavorites();
    void deleteWorkout();
    void saveToFile(ofstream& output);
    void loadFromFile(ifstream& input);
};

#endif