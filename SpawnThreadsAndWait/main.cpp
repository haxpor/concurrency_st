#include <thread>
#include <atomic>
#include <vector>
#include <iostream>

static std::atomic<int> s_value {0};

void doWork(int i)
{
	// atomicially add value to the atomic value
	s_value += i;
}

int main()
{
	std::vector<std::thread> threads;

	for (int i=0; i<20; ++i)
	{
		threads.push_back(std::thread(doWork, i));
	}

	// defer calling join() at this new loop becase we don't want to wait for each thread to finish
	// until we spawn a new thread. We want to spawn all threads, then wait them all at once.
	for (auto& t : threads)
	{
		t.join();
	}

	std::cout << "Result: " << s_value << std::endl;

	return 0;
}
