/**
 * Example of a threads that waste CPU cycles
 */
#include <thread>
#include <chrono>
#include <process.h>
#include <iostream>

 // Simple function that wastes CPU cycles non-stop
void waster() {
	std::cout << "Waster Process ID (parent process): " << _getpid() << std::endl;
	std::cout << "Waster Thread ID: " << std::this_thread::get_id() << std::endl;
	while (true)
	{
		continue;
	}
}

int main()
{
	std::cout << "Main Process ID: " << _getpid() << std::endl;
	std::cout << "Main Thread ID: " << std::this_thread::get_id() << std::endl;
	std::thread child1(waster);
	std::thread child2(waster);

	while (true)
	{
		// keep the main thread alive "forever"
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}