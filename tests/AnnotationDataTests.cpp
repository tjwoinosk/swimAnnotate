#include "gtest/gtest.h"
#include "AnnotationData.h"

/*
TEST(KeyPointDataTests, AnnotationDataPointTests) {
    WallLeftKeyPoint WL1(25, 66);

    EXPECT_EQ(25, WL1.getXPoint());
    EXPECT_EQ(66, WL1.getYPoint());
    WL1.setXPoint(0);
    EXPECT_EQ(0, WL1.getXPoint());
    EXPECT_THROW(WL1.setXPoint(-1), KeyPointDataError);
    EXPECT_EQ(0, WL1.getXPoint());
    WL1.setYPoint(70);
    EXPECT_EQ(70, WL1.getYPoint());
    EXPECT_THROW(WL1.setYPoint(-5), KeyPointDataError);
    EXPECT_EQ(70, WL1.getYPoint());
    WL1.setPoint(20, 75);
    EXPECT_EQ(20, WL1.getXPoint());
    EXPECT_EQ(75, WL1.getYPoint());
}

TEST(KeyPointDataTests, CheckSamePointsTest) {

    WallLeftKeyPoint WL1_0(1, 25, 66);

    WallLeftKeyPoint WL1_1(1, 25, 66);
    WallLeftKeyPoint WL1_2(1, 25, 77);
    WallLeftKeyPoint WL1_3(1, 26, 66);

    EXPECT_TRUE(WL1_0.isTheSamePointAs(&WL1_0));
    EXPECT_TRUE(WL1_0.isTheSamePointAs(&WL1_1));
    EXPECT_FALSE(WL1_0.isTheSamePointAs(&WL1_2));
    EXPECT_FALSE(WL1_0.isTheSamePointAs(&WL1_3));
}
*/