#if ! defined(AABBTESTS_HPP_INCLUDED)
#define       AABBTESTS_HPP_INCLUDED

#include <cmath>
#include "primitives.hpp"

typedef AABB_center AABB;

double Abs(double a) 
{
	return std::fabs(a);
}

bool testAABBAABB(const AABB &a, const AABB &b)
{
	if ( Abs(a.c[0] - b.c[0]) > (a.r[0] + b.r[0]) ) return false;
	if ( Abs(a.c[1] - b.c[1]) > (a.r[1] + b.r[1]) ) return false;
	if ( Abs(a.c[2] - b.c[2]) > (a.r[2] + b.r[2]) ) return false;
	
	// We have an overlap
	return true;
};

bool testAABBAABB_anon(const AABB &a, const AABB &b)
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

bool testAABBAABB_CJM(const AABB &a, const AABB &b)
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

bool testAABBAABB_SIMD(const AABB &a, const AABB &b)
{
	// SIMD optimized AABB-AABB test
	// Optimized by removing conditional branches
	bool x = Abs(a.c[0] - b.c[0]) <= (a.r[0] + b.r[0]);
	bool y = Abs(a.c[1] - b.c[1]) <= (a.r[1] + b.r[1]);
	bool z = Abs(a.c[2] - b.c[2]) <= (a.r[2] + b.r[2]);

	return x && y && z;
}

#endif // AABBTESTS_HPP_INCLUDED


