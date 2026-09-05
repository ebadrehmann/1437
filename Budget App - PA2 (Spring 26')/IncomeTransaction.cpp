#include "IncomeTransaction.h"
#include <iostream>

using namespace std;


void IncomeTransaction::display(){
    cout << "Print the income transaction details here" << endl;
}


string IncomeTransaction::getType(){
    return type;
}