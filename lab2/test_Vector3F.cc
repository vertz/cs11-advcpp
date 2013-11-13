#include "Vector3F.hh"
#include <gtest/gtest.h>
#include <iostream>

// This is the namespace that the Google C++ Testing Framework uses.
using namespace testing;


TEST(TestVector3F, Constructors) 
{
    Vector3F v;
    
    EXPECT_FLOAT_EQ(v(0), 0);
    EXPECT_FLOAT_EQ(v(1), 0);
    EXPECT_FLOAT_EQ(v(2), 0);
    
    Vector3F u(1,2,3);
    
    EXPECT_FLOAT_EQ(u(0), 1);
    EXPECT_FLOAT_EQ(u(1), 2);
    EXPECT_FLOAT_EQ(u(2), 3);
}


TEST(TestVector3F, CompoundAssignment) 
{
    Vector3F v(0,1,7), w;
    
    w = v;
    
    EXPECT_FLOAT_EQ(v(0), w(0));
    EXPECT_FLOAT_EQ(v(1), w(1));
    EXPECT_FLOAT_EQ(v(2), w(2));
    
    v -= w;
    
    EXPECT_FLOAT_EQ(v(0), 0);
    EXPECT_FLOAT_EQ(v(1), 0);
    EXPECT_FLOAT_EQ(v(2), 0);
    
    v += w;
    
    EXPECT_FLOAT_EQ(v(0), w(0));
    EXPECT_FLOAT_EQ(v(1), w(1));
    EXPECT_FLOAT_EQ(v(2), w(2));
}

TEST(TestVector3F, unaryMinus) 
{
    Vector3F v(1,-2,3), w;
    
    w = -v;
    
    EXPECT_FLOAT_EQ(w(0), -1);
    EXPECT_FLOAT_EQ(w(1),  2);
    EXPECT_FLOAT_EQ(w(2), -3);
}


int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
