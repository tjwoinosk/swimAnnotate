#include "gtest/gtest.h"
#include "AnnotationData.h"

TEST(KeyPointDataTests, AnnotationDataPointTests) {
    WallLeftKeyPoint WL1(1,25, 66);

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
    WallLeftKeyPoint WL1(1,25,66);
    WallLeftKeyPoint WL1Again(1);
    WallLeftKeyPoint WL8(8);
    //WallLeftKeyPoint WLNot;//should not compile 

    //Test is valid and comparitor operation
    EXPECT_EQ(true, WL1Again.isDefinedClass());
    //EXPECT_EQ(false, WLNot.isDefinedClass());//should not compile 
    EXPECT_EQ(true, WL1.isDefinedClass());

    EXPECT_EQ(true, WL1.isTheSameAs(&WL1Again));
    //EXPECT_EQ(false, WL1.isTheSameAs(&WLNot));//should not compile 
    EXPECT_EQ(false, WL1.isTheSameAs(&WL8));
}

TEST(KeyPointDataTests, WallLeftKeyPointTests) {

    WallLeftKeyPoint WL1(1, 25, 66);
    WallLeftKeyPoint WL12(12);
    //WallLeftKeyPoint WLNot; //should not compile 

    //test number range
    EXPECT_THROW(WallLeftKeyPoint WLFail(13), KeyPointDataError);
    EXPECT_THROW(WallLeftKeyPoint WLFail(-1, 25, 66), KeyPointDataError);

    //Test get class
    EXPECT_EQ("WL1", WL1.getClass());
    EXPECT_EQ("WL12", WL12.getClass());
    //EXPECT_THROW(WLNot.getClass(), KeyPointDataError); //should not compile 
}

TEST(KeyPointDataTests, WallRightKeyPointTests) {

    WallRightKeyPoint WR3(3, 25, 66);
    WallRightKeyPoint WR10(10);
    //WallRightKeyPoint WRNot; //should not compile 

    //test number range
    EXPECT_THROW(WallRightKeyPoint WRFail(-1), KeyPointDataError);
    EXPECT_THROW(WallRightKeyPoint WRFail(25, 66, 13), KeyPointDataError);

    //Test get class
    EXPECT_EQ("WR3", WR3.getClass());
    EXPECT_EQ("WR10", WR10.getClass());
    //EXPECT_THROW(WRNot.getClass(), KeyPointDataError); //should not compile 
}

TEST(KeyPointDataTests, WallTopKeyPointTests) {

    WallTopKeyPoint WT3(3, 25, 66);
    WallTopKeyPoint WT8(8);
    //WallTopKeyPoint WTNot; //should not compile 

    //test number range
    EXPECT_THROW(WallTopKeyPoint WTFail(9), KeyPointDataError);
    EXPECT_THROW(WallTopKeyPoint WTFail(-1, 25, 66), KeyPointDataError);

    //Test get class
    EXPECT_EQ("WT3", WT3.getClass());
    EXPECT_EQ("WT8", WT8.getClass());
    //EXPECT_THROW(WTNot.getClass(), KeyPointDataError); //should not compile 

}

TEST(KeyPointDataTests, WallBottomKeyPointTests) {

    WallBottomKeyPoint WB7(7, 25, 66);
    WallBottomKeyPoint WB2(2);
    //WallBottomKeyPoint WBNot;//should not compile 

    //test number range
    EXPECT_THROW(WallBottomKeyPoint WBFail(-1), KeyPointDataError);
    EXPECT_THROW(WallBottomKeyPoint WBFail(9, 25, 66), KeyPointDataError);

    //Test get class
    EXPECT_EQ("WB7", WB7.getClass());
    EXPECT_EQ("WB2", WB2.getClass());
    //EXPECT_THROW(WBNot.getClass(), KeyPointDataError);//should not compile 
}

TEST(KeyPointDataTests, FloatingRightKeyPointTest) {

    FloatingRightKeyPoint FR12(12, 25, 66);
    FloatingRightKeyPoint FR4(4);
    //FloatingRightKeyPoint FRNot;//should not compile 

    //test number range
    EXPECT_THROW(FloatingRightKeyPoint FRFail(-1), KeyPointDataError);
    EXPECT_THROW(FloatingRightKeyPoint FRFail(13, 25, 66), KeyPointDataError);

    //Test get class
    EXPECT_EQ("FR12", FR12.getClass());
    EXPECT_EQ("FR4", FR4.getClass());
    //EXPECT_THROW(FRNot.getClass(), KeyPointDataError);//should not compile 
}

TEST(KeyPointDataTests, FloatingLeftKeyPointTest) {

    FloatingLeftKeyPoint FL6(6, 25, 66);
    FloatingLeftKeyPoint FL4(5);
    //FloatingLeftKeyPoint FLNot;//should not compile 

    //test number range
    EXPECT_THROW(FloatingLeftKeyPoint FRFail(13), KeyPointDataError);
    EXPECT_THROW(FloatingLeftKeyPoint FRFail(-1, 25, 66), KeyPointDataError);

    //Test get class
    EXPECT_EQ("FL6", FL6.getClass());
    EXPECT_EQ("FL5", FL4.getClass());
    //EXPECT_THROW(FLNot.getClass(), KeyPointDataError);//should not compile 
}
