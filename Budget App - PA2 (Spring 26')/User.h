#ifndef USER_H
#define USER_H

#include "App.h"

class User{
    private:

    string username;
    double savingsGoal;
    App myBudget;

    public:

    User(){

    }

    User(string username, double savingsGoal){
        this->username = username;
        this->savingsGoal = savingsGoal;
    }

    void display();
    void showSavingsProgress();
    void saveUserData(string filename);
    void loadUserData(string filename);
    void startSession();
};

#endif