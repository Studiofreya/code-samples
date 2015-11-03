#include <iostream>
#include <vector>
#include <iterator>

struct large
{
	//large() = default;
	//explicit large(large &) = delete;

	static const size_t elements = 1024*1024;

	char arr[elements] = { 0 };
};


int main()
{
	std::cout << "large size: " << sizeof(large);

	auto sz = sizeof(large);

	typedef std::vector<large> lv;

	lv l;

	for (size_t i = 0; i < 100; ++i)
	{
		l.emplace_back(large());
	}

	lv a, b, c, d;

	std::move(l.begin(), l.end(), std::back_inserter(a));

	//b = std::move(a);
	//c = std::move(b);
	//d = std::move(c);

	for (auto & m : l)
	{
		memset(&m.arr, 0xFF, sz);
	}


	return 0;
}