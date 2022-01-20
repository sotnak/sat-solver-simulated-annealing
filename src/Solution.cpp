//
// Created by antos on 24.09.2021.
//

#include "headers/Solution.h"

Solution::Solution(State config, const Problem& problem)
    :configuration(config), problem(problem) {}

string Solution::toString() const {

    return to_string(configuration.getWeight()) + " " +
    configuration.toString() + " 0";
}

Solution::Solution(const Solution &other): configuration(other.configuration), problem(other.problem) {

}

Solution::Solution() = default;