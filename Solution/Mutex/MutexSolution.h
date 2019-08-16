//
// Created by Kemmerzell Michael on 11.08.2019.
//

#ifndef UNTITLED_MUTEXSOLUTION_H
#define UNTITLED_MUTEXSOLUTION_H

#include <mutex>

#include "../../Issue/RacingCondition.h"

/**
 * MutexSolution increments a counter using 5 threads.
 *
 * Racing Conditions are voided by the use of a mutex.
 */
class MutexSolution : public RacingCondition
{

public:
    /**
     * Constructor of the class.
     * Prepares the counter so it is ready to use.
     */
    MutexSolution();

private:

    /**
     * Mutex that is used to synchronize the threads in the incrementCounter-method.
     */
    std::mutex incMutex;

    // Override methods of base class
    void incrementCounter(const int amount) final;
};

#endif //UNTITLED_MUTEXSOLUTION_H
