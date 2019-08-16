//
// Created by Michi on 16.08.2019.
//

#include "../LockGuard/LockGuardSolution.h"

LockGuardSolution::LockGuardSolution()
{
}

void LockGuardSolution::incrementCounter(const int amount)
{
    /*
     * The lock is hold for the scope of the method and is released automatically if the scope ends.
     * The lock_guard itself is only a wrapper for the mutex.
     */
    std::lock_guard<std::mutex> lock(mutex);

    for (int i = 0; i < amount; i++)
    {
        counter++;
    }
}
