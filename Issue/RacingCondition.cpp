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

void RacingCondition::printPreExecutionMessage(const std::string& message)
{
    std::cout << message << std::endl;
}

void RacingCondition::resetCounter()
{
    counter = 0;
}

int RacingCondition::getCounter()
{
    return counter;
}

void RacingCondition::incrementCounter(const int amount)
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

    return getCounter();
}

void RacingCondition::execute(const std::string& preMessage)
{
    printPreExecutionMessage(preMessage);
    auto amountOfRacingConditions = 0;

    /**
     * Racing conditions are often luck / back to reproduce so we execute our example multiple times
     * so we can be sure that our racing condition appears at least once.
     */
    for (int k = 0; k < amountOfIterations; k++)
    {
        const auto val = startIncMultithreaded();
        if (val != expectedValueForCounter)
        {
            amountOfRacingConditions++;
        }

        resetCounter(); /* The next iteration needs a fresh start */
    }

    if (amountOfRacingConditions == 0)
        std::cout << "No racing condition appeared. Well done - or was it simply luck?" << std::endl;
    else
        std::cout << std::to_string(amountOfRacingConditions) << " racing conditions occurred in "
                  << std::to_string(amountOfIterations) << " iterations." <<std::endl;
}
