//
// Created by antos on 24.09.2021.
//

#include "headers/Problem.h"
#include <iostream>
using namespace std;

Problem::Problem(int literalCount, int clauseCount)
        :literalCount(literalCount), clauseCount(clauseCount){
    this->weights = new int[literalCount];
    this->clauses = new Clause[clauseCount];
}

Problem::Problem() = default;

Problem::Problem(int literalCount, int clauseCount, const int* weights, const Clause* clauses)
        :Problem(literalCount, clauseCount){

    //this->weights = new int[literalCount];
    for(int i=0; i<literalCount; i++){
        this->weights[i] = weights[i];
    }

    for(int i=0; i<clauseCount; i++){
        this->clauses[i] = clauses[i];
    }

    evaluateMaxWeight();
}

string Problem::toString() const {
    string weightString;

    for(int i=0; i<literalCount; i++){
        weightString += "\t" + to_string(weights[i]) + " ";
    }

    string clauseString;

    for(int i=0; i<clauseCount; i++){
        clauseString += "\t" + clauses[i].toString() + "\n";
    }

    return "literalCount: " + to_string(literalCount) +
           "\nweights:\n" + weightString +
           "\nmaxWeight: " + to_string(maxWeight) +
            "\nclauseCount: " + to_string(clauseCount) +
            "\nclauses:\n" + clauseString;
}

Problem &Problem::operator=(const Problem &other) {
    if(this ==&other){
        return *this;
    }

    if(literalCount != other.literalCount){
        delete[] weights;

        if(other.literalCount == 0){
            weights = nullptr;
        }
        else{
            weights = new int[other.literalCount];
        }
        literalCount = other.literalCount;
    }

    for(int i = 0; i < literalCount; i++){
        weights[i]=other.weights[i];
    }

    if(clauseCount != other.clauseCount){
        delete[] clauses;

        if(other.clauseCount == 0){
            clauses = nullptr;
        }
        else{
            clauses = new Clause[other.clauseCount];
        }
        clauseCount = other.clauseCount;
    }

    for(int i = 0; i < clauseCount; i++){
        clauses[i]=other.clauses[i];
    }

    evaluateMaxWeight();

    return *this;
}

Problem::~Problem() {
    delete[] weights;
    delete[] clauses;
}

Problem::Problem(const Problem &other):
    literalCount(other.literalCount), clauseCount(other.clauseCount){

    weights = new int[literalCount];

    for(int i=0; i<literalCount; i++){
        weights[i] = other.weights[i];
    }

    clauses = new Clause[clauseCount];

    for(int i=0; i<clauseCount; i++){
        clauses[i] = other.clauses[i];
    }

    evaluateMaxWeight();
}

void Problem::evaluateMaxWeight() {
    maxWeight=0;
    for(int i=0; i<literalCount; i++){
        maxWeight+=weights[i];
    }
}


int Problem::numOfTrueClauses(bool* arr) const {
    int res = 0;

    for(int i=0; i<clauseCount; i++){
        if(clauses[i].isTrue(arr)) {
            res++;
        }
    }

    return res;
}
