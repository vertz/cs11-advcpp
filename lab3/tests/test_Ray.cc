#include "Ray.hh"

#include <gtest/gtest.h>
#include <iostream>

// This is the namespace that the Google C++ Testing Framework uses.
using namespace testing;


TEST(TestRay, Constructors) 
{
    Ray r1;
    
    Vector3F orig = r1.get_origin();
    
    EXPECT_FLOAT_EQ(orig(0), 0);
    EXPECT_FLOAT_EQ(orig(1), 0);
    EXPECT_FLOAT_EQ(orig(2), 0);
    
    Vector3F dir = r1.get_direction();
    
    EXPECT_FLOAT_EQ(dir(0), 0);
    EXPECT_FLOAT_EQ(dir(1), 0);
    EXPECT_FLOAT_EQ(dir(2), 0);
}


int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
