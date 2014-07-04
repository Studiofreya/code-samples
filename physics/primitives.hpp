#if !defined (BASIC_PRIMITIVES_HPP_INCLUDED)
#define       BASIC_PRIMITIVES_HPP_INCLUDED

#include <assert.h>

struct Point
{
	Point() {}
	Point( double x, double y, double z )
		: x(x)
		, y(y)
		, z(z)
	{}
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double w = 0.0;

	const double operator[](const int idx) const
	{
		if (idx == 0) return x;
		if (idx == 1) return y;
		if (idx == 2) return z;
		if (idx == 3) return w;

		assert(0);
	}
};

struct AABB_minmax
{
	AABB_minmax() : min(), max() {}
	AABB_minmax( const Point & min, const Point & max ) 
		: min(min)
		, max(max)
	{}

	Point min;
	Point max;
};

struct AABB_center
{
	AABB_center() : c(), r() {}

	AABB_center(const Point & center, const Point & halfwidths)
		: c(center)
		, r(halfwidths)
	{}

	Point c;		// center point
	Point r;		// halfwidths
};

struct Sphere
{
	Sphere() : center(), radius() {}
	Sphere( const Point & center, double radius )
		: center(center)
		, radius(radius)
	{}

	Point center;
	double radius = 0;
};

#endif
