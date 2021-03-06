#include "gtest/gtest.h"
#include "KeyPointData.h"
#include "PoolData.h"
#include "PoolKeyPointValidator.h" 
#include "PoolConstants.h"

class PoolKeyPointValidatorTestClass : public PoolKeyPointValidator
{
public:
	PoolKeyPointValidatorTestClass(PoolData& inPool) : PoolKeyPointValidator(inPool) {}
	bool keyPointNotInPoolTest(KeyPointData* candidateKeypoint) { return keyPointNotInPool(candidateKeypoint); }
};

class PoolKeyPointValidatorTests : public ::testing::Test {
protected:
	void SetUp() override {
		for (int ii = 0; ii < PoolConstants::maxVerticalPoints; ii++) {
			WL[ii] = new WallLeftKeyPoint(ii);
			WR[ii] = new WallRightKeyPoint(ii);
			FL[ii] = new FloatingLeftKeyPoint(ii);
			FR[ii] = new FloatingRightKeyPoint(ii);
			BR[ii] = new BulkheadRightKeyPoint(ii);
			BL[ii] = new BulkheadLeftKeyPoint(ii);
			if (ii < PoolConstants::maxHorizontalPoints) {
				WT[ii] = new WallTopKeyPoint(ii);
				WB[ii] = new WallBottomKeyPoint(ii);
			}
		}
	}

	void TearDown() override {
		for (int ii = 0; ii < PoolConstants::maxVerticalPoints; ii++) {
			delete WL[ii];
			delete WR[ii];
			delete FL[ii];
			delete FR[ii];
			delete BL[ii];
			delete BR[ii];
			if (ii < PoolConstants::maxHorizontalPoints) {
				delete WT[ii];
				delete WB[ii];
			}
		}
	}

	WallLeftKeyPoint* WL[PoolConstants::maxVerticalPoints]{ nullptr };
	WallRightKeyPoint* WR[PoolConstants::maxVerticalPoints]{ nullptr };
	FloatingLeftKeyPoint* FL[PoolConstants::maxVerticalPoints]{ nullptr };
	FloatingRightKeyPoint* FR[PoolConstants::maxVerticalPoints]{ nullptr };
	WallTopKeyPoint* WT[PoolConstants::maxHorizontalPoints]{ nullptr };
	WallBottomKeyPoint* WB[PoolConstants::maxHorizontalPoints]{ nullptr };
	BulkheadLeftKeyPoint* BL[PoolConstants::maxVerticalPoints]{ nullptr };
	BulkheadRightKeyPoint* BR[PoolConstants::maxVerticalPoints]{ nullptr };
};

TEST_F(PoolKeyPointValidatorTests, KeyPointsIn6LanePoolWithBumpersTest)
{
	PoolData simple6laneSCMPool(true,false,PoolConstants::LCM,PoolConstants::sixLanes);
	PoolKeyPointValidatorTestClass testDiscriminator(simple6laneSCMPool);

	for (int ii = 0; ii < PoolConstants::maxVerticalPoints; ii++) {
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
		EXPECT_EQ(true, testDiscriminator.keyPointNotInPoolTest(BL[ii])) << "keyPoint number is:  " << ii;
		EXPECT_EQ(true, testDiscriminator.keyPointNotInPoolTest(BR[ii])) << "keyPoint number is:  " << ii;
	}
}

