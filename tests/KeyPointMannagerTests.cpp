#include "gtest/gtest.h"
#include "KeyPointManager.h"
#include "AnnotationData.h"
#include "PoolData.h"
#include "FrameData.h"
#include "AnnotationDiscriminator.h"

/*
class KeyPointMannagerTests : public ::testing::Test {
protected:
	
	void SetUp() override {

	}
	// void TearDown() override {}


};
*/

TEST(KeyPointMannagerTests, SimpleAddKeyPointTest)
{
	PoolData simple6laneSCMPool;
	FrameData std500SquareFrame;
	simple6laneSCMPool.specifyBumpers(true);
	simple6laneSCMPool.setLengthPool(25);
	simple6laneSCMPool.setNumberLanes(6);
	std500SquareFrame.setFrameRes(500, 500);

	const int numClasses = 13;
	KeyPointData* WR[numClasses];
	for (int ii = 0; ii < numClasses; ii++)
		WR[ii] = new WallRightKeyPoint(ii);

	KeyPointManager mannager(simple6laneSCMPool, std500SquareFrame);
	
	mannager.addKeyPoint(WR[0], 300, 200);
	EXPECT_EQ(1, mannager.keyPointCount());
	mannager.addKeyPoint(WR[1],350,200);
	EXPECT_EQ(2,mannager.keyPointCount());
	mannager.addKeyPoint(WR[2],360,210);
	EXPECT_EQ(3, mannager.keyPointCount());
	mannager.addKeyPoint(WR[3],370,220);
	EXPECT_EQ(4, mannager.keyPointCount());
	
	KeyPointData* WR3Extra = new WallRightKeyPoint(3);
	EXPECT_THROW(mannager.addKeyPoint(WR3Extra,200,200), AnnotationDiscriminatorError);
	EXPECT_EQ(4, mannager.keyPointCount());
	delete WR3Extra;

	mannager.addKeyPoint(WR[4],380,230);
	EXPECT_EQ(5, mannager.keyPointCount());
	EXPECT_THROW(mannager.addKeyPoint(WR[5],300,500), AnnotationDiscriminatorError);
	EXPECT_EQ(5, mannager.keyPointCount());
	mannager.addKeyPoint(WR[5],300,499);
	EXPECT_EQ(6, mannager.keyPointCount());
	EXPECT_THROW(mannager.addKeyPoint(WR[6], 500, 499), AnnotationDiscriminatorError);
	EXPECT_EQ(6, mannager.keyPointCount());
	mannager.addKeyPoint(WR[6], 499, 499);
	EXPECT_EQ(7, mannager.keyPointCount());
	EXPECT_THROW(mannager.addKeyPoint(WR[7], 350, 200), AnnotationDiscriminatorError);
	EXPECT_EQ(7, mannager.keyPointCount());
	EXPECT_THROW(mannager.addKeyPoint(WR[8], 350, 200), AnnotationDiscriminatorError);
	EXPECT_EQ(7, mannager.keyPointCount());
	EXPECT_THROW(mannager.addKeyPoint(WR[9], 350, 200), AnnotationDiscriminatorError);
	EXPECT_EQ(7, mannager.keyPointCount());
	EXPECT_THROW(mannager.addKeyPoint(WR[10], 350, 200), AnnotationDiscriminatorError);
	EXPECT_EQ(7, mannager.keyPointCount());

	mannager.addKeyPoint(WR[11], 350, 200);
	EXPECT_EQ(8, mannager.keyPointCount());
	EXPECT_THROW(mannager.addKeyPoint(WR[11], 350, 200), AnnotationDiscriminatorError);
	EXPECT_EQ(8, mannager.keyPointCount());
	mannager.addKeyPoint(WR[12], 350, 200);
	EXPECT_EQ(9, mannager.keyPointCount());
	
	//EXPECT_EQ()
	//EXPECT_THROW()
}