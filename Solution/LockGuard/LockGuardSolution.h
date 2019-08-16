//
// Created by Kemmerzell Michael on 16.08.2019.
//

#ifndef UNTITLED_LOCKGUARDSOLUTION_H
#define UNTITLED_LOCKGUARDSOLUTION_H

#include <mutex>

#include "../../Issue/RacingCondition.h"

/**
 * LockGuardSolution increments a counter using 5 threads.
 *
 * Racing Conditions are voided by the use of a lock_guard.
 * A lock_guard uses a mutex. The lock_guard prevents a specific scope
 * of code to be executed concurrently which leads to a synchronization of the code.
 */
class LockGuardSolution : public RacingCondition
{
public:

    /**
     * Constructor of the class.
     */
    LockGuardSolution();

private:

    /**
     * Mutex that is used to synchronize the threads in the incrementCounter-method.
     */
    std::mutex mutex;

    // Override methods of base class
    void incrementCounter(const int amount) final;
};

#endif //UNTITLED_LOCKGUARDSOLUTION_H
