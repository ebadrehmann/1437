#include "User.h"
#include <fstream>
#include <iostream>

void User::display() {
    cout << "Username: " << username << endl;
    cout << "Goal: $" << savingsGoal << endl;
    cout << "Balance: $" << myBudget.calculateBalance() << endl;
}


void User::showSavingsProgress() {
    double balance  = myBudget.calculateBalance();
    double remaining = savingsGoal - balance;
    if (remaining <= 0)
        cout << username << " has reached their savings goal!" << endl;
    else
        cout << username << " is $" << remaining << " away from their goal of $" << savingsGoal << "." << endl;
}


void User::saveUserData(string filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) { cout << "ERROR: Could not open file." << endl; return; }
    outFile << username    << endl;
    outFile << savingsGoal << endl;
    myBudget.saveToFile(outFile);
}

void User::loadUserData(string filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) { cout << "ERROR: Could not open file." << endl; return; }
    getline(inputFile, username);
    inputFile >> savingsGoal;
    inputFile.ignore();
    myBudget.loadFromFile(inputFile);
    cout << "Profile loaded for " << username << "." << endl;
}

// CS
void User::startSession() {
    int choice = 0;
    while (true) {
        cout << "\n===========================" << endl;
        cout << "MAIN MENU for " << username      << endl;
        cout << "===========================" << endl;
        cout << "1.  Add Income"               << endl;
        cout << "2.  Add Expense"              << endl;
        cout << "3.  View All Transactions"    << endl;
        cout << "4.  View Balance"             << endl;
        cout << "5.  View Spending by Category"<< endl;
        cout << "6.  Show Savings Progress"    << endl;
        cout << "7.  Save"                     << endl;
        cout << "8.  View User Profile"        << endl;
        cout << "9. Return to Main Menu"      << endl;
        cout << "Choice: ";
        cin  >> choice;
        cin.ignore();

        switch (choice) {
            case 1:  
                myBudget.addIncome();
                break;
            case 2:
                myBudget.addExpense();            
                break;
            case 3:  
                myBudget.viewAllTransactions();   
                break;
            case 4:
                cout << "Balance: $" << myBudget.calculateBalance() << endl;
                break;
            case 5:  
                myBudget.viewSpendingByCategory(); 
                break;
            case 6: 
                showSavingsProgress();             
                break;
            case 7: {
                string file = username + "_data.txt";
                saveUserData(file);
                cout << "Saved to " << file << endl;
                break;
            }
            case 8:
                display();  
                break;
            case 9: 
                return;     // back to USER menu in main()
            default: 
                cout << "Invalid Choice, try again" << endl;
        }
    }
}
