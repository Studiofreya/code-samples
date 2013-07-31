// build with make or:
//
// g++ -I../../boost_1_46_0 fmt.cpp
//


#include <iostream>
#include <sstream>
#include <boost/format.hpp>

using namespace std;
using namespace boost;


int main()
{
	stringstream ss;

	int year 	= 2011;
	int month 	= 3;
	int day 	= 11;
	int hour 	= 12;
	int minute 	= 1;
	double seconds= 23.35;
	double epoch  = 1231234567890.35;

	// Fill with whitespace, right align
	ss << format("#1.0 %4i %4i %4i\n") % year % month % day;
	// Output: #1.0 2011    3   11

	// Fill with whitespace, left align
	ss << format("#1.1 %-4i %-4i %-4i\n") % year % month % day;
	// Output: #1.1 2011 3    11

	// Fill with zero (pad)
	ss << format("#2.0 %04i %04i %04i\n") % year % month % day;
	// Output: #2.0 2011 0003 0011

	// Floating point precision
	ss << format("#3.0 %11.2f\n") % seconds;
	// Output: #3.0       23.35

	// Floating point precision with zero-fill (zero pad)
	ss << format("#4.0 %011.2f\n") % seconds;
	// Output: #4.0 00000023.35

	// Left aligned string literal with 30+20 columns
	ss << format("#5.0 %-30s%-20s\n") % "LEFT ALIGNED 1" % "LEFT ALIGNED 2";
	// Output: #5.0 LEFT ALIGNED 1                LEFT ALIGNED 2

	// Right aligned string literal
	ss << format("#6.0 %30s%20s\n") % "RIGHT ALIGNED 1" % "RIGHT ALIGNED 2";
	// Output: #6.0                RIGHT ALIGNED 1     RIGHT ALIGNED 2
	

	cout << ss.str();

	return 0;
}



