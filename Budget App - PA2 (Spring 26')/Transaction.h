#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>


using namespace std;

class Transaction{

    private:

    double amount;
    string date;
    string category;
    string description;

    public:
    
    Transaction(double amount, string date, string category, string description);

    virtual string getType();
    virtual void display();
    
    double getAmount();
    string getDate();
    string getCategory();
    string getDescription();
    

};


#endif