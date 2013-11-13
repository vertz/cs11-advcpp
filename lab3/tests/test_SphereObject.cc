#include "SphereObject.hh"
#include "Vector3F.hh"
#include "Ray.hh"

#include <gtest/gtest.h>
#include <iostream>

// This is the namespace that the Google C++ Testing Framework uses.
using namespace testing;

TEST(TestSphereObject, intersection) 
{
    // shooting a ray from (0,0,0) 
    // at a sphere of radius 1 at (2,0,0)
    // making sure you get back a result of (1,0,0)
    
    Vector3F center(2,0,0), P(0,0,0);
    Ray r(P, center, false);
    SphereObject sObj (center, 1);
    
    float t = sObj.intersection(r);
    Vector3F intersectionPoint = r.getPointAtT(t);
    
    EXPECT_FLOAT_EQ(intersectionPoint(0), 1);
    EXPECT_FLOAT_EQ(intersectionPoint(1), 0);
    EXPECT_FLOAT_EQ(intersectionPoint(2), 0);
}

TEST(TestSphereObject, getIntersections) 
{
    // shooting a ray from (0,0,0) 
    // at a sphere of radius 1 at (2,0,0)
    //sphere-intersection helper function, and check that you get both (1, 0, 0) and (3, 0, 0)
    
    Vector3F center(2,0,0), P(0,0,0);
    Ray r(P, center, false);
    SphereObject sObj (center, 1);
    
    float t1, t2;
    int count = sObj.getIntersections(r, t1, t2);
    
    ASSERT_EQ(count, 2);
    
    Vector3F intersectionPoint = r.getPointAtT(t1);
    
    EXPECT_FLOAT_EQ(intersectionPoint(0), 1);
    EXPECT_FLOAT_EQ(intersectionPoint(1), 0);
    EXPECT_FLOAT_EQ(intersectionPoint(2), 0);
    
    intersectionPoint = r.getPointAtT(t2);
    
    EXPECT_FLOAT_EQ(intersectionPoint(0), 3);
    EXPECT_FLOAT_EQ(intersectionPoint(1), 0);
    EXPECT_FLOAT_EQ(intersectionPoint(2), 0);
}

int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
