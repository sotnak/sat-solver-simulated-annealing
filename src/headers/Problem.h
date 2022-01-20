//
// Created by antos on 24.09.2021.
//

#ifndef HW1_PROBLEM_H
#define HW1_PROBLEM_H

#include <string>
#include <vector>
#include "Clause.h"

using namespace std;


class Problem {
    void evaluateMaxWeight();

public:
    int literalCount{};
    int clauseCount{};
    int maxWeight{};
    int* weights{};
    Clause* clauses{};

    Problem();
    Problem(const Problem& other);
    Problem(int literalCount, int clauseCount);
    Problem(int literalCount, int clauseCount, const int* weights, const Clause* clauses);
    ~Problem();

    Problem& operator=(const Problem& other);

    int numOfTrueClauses(bool* arr) const;
    string toString() const;
};


#endif //HW1_PROBLEM_H
