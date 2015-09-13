#include <boost/format.hpp>

int main()
{
	boost::format fmt("Pi is %4.2f");
	fmt % 3.14;

	// Copy of string
	std::string s1 = boost::str(fmt);
	std::string s2 = fmt.str();

	// If a constant value can be used,
	// use a const ref. This is legal C++ code.
	// See "The most important const":
	// http://herbsutter.com/2008/01/01/gotw-88-a-candidate-for-the-most-important-const/
	const std::string & s3 = boost::str(fmt);
	const std::string & s4 = fmt.str();

	return 0;
}