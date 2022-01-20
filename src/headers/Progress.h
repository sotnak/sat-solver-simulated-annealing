//
// Created by pavel on 09.12.21.
//

#ifndef HW4_PROGRESS_H
#define HW4_PROGRESS_H

#include <vector>
#include<string>
using namespace std;


class Progress {
    vector<double> arr;
public:
    void add(double value);
    void clear();
    [[nodiscard]] double lastNDiff(unsigned long n) const;
    [[nodiscard]] string toString() const;
    [[nodiscard]] unsigned long getLength() const;
};


#endif //HW4_PROGRESS_H
