/**
 * Two child threads doing some work for about one second, to demonstrate execution scheduling.

 */
#include <thread>
#include <chrono>
#include <iostream>

 /* Main thread uses this variable to indicate if it is working */
bool working = true;

/*
* Input: name of which can be used to uniquely identify this thread
*/
void doSomething(const char* name)
{
	// Local variable to count the number of turns
	unsigned int turns = 0;

	// The number of turns increases while the global status is working
	while (working)
	{
		turns++;
	}

	// At the end of the execution, thread prints the number of turns
	std::cout << "Number of turns for thread " << name << ": " << turns << std::endl;
}

int main()
{
	// Here, two threads are created and started, one after the other.
	// They won't begin at the exact same time, but they'll begin close enough together.
	std::thread thread1(doSomething, "Thread 1");
	std::thread thread2(doSomething, "Thread 2");

	std::cout << "Both threads started: " << std::endl;

	// Main thread sleeps for a second
	std::this_thread::sleep_for(std::chrono::seconds(1));

	// Set "working" state to false, to stop the while loop in both threads
	working = false;

	// Wait for both threads to finish
	thread1.join();
	thread2.join();

	/* Even though these two threads started and stopped at roughly the same time, they got very different number of
	turns. Scheduling is not always fair.
	*/

	/*If the program is run again, threads will end with different amounts than before. Scheduling is not consistent from run to run, so your programs should not rely on execution scheduling for correctness.
	*/
}