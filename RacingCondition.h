#ifndef UNTITLED_RACINGCONDITION_H
#define UNTITLED_RACINGCONDITION_H

/**
 * Description of the example.
 *
 * 5 Threads are working unsynchronized on a static int variable.
 * Each thread shall increment the variable 1000 times.
 *
 * What should we expect?
 * Racing conditions may appear because the threads are not synchronized nor using a mutex.
 */

class RacingCondition
{
public:
    /**
     * Default constructor.
     */
    RacingCondition();

    /**
     * Creates a racing condition.
     */
    void execute();

private:
    /**
     * The counter of this class, multiple threads are working on it.
     */
    int counter = 0;

    /**
     * Simple increment method. Increments the static variable of this class amount-times.
     *
     * @param amount The amount of increments
     */
    void incrementCounter(int amount);

    /**
     * Executes the scenario mentioned in the class description.
     * Create 5 Thread and call inc() with 1000 increments each.
     *
     * @return
     */
    int startIncMultithreaded();

};

#endif //UNTITLED_RACINGCONDITION_H
