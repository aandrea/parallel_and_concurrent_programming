/**
* A parent thread and a child thread, for an example of thread life cycle from creation to termination.
Main thread spawns a second thread.

C++ doesn't provide a view into a thread state (blocked or running in the operating system).
It is possible to check if a thread is still considered active, which returns a Boolean whether thread is alive.
 */


#include <thread>
#include <chrono>
#include <iostream>

void childThread()
{
	// Thread waits for three seconds and prints message when finished.
	std::cout << "Child thread will wait for 3 sec." << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "Child thread will finish waiting." << std::endl;
}

int main()
{
	std::cout << "Main thread starts a new child thread." << std::endl;

	// New child thread is created and started right away, depending on OS (default on C++)
	std::thread childThread(childThread);

	// Child is joinable right after start
	std::cout << "  Is child joinable? " << (childThread.joinable() ? "true" : "false") << std::endl;

	// Main thread sleeps for a second
	std::cout << "Main threads waits for 1 sec." << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));

	// Child is even if it is sleeping
	std::cout << "  Is child joinable? " << (childThread.joinable() ? "true" : "false") << std::endl;

	// Main thread will finish work before child but it will wait for child to finish (using join)
	std::cout << "Main thread waits for child thread to finish and join..." << std::endl;
	childThread.join();

	// Finally child has finished its job so it is no longer joinable
	std::cout << "  Is child joinable? " << (childThread.joinable() ? "true" : "false") << std::endl;

	std::cout << "Both threads are both done!" << std::endl;
}