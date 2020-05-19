//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"
#include <Functions.h>

TEST(LeapTest, InvalidArgument) {
    ASSERT_THROW(IsLeap(0), std::invalid_argument);
}

TEST(LeapTest, IsLeapYear) {
    ASSERT_TRUE(IsLeap(400));
    ASSERT_TRUE(IsLeap(4));
}

TEST(LeapTest, IsNotLeapYear) {
    ASSERT_FALSE(IsLeap(100));
    ASSERT_FALSE(IsLeap(3));
}