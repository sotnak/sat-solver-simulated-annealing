//
// Created by antos on 24.09.2021.
//

#ifndef HW2_ASOLVER_H
#define HW2_ASOLVER_H

#include "../../headers/Problem.h"
#include "../../headers/Solution.h"
#include "../../headers/Progress.h"


class ASolver {
protected:
    long long int counter=0;
    Progress progress;
public:
    virtual Solution solve(const Problem& problem) = 0;
    virtual ~ASolver();
    [[nodiscard]] long long int getCounter() const;
    string getProgress();
    void resetCounter();

    static ASolver *SolverFactory(int startingTemperature, double coolingCoefficient, double frozenSize, double frozenDiff,
                           double innerCycleMultiplier);
};


#endif //HW2_ASOLVER_H
