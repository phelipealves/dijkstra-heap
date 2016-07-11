#include <MinHeap.h>
#include "gtest/gtest.h"


class MinHeapFixture : public ::testing::Test {
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {
    }
};

TEST_F(MinHeapFixture, insert_key){
    MinHeap minHeap(11);
    minHeap.insertKey(10);
    EXPECT_EQ(1, 10);
}