//
// Created by pavel on 19.01.22.
//

#include <sstream>
#include <iostream>
#include "headers/ProblemFactory.h"

vector<string> ProblemFactory::splitString(const string& str, char delimiter = ' '){
    stringstream strS(str);
    vector<string> res;
    string tmp;

    while(getline(strS, tmp, delimiter))
        if(!tmp.empty())
            res.push_back(tmp);
    return res;
}

Problem ProblemFactory::create(ifstream* input) {

    string tmp;
    vector<string> line;

    int literalCount = 0;
    int clauseCount = 0;

    bool isReadingClauses=false;
    int clausesIndex = 0;
    int* clauseTmp;

    int* weights;
    Clause* clauses;

    while(getline( *input, tmp)){
        line = splitString(tmp);

        if(isReadingClauses){
            clauseTmp = new int[3];
            clauseTmp[0] = stoi(line[0]);
            clauseTmp[1] = stoi(line[1]);
            clauseTmp[2] = stoi(line[2]);

            clauses[clausesIndex]= Clause(clauseTmp);
            delete[] clauseTmp;
            clausesIndex++;
        }

        else if(line[0]=="p"){
            literalCount = stoi(line[2]);
            clauseCount = stoi(line[3])-1;

            weights = new int[literalCount];
            clauses = new Clause[clauseCount];
        }

        else if(line[0]=="w"){
            for(long unsigned int i=1; i<line.size(); i++){
                if(stoi(line[i])==0){
                    break;
                }

                weights[i-1] = stoi(line[i]);
            }
        }

        else if(line[0]=="c" && line.size()>4 && line[1]=="weight" && line[2]=="generation" && line[3]=="strategy")
            isReadingClauses = true;
        else if(line[0]=="c" && line.size()>3 && line[1]=="range")
            isReadingClauses = true;

    }

    /*
    cout<<"weights: ";
    for(int i=0; i<literalCount; i++){
        cout<<weights[i]<<" ";
    }
    cout<<endl;
    cout<<"clauses: "<< clauseCount<<endl;
    cout<<"literals: "<<literalCount<<endl;

    for(int i=0; i<clauseCount; i++){
        cout<<clauses[i].toString()<<endl;
    }
    */

    Problem p(literalCount,clauseCount, weights, clauses);

    delete[] weights;
    delete[] clauses;

    return p;
}
