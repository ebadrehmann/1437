#include "ExpenseTransaction.h"
#include <iostream>

using namespace std;


void ExpenseTransaction::display(){
    cout << "Print the expense transaction details here." << endl;
}


string ExpenseTransaction::getType(){
    return type;
}