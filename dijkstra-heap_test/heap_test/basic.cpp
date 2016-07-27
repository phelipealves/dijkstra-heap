#include <HeapNode.h>
#include "gtest/gtest.h"

TEST(basic_check, test_eq) {
    EXPECT_EQ(1, 1);
}

TEST(basic_check, test_neq) {
    EXPECT_NE(1, 0);
}

TEST(HeapNodeTest, HeapNodeEQVertexAndDistance_Test) {
    HeapNode foo(1,4);
    EXPECT_EQ(1, foo.getVertex());
    EXPECT_EQ(4, foo.getDistance());
}
