#ifndef EXPENSETRANSACTION_H
#define EXPENSETRANSACTION_H

#include "Transaction.h"

class ExpenseTransaction: public Transaction{

    private:

    string type;

    public:

    ExpenseTransaction(double amount, string date, string category, string description, string type):
    Transaction(amount, date, category, description){this->type = type;};

    void display() override;

    string getType() override;
};

#endif