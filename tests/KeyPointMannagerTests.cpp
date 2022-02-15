#include "gtest/gtest.h"
#include "KeyPointMannager.h"
#include "AnnotationData.h"
#include "PoolData.h"
#include "FrameData.h"
#include <vector>

class KeyPointMannagerTests : public ::testing::Test {
protected:
	
	void SetUp() override {
		simple6laneSCMPool.specifyBumpers(true);
		simple6laneSCMPool.setLengthPool(25);
		simple6laneSCMPool.setNumberLanes(6);
		std500SquareFrame.setFrameName("test.png");
		std500SquareFrame.setFrameRes(500, 500);
	}
	// void TearDown() override {}

	PoolData simple6laneSCMPool;
	FrameData std500SquareFrame;
};


TEST_F(KeyPointMannagerTests, SimpleAddKeyPointTest)
{
	WallRightKeyPoint WR0(200, 300, 0);
	WallRightKeyPoint WR1(200,300, 1);
	WallRightKeyPoint WR2(300,400, 2);
	WallRightKeyPoint WR3(300, 400, 3);
	WallRightKeyPoint WR3Extra(375, 200, 3);
	WallRightKeyPoint WR4(300, 400, 4);
	WallRightKeyPoint WR5OutOfRange(300, 500, 5);
	WallRightKeyPoint WR5(300, 499, 5);
	WallRightKeyPoint WR6OutOfRange(500, 499, 6);
	WallRightKeyPoint WR6(499, 499, 6);
	WallRightKeyPoint WR7(350, 200, 7);
	WallRightKeyPoint WR8(350, 200, 8);
	WallRightKeyPoint WR9(350, 200, 9);
	WallRightKeyPoint WR10(350, 200, 10);
	WallRightKeyPoint WR11(350, 200, 11);
	WallRightKeyPoint WR12(350, 200, 12);

	KeyPointMannager mannager(simple6laneSCMPool, std500SquareFrame);

	mannager.addKeyPoint(&WR0);
	EXPECT_EQ(1, mannager.keyPointCount());

	mannager.addKeyPoint(&WR1);
	EXPECT_EQ(2,mannager.keyPointCount());

	mannager.addKeyPoint(&WR2);
	EXPECT_EQ(3, mannager.keyPointCount());

	mannager.addKeyPoint(&WR3);
	EXPECT_EQ(4, mannager.keyPointCount());

	EXPECT_THROW(mannager.addKeyPoint(&WR3Extra), KeyPointMannagerKeyPointError);
	EXPECT_EQ(4, mannager.keyPointCount());

	mannager.addKeyPoint(&WR4);
	EXPECT_EQ(5, mannager.keyPointCount());
	
	EXPECT_THROW(mannager.addKeyPoint(&WR5OutOfRange), KeyPointMannagerFrameError);
	EXPECT_EQ(5, mannager.keyPointCount());

	mannager.addKeyPoint(&WR5);
	EXPECT_EQ(6, mannager.keyPointCount());

	EXPECT_THROW(mannager.addKeyPoint(&WR6OutOfRange), KeyPointMannagerFrameError);
	EXPECT_EQ(6, mannager.keyPointCount());

	mannager.addKeyPoint(&WR6);
	EXPECT_EQ(7, mannager.keyPointCount());

	EXPECT_THROW(mannager.addKeyPoint(&WR7), KeyPointMannagerPoolError);
	EXPECT_EQ(7, mannager.keyPointCount());
	EXPECT_THROW(mannager.addKeyPoint(&WR8), KeyPointMannagerPoolError);
	EXPECT_EQ(7, mannager.keyPointCount());
	EXPECT_THROW(mannager.addKeyPoint(&WR9), KeyPointMannagerPoolError);
	EXPECT_EQ(7, mannager.keyPointCount());
	EXPECT_THROW(mannager.addKeyPoint(&WR10), KeyPointMannagerPoolError);
	EXPECT_EQ(7, mannager.keyPointCount());

	mannager.addKeyPoint(&WR11);
	EXPECT_EQ(8, mannager.keyPointCount());
	mannager.addKeyPoint(&WR12);
	EXPECT_EQ(9, mannager.keyPointCount());

	//EXPECT_EQ()
	//EXPECT_THROW()
}