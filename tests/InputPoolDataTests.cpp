#include "gtest/gtest.h"
#include "PoolData.h"
#include "PoolConstants.h"
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
    
    PoolData poolData1(false, false, PoolConstants::LCM, PoolConstants::eightLanes);
    PoolData poolData2(true, false, PoolConstants::SCM, PoolConstants::tenLanes);

    EXPECT_EQ(25, poolData2.getLengthPool());
    EXPECT_EQ(50, poolData1.getLengthPool());

    EXPECT_THROW(PoolData poolData1(false, false, 44, PoolConstants::eightLanes), PoolDataError);
    EXPECT_THROW(PoolData poolData1(false, false, -1, PoolConstants::eightLanes), PoolDataError);
    EXPECT_THROW(PoolData poolData1(false, false, 1, PoolConstants::eightLanes), PoolDataError);
}

TEST(InputPoolDataTests, NumberLanesTest) {

    PoolData poolData1(true, true, PoolConstants::LCM, PoolConstants::sixLanes);
    PoolData poolData2(false, false, PoolConstants::LCM, PoolConstants::eightLanes);
    PoolData poolData3(true, true, PoolConstants::LCM, PoolConstants::tenLanes);

    EXPECT_EQ(6, poolData1.getNumberLanes());
    EXPECT_EQ(8, poolData2.getNumberLanes());
    EXPECT_EQ(10, poolData3.getNumberLanes());

    EXPECT_THROW(PoolData poolData3(true, true, PoolConstants::LCM, 44), PoolDataError);
    EXPECT_THROW(PoolData poolData3(true, true, PoolConstants::LCM, -1), PoolDataError);
    EXPECT_THROW(PoolData poolData3(true, true, PoolConstants::LCM, 0), PoolDataError);
}

TEST(InputPoolDataTests, HasBummpersTests) {

    PoolData poolData1(true, true, PoolConstants::LCM, PoolConstants::tenLanes);
    PoolData poolData2(false, false, PoolConstants::LCM, PoolConstants::tenLanes);

    EXPECT_EQ(true, poolData1.poolHasbumpers());
    EXPECT_EQ(false, poolData2.poolHasbumpers());
}

TEST(InputPoolDataTests, HasMiddleBulkheadTests) {

    PoolData poolData1(true, true, PoolConstants::LCM, PoolConstants::tenLanes);
    PoolData poolData2(true, false, PoolConstants::LCM, PoolConstants::tenLanes);
    EXPECT_EQ(true, poolData1.poolHasMiddleBulkhead());
    EXPECT_EQ(false, poolData2.poolHasMiddleBulkhead());
}

TEST(InputPoolDataTests, BulkheadMissmatchTest)
{
    EXPECT_THROW(PoolData testPoolData(true, true, PoolConstants::SCM, PoolConstants::sixLanes), PoolDataError);
    EXPECT_NO_THROW(PoolData testPoolData(true, false, PoolConstants::SCM, PoolConstants::sixLanes));
    EXPECT_NO_THROW(PoolData testPoolData(true, true, PoolConstants::LCM, PoolConstants::sixLanes));
    EXPECT_NO_THROW(PoolData testPoolData(true, false, PoolConstants::LCM, PoolConstants::sixLanes));
}

TEST(InputPoolDataTests, PoolIsDefinedTest) {

    PoolData poolData(true,false, PoolConstants::LCM, PoolConstants::tenLanes);
    EXPECT_EQ(true, poolData.isDefined());
}