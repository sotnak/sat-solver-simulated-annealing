//
// Created by pavel on 09.12.21.
//

#include "headers/SASolver.h"
#include <iostream>

Solution SASolver::solve(const Problem &problem) {
    intDist= uniform_int_distribution<>(0,problem.literalCount-1);
    iterationsBeforeCooling = (int)(problem.literalCount * iterationsBeforeCoolingMultiplier);

    progress.clear();

    State best(problem);

    State state(problem);
    temperature = startTemperature;

    bool firstRun = true;

    while(firstRun || !frozen()){
        firstRun=false;
        for(unsigned long i=0; i<iterationsBeforeCooling; i++){
            counter++;
            state = tryState(state);

            progress.add(state.getWorth());
            if(state.better(best))
                best = state;

        }

        cool();
    }

    return Solution(best, problem);
}

bool SASolver::frozen() const {

    unsigned long progressLength = progress.getLength();
    unsigned long length = max( (unsigned long)((double)progressLength * frozenSize), iterationsBeforeCooling);

    if(progress.lastNDiff(length) <= frozenDiff){
        return true;
    }

    return false;
}

State SASolver::tryState(const State& state) {
    int index = intDist(gen);
    State n_state(state);
    n_state.swap(index);
    if(n_state.better(state))
        return n_state;

    double diff = n_state.howMuchWorse(state)*100;

    if( realDist(gen) < exp(- ( diff/temperature ) ) )
        return n_state;

    return state;
}

void SASolver::cool() {
    temperature = coolingCoefficient * temperature;
}

SASolver::SASolver(int startingTemperature, double coolingCoeff, double innerCycleMultiplier, double frozenLength, double frozenDifference):
    startTemperature(startingTemperature),
    iterationsBeforeCoolingMultiplier(innerCycleMultiplier),
    frozenSize(frozenLength),
    frozenDiff(frozenDifference),
    coolingCoefficient(coolingCoeff){

    gen =  mt19937(rd());
    realDist= uniform_real_distribution<>(0,1);
}
