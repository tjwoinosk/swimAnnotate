#include "gtest/gtest.h"
#include "FrameData.h"

/*
class InputPoolDataTests : public ::testing::Test {
protected:
    void SetUp() override {}
    // void TearDown() override {}
private:
    some class...
};
*/

TEST(FrameDataTests, InputFrameSizeTests) {
    FrameData frame;

    EXPECT_THROW(frame.getFrameHeight(), FrameDataError);
    EXPECT_THROW(frame.getFrameWidth(), FrameDataError);

    frame.setFrameRes(60, 70);
    EXPECT_EQ(60, frame.getFrameHeight());
    EXPECT_EQ(70, frame.getFrameWidth());

    EXPECT_THROW(frame.setFrameRes(-1, 60), FrameDataError);
    EXPECT_NE(-1, frame.getFrameHeight());
    EXPECT_NE(60, frame.getFrameWidth());
    EXPECT_THROW(frame.setFrameRes(65, 49), FrameDataError);
    EXPECT_NE(65, frame.getFrameHeight());
    EXPECT_NE(49, frame.getFrameWidth());
    EXPECT_THROW(frame.setFrameRes(49, -1), FrameDataError);
    EXPECT_NE(49, frame.getFrameHeight());
    EXPECT_NE(-1, frame.getFrameWidth());
    frame.setFrameRes(65, 75);
    EXPECT_EQ(65, frame.getFrameHeight());
    EXPECT_EQ(75, frame.getFrameWidth());
}

TEST(FrameDataTests, InputFrameNameTests) {
    FrameData frame;
    
    EXPECT_THROW(frame.getFrameName(), FrameDataError);
    frame.setFrameName("NewName.png");
    EXPECT_EQ("NewName.png", frame.getFrameName());
}

TEST(FrameDataTests, FrameIsDefinedTests) {
    FrameData frame;
    FrameData frame2;

    EXPECT_EQ(false,frame.isDefined());
    frame.setFrameName("test.png");
    EXPECT_EQ(false, frame.isDefined());
    frame.setFrameRes(60, 70);
    EXPECT_EQ(true, frame.isDefined());

    EXPECT_EQ(false, frame2.isDefined());
    frame2.setFrameRes(60, 70);
    EXPECT_EQ(true, frame2.isDefined());
    frame2.setFrameName("test.png");
    EXPECT_EQ(true, frame2.isDefined());
}