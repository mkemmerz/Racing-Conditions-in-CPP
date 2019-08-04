//
// Created by Kemmerzell Michael on 04.08.2019.
//

#include <iostream>
#include <thread>
#include <vector>

#include "RacingCondition.h"

RacingCondition::RacingCondition()
{
}

void RacingCondition::incrementCounter(int amount)
{
    for (int i = 0; i < amount; i++)
    {
        counter++;
    }
}

int RacingCondition::startIncMultithreaded()
{
    std::vector<std::thread> threads;

    // Create and start our threads
    for(int i = 0; i < 5; ++i)
    {
        threads.push_back(std::thread(&RacingCondition::incrementCounter, this, 1000));
    }

    // Join all threads so we dont crash anything
    for(int i = 0; i < threads.size() ; i++)
    {
        threads.at(i).join();
    }

    return counter;
}

void RacingCondition::execute()
{
    /**
     * Racing conditions are often luck / back to reproduce so we execute our example multiple times
     * so we can be sure that our racing condition appears at least once.
     */
    for (int k = 0; k < 10000; k++)
    {
        const auto val = startIncMultithreaded();
        if (val != 5000)
        {
            std::cout << "Racing condition appeared, value only " << std::to_string(val) << std::endl;
            return;
        }

        counter = 0; /* The next iteration needs a fresh start */
    }

    std::cout << "No Racing Condition appeared. Well done - or was it simply luck?" << std::endl;
}
