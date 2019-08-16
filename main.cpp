#include "Issue/RacingCondition.h"
#include "Solution/AtomicCounter/AtomicSolution.h"
#include "Solution/Mutex/MutexSolution.h"
#include "Solution/LockGuard/LockGuardSolution.h"

int main()
{
    RacingCondition racingCondition;
    racingCondition.execute({"Starting execution of RacingCondition"});

    AtomicSolution atomicSolution;
    atomicSolution.execute({"Starting execution of AtomicSolution"});

    MutexSolution mutexSolution;
    mutexSolution.execute({"Starting execution of MutexSolution."});

    LockGuardSolution lockGuardSolution;
    lockGuardSolution.execute({"Starting execution of LockGuardSolution."});

    return 0;
}

