#include "gtest/gtest.h"
#include "KeyPointAnnotator.h"

//extern KeyPointAnnotator;

TEST(InputPoolDataTests, poolLengthTests) {

    KeyPointAnnotator aPool;

    aPool.addPoolLength(25);

    EXPECT_EQ(25, aPool.getPoolLength());
}