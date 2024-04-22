#include <iostream>
#include "../A/index.h"
#include "gtest/gtest.h"

void f(int x) {
	std::cout << x;
}

int g(int y) {
	return y + 1;
}

TEST(IndexTest, Tests) {
	ASSERT_TRUE(1 == 1);
	EXPECT_EQ(g(1), 2);
}
