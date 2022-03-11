#include "gtest/gtest.h"
#include "PoolData.h"
#include "PoolConstants.h"

TEST(PoolDataTests, LengthPoolTests) {
    
    PoolData poolData1(false, false, PoolConstants::LCM, PoolConstants::eightLanes);
    PoolData poolData2(true, false, PoolConstants::SCM, PoolConstants::tenLanes);

    EXPECT_EQ(25, poolData2.getLengthPool());
    EXPECT_EQ(50, poolData1.getLengthPool());

    EXPECT_THROW(PoolData poolData1(false, false, 44, PoolConstants::eightLanes), PoolDataError);
    EXPECT_THROW(PoolData poolData1(false, false, -1, PoolConstants::eightLanes), PoolDataError);
    EXPECT_THROW(PoolData poolData1(false, false, 1, PoolConstants::eightLanes), PoolDataError);
}

TEST(PoolDataTests, NumberLanesTest) {

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

TEST(PoolDataTests, HasBummpersTests) {

    PoolData poolData1(true, true, PoolConstants::LCM, PoolConstants::tenLanes);
    PoolData poolData2(false, false, PoolConstants::LCM, PoolConstants::tenLanes);

    EXPECT_EQ(true, poolData1.poolHasbumpers());
    EXPECT_EQ(false, poolData2.poolHasbumpers());
}

TEST(PoolDataTests, HasMiddleBulkheadTests) {

    PoolData poolData1(true, true, PoolConstants::LCM, PoolConstants::tenLanes);
    PoolData poolData2(true, false, PoolConstants::LCM, PoolConstants::tenLanes);
    EXPECT_EQ(true, poolData1.poolHasMiddleBulkhead());
    EXPECT_EQ(false, poolData2.poolHasMiddleBulkhead());
}

TEST(PoolDataTests, BulkheadMissmatchTest)
{
    EXPECT_THROW(PoolData testPoolData(true, true, PoolConstants::SCM, PoolConstants::sixLanes), PoolDataError);
    EXPECT_NO_THROW(PoolData testPoolData(true, false, PoolConstants::SCM, PoolConstants::sixLanes));
    EXPECT_NO_THROW(PoolData testPoolData(true, true, PoolConstants::LCM, PoolConstants::sixLanes));
    EXPECT_NO_THROW(PoolData testPoolData(true, false, PoolConstants::LCM, PoolConstants::sixLanes));
}

TEST(PoolDataTests, PoolIsDefinedSCMTest) 
{
    PoolData poolData;

    poolData.setLengthPool(PoolConstants::SCM);
    EXPECT_FALSE(poolData.isDefined());

    poolData.setNumberLanes(PoolConstants::eightLanes);
    EXPECT_FALSE(poolData.isDefined());

    poolData.specifyBumpers(true);
    EXPECT_TRUE(poolData.isDefined());
}

TEST(PoolDataTests, PoolIsDefinedLCMTest)
{
    PoolData poolData;

    poolData.setLengthPool(PoolConstants::LCM);
    EXPECT_FALSE(poolData.isDefined());

    poolData.setNumberLanes(PoolConstants::eightLanes);
    EXPECT_FALSE(poolData.isDefined());

    poolData.specifyBumpers(false);
    EXPECT_FALSE(poolData.isDefined());

    poolData.specifyMiddlePool(false);
    EXPECT_TRUE(poolData.isDefined());
}

//screwy if you ask me but seems to be a good way to sort out the problem at this point
TEST(PoolDataTests, AutoChangeMiddelBulkhead)
{
    PoolData poolData;
    poolData.specifyMiddlePool(true);
    EXPECT_NO_THROW(poolData.setLengthPool(PoolConstants::SCM));
    EXPECT_FALSE(poolData.poolHasMiddleBulkhead());
}

TEST(PoolDataTests, PoolDataCopyConstructorTest) 
{
    PoolData testPoolData(true, false, PoolConstants::SCM, PoolConstants::sixLanes);
    PoolData newPool(testPoolData);

    EXPECT_EQ(PoolConstants::SCM, newPool.getLengthPool());
    EXPECT_EQ(PoolConstants::sixLanes, newPool.getNumberLanes());
    EXPECT_TRUE(newPool.poolHasbumpers());
    EXPECT_FALSE(newPool.poolHasMiddleBulkhead());
}