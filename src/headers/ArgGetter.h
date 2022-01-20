//
// Created by pavel on 29.10.21.
//

#ifndef HW2_ARGGETTER_H
#define HW2_ARGGETTER_H


class ArgGetter {
public:
    static const char* getSourcePath(int argc, char *argv[]);
    static int getThreadCount(int argc, char *argv[]);
    static int getStartingTemperature(int argc, char **argv);
    static double getInnerCycleMultiplier(int argc, char **argv);
    static double getCoolingCoefficient(int argc, char **argv);
    static double getFrozenDiff(int argc, char **argv);
    static double getFrozenSize(int argc, char **argv);

    static bool getPrintProgress(int argc, char **argv);
};


#endif //HW2_ARGGETTER_H
