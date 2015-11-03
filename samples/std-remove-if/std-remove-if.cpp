#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>


template<typename T>
void printVector(const T & v)
{
	std::copy(v.cbegin(), v.cend(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n";
}


int main()
{
	{
		// Vector with numbers, initialized with an initializer list
		std::vector<int> numbers{ 1,1,2,3,4,5,6 };

		// Lambda for removing numbers less than 3
		auto removeNumbers = [&](int number) -> bool
		{
			return number < 3;
		};

		// Print contents of vector
		printVector(numbers);

		// Call std::remove_if and obtain iterator
		auto iterator = std::remove_if(numbers.begin(), numbers.end(), removeNumbers);

		// Print vector again
		printVector(numbers);

		// Remove from vector
		numbers.erase(iterator, numbers.end());;

		// Final print of vectors
		printVector(numbers);
	}

	{
		std::list<int> numbers{ 1,1,2,3,4,5,6 };

		// Lambda for removing numbers less than 3
		auto removeNumbers = [](int number) -> bool
		{
			return number < 3;
		};

		printVector(numbers);

		numbers.remove_if(removeNumbers);

		printVector(numbers);
	}

	{
		std::vector<int> numbers{ 1,1,2,3,4,5,6 };
		std::vector<int> removed(numbers.size());

		// Lambda for removing numbers less than 3
		auto removeNumbers = [&](int number) -> bool
		{
			return number < 3;
		};

		printVector(numbers);

		std::remove_copy_if(numbers.begin(), numbers.end(), removed.begin(), removeNumbers);

		printVector(numbers);

		int baba = 0;
	}

	{
		struct Widget
		{
			std::string name;	// Widget name
			bool deleted;		// Should be deleted
		};

		auto printWidgets = [&](const std::vector<Widget> & widgets)
		{
			for (const auto & w : widgets)
			{
				std::cout << std::boolalpha << "'" << w.name << "'=" << w.deleted << " ";
			}

			std::cout << "\n";
		};

		// Store them in a container
		std::vector<Widget>	widgets;
		widgets.emplace_back(Widget{ "W1", true });
		widgets.emplace_back(Widget{ "W2", true });
		widgets.emplace_back(Widget{ "W3", false });
		widgets.emplace_back(Widget{ "W4", true });
		widgets.emplace_back(Widget{ "W5", false });
		widgets.emplace_back(Widget{ "W6", true });
		widgets.emplace_back(Widget{ "W7", true });
		widgets.emplace_back(Widget{ "W8", false });

		auto removeDeletedWidgets = [&](const Widget & widget) -> bool
		{
			return widget.deleted;
		};

		printWidgets(widgets);

		auto iterator = std::remove_if(widgets.begin(), widgets.end(), removeDeletedWidgets);

		printWidgets(widgets);

		widgets.erase(iterator, widgets.end());

		printWidgets(widgets);


		int baba = 0;
	}

	return 0;
}