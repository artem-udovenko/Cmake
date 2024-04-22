#include <iostream>                                         index_test.cpp                                                     #include <iostream>
#include "../B/lib.cpp"
#include "gtest/gtest.h"

TEST(LibTest, Tests) {
        ASSERT_TRUE(1 == 1);
        EXPECT_TRUE(SayHi()[0] == 'H');
}
