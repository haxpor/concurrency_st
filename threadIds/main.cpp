#ifdef _MSC_VER
#include <windows.h>
#elif __linux__
#include <pthread.h>
#endif

#include <iostream>
#include <thread>
#include <atomic>
#include <array>

static std::atomic_flag sPrintLock = ATOMIC_FLAG_INIT;

void threadFunc()
{
#ifdef _MSC_VER
    // there is __readfsdword but only for x86
    // ref: https://docs.microsoft.com/en-us/cpp/intrinsics/readfsbyte-readfsdword-readfsqword-readfsword?view=vs-2019
    // but result in not found external symbol compiling on AMD cpu even with MSVC x86 compiler
    DWORD threadId = GetCurrentThreadId();
#elif __linux__
    pthread_t threadId = pthread_self();
#endif

    while (sPrintLock.test_and_set(std::memory_order_relaxed)) {}
    std::cout << "Current threadId: " << threadId << std::endl;
    sPrintLock.clear();
}

int main()
{
    constexpr const int kThreadCount = 5;
    std::array<std::thread, kThreadCount> threads;

    for (int i=0; i<kThreadCount; ++i)
    {
        threads[i] = std::thread(threadFunc);
    }

    for (int i=0; i<kThreadCount; ++i)
    {
        threads[i].join();
    }

    return 0;
}

