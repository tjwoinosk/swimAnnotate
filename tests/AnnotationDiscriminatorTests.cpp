#include "gtest/gtest.h"
#include "AnnotationData.h"
#include "PoolData.h"
#include "FrameData.h"
#include "AnnotationDiscriminator.h"

class AnnotationDiscriminatorTest : public AnnotationDiscriminator
{
public:
	AnnotationDiscriminatorTest(PoolData& inPool, FrameData& inFrame) : AnnotationDiscriminator(inPool, inFrame) {}
	bool keyPointPresentTest(KeyPointData* candidateKeypoint, const std::vector<KeyPointData*>& mannagersList) { return keyPointIsPresent(candidateKeypoint, mannagersList); }
	bool keyPointNotInFrameTest(KeyPointData* candidateKeypoint) { return keyPointNotInFrame(candidateKeypoint); }
	bool keyPointInPoolTest(KeyPointData* candidateKeypoint) { return keyPointInPool(candidateKeypoint); }
};

class AnnotationDiscriminatorTests : public ::testing::Test {
protected:
	void SetUp() override {
		simple6laneSCMPool.specifyBumpers(true);
		simple6laneSCMPool.setLengthPool(25);
		simple6laneSCMPool.setNumberLanes(6);
		std500SquareFrame.setFrameRes(500, 500);

		for (int ii = 0; ii < totalNumberVerticalPoints; ii++) {
			WL[ii] = new WallLeftKeyPoint(ii);
			WR[ii] = new WallRightKeyPoint(ii);
			FL[ii] = new FloatingLeftKeyPoint(ii);
			FR[ii] = new FloatingRightKeyPoint(ii);
			if (ii < totalNumberHorazontalWallPoints) {
				WT[ii] = new WallTopKeyPoint(ii);
				WB[ii] = new WallBottomKeyPoint(ii);
			}
		}
	}

	void TearDown() override {
		for (int ii = 0; ii < totalNumberVerticalPoints; ii++) {
			delete WL[ii];
			delete WR[ii];
			delete FL[ii];
			delete FR[ii];
			if (ii < totalNumberHorazontalWallPoints) {
				delete WT[ii];
				delete WB[ii];
			}
		}
	}

	PoolData simple6laneSCMPool;
	FrameData std500SquareFrame;

	static const int totalNumberVerticalPoints{ 13 };
	static const int totalNumberHorazontalWallPoints{ 9 };

	WallLeftKeyPoint* WL[totalNumberVerticalPoints]{ NULL };
	WallRightKeyPoint* WR[totalNumberVerticalPoints]{ NULL };
	FloatingLeftKeyPoint* FL[totalNumberVerticalPoints]{ NULL };
	FloatingRightKeyPoint* FR[totalNumberVerticalPoints]{ NULL };
	WallTopKeyPoint* WT[totalNumberHorazontalWallPoints]{ NULL };
	WallBottomKeyPoint* WB[totalNumberHorazontalWallPoints]{ NULL };
};

