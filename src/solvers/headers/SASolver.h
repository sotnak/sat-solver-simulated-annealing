//
// Created by pavel on 09.12.21.
//

#ifndef HW4_SASOLVER_H
#define HW4_SASOLVER_H

#include<random>

#include "ASolver.h"

class SASolver : public ASolver {
    const double startTemperature = 100;
    double temperature = 0;
    const double iterationsBeforeCoolingMultiplier = 1;
    unsigned long iterationsBeforeCooling = 0;
    const double frozenSize = 1.0/8.0;
    const double frozenDiff = 0.01;
    const double coolingCoefficient = 0.95;

    random_device rd;
    mt19937 gen;
    uniform_int_distribution<> intDist;
    uniform_real_distribution<> realDist;

    [[nodiscard]] bool frozen() const;

    State tryState(const State& state);

    void cool();

public:
    SASolver(int startingTemperature, double coolingCoeff, double innerCycleMultiplier, double frozenLength, double frozenDifference);

    Solution solve(const Problem &problem) override;
};


#endif //HW4_SASOLVER_H
