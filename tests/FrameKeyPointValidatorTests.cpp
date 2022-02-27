#include "gtest/gtest.h"
#include "AnnotationData.h"
#include "FrameData.h"
#include "FrameKeyPointValidator.h" 


TEST(FrameKeyPointValidatorTests, KeyPointNotInFrameTest)
{
	FrameData testFrame;
	testFrame.setFrameRes(500, 500);
	FrameKeyPointValidator testFrameValidator(testFrame);
	
	WallTopKeyPoint* T7 = new WallTopKeyPoint(7, 500, 499);
	EXPECT_THROW(testFrameValidator.validateKeyPoint(T7), FrameKeyPointValidatorError);
	T7->setPoint(499, 500);
	EXPECT_THROW(testFrameValidator.validateKeyPoint(T7), FrameKeyPointValidatorError);
	T7->setPoint(550, 550);
	EXPECT_THROW(testFrameValidator.validateKeyPoint(T7), FrameKeyPointValidatorError);
	T7->setPoint(0, 0);
	EXPECT_NO_THROW(testFrameValidator.validateKeyPoint(T7));
	delete T7;
}

TEST(FrameKeyPointValidatorTests, KeyPointNullTest)
{
	FrameData testFrame;
	testFrame.setFrameRes(500, 500);
	FrameKeyPointValidator testFrameValidator(testFrame);

	WallTopKeyPoint* T7 = NULL;
	EXPECT_THROW(testFrameValidator.validateKeyPoint(T7), FrameKeyPointValidatorError);
}

TEST(FrameKeyPointValidatorTests, InvalidFrameTest)
{
	FrameData testFrame;
	EXPECT_THROW(FrameKeyPointValidator testFrameValidator(testFrame), FrameKeyPointValidatorError);
}