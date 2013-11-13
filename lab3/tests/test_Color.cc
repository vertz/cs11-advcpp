#include "Color.hh"

#include <gtest/gtest.h>
#include <iostream>

// This is the namespace that the Google C++ Testing Framework uses.
using namespace testing;


TEST(TestColor, Constructors) 
{
    Color c1;
    
    EXPECT_FLOAT_EQ(c1.get_red()  , 0);
    EXPECT_FLOAT_EQ(c1.get_green(), 0);
    EXPECT_FLOAT_EQ(c1.get_blue() , 0);
    
    Color c2 (0.2, 0.3, 0.5);
    
    EXPECT_FLOAT_EQ(c2.get_red()  , 0.2);
    EXPECT_FLOAT_EQ(c2.get_green(), 0.3);
    EXPECT_FLOAT_EQ(c2.get_blue() , 0.5);
}


TEST(TestColor, CompoundAssignment) 
{
    Color c1(0.3, 0.1, 0.7), c2;
    
    c2 = c1;
    
    EXPECT_FLOAT_EQ(c1.get_red()  , c2.get_red());
    EXPECT_FLOAT_EQ(c1.get_green(), c2.get_green());
    EXPECT_FLOAT_EQ(c1.get_blue() , c2.get_blue());
    
    c1 -= c2;
    
    EXPECT_FLOAT_EQ(c1.get_red()  , 0);
    EXPECT_FLOAT_EQ(c1.get_green(), 0);
    EXPECT_FLOAT_EQ(c1.get_blue() , 0);
    
    c1 += c2;
    
    EXPECT_FLOAT_EQ(c1.get_red()  , c2.get_red());
    EXPECT_FLOAT_EQ(c1.get_green(), c2.get_green());
    EXPECT_FLOAT_EQ(c1.get_blue() , c2.get_blue());
}

TEST(TestColor, Math) 
{
    Color c1(0.3, 0.1, 0.7), c2, c3, c4;
    
    c3 = c1 + c2;
    
    EXPECT_FLOAT_EQ(c1.get_red()  , c3.get_red());
    EXPECT_FLOAT_EQ(c1.get_green(), c3.get_green());
    EXPECT_FLOAT_EQ(c1.get_blue() , c3.get_blue());
    
    c2 =  3 * c1;
    c4 = c1 * 3;
    
    EXPECT_FLOAT_EQ(c2.get_red()  , c4.get_red());
    EXPECT_FLOAT_EQ(c2.get_green(), c4.get_green());
    EXPECT_FLOAT_EQ(c2.get_blue() , c4.get_blue());
}


int main(int argc, char **argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
