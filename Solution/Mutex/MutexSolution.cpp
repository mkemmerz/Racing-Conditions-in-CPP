//
// Created by Michi on 11.08.2019.
//

#include "MutexSolution.h"

MutexSolution::MutexSolution()
{
}

void MutexSolution::incrementCounter(const int amount)
{
    for (int i = 0; i < amount; i++)
    {
        /**
         * The mutex signalizes a thread that it can't execute the incrementation if another thread is holding
         * the mutex which leads to a synchronization.
         */
        incMutex.lock();
        counter++;
        incMutex.unlock();
    }
}
