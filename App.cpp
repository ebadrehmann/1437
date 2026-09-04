#include "App.h"
#include <iostream>
using namespace std;

App::~App() {
    for (Workout* w : workouts)
        delete w;
}

void App::createWorkout() {
    string title, category, favoriteInput;
    int totalTime;
    bool isFavorite;

    cout << "Workout name: ";
    getline(cin, title);
    cout << "Category (Upper Body, Lower Body, Full Body, Cardio): ";
    getline(cin, category);
    cout << "Total time (minutes): ";
    cin >> totalTime;
    cin.ignore();
    cout << "Mark as favorite? (yes/no): ";
    getline(cin, favoriteInput);
    isFavorite = (favoriteInput == "yes" || favoriteInput == "Yes");

    Workout* w = new Workout(title, category, totalTime, isFavorite);

    string continueExercise, continueSet;
    do {
        w->addExercise();
        do {
            w->addSet(w->getExercises().size() - 1);
            cout << "Add another set? (yes/no): ";
            getline(cin, continueSet);
        } while (continueSet == "yes" || continueSet == "Yes");

        cout << "Add another exercise? (yes/no): ";
        getline(cin, continueExercise);
    } while (continueExercise == "yes" || continueExercise == "Yes");

    workouts.push_back(w);
    cout << "Workout created!" << endl;
}

void App::createLoggedWorkout() {
    string title, category, favoriteInput, date, notes;
    int totalTime;
    bool isFavorite;

    cout << "Workout name: ";
    getline(cin, title);
    cout << "Category (Upper Body, Lower Body, Full Body, Cardio): ";
    getline(cin, category);
    cout << "Total time (minutes): ";
    cin >> totalTime;
    cin.ignore();
    cout << "Mark as favorite? (yes/no): ";
    getline(cin, favoriteInput);
    isFavorite = (favoriteInput == "yes" || favoriteInput == "Yes");
    cout << "Date of workout (MM/DD/YYYY): ";
    getline(cin, date);
    cout << "Any notes? ";
    getline(cin, notes);

    LoggedWorkout* w = new LoggedWorkout(title, category, totalTime, isFavorite, date, notes);

    string continueExercise, continueSet;
    do {
        w->addExercise();
        do {
            w->addSet(w->getExercises().size() - 1);
            cout << "Add another set? (yes/no): ";
            getline(cin, continueSet);
        } while (continueSet == "yes" || continueSet == "Yes");

        cout << "Add another exercise? (yes/no): ";
        getline(cin, continueExercise);
    } while (continueExercise == "yes" || continueExercise == "Yes");

    workouts.push_back(w);
    cout << "Logged workout created!" << endl;
}

void App::viewAllWorkouts() {
    if (workouts.empty()) {
        cout << "No workouts found." << endl;
        return;
    }
    for (Workout* w : workouts)
        w->display();
}

void App::viewByCategory(string category) {
    bool found = false;
    for (Workout* w : workouts) {
        if (w->getCategory() == category) {
            w->display();
            found = true;
        }
    }
    if (!found)
        cout << "No workouts found in category: " << category << endl;
}

void App::viewFavorites() {
    bool found = false;
    for (Workout* w : workouts) {
        if (w->getIsFavorite()) {
            w->display();
            found = true;
        }
    }
    if (!found)
        cout << "No favorite workouts found." << endl;
}

void App::deleteWorkout() {
    if (workouts.empty()) {
        cout << "No workouts to delete." << endl;
        return;
    }

    for (int i = 0; i < (int)workouts.size(); i++)
        cout << i << ". " << workouts[i]->getTitle() << endl;

    int choice;
    cout << "Enter number to delete: ";
    cin >> choice;
    cin.ignore();

    if (choice < 0 || choice >= (int)workouts.size()) {
        cout << "Invalid selection." << endl;
        return;
    }

    delete workouts[choice];
    workouts.erase(workouts.begin() + choice);
    cout << "Workout deleted." << endl;
}

// No cast needed — w->saveData() routes to the correct version via vtable.
void App::saveToFile(ofstream& output) {
    output << workouts.size() << "\n";
    for (Workout* w : workouts)
        w->saveData(output);
}

// loadFromFile still needs to read type first to know which object to construct.
// That is unavoidable since we have to decide what to 'new' before the object exists.
// NOTE: LoggedWorkout writes date/notes AFTER exercises (see LoggedWorkout::saveData),
//       so we read them in that same order here.
void App::loadFromFile(ifstream& input) {
    for (Workout* w : workouts) delete w;
    workouts.clear();

    int numWorkouts;
    input >> numWorkouts;
    input.ignore();

    for (int i = 0; i < numWorkouts; i++) {
        string type, title, category;
        int totalTime;
        bool isFavorite;

        getline(input, type);
        getline(input, title);
        getline(input, category);
        input >> totalTime >> isFavorite;
        input.ignore();

        int numExercises;
        input >> numExercises;
        input.ignore();

        // Temporary storage — we need exercises/sets before constructing LoggedWorkout
        vector<Exercise*> exList;
        vector<vector<Set*>> setList;

        for (int j = 0; j < numExercises; j++) {
            string name, muscleGroup, exType;
            int caloriesBurned;

            getline(input, name);
            getline(input, muscleGroup);
            getline(input, exType);
            input >> caloriesBurned;
            input.ignore();

            exList.push_back(new Exercise(name, muscleGroup, exType, caloriesBurned));

            int numSets;
            input >> numSets;
            input.ignore();

            vector<Set*> setsForExercise;
            for (int k = 0; k < numSets; k++) {
                int reps, duration;
                double weight;
                input >> reps >> weight >> duration;
                input.ignore();
                setsForExercise.push_back(new Set(reps, weight, duration));
            }
            setList.push_back(setsForExercise);
        }

        // Construct the right type, then load exercises/sets into it
        Workout* w;
        if (type == "Logged") {
            string date, notes;
            getline(input, date);
            getline(input, notes);
            w = new LoggedWorkout(title, category, totalTime, isFavorite, date, notes);
        } else {
            w = new Workout(title, category, totalTime, isFavorite);
        }

        for (int j = 0; j < (int)exList.size(); j++) {
            w->addExerciseDirect(exList[j]);
            for (Set* s : setList[j])
                w->addSetDirect(j, s);
        }

        workouts.push_back(w);
    }
}