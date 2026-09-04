#ifndef WORKOUT_H
#define WORKOUT_H

#include "Exercise.h"
#include "Set.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Workout {
protected:
    vector<Exercise*> exercises;
    vector<vector<Set*>> sets;

private:
    string title;
    string category;
    int totalTime;
    bool isFavorite;

public:
    Workout(string title, string category, int totalTime, bool isFavorite);
    virtual ~Workout();

    void addExercise();
    void addSet(int exerciseIndex);
    void addExerciseDirect(Exercise* e);
    void addSetDirect(int exerciseIndex, Set* s);

    void toggleFavorite();
    int calculateCalories();

    virtual void display();
    virtual string getType();

    // saveData writes this workout to a file.
    // LoggedWorkout overrides this to also write date and notes.
    virtual void saveData(ofstream& output);

    // Getters
    string getTitle()                { return title; }
    string getCategory()             { return category; }
    int getTotalTime()               { return totalTime; }
    bool getIsFavorite()             { return isFavorite; }
    vector<Exercise*> getExercises() { return exercises; }
    vector<vector<Set*>> getSets()   { return sets; }

    // Setters
    void setTitle(string t)    { title = t; }
    void setCategory(string c) { category = c; }
    void setTotalTime(int t)   { totalTime = t; }
    void setIsFavorite(bool f) { isFavorite = f; }
};

#endif