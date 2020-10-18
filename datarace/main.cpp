// More info: https://www.devx.com/cplus/Article/42725/0/page/2
// Non-atomic increments performed by all threads interfere with each others.
#include <thread>
#include <iostream>
#include <array>

const unsigned int kIncrement = 2000000; 
const int kNumThread = 2;
unsigned int a;

void increment()
{
    for (int i=0; i<kIncrement; ++i)
    {
        ++a;    // increment is not atomic instruction
                // if compile with optimization level (something like -O2 for GCC)
                // you might not be able to see assembly code output for this increment operation.
                // Try remove optimization level, and we will see that this operation is not atomic.
    }
}

int main()
{
    std::array<std::thread, kNumThread> threads;
    for (int i=0; i<kNumThread; ++i)
    {
        threads[i] = std::thread(increment);
    }
    for (int i=0; i<kNumThread; ++i)
    {
        threads[i].join();
    }

    std::cout << "thread count: " << kNumThread << ", Final a: " << a << ", Increment total: " <<
        (kIncrement * 2) << std::endl;
    return 0;
}
