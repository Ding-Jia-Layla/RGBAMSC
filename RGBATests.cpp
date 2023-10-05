#include <gtest/gtest.h>
#include "RGBA.h"
TEST(RGBA,construct){
    RGBA pixel;
    EXPECT_EQ(pixel.r,255);
    EXPECT_EQ(pixel.g,255);
}