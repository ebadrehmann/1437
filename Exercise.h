#ifndef EXERCISE_H
#define EXERCISE_H

#include <string>
using namespace std;

class Exercise {
private:
    string name;
    string muscleGroup;
    string type;
    int caloriesBurned;

public:
    Exercise(string name, string muscleGroup, string type, int caloriesBurned) {
        this->name = name;
        this->muscleGroup = muscleGroup;
        this->type = type;
        this->caloriesBurned = caloriesBurned;
    }

    void display();

    // Getters
    string getName()        { return name; }
    string getMuscleGroup() { return muscleGroup; }
    string getType()        { return type; }
    int getCaloriesBurned() { return caloriesBurned; }

    // Setters
    void setName(string n)        { name = n; }
    void setMuscleGroup(string m) { muscleGroup = m; }
    void setType(string t)        { type = t; }
    void setCaloriesBurned(int c) { caloriesBurned = c; }
};

#endif