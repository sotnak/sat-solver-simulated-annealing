#include <iostream>
#include <chrono>
#include <filesystem>
#include <vector>


#include "headers/Problem.h"
#include "solvers/headers/ASolver.h"
#include "headers/ArgGetter.h"
#include "headers/ProblemFactory.h"

using namespace std;
namespace fs = std::filesystem;

chrono::steady_clock::time_point getTimePoint(){
    return chrono::steady_clock::now();
}

chrono::duration<double> getDuration(chrono::steady_clock::time_point t1, chrono::steady_clock::time_point t2){
    return chrono::duration_cast<chrono::duration<double>>(t2 - t1);
}

ifstream getInput(const char* path){
    ifstream sourceFile;
    sourceFile.open(path);
    if(!sourceFile.is_open()){
        throw invalid_argument("file not found");
    }

    return sourceFile;
}

ofstream getOutput(const char* path, const char* solverName){
    const string sPath = string(path);
    const string outPath = "OUT/" + string(solverName) + "/" + sPath.substr(sPath.find('/'));
    const string folders = outPath.substr(0,outPath.find_last_of('/'));

    if(!fs::is_directory(folders))
        fs::create_directories(folders);

    ofstream output;
    output.open(outPath);
    if(output.fail())
        throw exception();
    return output;
}

ofstream getProgressOutput(const char* path, const char* solverName, int problemId){
    const string sPath = string(path);
    const string outPath = "PROGRESS/" + string(solverName) + "/" + sPath.substr(sPath.find('/')) + "/problem" + to_string(problemId) + ".dat";
    const string folders = outPath.substr(0,outPath.find_last_of('/'));

    if(!fs::is_directory(folders))
        fs::create_directories(folders);

    ofstream output;
    output.open(outPath);
    if(output.fail())
        throw exception();
    return output;
}

struct ThreadArgs{
    const char* path;
    ifstream* input;
    ofstream* output;
    int startingTemperature;
    double coolingCoefficient;
    double innerCycleMultiplier;
    double frozenSize;
    double frozenDiff;
    bool printProgress;
    int threadId;

    ThreadArgs(const char* path, ifstream* input, ofstream* output, int startingTemperature, double coolingCoefficient, double frozenSize, double frozenDiff,
               double innerCycleMultiplier, bool printProgress)
            :path(path), input(input), output(output), startingTemperature(startingTemperature), coolingCoefficient(coolingCoefficient),
            innerCycleMultiplier(innerCycleMultiplier), frozenSize(frozenSize), frozenDiff(frozenDiff), printProgress(printProgress), threadId(0){}
};

void threadFun(ThreadArgs ta){
    ASolver* solver = ASolver::SolverFactory(ta.startingTemperature, ta.coolingCoefficient, ta.frozenSize, ta.frozenDiff, ta.innerCycleMultiplier);

    chrono::steady_clock::time_point t1;
    chrono::steady_clock::time_point t2;
    chrono::duration<double> time_span{};

    Problem problem;
    Solution solution;
    ofstream progressOut;

    problem = ProblemFactory::create(ta.input);

    //--------------------------------------
    State s(problem);
    State n_state(s);
    n_state.swap(3);

    cout<<s.getWorth()<<" vs "<<n_state.getWorth()<<endl;

    if(n_state.better(s))
        cout<<"n is better"<<endl;

    double diff = n_state.howMuchWorse(s);

    cout<<"diff: " << diff<<endl;
    //--------------------------------------

    t1 = getTimePoint();

    solution = solver->solve(problem);

    t2 = getTimePoint();
    time_span = getDuration(t1, t2);


    *(ta.output) << solution.toString() << " "
        << solver->getCounter() << " "
        << time_span.count() << endl;

    flush(*(ta.output));

    if(ta.printProgress) {
        progressOut = getProgressOutput(ta.path, "SA", 0);

        progressOut << solver->getProgress();
        progressOut.flush();
        progressOut.close();
    }


    cout<<"solution:" << solution.toString()<<endl;
    cout<<"value: " << solution.configuration.getWorth()<<endl;
    cout<<"operations: " << solver->getCounter() <<endl;
    cout<<"time: " << time_span.count() <<endl;

    solver->resetCounter();

    delete solver;
}

int main(int argc, char *argv[])
{
    int startingTemperature = ArgGetter::getStartingTemperature(argc, argv);
    double coolingCoefficient = ArgGetter::getCoolingCoefficient(argc, argv);
    double innerCycleMultiplier = ArgGetter::getInnerCycleMultiplier(argc, argv);
    double frozenSize = ArgGetter::getFrozenSize(argc, argv);
    double frozenDiff = ArgGetter::getFrozenDiff(argc,argv);
    bool printProgress = ArgGetter::getPrintProgress(argc,argv);

    const char* path = ArgGetter::getSourcePath(argc, argv);

    ifstream input = getInput(path);
    ofstream output = getOutput(path, "SA");

    ThreadArgs threadArgs(path, &input, &output, startingTemperature, coolingCoefficient, frozenSize, frozenDiff, innerCycleMultiplier, printProgress);

    chrono::steady_clock::time_point t1;
    chrono::steady_clock::time_point t2;
    chrono::duration<double> time_span{};

    threadFun(threadArgs);

    input.close();

    output.close();

    return 0;
}
