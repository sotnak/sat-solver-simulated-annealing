//
// Created by antos on 24.09.2021.
//

#ifndef HW2_SOLUTION_H
#define HW2_SOLUTION_H

#include <vector>
#include <string>

#include "Problem.h"
#include "State.h"

using namespace std;

class Solution {
public:
    State configuration;
    Problem problem;

    Solution(State config, const Problem& problem);

    Solution();
    Solution(const Solution& other);

    string toString() const;
};


#endif //HW2_SOLUTION_H