TEST_F(AnnotationDiscriminatorTests, KeyPointsIn6LanePoolTest)
{
	AnnotationDiscriminatorTest testDiscriminator(simple6laneSCMPool, std500SquareFrame);

	for (int ii = 0; ii < totalNumberVerticalPoints; ii++) {
		if (ii == 7 || ii == 8 || ii == 9 || ii == 10) {
			EXPECT_EQ(false, testDiscriminator.keyPointInPoolTest(WL[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(false, testDiscriminator.keyPointInPoolTest(WR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(false, testDiscriminator.keyPointInPoolTest(FR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(false, testDiscriminator.keyPointInPoolTest(FL[ii])) << "keyPoint number is:  " << ii;
		}
		else {
			EXPECT_EQ(true, testDiscriminator.keyPointInPoolTest(WL[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(true, testDiscriminator.keyPointInPoolTest(WR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(true, testDiscriminator.keyPointInPoolTest(FR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(true, testDiscriminator.keyPointInPoolTest(FL[ii])) << "keyPoint number is:  " << ii;
		}
	}
}

TEST_F(AnnotationDiscriminatorTests, KeyPointsIn8LanePoolTest)
{
	PoolData simple8laneSCMPool(25, 8, true);
	AnnotationDiscriminatorTest testDiscriminator(simple8laneSCMPool, std500SquareFrame);

	for (int ii = 0; ii < totalNumberVerticalPoints; ii++) {
		if (ii == 9 || ii == 10) {
			EXPECT_EQ(false, testDiscriminator.keyPointInPoolTest(WL[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(false, testDiscriminator.keyPointInPoolTest(WR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(false, testDiscriminator.keyPointInPoolTest(FR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(false, testDiscriminator.keyPointInPoolTest(FL[ii])) << "keyPoint number is:  " << ii;
		}
		else {
			EXPECT_EQ(true, testDiscriminator.keyPointInPoolTest(WL[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(true, testDiscriminator.keyPointInPoolTest(WR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(true, testDiscriminator.keyPointInPoolTest(FR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(true, testDiscriminator.keyPointInPoolTest(FL[ii])) << "keyPoint number is:  " << ii;
		}
	}
}

TEST_F(AnnotationDiscriminatorTests, KeyPointsIn10LanePoolNoBumpersTest)
{
	PoolData simple10laneSCMPool(25, 10, false);
	AnnotationDiscriminatorTest testDiscriminator(simple10laneSCMPool, std500SquareFrame);

	for (int ii = 0; ii < totalNumberVerticalPoints; ii++) {
		if (ii == 1 || ii == 11) {
			EXPECT_EQ(false, testDiscriminator.keyPointInPoolTest(WL[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(false, testDiscriminator.keyPointInPoolTest(WR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(false, testDiscriminator.keyPointInPoolTest(FR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(false, testDiscriminator.keyPointInPoolTest(FL[ii])) << "keyPoint number is:  " << ii;
		}
		else {
			EXPECT_EQ(true, testDiscriminator.keyPointInPoolTest(WL[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(true, testDiscriminator.keyPointInPoolTest(WR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(true, testDiscriminator.keyPointInPoolTest(FR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(true, testDiscriminator.keyPointInPoolTest(FL[ii])) << "keyPoint number is:  " << ii;
		}
	}
}

TEST_F(AnnotationDiscriminatorTests, KeyPointsIn6LanePoolNoBumpersTest)
{
	simple6laneSCMPool.specifyBumpers(false);
	AnnotationDiscriminatorTest testDiscriminator(simple6laneSCMPool, std500SquareFrame);

	for (int ii = 0; ii < totalNumberVerticalPoints; ii++) {
		if (ii == 7 || ii == 8 || ii == 9 || ii == 10 || ii == 1 || ii == 11) {
			EXPECT_EQ(false, testDiscriminator.keyPointInPoolTest(WL[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(false, testDiscriminator.keyPointInPoolTest(WR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(false, testDiscriminator.keyPointInPoolTest(FR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(false, testDiscriminator.keyPointInPoolTest(FL[ii])) << "keyPoint number is:  " << ii;
		}
		else {
			EXPECT_EQ(true, testDiscriminator.keyPointInPoolTest(WL[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(true, testDiscriminator.keyPointInPoolTest(WR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(true, testDiscriminator.keyPointInPoolTest(FR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(true, testDiscriminator.keyPointInPoolTest(FL[ii])) << "keyPoint number is:  " << ii;
		}
	}
}

TEST_F(AnnotationDiscriminatorTests, KeyPointsInSCMPoolTest)
{
	AnnotationDiscriminatorTest testDiscriminator(simple6laneSCMPool, std500SquareFrame);

	for (int ii = 0; ii < totalNumberHorazontalWallPoints; ii++) {
		if (ii == 2 || ii == 3 || ii == 4 || ii == 5 || ii == 6) {
			EXPECT_EQ(false, testDiscriminator.keyPointInPoolTest(WT[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(false, testDiscriminator.keyPointInPoolTest(WB[ii])) << "keyPoint number is:  " << ii;
		}
		else {
			EXPECT_EQ(true, testDiscriminator.keyPointInPoolTest(WT[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(true, testDiscriminator.keyPointInPoolTest(WB[ii])) << "keyPoint number is:  " << ii;
		}
	}
}

TEST_F(AnnotationDiscriminatorTests, KeyPointsInLCMPoolTest)
{
	PoolData simpleLCMPool(50, 8, false);
	AnnotationDiscriminatorTest testDiscriminator(simpleLCMPool, std500SquareFrame);

	for (int ii = 0; ii < totalNumberHorazontalWallPoints; ii++) {
		EXPECT_EQ(true, testDiscriminator.keyPointInPoolTest(WT[ii])) << "keyPoint number is:  " << ii;
		EXPECT_EQ(true, testDiscriminator.keyPointInPoolTest(WB[ii])) << "keyPoint number is:  " << ii;
	}
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


TEST_F(AnnotationDiscriminatorTests, KeyPointNotInFrameTest)
{
	AnnotationDiscriminatorTest testDiscriminator(simple6laneSCMPool, std500SquareFrame);

	WallTopKeyPoint* T7 = new WallTopKeyPoint(7,500,499);
	EXPECT_EQ(true, testDiscriminator.keyPointNotInFrameTest(T7));
	T7->setPoint(499, 500);
	EXPECT_EQ(true, testDiscriminator.keyPointNotInFrameTest(T7));
	T7->setPoint(550, 550);
	EXPECT_EQ(true, testDiscriminator.keyPointNotInFrameTest(T7));
	T7->setPoint(0, 0);
	EXPECT_EQ(false, testDiscriminator.keyPointNotInFrameTest(T7));
	delete T7;
}