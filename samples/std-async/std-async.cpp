#if 0
#include <future>
#include <iostream>

void printThreadId() {
    std::cout << "Current thread id: " << std::this_thread::get_id() << "\n";
}

int main()
{
    // Print main thread id
    std::cout << "Main thread id: ";
    printThreadId();
    
    // Launch printThreadId on a different thread
    std::async(&printThreadId);
    std::cout << "After async dispatch.\n";
    
    return 0;
}

#endif

#if 0
#include <future>
#include <iostream>

void printThreadId() {
	std::cout << "Current thread id: " << std::this_thread::get_id() << "\n";
}

int main()
{
    // Print main thread id
    std::cout << "Main thread id: ";
    printThreadId();
    
    // Save std::async return value
    auto future = std::async(&printThreadId);
    std::cout << "After async dispatch.\n";
    future.wait();
    std::cout << "After future.wait\n";
    
    return 0;
}
#endif

#if 1
#include <future>
#include <iostream>
#include <chrono>

using namespace std::literals;

auto ms = 1ms;
auto second = 1s;
auto minute = 1min;
auto hour = 1h;
auto waittime = 1s + 500ms + 1ns;

// Sleep-helper
template<typename REP, typename DUR>
void wait(std::chrono::duration<REP, DUR> & dur) {
    std::this_thread::sleep_for(dur);
}

// Print threadId
void printThreadId() {
    std::cout << "Current thread id: " << std::this_thread::get_id() << "\n";
}

void printThreadIdWait() {
    wait(500ms);
    std::cout << "Wait thread id: " << std::this_thread::get_id() << "\n";
}

int main()
{
    // Print main thread id
    std::cout << "Main thread id: ";
    printThreadId();
    
    // Save std::async return value
    auto future = std::async(&printThreadIdWait);
    wait(1000ms);
    std::cout << "After async dispatch.\n";
    future.wait();
    std::cout << "After future.wait\n";
    
    return 0;
}
#endif 
 
#if 0
#include <thread>
#include <future>
#include <iostream>
#include <mutex>
#include <map>

#include "ex1.hpp"

std::mutex mut;
std::map<std::thread::id, uint32_t> threadIds;

void doWork()
{
	std::lock_guard<std::mutex> locker(mut);
	threadIds[std::this_thread::get_id()]++;
	std::cout << "Current thread id: " << std::this_thread::get_id() << "\n";
}


int main()
{
	std::cout << "Main thread id: " << std::this_thread::get_id() << "\n";

	using promise_t = decltype(std::async(&doWork));

	std::vector<promise_t> waits;

	for (size_t i = 0; i < 100; i++)
	{
		waits.emplace_back(std::async(std::launch::deferred, &doWork));
	}

	std::for_each(waits.begin(), waits.end(), [&](promise_t & p) {p.get(); });

	return 0;
}
#endif 0