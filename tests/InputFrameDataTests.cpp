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

TEST(InputFrameDataTests, InputFrameSizeTests) {
    FrameData frame;

    EXPECT_THROW(frame.getFrameHeight(), FrameResError);
    EXPECT_THROW(frame.getFrameWidth(), FrameResError);

    frame.setFrameRes(10, 20);
    EXPECT_EQ(10, frame.getFrameHeight());
    EXPECT_EQ(20, frame.getFrameWidth());

    EXPECT_THROW(frame.setFrameRes(-1, 10), FrameResError);
    EXPECT_NE(-1, frame.getFrameHeight());
    EXPECT_NE(10, frame.getFrameWidth());
    EXPECT_THROW(frame.setFrameRes(15, 0), FrameResError);
    EXPECT_NE(15, frame.getFrameHeight());
    EXPECT_NE(0, frame.getFrameWidth());
    EXPECT_THROW(frame.setFrameRes(-1, 0), FrameResError);
    EXPECT_NE(-1, frame.getFrameHeight());
    EXPECT_NE(0, frame.getFrameWidth());
    frame.setFrameRes(15, 25);
    EXPECT_EQ(15, frame.getFrameHeight());
    EXPECT_EQ(25, frame.getFrameWidth());
}

TEST(InputFrameDataTests, InputFrameNameTests) {
    FrameData frame;
    
    EXPECT_THROW(frame.getFrameName(), FrameNameError);
    frame.setFrameName("NewName.png");
    EXPECT_EQ("NewName.png", frame.getFrameName());
}

TEST(InputFrameDataTests, FrameIsDefinedTests) {
    FrameData frame;
    FrameData frame2;

    EXPECT_EQ(false,frame.frameIsDefined());
    frame.setFrameName("test.png");
    EXPECT_EQ(false, frame.frameIsDefined());
    frame.setFrameRes(10, 20);
    EXPECT_EQ(true, frame.frameIsDefined());

    EXPECT_EQ(false, frame2.frameIsDefined());
    frame2.setFrameRes(10, 20);
    EXPECT_EQ(true, frame2.frameIsDefined());
    frame2.setFrameName("test.png");
    EXPECT_EQ(true, frame2.frameIsDefined());
}