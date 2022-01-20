//
// Created by antos on 24.09.2021.
//

#include "headers/ASolver.h"
#include "headers/SASolver.h"

#include <stdexcept>


ASolver::~ASolver() = default;

ASolver *ASolver::SolverFactory(int startingTemperature, double coolingCoefficient, double frozenSize, double frozenDiff, double innerCycleMultiplier ){

    return new SASolver(startingTemperature, coolingCoefficient, innerCycleMultiplier, frozenSize, frozenDiff);
}

long long int ASolver::getCounter() const {
    return this->counter;
}

void ASolver::resetCounter() {
    this->counter=0;
}

string ASolver::getProgress() {
    return progress.toString();
}
