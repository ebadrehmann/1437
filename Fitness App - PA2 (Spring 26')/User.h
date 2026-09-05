#ifndef USER_H
#define USER_H

#include "App.h"
#include <string>
using namespace std;

class User {
private:
    string username;
    int age;
    double weight;
    string fitnessGoal;
    App myFitness;

public:
    User();
    User(string username, int age, double weight, string fitnessGoal);

    void display();
    void saveUserData(string filename);
    void loadUserData(string filename);
    void startSession();

    // Getters
    string getUsername()    { return username; }
    int getAge()            { return age; }
    double getWeight()      {return weight; }
    string getFitnessGoal() { return fitnessGoal; }

    // Setters
    void setUsername(string u)    { username = u; }
    void setAge(int a)            { age = a; }
    void setWeight(double w)      { weight = w; }
    void setFitnessGoal(string g) { fitnessGoal = g; }
};

#endif