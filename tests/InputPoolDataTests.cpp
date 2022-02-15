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
    
    PoolData poolData;

    EXPECT_THROW(poolData.getLengthPool(), LengthPoolError);

    poolData.setLengthPool(25);
    EXPECT_EQ(25, poolData.getLengthPool());
    poolData.setLengthPool(50);
    EXPECT_EQ(50, poolData.getLengthPool());

    EXPECT_THROW(poolData.setLengthPool(44), LengthPoolError);
    EXPECT_THROW(poolData.setLengthPool(-1), LengthPoolError);
    EXPECT_THROW(poolData.setLengthPool(0), LengthPoolError);
}

TEST(InputPoolDataTests, NumberLanesTest) {

    PoolData poolData;
    EXPECT_THROW(poolData.getNumberLanes(), NumberLanesError);

    poolData.setNumberLanes(6);
    EXPECT_EQ(6, poolData.getNumberLanes());
    poolData.setNumberLanes(8);
    EXPECT_EQ(8, poolData.getNumberLanes());
    poolData.setNumberLanes(10);
    EXPECT_EQ(10, poolData.getNumberLanes());

    EXPECT_THROW(poolData.setNumberLanes(44), NumberLanesError);
    EXPECT_THROW(poolData.setNumberLanes(-1), NumberLanesError);
    EXPECT_THROW(poolData.setNumberLanes(0), NumberLanesError);
}

TEST(InputPoolDataTests, HasBummpersTests) {

    PoolData poolData;
    EXPECT_THROW(poolData.poolHasbumpers(), HasBumpersError);

    poolData.specifyBumpers(true);
    EXPECT_EQ(true, poolData.poolHasbumpers());
    poolData.specifyBumpers(false);
    EXPECT_EQ(false, poolData.poolHasbumpers());
}

TEST(InputPoolDataTests, PoolIsDefinedTest) {

    PoolData poolData;

    EXPECT_EQ(false, poolData.isDefined());
    poolData.specifyBumpers(true);
    EXPECT_EQ(false, poolData.isDefined());
    poolData.setNumberLanes(10);
    EXPECT_EQ(false, poolData.isDefined());
    poolData.setLengthPool(50);
    EXPECT_EQ(true, poolData.isDefined());
}