//
// Created by pavel on 19.01.22.
//

#ifndef KOP_HW5_PROBLEMFACTORY_H
#define KOP_HW5_PROBLEMFACTORY_H

#include <fstream>
#include <vector>

#include "Problem.h"

class ProblemFactory {

    static vector<string> splitString(const string &str, char delimiter);

public:
    static Problem create(ifstream* input);
};


#endif //KOP_HW5_PROBLEMFACTORY_H
