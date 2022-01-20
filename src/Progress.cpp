//
// Created by pavel on 09.12.21.
//

#include "headers/Progress.h"

unsigned long Progress::getLength() const{
    return arr.size();
}

void Progress::add(double value) {
    arr.push_back(value);
}

string Progress::toString() const {
    string s;

    for(double value : arr){
        s.append(to_string(value)+"\n");
    }

    return s;
}

void Progress::clear() {
    arr.clear();
}

double Progress::lastNDiff(unsigned long n) const{

    if(arr.empty())
        return 0;

    double min = arr[arr.size()-1];
    double max = arr[arr.size()-1];
    double sum = 0;
    double mean = 0;

    for(long int i = (long int)arr.size()-1; i>=0 && i>= (long int)(arr.size()-n); i--){
        sum+=arr[i];

        if(arr[i]>max)
            max = arr[i];

        if(arr[i]<min)
            min=arr[i];
    }

    mean = sum / (double)n;

    if(mean == 0)
        return abs(max-min);

    return abs(max-min)/(abs(mean));
}
