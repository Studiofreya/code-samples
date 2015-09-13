// Code on Github:
// https://github.com/Studiofreya/code-samples/blob/master/samples/boost-format-str/boost-format-str.cpp
//
// Post with code:
// http://studiofreya.com/cpp/boost/boost-format-string-examples/

#include <boost/format.hpp>

int main()
{
	// Create a boost::format object, 
	boost::format formatobject("Pi is %4.2f");

	// Feed it with Pi
	formatobject % 3.14;
					 
	// Get strings
	std::string str1 = boost::str(formatobject);
	std::string str2 = formatobject.str();

	// If a constant value can be used,
	// use a const ref. This is legal C++ code.
	// See "The most important const":
	// http://herbsutter.com/2008/01/01/gotw-88-a-candidate-for-the-most-important-const/
	const std::string & str3 = boost::str(formatobject);
	const std::string & str4 = formatobject.str();

	// Character array from the first string
	const char * char1 = str1.c_str();

	return 0;
}