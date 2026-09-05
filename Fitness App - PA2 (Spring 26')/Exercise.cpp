#include "Exercise.h"
#include <iostream>
using namespace std;

void Exercise::display() {
    cout << "  Exercise Name:   " << name << endl;
    cout << "  Muscle Group:    " << muscleGroup << endl;
    cout << "  Type:            " << type << endl;
    cout << "  Calories Burned: " << caloriesBurned << endl;
}