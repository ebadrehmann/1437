#ifndef INCOMETRANSACTION_H
#define INCOMETRANSACTION_H

#include "Transaction.h"

class IncomeTransaction: public Transaction{
    private:

    string type;

    public:

    IncomeTransaction(double amount, string date, string category, string description, string type):
    Transaction(amount, date, category, description){this->type = type;};

    void display() override;
    string getType() override;

};

#endif