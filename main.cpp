#include "Issue/RacingCondition.h"
#include "Solution/AtomicCounter/AtomicSolution.h"
#include "Solution/Mutex/MutexSolution.h"

int main()
{
    auto racingCondition = RacingCondition{};
    racingCondition.execute({"Starting execution of RacingCondition"});

    AtomicSolution atomicSolution;
    atomicSolution.execute({"Starting execution of AtomicSolution"});

    MutexSolution mutexSolution;
    mutexSolution.execute("Starting execution of MutexSolution.");

    return 0;
}

