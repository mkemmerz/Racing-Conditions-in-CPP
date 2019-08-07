//
// Created by Michi on 07.08.2019.
//
#include "AtomicSolution.h"

AtomicSolution::AtomicSolution()
{
    m_counter = 0;
}

void AtomicSolution::incrementCounter(int amount)
{
    for (int i = 0; i < amount; i++)
    {
        m_counter++;
    }
}

int AtomicSolution::getCounter()
{
    return m_counter;
}

void AtomicSolution::resetCounter()
{
    m_counter = 0;
}
