#include <thread>
#include <iostream>

int main()
{
	// for 6 cores, 12 threads processor, this will return as 12
	std::cout << "Number of concurrent threads supported: " << std::thread::hardware_concurrency() << std::endl;
	return 0;
}
