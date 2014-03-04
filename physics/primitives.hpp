#if !defined (BASIC_PRIMITIVES_HPP_INCLUDED)
#define       BASIC_PRIMITIVES_HPP_INCLUDED

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
};

struct AABB
{
	AABB() : min(), max() {}
	AABB( const Point & min, const Point & max ) 
		: min(min)
		, max(max)
	{}

	Point min;
	Point max;
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
