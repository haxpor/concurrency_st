/**
 * Demonstrate transfering of thread ownership.
 */
#include <thread>
#include <cstdio>
#include <utility>

void threadFunc1(int i)
{
	std::printf("called threadFunc1(%d)\n", i);
}

void threadFunc2(float f)
{
	std::printf("called threadFunc2(%.2f)\n", f);
}

int main()
{
	using namespace std::chrono_literals;
	std::thread t1(threadFunc1, 1);

	// just to make it explicit that t1 (or thread associated with threadFunc1 function) has already started although even without sleeping
	std::this_thread::sleep_for(2s);

	std::thread t2(threadFunc2, 5.0f);
	std::thread t3;

	// associated thread of execution of t1 has been transfered to t3 (but t1 has already started)
	t3 = std::move(t1);
	t1 = std::thread(threadFunc2, 10.0f);

	t1.join();
	t2.join();
	t3.join();

	// you should see 3 printing outputs

	return 0;
}
