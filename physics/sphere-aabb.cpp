// Code samples used in this post:
// http://studiofreya.com/3d-math-and-physics/sphere-vs-aabb-collision-detection-test/

#include <iostream>
#include "primitives.hpp"

double SquaredDistPointAABB( const Point & p, const AABB & aabb )
{
    auto check = [&]( const double pn, const double bmin, const double bmax ) -> double
    {
        double out = 0;
        double v = pn;

        if ( v < bmin )
        {
            double val = (bmin - v);
            out += val * val;
        }

        if ( v > bmax )
        {
            double val = (v - bmax);
            out += val * val;
        }

        return out;
    };


    // Squared distance
    double sq = 0.0;

    sq += check( p.x, aabb.min.x, aabb.max.x );
    sq += check( p.y, aabb.min.y, aabb.max.y );
    sq += check( p.z, aabb.min.z, aabb.max.z );

    return sq;
}


// True if the Sphere and AABB intersects
bool TestSphereAABB( const Sphere & sphere, const AABB & aabb )
{
    double squaredDistance = SquaredDistPointAABB( sphere.center, aabb );

    // Intersection if the distance from center is larger than the radius
    // of the sphere.

    return squaredDistance <= (sphere.radius * sphere.radius);
}


int main()
{
    // AABB
    AABB aabb( Point(-1, -1, -1), Point(1,1,1) );

    // Sphere 1 in the center with radious 1
    Sphere s1( Point(0, 0, 0), 1 );

    // Sphere 2 at x=1 with radious 1
    Sphere s2( Point(1, 0, 0), 1 );

    // Sphere 3 at x=3 with radious 1
    Sphere s3( Point(3, 0, 0), 1 );

    bool t1 = TestSphereAABB( s1, aabb );
    bool t2 = TestSphereAABB( s2, aabb );
    bool t3 = TestSphereAABB( s3, aabb );

    std::cout << " Test 1 " << ( t1 ? "succeeded" : "failed" ) << std::endl;
    std::cout << " Test 2 " << ( t2 ? "succeeded" : "failed" ) << std::endl;
    std::cout << " Test 3 " << ( t3 ? "succeeded" : "failed" ) << std::endl;



    return 0;
}