TEST_F(PoolKeyPointValidatorTests, KeyPointsIn8LanePoolWithBumpersAndMiddleBulkheadTest)
{
	PoolData simple8laneSCMPool(true, true, PoolConstants::LCM, PoolConstants::eightLanes);
	PoolKeyPointValidatorTestClass testDiscriminator(simple8laneSCMPool);

	for (int ii = 0; ii < PoolConstants::maxVerticalPoints; ii++) {
		if (ii == 9 || ii == 10) {
			EXPECT_EQ(true, testDiscriminator.keyPointNotInPoolTest(WL[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(true, testDiscriminator.keyPointNotInPoolTest(WR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(true, testDiscriminator.keyPointNotInPoolTest(FR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(true, testDiscriminator.keyPointNotInPoolTest(FL[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(true, testDiscriminator.keyPointNotInPoolTest(BL[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(true, testDiscriminator.keyPointNotInPoolTest(BR[ii])) << "keyPoint number is:  " << ii;
		}
		else {
			EXPECT_EQ(false, testDiscriminator.keyPointNotInPoolTest(WL[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(false, testDiscriminator.keyPointNotInPoolTest(WR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(false, testDiscriminator.keyPointNotInPoolTest(FR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(false, testDiscriminator.keyPointNotInPoolTest(FL[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(false, testDiscriminator.keyPointNotInPoolTest(BL[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(false, testDiscriminator.keyPointNotInPoolTest(BR[ii])) << "keyPoint number is:  " << ii;
		}
	}
}

TEST_F(PoolKeyPointValidatorTests, KeyPointsIn10LanePoolNoBumpersAndMiddleBulkheadTest)
{
	PoolData simple10laneSCMPool(false, true, PoolConstants::LCM, PoolConstants::tenLanes);
	PoolKeyPointValidatorTestClass testDiscriminator(simple10laneSCMPool);

	for (int ii = 0; ii < PoolConstants::maxVerticalPoints; ii++) {
		if (ii == 1 || ii == 11) {
			EXPECT_EQ(true, testDiscriminator.keyPointNotInPoolTest(WL[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(true, testDiscriminator.keyPointNotInPoolTest(WR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(true, testDiscriminator.keyPointNotInPoolTest(FR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(true, testDiscriminator.keyPointNotInPoolTest(FL[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(true, testDiscriminator.keyPointNotInPoolTest(BL[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(true, testDiscriminator.keyPointNotInPoolTest(BR[ii])) << "keyPoint number is:  " << ii;
		}
		else {
			EXPECT_EQ(false, testDiscriminator.keyPointNotInPoolTest(WL[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(false, testDiscriminator.keyPointNotInPoolTest(WR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(false, testDiscriminator.keyPointNotInPoolTest(FR[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(false, testDiscriminator.keyPointNotInPoolTest(FL[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(false, testDiscriminator.keyPointNotInPoolTest(BL[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(false, testDiscriminator.keyPointNotInPoolTest(BR[ii])) << "keyPoint number is:  " << ii;
		}
	}
}

TEST_F(PoolKeyPointValidatorTests, KeyPointsIn6LanePoolNoBumpersTest)
{
	PoolData noBumpers6laneSCMPool(false, false, PoolConstants::SCM, PoolConstants::sixLanes);
	PoolKeyPointValidatorTestClass testDiscriminator(noBumpers6laneSCMPool);

	for (int ii = 0; ii < PoolConstants::maxVerticalPoints; ii++) {
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
		EXPECT_EQ(true, testDiscriminator.keyPointNotInPoolTest(BL[ii])) << "keyPoint number is:  " << ii;
		EXPECT_EQ(true, testDiscriminator.keyPointNotInPoolTest(BR[ii])) << "keyPoint number is:  " << ii;
	}
}

TEST_F(PoolKeyPointValidatorTests, KeyPointsInSCMPoolTest)
{
	PoolData simple6laneSCMPool(true, false, PoolConstants::SCM, PoolConstants::sixLanes);
	PoolKeyPointValidatorTestClass testDiscriminator(simple6laneSCMPool);

	for (int ii = 0; ii < PoolConstants::maxHorizontalPoints; ii++) {
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
	PoolData simpleLCMPool(false, false, PoolConstants::LCM, PoolConstants::eightLanes);
	PoolKeyPointValidatorTestClass testDiscriminator(simpleLCMPool);

	for (int ii = 0; ii < PoolConstants::maxHorizontalPoints; ii++) {
		EXPECT_EQ(false, testDiscriminator.keyPointNotInPoolTest(WT[ii])) << "keyPoint number is:  " << ii;
		EXPECT_EQ(false, testDiscriminator.keyPointNotInPoolTest(WB[ii])) << "keyPoint number is:  " << ii;
	}
}

TEST_F(PoolKeyPointValidatorTests, KeyPointsInLCMPoolWithMiddleBulkheadTest)
{
	PoolData simpleLCMPool(false, true, PoolConstants::LCM, PoolConstants::eightLanes);
	PoolKeyPointValidatorTestClass testDiscriminator(simpleLCMPool);

	for (int ii = 0; ii < PoolConstants::maxHorizontalPoints; ii++) {
		if (ii == 4) {
			EXPECT_EQ(true, testDiscriminator.keyPointNotInPoolTest(WT[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(true, testDiscriminator.keyPointNotInPoolTest(WB[ii])) << "keyPoint number is:  " << ii;
		}
		else {
			EXPECT_EQ(false, testDiscriminator.keyPointNotInPoolTest(WT[ii])) << "keyPoint number is:  " << ii;
			EXPECT_EQ(false, testDiscriminator.keyPointNotInPoolTest(WB[ii])) << "keyPoint number is:  " << ii;
		}
	}
}

/* // cant be done without error
TEST_F(PoolKeyPointValidatorTests, InvalidPoolTest)
{
	PoolData noBumpers6laneSCMPool;
	EXPECT_THROW(PoolKeyPointValidatorTestClass testDiscriminator(simpleLCMPool), PoolKeyPointValidatorError);
}
*/

TEST_F(PoolKeyPointValidatorTests, InvalidKeyPointTest)
{
	PoolData simpleLCMPool(false, true, PoolConstants::LCM, PoolConstants::eightLanes);
	PoolKeyPointValidatorTestClass testDiscriminator(simpleLCMPool);

	KeyPointData* WL9 = nullptr;
	EXPECT_THROW(testDiscriminator.validateKeyPoint(WL9), PoolKeyPointValidatorError);
	WL9 = new WallLeftKeyPoint(9);
	EXPECT_FALSE(testDiscriminator.validateKeyPoint(WL9));
	delete WL9;
}

TEST_F(PoolKeyPointValidatorTests, TestDeepCopy)
{
	PoolData simpleLCMPool(false, true, PoolConstants::LCM, PoolConstants::tenLanes);
	PoolKeyPointValidatorTestClass testDiscriminator(simpleLCMPool);

	KeyPointData* WL9 = new WallLeftKeyPoint(9);
	EXPECT_TRUE(testDiscriminator.validateKeyPoint(WL9));

	std::vector<KeyPointData*> testCopy = testDiscriminator.getCopyOfPoolModel();
	for (std::size_t ii = 0; ii < testCopy.size(); ii++)
		EXPECT_NO_THROW(delete testCopy[ii]);

	EXPECT_TRUE(testDiscriminator.validateKeyPoint(WL9));
	delete WL9;
}
