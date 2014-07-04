#include <iostream>
#include <ostream>
#include "aabbtests.hpp"

std::ostream& operator<< (std::ostream& os, const Point & p)
{	
	os << p.x << " " << p.y << " " << p.z;
	return os;
}

void print(const AABB2 & a)
{
	std::cout << "AABB center(" << a.c << ") halfs(" << a.r << ")" << std::endl;
}

void doTest(const AABB2 & a, const AABB2 & b)
{
	std::cout << "AABB 1: "; print(a);
	std::cout << "AABB 2: "; print(b);
	bool postResult = testAABBAABB(a,b);
	bool anonResult = testAABBAABB_anon(a,b);
	bool cjResult = testAABBAABB_CJ(a,b);

	std::cout << "Post result " << postResult << std::endl <<
	"Anon result " << anonResult << std::endl <<
	"CJ result " << cjResult << std::endl;
}

int main()
{
	const Point half(0.5, 0.5, 0.5);
	AABB2 a(Point(), half);
	AABB2 b(Point(1.0, 0, 0), half);
	AABB2 c(Point(1.5, 0, 0), half);
	AABB2 d(Point(15, 0, 0), half);

	doTest(a,a);
	doTest(a,b);
	doTest(a,c);
	doTest(a,d);

	doTest(b,b);
	doTest(b,c);
	doTest(b,d);

	doTest(c,c);
	doTest(c,d);

	AABB2 a2(Point(0, 1.5, 0), half);
	AABB2 a3(Point(0, 2.5, 0), half);
	AABB2 a4(Point(0, 3.5, 0), half);

	doTest(a,a2);
	doTest(a,a3);
	doTest(a,a4);

	AABB2 d2(Point(15,15,15), half);
	doTest(a,d2);
	
	return 0;
}
