//
// Created by Kemmerzell Michael on 07.08.2019.
//
#ifndef UNTITLED_ATOMICSOLUTION_H
#define UNTITLED_ATOMICSOLUTION_H

#include <atomic>

#include "../../Issue/RacingCondition.h"

/**
 * AtomicSolution increases an counter using 5 threads in concurrency.
 *
 * A solution to encounter racing conditions is to use std::atomic.
 * Std::atomic promises that it can handle multiple actions on it correctly.
 */
class AtomicSolution : public RacingCondition
{

public:
    /**
     * Constructor of the class.
     * Prepares the counter so it is ready to use.
     */
    AtomicSolution();

private:
    /**
     * The counter of the class. Initialized with zero.
     * std::atomic prevents racing conditions to appear.
     */
    std::atomic<int> m_counter;

    // Override methods of base class
    void incrementCounter(const int amount) final;
    int getCounter() final;
    void resetCounter() final;
};


#endif //UNTITLED_ATOMICSOLUTION_H
