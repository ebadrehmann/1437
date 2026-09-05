#include "App.h"
#include <iostream>
#include <fstream>


void App::addIncome(){

    double amount;
    string date, category, description;

    cout << "What is the amount you would like to deposit?" << endl;
    cin >> amount;
    cin.ignore();
    cout << "What is the date?" << endl;
    getline(cin, date);
    cout << "What is the category?" << endl;
    getline(cin, category);
    cout << "Memo: " << endl;
    getline(cin, description);

    transactions.push_back(new IncomeTransaction(amount, date, category, description, "Income"));
}
void App::addExpense(){

    double amount;
    string date, category, description;

    cout << "What is the amount you would like to withdraw?" << endl;
    cin >> amount;
    cin.ignore();
    cout << "What is the date?" << endl;
    getline(cin, date);
    cout << "What is the category?" << endl;
    getline(cin, category);
    cout << "Memo: " << endl;
    getline(cin, description);

    transactions.push_back(new ExpenseTransaction(amount, date, category, description, "Expense"));
}

void App::viewAllTransactions(){
    for (Transaction* t: transactions){
        t->display();
    }
}

double App::calculateBalance(){
    double total = 0;
    for (Transaction* t: transactions){
        if (t->getType() == "Income")
            total += t->getAmount();
        else
            total -= t->getAmount();
    }
    return total;
}

void App::viewSpendingByCategory(){
    string category;
    cout << "What category would you like to seek?" << endl;
    getline(cin, category);
    
    for (Transaction* t: transactions){
        if (t->getCategory() == category)
            t->display();
    }
}


void App::saveToFile(ofstream& output){
    for (Transaction* t: transactions){
        output << t->getType() << endl;
        output << t->getAmount() << endl;
        output << t->getDate() << endl;
        output << t->getCategory() << endl;
        output << t->getDescription() << endl;
    }
}

void App::loadFromFile(ifstream& input){
    string type, date, category, description;
    double amount;

    while (getline(input, type)) {
        input >> amount;
        input.ignore();

        getline(input, date);
        getline(input, category);
        getline(input, description);

        if (type == "Income")
            transactions.push_back(new IncomeTransaction(amount, date, category, description, type));
        else
            transactions.push_back(new ExpenseTransaction(amount, date, category, description, type));
    }
}