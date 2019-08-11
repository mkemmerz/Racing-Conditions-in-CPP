# cmake_minimum_required(VERSION <specify CMake version here>)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp Issue/RacingCondition.cpp Issue/RacingCondition.h Solution/AtomicCounter/AtomicSolution.h Solution/AtomicCounter/AtomicSolution.cpp Solution/Mutex/MutexSolution.h Solution/Mutex/MutexSolution.cpp)