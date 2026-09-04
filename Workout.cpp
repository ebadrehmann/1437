#include "Workout.h"
#include <iostream>
using namespace std;

Workout::Workout(string title, string category, int totalTime, bool isFavorite) {
    this->title = title;
    this->category = category;
    this->totalTime = totalTime;
    this->isFavorite = isFavorite;
}

Workout::~Workout() {
    for (int i = 0; i < (int)exercises.size(); i++) {
        delete exercises[i];
        for (int j = 0; j < (int)sets[i].size(); j++)
            delete sets[i][j];
    }
}

void Workout::addExercise() {
    string name, muscleGroup, type;
    int caloriesBurned;

    cout << "Exercise name: ";
    getline(cin, name);
    cout << "Muscle group targeted: ";
    getline(cin, muscleGroup);
    cout << "Type (Cardio, Strength, Flexibility, Balance): ";
    getline(cin, type);
    cout << "Calories burned per session: ";
    cin >> caloriesBurned;
    cin.ignore();

    exercises.push_back(new Exercise(name, muscleGroup, type, caloriesBurned));
    sets.push_back(vector<Set*>());
}

void Workout::addSet(int exerciseIndex) {
    int reps, duration;
    double weight;

    cout << "Reps: ";
    cin >> reps;
    cin.ignore();
    cout << "Weight (lbs): ";
    cin >> weight;
    cin.ignore();
    cout << "Duration in seconds (0 if not cardio): ";
    cin >> duration;
    cin.ignore();

    sets.at(exerciseIndex).push_back(new Set(reps, weight, duration));
}

void Workout::addExerciseDirect(Exercise* e) {
    exercises.push_back(e);
    sets.push_back(vector<Set*>());
}

void Workout::addSetDirect(int exerciseIndex, Set* s) {
    sets.at(exerciseIndex).push_back(s);
}

void Workout::toggleFavorite() {
    isFavorite = !isFavorite;
}

int Workout::calculateCalories() {
    int total = 0;
    for (int i = 0; i < (int)exercises.size(); i++)
        for (int j = 0; j < (int)sets[i].size(); j++)
            total += exercises[i]->getCaloriesBurned();
    return total;
}

void Workout::display() {
    cout << "============================" << endl;
    cout << "Workout:   " << title << endl;
    cout << "Category:  " << category << endl;
    cout << "Duration:  " << totalTime << " min" << endl;
    cout << "Calories:  " << calculateCalories() << endl;
    cout << "Favorite:  " << (isFavorite ? "Yes" : "No") << endl;
    cout << "Type:      " << getType() << endl;

    for (int i = 0; i < (int)exercises.size(); i++) {
        cout << "----------------------------" << endl;
        exercises[i]->display();
        for (int j = 0; j < (int)sets[i].size(); j++) {
            cout << "  -- Set #" << j + 1 << " --" << endl;
            sets[i][j]->display();
        }
    }
    cout << "============================" << endl;
}

string Workout::getType() {
    return "Normal";
}

// Writes all base workout data to the file.
// LoggedWorkout::saveData() calls this first, then appends its own fields.
void Workout::saveData(ofstream& output) {
    output << getType() << "\n";   // "Normal" or "Logged" — read first on load
    output << title << "\n";
    output << category << "\n";
    output << totalTime << "\n";
    output << isFavorite << "\n";

    output << exercises.size() << "\n";
    for (int i = 0; i < (int)exercises.size(); i++) {
        output << exercises[i]->getName() << "\n";
        output << exercises[i]->getMuscleGroup() << "\n";
        output << exercises[i]->getType() << "\n";
        output << exercises[i]->getCaloriesBurned() << "\n";

        output << sets[i].size() << "\n";
        for (int j = 0; j < (int)sets[i].size(); j++) {
            output << sets[i][j]->getReps() << "\n";
            output << sets[i][j]->getWeight() << "\n";
            output << sets[i][j]->getDuration() << "\n";
        }
    }
}