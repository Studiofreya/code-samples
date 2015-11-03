#include <condition_variable>
#include <iostream>
#include <chrono>
#include <thread>
#include <atomic>

int main()
{
	std::condition_variable cv;
	std::mutex m;
	std::atomic_char32_t jobs = 0;

	auto threadStart = [&](int i)
	{
		std::unique_lock<std::mutex> lck(m);
		std::cout << "Thread Start num: " << i << "\n";
		cv.wait_for(lck, std::chrono::seconds(4));
		std::cout << "Thread num continued: " << i << "\n";
		jobs--;
		cv.notify_one();
		//cv.notify_all();
	};


	std::cout << "Creating threads\n";

	for (size_t i = 0; i < 10; ++i)
	{
		std::thread thread(threadStart, i);
		thread.detach();
		jobs++;
	}

	std::cout << "Waiting for threads???\n";
	
	std::unique_lock<std::mutex> lock(m);

	while(jobs != 0)
	{
		cv.wait(lock);
	}

	std::cout << "Done waiting for threads...\n";


	return 0;
}