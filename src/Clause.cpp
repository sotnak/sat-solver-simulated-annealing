//
// Created by pavel on 19.01.22.
//

#include "headers/Clause.h"
#include <iostream>

using namespace std;

Clause::Clause(int *literals, int length): length(length) {
    this->literals = new int[length];

    for(int i=0; i<length; i++){
        this->literals[i] = literals[i];
    }
}

string Clause::toString() {

    string str;

    for(int i=0; i<length; i++){
        str+= to_string(literals[i]) + " ";
    }

    return str;
}

bool Clause::isTrue(bool* arr) {
    bool literalInState;

    for(int i=0; i<length; i++){
        literalInState = arr[ abs(literals[i]) - 1 ];

        if(literalInState && literals[i]>0) {
            return true;
        }

        if(!literalInState && literals[i]<0) {
            return true;
        }
    }

    return false;
}

Clause::~Clause() {
    delete[] literals;
}

Clause::Clause(const Clause &other) {

    literals = new int[other.length];
    length = other.length;

    for(int i = 0; i < length; i++){
        literals[i]=other.literals[i];
    }
}

Clause &Clause::operator=(const Clause &other) {
    if(this ==&other){
        return *this;
    }

    if(length != other.length){
        delete[] literals;

        if(other.length == 0){
            literals = nullptr;
        }
        else{
            literals = new int[other.length];
        }
        length = other.length;
    }

    for(int i = 0; i < length; i++){
        literals[i]=other.literals[i];
    }

    return *this;
}

Clause::Clause() = default;
