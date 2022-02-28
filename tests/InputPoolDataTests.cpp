#include "gtest/gtest.h"
#include "PoolData.h"

/*
class InputPoolDataTests : public ::testing::Test {
protected:
    void SetUp() override {}
    // void TearDown() override {}
private:
    some class...
};
*/

TEST(InputPoolDataTests, LengthPoolTests) {
    
    PoolData poolData1(false, false, 50, 8);
    PoolData poolData2(true, false, 25, 10);

    EXPECT_EQ(25, poolData2.getLengthPool());
    EXPECT_EQ(50, poolData1.getLengthPool());

    EXPECT_THROW(PoolData poolData1(false, false, 44, 8), PoolDataError);
    EXPECT_THROW(PoolData poolData1(false, false, -1, 8), PoolDataError);
    EXPECT_THROW(PoolData poolData1(false, false, 1, 8), PoolDataError);
}

TEST(InputPoolDataTests, NumberLanesTest) {

    PoolData poolData1(true, true, 50, 6);
    PoolData poolData2(false, false, 50, 8);
    PoolData poolData3(true, true, 50, 10);

    EXPECT_EQ(6, poolData1.getNumberLanes());
    EXPECT_EQ(8, poolData2.getNumberLanes());
    EXPECT_EQ(10, poolData3.getNumberLanes());

    EXPECT_THROW(PoolData poolData3(true, true, 50, 44), PoolDataError);
    EXPECT_THROW(PoolData poolData3(true, true, 50, -1), PoolDataError);
    EXPECT_THROW(PoolData poolData3(true, true, 50, 0), PoolDataError);
}

TEST(InputPoolDataTests, HasBummpersTests) {

    PoolData poolData1(true, true, 50, 10);
    PoolData poolData2(false, false, 50, 10);

    EXPECT_EQ(true, poolData1.poolHasbumpers());
    EXPECT_EQ(false, poolData2.poolHasbumpers());
}

TEST(InputPoolDataTests, HasMiddleBulkheadTests) {

    PoolData poolData1(true, true, 50, 10);
    PoolData poolData2(true, false, 50, 10);
    EXPECT_EQ(true, poolData1.poolHasMiddleBulkhead());
    EXPECT_EQ(false, poolData2.poolHasMiddleBulkhead());
}

TEST(InputPoolDataTests, BulkheadMissmatchTest)
{
    EXPECT_THROW(PoolData testPoolData(true, true, 25, 6), PoolDataError);
    EXPECT_NO_THROW(PoolData testPoolData(true, false, 25, 6));
    EXPECT_NO_THROW(PoolData testPoolData(true, true, 50, 6));
    EXPECT_NO_THROW(PoolData testPoolData(true, false, 50, 6));
}

TEST(InputPoolDataTests, PoolIsDefinedTest) {

    PoolData poolData(true,false,50,10);
    EXPECT_EQ(true, poolData.isDefined());
}