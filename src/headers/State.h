//
// Created by pavel on 19.01.22.
//

#ifndef KOP_HW5_STATE_H
#define KOP_HW5_STATE_H

#include "Problem.h"

class State {
    bool* arr{};
    int weight = 1;
    double value = -1;
    Problem problem;

    void evaluate();
public:

    State(const Problem& problem);
    State();
    State(const State& other);
    ~State();

    State& operator=(const State &other);

    void swap(int n);
    bool at(int n) const;
    double getWorth() const;
    int getWeight() const;
    bool better(const State& state) const;
    double howMuchWorse(const State &state) const;
    string toString() const;
};


#endif //KOP_HW5_STATE_H
