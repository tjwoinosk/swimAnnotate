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

TEST(FrameKeyPointValidatorTests, LeftFloatingToLeftBoarderTest)
{
	FrameData testFrame;
	testFrame.setFrameRes(601, 1000);
	FrameKeyPointValidator validator(testFrame);

	//x<300 && y>x
	KeyPointData* FL8 = new FloatingLeftKeyPoint(8, 285, 290);
	FL8 = validator.validateKeyPoint(FL8);
	EXPECT_EQ(0, FL8->getXPoint());
	EXPECT_EQ(290, FL8->getYPoint());

	//x<300 && y<x
	KeyPointData* FL7 = new FloatingLeftKeyPoint(7, 299, 233);
	FL7 = validator.validateKeyPoint(FL7);
	EXPECT_EQ(299, FL7->getXPoint());
	EXPECT_EQ(0, FL7->getYPoint());

	//x<300 && y=x
	KeyPointData* FL6 = new FloatingLeftKeyPoint(6, 299, 299);
	FL6 = validator.validateKeyPoint(FL6);
	EXPECT_EQ(299, FL6->getXPoint());
	EXPECT_EQ(0, FL6->getYPoint());

	//x=300 && y>x
	KeyPointData* FL5 = new FloatingLeftKeyPoint(5, 300, 301);
	FL5 = validator.validateKeyPoint(FL5);
	EXPECT_EQ(0, FL5->getXPoint());
	EXPECT_EQ(301, FL5->getYPoint());

	//x=300 && y<x
	KeyPointData* FL4 = new FloatingLeftKeyPoint(4, 300, 299);
	FL4 = validator.validateKeyPoint(FL4);
	EXPECT_EQ(300, FL4->getXPoint());
	EXPECT_EQ(0, FL4->getYPoint());

	//x=300 && y=x
	KeyPointData* FL3 = new FloatingLeftKeyPoint(3, 300, 300);
	FL3 = validator.validateKeyPoint(FL3);
	EXPECT_EQ(300, FL3->getXPoint());
	EXPECT_EQ(0, FL3->getYPoint());

	//x>300 && y>x
	KeyPointData* FL2 = new FloatingLeftKeyPoint(2, 355, 455);
	FL2 = validator.validateKeyPoint(FL2);
	EXPECT_EQ(601, FL2->getXPoint());
	EXPECT_EQ(455, FL2->getYPoint());

	//x>300 && y<x
	KeyPointData* FL1 = new FloatingLeftKeyPoint(1, 301, 300);
	FL1 = validator.validateKeyPoint(FL1);
	EXPECT_EQ(601, FL1->getXPoint());
	EXPECT_EQ(300, FL1->getYPoint());

	//x>300 && y=x
	KeyPointData* FL0 = new FloatingLeftKeyPoint(0, 301, 301);
	FL0 = validator.validateKeyPoint(FL0);
	EXPECT_EQ(601, FL0->getXPoint());
	EXPECT_EQ(301, FL0->getYPoint());

}