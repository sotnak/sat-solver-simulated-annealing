cmake_minimum_required(VERSION 3.21)
project(kop_hw5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -Wall -pedantic")

add_executable(kop_hw5 src/main.cpp src/Problem.cpp src/headers/Problem.h src/Solution.cpp src/headers/Solution.h src/solvers/headers/ASolver.h src/solvers/Asolver.cpp src/ArgGetter.cpp src/headers/ArgGetter.h src/solvers/SASolver.cpp src/solvers/headers/SASolver.h src/Progress.cpp src/headers/Progress.h src/Clause.cpp src/headers/Clause.h src/ProblemFactory.cpp src/headers/ProblemFactory.h src/State.cpp src/headers/State.h)
