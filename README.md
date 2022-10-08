# Racing conditions in C++

The project contains multiple solutions about how to fix racing conditions in C++.

## What is a Race Condition?
A race condition is a type of concurrency bug that can happen if multiple threads are working with the same data / objects parallely. Race conditions can lead to wrong calculation due to multiple threads not working fully successivly but rather overwriting calculations of a different thread.

A good example on a race condition is incrementing a counter with multiple threads, this example is also covered in this repository. The incrementation process requires the execution of the following steps:
1. Reading the value from memory
2. Increasing value
3. Writing value to memory

Let's imagine we are using 2 threads and we want to increase a counter two times.

`int i = 0; i++; i++ `

Usually our variable `i` should contain the value 2 after the incrementations.

Now let's have a deeper look on how a race condition can happen:
* Thread 1: Reading value (i = 0)
* Thread 1: Increasing value (i = 1)
* Thread 2: Reading value (i = 0) <-- This is the important part, Thread 1 hasn't written the incremented value to memory yet! The memory still has i = 0 set.
* Thread 1: Writing value (i = 1)
* Thread 2: Writing value (i = 1)
* Result: i = 1

Due to a bad timing our threads only incremented our counter a single time instead of two times. This is called a race condition. Basically a bad timing of threads in this case.

## How to prevent Race Conditions?
The solution to fix this is to enforce multiple threads to work successively instead of parallely. There are many implementation on how to solve this. This repository covers the following 3 solutions:
* atomic variables
* mutex
* locks
