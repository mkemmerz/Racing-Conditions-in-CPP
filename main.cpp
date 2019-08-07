#include "Issue/RacingCondition.h"
#include "Solution/AtomicCounter/AtomicSolution.h"

int main()
{
    auto racingCondition = RacingCondition{};
    racingCondition.execute({"Starting execution of RacingCondition"});

    AtomicSolution atomicSolution;
    atomicSolution.execute({"Starting execution of AtomicSolution"});

    return 0;
}

