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

#include <string>

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
    virtual void execute(const std::string& preMessage);

private:

    /**
     * Simple increment method. Increments the static variable of this class amount-times.
     *
     * @param amount The amount of increments
     */
    virtual void incrementCounter(const int amount);

    /**
     * Getter for the counter of the class.
     *
     * @return The current counter in a specific state.
     */
    virtual int getCounter();

    /**
     * Executes the scenario mentioned in the class description.
     * Create 5 Thread and call inc() with 1000 increments each.
     *
     * @return
     */
    int startIncMultithreaded();

    /**
     * Reset the counter to its initial value so it can be used
     * for a fresh try.
     */
    virtual void resetCounter();

    /**
     * Prints a message to the console for the current test case.
     */
    void printPreExecutionMessage(const std::string& message);

    static constexpr int amountOfIterations = 10000;   /* Tries to provoke a racing condition */
    static constexpr int expectedValueForCounter = 5000; /* The expected outcome for our counter after the execution */

protected:
    /**
     * The counter of this class, multiple threads are working on it.
     */
    int counter = 0;

};

#endif //UNTITLED_RACINGCONDITION_H
