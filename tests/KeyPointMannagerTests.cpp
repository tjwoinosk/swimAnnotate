#include "gtest/gtest.h"
#include "KeyPointManager.h"
#include "AnnotationData.h"
#include "PoolData.h"
#include "FrameData.h"
#include "PoolKeyPointValidator.h"

/*
class KeyPointMannagerTests : public ::testing::Test {
protected:
	
	void SetUp() override {

	}
	// void TearDown() override {}


};
*/
/*
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
	EXPECT_THROW(mannager.addKeyPoint(WR3Extra,200,200), PoolKeyPointValidatorError);
	EXPECT_EQ(4, mannager.keyPointCount());
	delete WR3Extra;

	mannager.addKeyPoint(WR[4],380,230);
	EXPECT_EQ(5, mannager.keyPointCount());
	EXPECT_THROW(mannager.addKeyPoint(WR[5],300,500), PoolKeyPointValidatorError);
	EXPECT_EQ(5, mannager.keyPointCount());
	mannager.addKeyPoint(WR[5],300,499);
	EXPECT_EQ(6, mannager.keyPointCount());
	EXPECT_THROW(mannager.addKeyPoint(WR[6], 500, 499), PoolKeyPointValidatorError);
	EXPECT_EQ(6, mannager.keyPointCount());
	mannager.addKeyPoint(WR[6], 499, 499);
	EXPECT_EQ(7, mannager.keyPointCount());
	EXPECT_THROW(mannager.addKeyPoint(WR[7], 350, 200), PoolKeyPointValidatorError);
	EXPECT_EQ(7, mannager.keyPointCount());
	EXPECT_THROW(mannager.addKeyPoint(WR[8], 350, 200), PoolKeyPointValidatorError);
	EXPECT_EQ(7, mannager.keyPointCount());
	EXPECT_THROW(mannager.addKeyPoint(WR[9], 350, 200), PoolKeyPointValidatorError);
	EXPECT_EQ(7, mannager.keyPointCount());
	EXPECT_THROW(mannager.addKeyPoint(WR[10], 350, 200), PoolKeyPointValidatorError);
	EXPECT_EQ(7, mannager.keyPointCount());

	mannager.addKeyPoint(WR[11], 350, 200);
	EXPECT_EQ(8, mannager.keyPointCount());
	EXPECT_THROW(mannager.addKeyPoint(WR[11], 350, 200), PoolKeyPointValidatorError);
	EXPECT_EQ(8, mannager.keyPointCount());
	mannager.addKeyPoint(WR[12], 350, 200);
	EXPECT_EQ(9, mannager.keyPointCount());
	
	//EXPECT_EQ()
	//EXPECT_THROW()
}


TEST_F(AnnotationDiscriminatorTests, ValidateKeyPointChkNULLTests)
{
	AnnotationDiscriminatorTest testDiscriminator(simple6laneSCMPool, std500SquareFrame);
	std::vector<KeyPointData*> mKeyPoints;
	KeyPointData* WL2 = new WallLeftKeyPoint(2);
	EXPECT_NO_THROW(testDiscriminator.validateKeyPoint(WL2,mKeyPoints));
	delete WL2;
	EXPECT_THROW(testDiscriminator.validateKeyPoint(NULL, mKeyPoints), AnnotationDiscriminatorError);
}


TEST_F(AnnotationDiscriminatorTests, KeyPointPresentTests)
{
	AnnotationDiscriminatorTest testDiscriminator(simple6laneSCMPool, std500SquareFrame);

	std::vector<KeyPointData*> mKeyPoints;
	KeyPointData* FR6 = NULL;
	mKeyPoints.push_back(FR6);
	FR6 = new FloatingRightKeyPoint(6);
	KeyPointData* FL7 = new FloatingLeftKeyPoint(7);
	EXPECT_THROW(testDiscriminator.keyPointPresentTest(FR6, mKeyPoints), AnnotationDiscriminatorError);
	EXPECT_THROW(testDiscriminator.keyPointPresentTest(FL7, mKeyPoints), AnnotationDiscriminatorError);
	mKeyPoints.clear();

	mKeyPoints.push_back(FR6);
	EXPECT_EQ(true, testDiscriminator.keyPointPresentTest(FR6, mKeyPoints));

	//This will crash the test
	//delete FR6;

	mKeyPoints.push_back(FL7);
	KeyPointData* T1 = new WallTopKeyPoint(1);
	EXPECT_EQ(true, testDiscriminator.keyPointPresentTest(FL7, mKeyPoints));
	EXPECT_EQ(false, testDiscriminator.keyPointPresentTest(T1, mKeyPoints));

	delete FR6;
	delete FL7;
	delete T1;
}

*/