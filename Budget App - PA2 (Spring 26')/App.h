#ifndef APP_H
#define APP_H

#include <vector>
#include "ExpenseTransaction.h"
#include "IncomeTransaction.h"


class App{
    private:

    vector<Transaction*> transactions;

    public:

    ~App(){
        for (Transaction *t: transactions)
            delete t;
    }
    void addIncome(); //  prompts user to add an income transaction
    void addExpense(); //  prompts user to add an expense transaction
    void viewAllTransactions(); //  displays all transactions
    double calculateBalance(); // calculates net balance (income – expense)
    void viewSpendingByCategory(); // prompts user for a category and displays total expenses for that category
    void saveToFile(ofstream& output); // saves all transactions to a file
    void loadFromFile(ifstream& input); // loads all transactions from a file
};



#endif