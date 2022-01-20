//
// Created by pavel on 19.01.22.
//

#ifndef KOP_HW5_CLAUSE_H
#define KOP_HW5_CLAUSE_H

#include <string>

using namespace std;


class Clause {
    int* literals{};
    int length{};
public:

    Clause();
    explicit Clause(int* literals, int length = 3);
    Clause(const Clause& other);
    ~Clause();

    Clause& operator=(const Clause& other);

    string toString();

    bool isTrue(bool* arr);
};


#endif //KOP_HW5_CLAUSE_H
