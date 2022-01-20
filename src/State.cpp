//
// Created by pavel on 19.01.22.
//

#include "headers/State.h"

void State::evaluate() {

    weight = 0;

    int numOfTrueClauses = problem.numOfTrueClauses(arr);

    for (int i = 0; i < problem.literalCount; i++) {
        if (arr[i])
            weight += problem.weights[i];
    }

    if (weight != 0) {
        value = (2*numOfTrueClauses + ((double) weight / (2*problem.maxWeight) )) / problem.clauseCount;
    }else{
        value = (double)numOfTrueClauses / problem.clauseCount;
    }
}

void State::swap(int n) {
    arr[n] = !arr[n];

    evaluate();
}

State::State(const Problem &problem): problem(problem) {
    arr = new bool[problem.literalCount];
    for(int i=0; i<problem.literalCount; i++){
        arr[i]=false;
    }

    evaluate();
}

bool State::at(int n) const{
    if(problem.literalCount<=n)
        return false;

    return arr[n];
}

double State::getWorth() const {
    return value;
}

bool State::better(const State& state) const {
    return state.value<value;
}

double State::howMuchWorse(const State &state) const{
    return state.value-value;
}

State::State() = default;

State &State::operator=(const State &other) {
    if(this ==&other){
        return *this;
    }

    if(problem.literalCount != other.problem.literalCount){
        delete[] arr;

        if(other.problem.literalCount == 0){
            arr = nullptr;
        }
        else{
            arr = new bool[other.problem.literalCount];
        }
    }

    weight = other.weight;
    value = other.value;
    problem = other.problem;

    for(int i = 0; i < problem.literalCount; i++){
        arr[i]=other.arr[i];
    }

    evaluate();

    return *this;
}

State::State(const State &other) {
    weight = other.weight;
    value = other.value;
    problem = other.problem;
    arr = new bool[other.problem.literalCount];

    for(int i = 0; i < problem.literalCount; i++){
        arr[i]=other.arr[i];
    }

    evaluate();
}

string State::toString() const {
    string res;

    for(int i=0; i<problem.literalCount; i++){
        res += (arr[i]? to_string(i+1) : to_string(-i-1)) + " ";
    }

    return res;
}

State::~State() {
    delete[] arr;
}

int State::getWeight() const {
    return weight;
}
