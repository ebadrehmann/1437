#ifndef SET_H
#define SET_H

using namespace std;

class Set {
private:
    int reps;
    double weight;
    int duration;

public:
    Set(int reps, double weight, int duration) {
        this->reps = reps;
        this->weight = weight;
        this->duration = duration;
    }

    void display();

    // Getters
    int getReps()       { return reps; }
    double getWeight()  { return weight; }
    int getDuration()   { return duration; }

    // Setters
    void setReps(int r)      { reps = r; }
    void setWeight(double w) { weight = w; }
    void setDuration(int d)  { duration = d; }
};

#endif