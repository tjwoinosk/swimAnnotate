#include "gtest/gtest.h"
#include "AnnotationData.h"
#include "PoolData.h"
#include "PoolKeyPointValidator.h" 

class PoolKeyPointValidatorTestClass : public PoolKeyPointValidator
{
public:
	PoolKeyPointValidatorTestClass(PoolData& inPool) : PoolKeyPointValidator(inPool) {}
	bool keyPointNotInPoolTest(KeyPointData* candidateKeypoint) { return keyPointNotInPool(candidateKeypoint); }
};

class PoolKeyPointValidatorTests : public ::testing::Test {
protected:
	void SetUp() override {
		simple6laneSCMPool.specifyBumpers(true);
		simple6laneSCMPool.setLengthPool(25);
		simple6laneSCMPool.setNumberLanes(6);

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

	static const int totalNumberVerticalPoints{ 13 };
	static const int totalNumberHorazontalWallPoints{ 9 };

	WallLeftKeyPoint* WL[totalNumberVerticalPoints]{ NULL };
	WallRightKeyPoint* WR[totalNumberVerticalPoints]{ NULL };
	FloatingLeftKeyPoint* FL[totalNumberVerticalPoints]{ NULL };
	FloatingRightKeyPoint* FR[totalNumberVerticalPoints]{ NULL };
	WallTopKeyPoint* WT[totalNumberHorazontalWallPoints]{ NULL };
	WallBottomKeyPoint* WB[totalNumberHorazontalWallPoints]{ NULL };
};

TEST_F(PoolKeyPointValidatorTests, KeyPointsIn6LanePoolTest)
{
	PoolKeyPointValidatorTestClass testDiscriminator(simple6laneSCMPool);

	for (int ii = 0; ii < totalNumberVerticalPoints; ii++) {
		if (ii == 7 || ii == 8 || ii == 9 || ii == 10) {
			EXPECT_EQ(true, testDiscriminator.keyPointNotInPoolTest(WL[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(true, testDiscriminator.keyPointNotInPoolTest(WR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(true, testDiscriminator.keyPointNotInPoolTest(FR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(true, testDiscriminator.keyPointNotInPoolTest(FL[ii])) << "keyPoint number is:  " << ii;
		}
		else {
			EXPECT_EQ(false, testDiscriminator.keyPointNotInPoolTest(WL[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(false, testDiscriminator.keyPointNotInPoolTest(WR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(false, testDiscriminator.keyPointNotInPoolTest(FR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(false, testDiscriminator.keyPointNotInPoolTest(FL[ii])) << "keyPoint number is:  " << ii;
		}
	}
}

TEST_F(PoolKeyPointValidatorTests, KeyPointsIn8LanePoolTest)
{
	PoolData simple8laneSCMPool(25, 8, true);
	PoolKeyPointValidatorTestClass testDiscriminator(simple8laneSCMPool);

	for (int ii = 0; ii < totalNumberVerticalPoints; ii++) {
		if (ii == 9 || ii == 10) {
			EXPECT_EQ(true, testDiscriminator.keyPointNotInPoolTest(WL[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(true, testDiscriminator.keyPointNotInPoolTest(WR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(true, testDiscriminator.keyPointNotInPoolTest(FR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(true, testDiscriminator.keyPointNotInPoolTest(FL[ii])) << "keyPoint number is:  " << ii;
		}
		else {
			EXPECT_EQ(false, testDiscriminator.keyPointNotInPoolTest(WL[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(false, testDiscriminator.keyPointNotInPoolTest(WR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(false, testDiscriminator.keyPointNotInPoolTest(FR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(false, testDiscriminator.keyPointNotInPoolTest(FL[ii])) << "keyPoint number is:  " << ii;
		}
	}
}

TEST_F(PoolKeyPointValidatorTests, KeyPointsIn10LanePoolNoBumpersTest)
{
	PoolData simple10laneSCMPool(25, 10, false);
	PoolKeyPointValidatorTestClass testDiscriminator(simple10laneSCMPool);

	for (int ii = 0; ii < totalNumberVerticalPoints; ii++) {
		if (ii == 1 || ii == 11) {
			EXPECT_EQ(true, testDiscriminator.keyPointNotInPoolTest(WL[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(true, testDiscriminator.keyPointNotInPoolTest(WR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(true, testDiscriminator.keyPointNotInPoolTest(FR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(true, testDiscriminator.keyPointNotInPoolTest(FL[ii])) << "keyPoint number is:  " << ii;
		}
		else {
			EXPECT_EQ(false, testDiscriminator.keyPointNotInPoolTest(WL[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(false, testDiscriminator.keyPointNotInPoolTest(WR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(false, testDiscriminator.keyPointNotInPoolTest(FR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(false, testDiscriminator.keyPointNotInPoolTest(FL[ii])) << "keyPoint number is:  " << ii;
		}
	}
}

TEST_F(PoolKeyPointValidatorTests, KeyPointsIn6LanePoolNoBumpersTest)
{
	simple6laneSCMPool.specifyBumpers(false);
	PoolKeyPointValidatorTestClass testDiscriminator(simple6laneSCMPool);

	for (int ii = 0; ii < totalNumberVerticalPoints; ii++) {
		if (ii == 7 || ii == 8 || ii == 9 || ii == 10 || ii == 1 || ii == 11) {
			EXPECT_EQ(true, testDiscriminator.keyPointNotInPoolTest(WL[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(true, testDiscriminator.keyPointNotInPoolTest(WR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(true, testDiscriminator.keyPointNotInPoolTest(FR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(true, testDiscriminator.keyPointNotInPoolTest(FL[ii])) << "keyPoint number is:  " << ii;
		}
		else {
			EXPECT_EQ(false, testDiscriminator.keyPointNotInPoolTest(WL[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(false, testDiscriminator.keyPointNotInPoolTest(WR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(false, testDiscriminator.keyPointNotInPoolTest(FR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(false, testDiscriminator.keyPointNotInPoolTest(FL[ii])) << "keyPoint number is:  " << ii;
		}
	}
}

TEST_F(PoolKeyPointValidatorTests, KeyPointsInSCMPoolTest)
{
	PoolKeyPointValidatorTestClass testDiscriminator(simple6laneSCMPool);

	for (int ii = 0; ii < totalNumberHorazontalWallPoints; ii++) {
		if (ii == 2 || ii == 3 || ii == 4 || ii == 5 || ii == 6) {
			EXPECT_EQ(true, testDiscriminator.keyPointNotInPoolTest(WT[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(true, testDiscriminator.keyPointNotInPoolTest(WB[ii])) << "keyPoint number is:  " << ii;
		}
		else {
			EXPECT_EQ(false, testDiscriminator.keyPointNotInPoolTest(WT[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(false, testDiscriminator.keyPointNotInPoolTest(WB[ii])) << "keyPoint number is:  " << ii;
		}
	}
}

TEST_F(PoolKeyPointValidatorTests, KeyPointsInLCMPoolTest)
{
	PoolData simpleLCMPool(50, 8, false);
	PoolKeyPointValidatorTestClass testDiscriminator(simpleLCMPool);

	for (int ii = 0; ii < totalNumberHorazontalWallPoints; ii++) {
		EXPECT_EQ(false, testDiscriminator.keyPointNotInPoolTest(WT[ii])) << "keyPoint number is:  " << ii;
		EXPECT_EQ(false, testDiscriminator.keyPointNotInPoolTest(WB[ii])) << "keyPoint number is:  " << ii;
	}
}

TEST_F(PoolKeyPointValidatorTests, InvalidPoolTest)
{
	PoolData simpleLCMPool;
	EXPECT_THROW(PoolKeyPointValidatorTestClass testDiscriminator(simpleLCMPool), PoolKeyPointValidatorError);
}

TEST_F(PoolKeyPointValidatorTests, InvalidKeyPointTest)
{
	PoolData simpleLCMPool(50, 8, false);
	PoolKeyPointValidatorTestClass testDiscriminator(simpleLCMPool);

	KeyPointData* WL9 = NULL;
	EXPECT_THROW(testDiscriminator.validateKeyPoint(WL9), PoolKeyPointValidatorError);
	WL9 = new WallLeftKeyPoint(9);
	EXPECT_THROW(testDiscriminator.validateKeyPoint(WL9), PoolKeyPointValidatorError);
	delete WL9;
}