#include <cstdint>
#include <thread>
#include <random>
#include <boost/signals2.hpp>

inline bool IsPrime(uint64_t number)
{
	if (((!(number & 1)) && number != 2) || (number < 2) || (number % 3 == 0 && number != 3))		
	{
		return false;
	}

	for (uint64_t k = 1; 36*k*k-12*k < number; ++k)		
	{
		if ((number % (6*k+1) == 0) || (number % (6*k-1) == 0))
		{
			return false;
		}
	}

	return true;
}

class ThreadStart
{
	public:
		explicit ThreadStart()
		{
		}

		virtual ~ThreadStart()
		{
		}

	public:
		void doWork(long long number)
		{

		}
};


const size_t n = 100000;

const size_t max = std::numeric_limits<uint64_t>::max();
const size_t min = max / 2;

std::random_device rd;   // non-deterministic generator
std::mt19937 gen(rd());  // to seed mersenne twister.
std::uniform_int_distribution<> dist(min, max); // distribute results between 1 and 10 inclusive.

 std::vector<uint64_t>	&& createLargeVector()
 {
	return dist(gen);
 }


int test6_threads()
{

	// Typedefs for beautiful code
	typedef boost::signals2::signal<bool(uint64_t)>	registration_manager;
	typedef registration_manager::slot_type			registration_request;

	// Our commander
	registration_manager signalHandler;

	// Create work for threads
	size_t numThreads = std::thread::hardware_concurrency();
	std::vector<

	// Create n-threads and connect them



	std::thread t(&threadstart, 20);
	t.join();


	return 0;
}