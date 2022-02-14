#include "gtest/gtest.h"
#include "KeyPointMannager.h"
#include "KeyPointData.h"


TEST(KeyPointDataTests, AnnotationDataPointTests) {
    WallLeftKeyPoint WL1(25,66,1);

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

TEST(KeyPointDataTests, KeyPointTests) {
    WallLeftKeyPoint WL1(25, 66, 1);
    WallLeftKeyPoint WL1Again(1);
    WallLeftKeyPoint WL8(8);
    WallLeftKeyPoint WLNot;
    WallLeftKeyPoint WLPoint(22, 77);

    //Test is valid and comparitor operation
    EXPECT_EQ(false, WLPoint.isValid());
    EXPECT_EQ(true, WL1Again.isValid());
    EXPECT_EQ(false, WLNot.isValid());
    EXPECT_EQ(true, WL1.isValid());

    EXPECT_EQ(true, WL1.isTheSameAs(&WL1Again));
    EXPECT_EQ(false, WL1.isTheSameAs(&WLNot));
    EXPECT_EQ(false, WL1.isTheSameAs(&WL8));
}

TEST(KeyPointDataTests, WallLeftKeyPointTests) {

    WallLeftKeyPoint WL1(25, 66, 1);
    WallLeftKeyPoint WL12(12);
    WallLeftKeyPoint WLPoint(22,77);
    WallLeftKeyPoint WLNot;

    //test number range
    EXPECT_THROW(WallLeftKeyPoint WLFail(13), KeyPointDataError);
    EXPECT_THROW(WallLeftKeyPoint WLFail(25, 66, -1), KeyPointDataError);

    //Test get class
    EXPECT_EQ("WL1", WL1.getClass());
    EXPECT_EQ("WL12", WL12.getClass());
    EXPECT_THROW(WLNot.getClass(), KeyPointDataError);
    EXPECT_THROW(WLPoint.getClass(), KeyPointDataError);
}

TEST(KeyPointDataTests, WallRightKeyPointTests) {

    WallRightKeyPoint WR3(25, 66, 3);
    WallRightKeyPoint WR10(10);
    WallRightKeyPoint WRPoint(22, 77);
    WallRightKeyPoint WRNot;

    //test number range
    EXPECT_THROW(WallRightKeyPoint WRFail(-1), KeyPointDataError);
    EXPECT_THROW(WallRightKeyPoint WRFail(25, 66, 13), KeyPointDataError);

    //Test get class
    EXPECT_EQ("WR3", WR3.getClass());
    EXPECT_EQ("WR10", WR10.getClass());
    EXPECT_THROW(WRNot.getClass(), KeyPointDataError);
    EXPECT_THROW(WRPoint.getClass(), KeyPointDataError);
}

TEST(KeyPointDataTests, WallTopKeyPointTests) {

    WallTopKeyPoint WT3(25, 66, 3);
    WallTopKeyPoint WT8(8);
    WallTopKeyPoint WTPoint(22, 77);
    WallTopKeyPoint WTNot;

    //test number range
    EXPECT_THROW(WallTopKeyPoint WTFail(9), KeyPointDataError);
    EXPECT_THROW(WallTopKeyPoint WTFail(25, 66, -1), KeyPointDataError);

    //Test get class
    EXPECT_EQ("WT3", WT3.getClass());
    EXPECT_EQ("WT8", WT8.getClass());
    EXPECT_THROW(WTNot.getClass(), KeyPointDataError);
    EXPECT_THROW(WTPoint.getClass(), KeyPointDataError);

}

TEST(KeyPointDataTests, WallBottomKeyPointTests) {

    WallBottomKeyPoint WB7(25, 66, 7);
    WallBottomKeyPoint WB2(2);
    WallBottomKeyPoint WBPoint(42, 79);
    WallBottomKeyPoint WBNot;

    //test number range
    EXPECT_THROW(WallBottomKeyPoint WBFail(-1), KeyPointDataError);
    EXPECT_THROW(WallBottomKeyPoint WBFail(25, 66, 9), KeyPointDataError);

    //Test get class
    EXPECT_EQ("WB7", WB7.getClass());
    EXPECT_EQ("WB2", WB2.getClass());
    EXPECT_THROW(WBNot.getClass(), KeyPointDataError);
    EXPECT_THROW(WBPoint.getClass(), KeyPointDataError);
}

TEST(KeyPointDataTests, FloatingRightKeyPointTest) {

    FloatingRightKeyPoint FR12(25, 66, 12);
    FloatingRightKeyPoint FR4(4);
    FloatingRightKeyPoint FRPoint(2, 100);
    FloatingRightKeyPoint FRNot;

    //test number range
    EXPECT_THROW(FloatingRightKeyPoint FRFail(-1), KeyPointDataError);
    EXPECT_THROW(FloatingRightKeyPoint FRFail(25, 66, 13), KeyPointDataError);

    //Test get class
    EXPECT_EQ("FR12", FR12.getClass());
    EXPECT_EQ("FR4", FR4.getClass());
    EXPECT_THROW(FRNot.getClass(), KeyPointDataError);
    EXPECT_THROW(FRPoint.getClass(), KeyPointDataError);
}

TEST(KeyPointDataTests, FloatingLeftKeyPointTest) {

    FloatingLeftKeyPoint FL6(25, 66, 6);
    FloatingLeftKeyPoint FL4(5);
    FloatingLeftKeyPoint FLPoint(2, 100);
    FloatingLeftKeyPoint FLNot;

    //test number range
    EXPECT_THROW(FloatingLeftKeyPoint FRFail(13), KeyPointDataError);
    EXPECT_THROW(FloatingLeftKeyPoint FRFail(25, 66, -1), KeyPointDataError);

    //Test get class
    EXPECT_EQ("FL6", FL6.getClass());
    EXPECT_EQ("FL5", FL4.getClass());
    EXPECT_THROW(FLNot.getClass(), KeyPointDataError);
    EXPECT_THROW(FLPoint.getClass(), KeyPointDataError);
}
