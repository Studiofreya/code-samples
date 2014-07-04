#include <iostream>
#include <ostream>
#include "aabbtests.hpp"

std::ostream& operator<< (std::ostream& os, const Point & p)
{	
	os << p.x << " " << p.y << " " << p.z;
	return os;
}

void print(const AABB & a)
{
	std::cout << "AABB center(" << a.c << ") halfs(" << a.r << ")" << std::endl;
}

void doTest(const AABB & a, const AABB & b)
{
	std::cout << "AABB 1: "; print(a);
	std::cout << "AABB 2: "; print(b);
	bool postResult = testAABBAABB(a,b);
	bool anonResult = testAABBAABB_anon(a,b);
	bool cjmResult = testAABBAABB_CJM(a,b);
	bool simdResult = testAABBAABB_SIMD(a,b);

	std::cout << "Post result " << postResult << std::endl <<
	"Anon result " << anonResult << std::endl <<
	"CJM result " << cjmResult << std::endl <<
	"SIMD result " << simdResult << std::endl;
}

int main()
{
	const Point half(0.5, 0.5, 0.5);
	AABB a(Point(), half);
	AABB b(Point(1.0, 0, 0), half);
	AABB c(Point(1.5, 0, 0), half);
	AABB d(Point(15, 0, 0), half);

	doTest(a,a);
	doTest(a,b);
	doTest(a,c);
	doTest(a,d);

	doTest(b,b);
	doTest(b,c);
	doTest(b,d);

	doTest(c,c);
	doTest(c,d);

	AABB a2(Point(0, 1.5, 0), half);
	AABB a3(Point(0, 2.5, 0), half);
	AABB a4(Point(0, 3.5, 0), half);

	doTest(a,a2);
	doTest(a,a3);
	doTest(a,a4);

	AABB d2(Point(15,15,15), half);
	doTest(a,d2);
	
	return 0;
}
