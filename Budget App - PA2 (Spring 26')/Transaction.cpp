#include "Transaction.h"
#include <iostream>

using namespace std;

Transaction::Transaction(double amount, string date, string category, string description){
    this->amount = amount;
    this->date = date;
    this->category = category;
    this->description = description;
}

string Transaction::getType(){
    return "N/A";
}
void Transaction::display(){
    cout << "N/A" << endl;
}


double Transaction::getAmount(){
    return amount;
}

string Transaction::getDate(){
    return date;
}

string Transaction::getCategory(){
    return category;
}

string Transaction::getDescription(){
    return description;
}