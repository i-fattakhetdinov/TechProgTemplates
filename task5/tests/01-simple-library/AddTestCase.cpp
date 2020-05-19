//
// Created by akhtyamovpavel on 5/1/20.
//

#include "AddTestCase.h"
#include "Functions.h"

TEST(AddTest, Equal) {
    ASSERT_EQ(Add(1, 2), 3);
}