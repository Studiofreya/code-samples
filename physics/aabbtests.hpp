#if ! defined(AABBTESTS_HPP_INCLUDED)
#define       AABBTESTS_HPP_INCLUDED

#include <cmath>
#include "primitives.hpp"

double Abs(double a) 
{
	return std::fabs(a);
}

bool testAABBAABB(const AABB2 &a, const AABB2 &b)
{
	if ( Abs(a.c[0] - b.c[0]) > (a.r[0] + b.r[0]) ) return false;
	if ( Abs(a.c[1] - b.c[1]) > (a.r[1] + b.r[1]) ) return false;
	if ( Abs(a.c[2] - b.c[2]) > (a.r[2] + b.r[2]) ) return false;
	// We have an overlap
	return true;
};

bool testAABBAABB_anon(const AABB2 &a, const AABB2 &b)
{
	if ( Abs(a.c[0] - b.c[0]) > (a.r[0] + b.r[0]) )
	{
		if ( Abs(a.c[1] - b.c[1]) > (a.r[1] + b.r[1]) )
		{
			if ( Abs(a.c[2] - b.c[2]) > (a.r[2] + b.r[2]) )
			{
				return false;
			}
		}
	}

	return true;
}

bool testAABBAABB_CJ(const AABB2 &a, const AABB2 &b)
{
	bool xOverlap = true;
	bool yOverlap = true;
	bool zOverlap = true;
	bool anyOverlap = false;
	
	if (Abs(a.c[0] - b.c[0]) > (a.r[0] + b.r[0])) xOverlap = false;
	if (Abs(a.c[1] - b.c[1]) > (a.r[1] + b.r[1])) yOverlap = false;
	if (Abs(a.c[2] - b.c[2]) > (a.r[2] + b.r[2])) zOverlap = false;

	anyOverlap = xOverlap && yOverlap && zOverlap;

	return anyOverlap;
}


#endif // AABBTESTS_HPP_INCLUDED


