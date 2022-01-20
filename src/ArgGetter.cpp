//
// Created by pavel on 29.10.21.
//

#include "headers/ArgGetter.h"

#include <cstring>
#include <sstream>

using namespace std;

const char *ArgGetter::getSourcePath(int argc, char **argv) {
    for(int i=0; i<argc; i++) {
        if (strcmp(argv[i], "--source") == 0) {
            if (i + 1 >= argc) {
                throw invalid_argument("value of file not specified");
            }
            return argv[i + 1];
        }
    }

    throw invalid_argument("--source not found");
}

int ArgGetter::getThreadCount(int argc, char **argv) {
    stringstream strstr;

    for(int i=0; i<argc; i++) {
        if (strcmp(argv[i], "--threads") == 0) {
            if (i + 1 >= argc) {
                throw invalid_argument("value of threads count not specified");
            }

            strstr << argv[i + 1];
            int res;
            strstr>>res;
            return res;
        }
    }

    return 1;
}

int ArgGetter::getStartingTemperature(int argc, char **argv) {
    stringstream strstr;

    for(int i=0; i<argc; i++) {
        if (strcmp(argv[i], "--temperature") == 0) {
            if (i + 1 >= argc) {
                throw invalid_argument("value of temperature not specified");
            }

            strstr << argv[i + 1];
            int res;
            strstr>>res;
            return res;
        }
    }

    throw invalid_argument("temperature not specified");
}

double ArgGetter::getFrozenSize(int argc, char **argv) {
    stringstream strstr;

    for(int i=0; i<argc; i++) {
        if (strcmp(argv[i], "--frozenSize") == 0) {
            if (i + 1 >= argc) {
                throw invalid_argument("value of frozen size not specified");
            }

            strstr << argv[i + 1];
            double res;
            strstr>>res;
            return res;
        }
    }

    return 1.0/8.0;
}

double ArgGetter::getFrozenDiff(int argc, char **argv) {
    stringstream strstr;

    for(int i=0; i<argc; i++) {
        if (strcmp(argv[i], "--frozenDiff") == 0) {
            if (i + 1 >= argc) {
                throw invalid_argument("value of frozen diff not specified");
            }

            strstr << argv[i + 1];
            double res;
            strstr>>res;
            return res;
        }
    }

    return 0.05;
}

double ArgGetter::getInnerCycleMultiplier(int argc, char **argv) {
    stringstream strstr;

    for(int i=0; i<argc; i++) {
        if (strcmp(argv[i], "--inner") == 0) {
            if (i + 1 >= argc) {
                throw invalid_argument("value of inner cycle not specified");
            }

            strstr << argv[i + 1];
            double res;
            strstr>>res;
            return res;
        }
    }

    throw invalid_argument("inner cycle not specified");
}

double ArgGetter::getCoolingCoefficient(int argc, char **argv) {
    stringstream strstr;

    for(int i=0; i<argc; i++) {
        if (strcmp(argv[i], "--cooling") == 0) {
            if (i + 1 >= argc) {
                throw invalid_argument("value of cooling coefficient not specified");
            }

            strstr << argv[i + 1];
            double res;
            strstr>>res;
            return res;
        }
    }

    throw invalid_argument("cooling coefficient not specified");
}

bool ArgGetter::getPrintProgress(int argc, char **argv){
    for(int i=0; i<argc; i++) {
        if (strcmp(argv[i], "--printProgress") == 0) {
            if (i + 1 >= argc) {
                throw invalid_argument("value of print progress not specified");
            }

            if(strcmp(argv[i + 1], "true") == 0){
                return true;
            }
            else if(strcmp(argv[i + 1], "false") == 0){
                return false;
            }
            throw invalid_argument("unknown value of print progress");
        }
    }

    return false;
}