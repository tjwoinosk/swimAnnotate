#include "gtest/gtest.h"
#include "KeyPointData.h"

TEST(KeyPointDataTests, AnnotationDataPointTests) {
    WallLeftKeyPoint WL1(1, 25, 66);

    EXPECT_EQ(25, WL1.getXPoint());
    EXPECT_EQ(66, WL1.getYPoint());
    WL1.setXPoint(0);
    EXPECT_EQ(0, WL1.getXPoint());
    EXPECT_THROW(WL1.setXPoint(-1), AnnotationDataError);
    EXPECT_EQ(0, WL1.getXPoint());
    WL1.setYPoint(70);
    EXPECT_EQ(70, WL1.getYPoint());
    EXPECT_THROW(WL1.setYPoint(-5), AnnotationDataError);
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

TEST(KeyPointDataTests, IsDefinedTests) {
    WallLeftKeyPoint WL1(1, 25, 66);
    WallLeftKeyPoint WL1Again(1);
    WallLeftKeyPoint WL8(8);
    //WallLeftKeyPoint WLNot;//should not compile 

    //Test is valid and comparitor operation
    EXPECT_EQ(true, WL1Again.isDefinedClass());
    //EXPECT_EQ(false, WLNot.isDefinedClass());//should not compile 
    EXPECT_EQ(true, WL1.isDefinedClass());
}

TEST(KeyPointDataTests, IsTheSameNumberTests) {
    WallLeftKeyPoint WL1(1,25,66);
    WallLeftKeyPoint WL1Again(1);
    WallLeftKeyPoint WL8(8);
    KeyPointData KP;

    EXPECT_THROW(WL1.isTheSameNumberAs(nullptr), KeyPointDataError);
    EXPECT_TRUE(WL1.isTheSameNumberAs(&WL1));
    EXPECT_TRUE(WL1.isTheSameNumberAs(&WL1Again));
    //EXPECT_EQ(false, WL1.isTheSameNumberAs(&WLNot));//should not compile 
    EXPECT_FALSE(WL1.isTheSameNumberAs(&WL8));

    EXPECT_FALSE(WL1.isTheSameNumberAs(&KP));
    EXPECT_FALSE(KP.isTheSameNumberAs(&WL1));
}

TEST(KeyPointDataTests, IsTheSameClassTest)
{
    WallLeftKeyPoint WL0(0);
    WallLeftKeyPoint WL1(1);
    WallRightKeyPoint WR0(0);
    WallTopKeyPoint WT7(7);
    KeyPointData KP0;

    EXPECT_THROW(WL0.isTheSameClass(nullptr), KeyPointDataError);
    EXPECT_TRUE(WL0.isTheSameClass(&WL0));
    EXPECT_TRUE(WL0.isTheSameClass(&WL1));
    EXPECT_FALSE(WL0.isTheSameClass(&WR0));
    EXPECT_FALSE(WL0.isTheSameClass(&WT7));
    EXPECT_FALSE(WL0.isTheSameClass(&KP0));
}

TEST(KeyPointDataTests, DeepCopyTest)
{
    KeyPointData* test = new WallLeftKeyPoint(3, 25, 66);
    KeyPointData* newTest = test->deepCopy();

    EXPECT_EQ(test->getObjectID(), newTest->getObjectID());
    EXPECT_TRUE(test->isTheSamePointAs(newTest));

    newTest->setXPoint(27);
    newTest->setYPoint(70);

    EXPECT_EQ(test->getObjectID(), newTest->getObjectID());
    EXPECT_FALSE(test->isTheSamePointAs(newTest));

    delete test;
    EXPECT_EQ("WL3", newTest->getObjectID());
    EXPECT_EQ(27, newTest->getXPoint());
    EXPECT_EQ(70, newTest->getYPoint());
    delete newTest;
}

TEST(KeyPointDataTests, GetObjetIDTest)
{
    //completed in nPointTests
    EXPECT_FALSE(false);
}

TEST(KeyPointDataTests, WallLeftKeyPointTests) {

    WallLeftKeyPoint WL1(1, 25, 66);
    WallLeftKeyPoint WL12(12);
    //WallLeftKeyPoint WLNot; //should not compile 
    WallLeftKeyPoint WL1Copy(WL1);

    //test number range
    EXPECT_THROW(WallLeftKeyPoint WLFail(13), KeyPointDataError);
    EXPECT_THROW(WallLeftKeyPoint WLFail(-1, 25, 66), KeyPointDataError);

    //Test get class
    EXPECT_EQ("WL1", WL1.getObjectID());
    EXPECT_EQ("WL12", WL12.getObjectID());
    EXPECT_EQ("WL1", WL1Copy.getObjectID());
    EXPECT_EQ(25, WL1Copy.getXPoint());
    EXPECT_EQ(66, WL1Copy.getYPoint());
    //EXPECT_THROW(WLNot.getObjectID(), KeyPointDataError); //should not compile 
}

TEST(KeyPointDataTests, WallRightKeyPointTests) {

    WallRightKeyPoint WR3(3, 25, 66);
    WallRightKeyPoint WR10(10);
    //WallRightKeyPoint WRNot; //should not compile 
    WallRightKeyPoint WR3Copy(WR3);

    //test number range
    EXPECT_THROW(WallRightKeyPoint WRFail(-1), KeyPointDataError);
    EXPECT_THROW(WallRightKeyPoint WRFail(25, 66, 13), KeyPointDataError);

    //Test get class
    EXPECT_EQ("WR3", WR3.getObjectID());
    EXPECT_EQ("WR10", WR10.getObjectID());
    EXPECT_EQ("WR3", WR3Copy.getObjectID());
    EXPECT_EQ(25, WR3Copy.getXPoint());
    EXPECT_EQ(66, WR3Copy.getYPoint());
    //EXPECT_THROW(WRNot.getObjectID(), KeyPointDataError); //should not compile 
}

TEST(KeyPointDataTests, WallTopKeyPointTests) {

    WallTopKeyPoint WT3(3, 25, 66);
    WallTopKeyPoint WT8(8);
    //WallTopKeyPoint WTNot; //should not compile 
    WallTopKeyPoint WT3Copy(WT3);

    //test number range
    EXPECT_THROW(WallTopKeyPoint WTFail(9), KeyPointDataError);
    EXPECT_THROW(WallTopKeyPoint WTFail(-1, 25, 66), KeyPointDataError);

    //Test get class
    EXPECT_EQ("WT3", WT3.getObjectID());
    EXPECT_EQ("WT8", WT8.getObjectID());
    EXPECT_EQ("WT3", WT3Copy.getObjectID());
    EXPECT_EQ(25, WT3Copy.getXPoint());
    EXPECT_EQ(66, WT3Copy.getYPoint());
    //EXPECT_THROW(WTNot.getObjectID(), KeyPointDataError); //should not compile 

}

TEST(KeyPointDataTests, WallBottomKeyPointTests) {

    WallBottomKeyPoint WB7(7, 25, 66);
    WallBottomKeyPoint WB2(2);
    //WallBottomKeyPoint WBNot;//should not compile 
    WallBottomKeyPoint WB7Copy(WB7);

    //test number range
    EXPECT_THROW(WallBottomKeyPoint WBFail(-1), KeyPointDataError);
    EXPECT_THROW(WallBottomKeyPoint WBFail(9, 25, 66), KeyPointDataError);

    //Test get class
    EXPECT_EQ("WB7", WB7.getObjectID());
    EXPECT_EQ("WB2", WB2.getObjectID());
    EXPECT_EQ("WB7", WB7Copy.getObjectID());
    EXPECT_EQ(25, WB7Copy.getXPoint());
    EXPECT_EQ(66, WB7Copy.getYPoint());
    //EXPECT_THROW(WBNot.getObjectID(), KeyPointDataError);//should not compile 
}

TEST(KeyPointDataTests, FloatingRightKeyPointTest) {

    FloatingRightKeyPoint FR12(12, 25, 66);
    FloatingRightKeyPoint FR4(4);
    //FloatingRightKeyPoint FRNot;//should not compile 
    FloatingRightKeyPoint FR12Copy(FR12);

    //test number range
    EXPECT_THROW(FloatingRightKeyPoint FRFail(-1), KeyPointDataError);
    EXPECT_THROW(FloatingRightKeyPoint FRFail(13, 25, 66), KeyPointDataError);

    //Test get class
    EXPECT_EQ("FR12", FR12.getObjectID());
    EXPECT_EQ("FR4", FR4.getObjectID());
    EXPECT_EQ("FR12", FR12Copy.getObjectID());
    EXPECT_EQ(25, FR12Copy.getXPoint());
    EXPECT_EQ(66, FR12Copy.getYPoint());
    //EXPECT_THROW(FRNot.getObjectID(), KeyPointDataError);//should not compile 
}

TEST(KeyPointDataTests, FloatingLeftKeyPointTest) {

    FloatingLeftKeyPoint FL6(6, 25, 66);
    FloatingLeftKeyPoint FL4(4);
    //FloatingLeftKeyPoint FLNot;//should not compile 
    FloatingLeftKeyPoint FL6Copy(FL6);

    //test number range
    EXPECT_THROW(FloatingLeftKeyPoint FLFail(13), KeyPointDataError);
    EXPECT_THROW(FloatingLeftKeyPoint FLFail(-1, 25, 66), KeyPointDataError);

    //Test get class
    EXPECT_EQ("FL6", FL6.getObjectID());
    EXPECT_EQ("FL4", FL4.getObjectID());
    EXPECT_EQ("FL6", FL6Copy.getObjectID());
    EXPECT_EQ(25, FL6Copy.getXPoint());
    EXPECT_EQ(66, FL6Copy.getYPoint());
    //EXPECT_THROW(FLNot.getObjectID(), KeyPointDataError);//should not compile 
}

TEST(KeyPointDataTests, BulkheadLeftKeyPointTest) {

    BulkheadLeftKeyPoint BL6(6, 25, 66);
    BulkheadLeftKeyPoint BL4(4);
    BulkheadLeftKeyPoint BL6Copy(BL6);

    //test number range
    EXPECT_THROW(BulkheadLeftKeyPoint BLFail(13), KeyPointDataError);
    EXPECT_THROW(BulkheadLeftKeyPoint BLFail(-1, 25, 66), KeyPointDataError);

    //Test get class
    EXPECT_EQ("BL6", BL6.getObjectID());
    EXPECT_EQ("BL4", BL4.getObjectID());
    EXPECT_EQ("BL6", BL6Copy.getObjectID());
    EXPECT_EQ(25, BL6Copy.getXPoint());
    EXPECT_EQ(66, BL6Copy.getYPoint());
}

TEST(KeyPointDataTests, BulkheadRightKeyPointTest) {

    BulkheadRightKeyPoint BR6(6, 25, 66);
    BulkheadRightKeyPoint BR4(4);
    BulkheadRightKeyPoint BR6Copy(BR6);

    //test number range
    EXPECT_THROW(BulkheadRightKeyPoint BRFail(13), KeyPointDataError);
    EXPECT_THROW(BulkheadRightKeyPoint BRFail(-1, 25, 66), KeyPointDataError);

    //Test get class
    EXPECT_EQ("BR6", BR6.getObjectID());
    EXPECT_EQ("BR4", BR4.getObjectID());
    EXPECT_EQ("BR6", BR6Copy.getObjectID());
    EXPECT_EQ(25, BR6Copy.getXPoint());
    EXPECT_EQ(66, BR6Copy.getYPoint());
}
