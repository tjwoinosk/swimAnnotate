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
	KeyPointData* FL8 = new FloatingLeftKeyPoint(8, 299, 300);
	FL8 = validator.validateKeyPoint(FL8);
	EXPECT_EQ(0, FL8->getXPoint());
	EXPECT_EQ(300, FL8->getYPoint());
	delete FL8;

	//x<300 && y=x
	KeyPointData* FL6 = new FloatingLeftKeyPoint(6, 299, 299);
	FL6 = validator.validateKeyPoint(FL6);
	EXPECT_EQ(299, FL6->getXPoint());
	EXPECT_EQ(0, FL6->getYPoint());
	delete FL6;

	//x=300 && y>x
	KeyPointData* FL5 = new FloatingLeftKeyPoint(5, 300, 301);
	FL5 = validator.validateKeyPoint(FL5);
	EXPECT_EQ(0, FL5->getXPoint());
	EXPECT_EQ(301, FL5->getYPoint());
	delete FL5;

	//x=300 && y=x
	KeyPointData* FL3 = new FloatingLeftKeyPoint(3, 300, 300);
	FL3 = validator.validateKeyPoint(FL3);
	EXPECT_EQ(300, FL3->getXPoint());
	EXPECT_EQ(0, FL3->getYPoint());
	delete FL3;

	//x>300 && y<x
	KeyPointData* FL1 = new FloatingLeftKeyPoint(1, 301, 300);
	FL1 = validator.validateKeyPoint(FL1);
	EXPECT_EQ(601, FL1->getXPoint());
	EXPECT_EQ(300, FL1->getYPoint());
	delete FL1;

	//x>300 && y<x
	KeyPointData* FL2 = new FloatingLeftKeyPoint(2, 301, 299);
	FL2 = validator.validateKeyPoint(FL2);
	EXPECT_EQ(301, FL2->getXPoint());
	EXPECT_EQ(0, FL2->getYPoint());
	delete FL2;

	KeyPointData* FL0 = new FloatingLeftKeyPoint(0, 299, 897);
	FL0 = validator.validateKeyPoint(FL0);
	EXPECT_EQ(0, FL0->getXPoint());
	EXPECT_EQ(897, FL0->getYPoint());
	delete FL0;
}

TEST(FrameKeyPointValidatorTests, RightFloatingToRightBoarderTest)
{
	FrameData testFrame;
	testFrame.setFrameRes(601, 1000);
	FrameKeyPointValidator validator(testFrame);

	KeyPointData* FR8 = new FloatingRightKeyPoint(8, 299, 699);
	FR8 = validator.validateKeyPoint(FR8);
	EXPECT_EQ(0, FR8->getXPoint());
	EXPECT_EQ(699, FR8->getYPoint());
	delete FR8;

	KeyPointData* FR6 = new FloatingRightKeyPoint(6, 299, 700);
	FR6 = validator.validateKeyPoint(FR6);
	EXPECT_EQ(299, FR6->getXPoint());
	EXPECT_EQ(1000, FR6->getYPoint());
	delete FR6;

	KeyPointData* FR5 = new FloatingRightKeyPoint(5, 300, 698);
	FR5 = validator.validateKeyPoint(FR5);
	EXPECT_EQ(0, FR5->getXPoint());
	EXPECT_EQ(698, FR5->getYPoint());
	delete FR5;

	KeyPointData* FR3 = new FloatingRightKeyPoint(3, 300, 699);
	FR3 = validator.validateKeyPoint(FR3);
	EXPECT_EQ(300, FR3->getXPoint());
	EXPECT_EQ(1000, FR3->getYPoint());
	delete FR3;

	KeyPointData* FR1 = new FloatingRightKeyPoint(1, 301, 699);
	FR1 = validator.validateKeyPoint(FR1);
	EXPECT_EQ(601, FR1->getXPoint());
	EXPECT_EQ(699, FR1->getYPoint());
	delete FR1;

	KeyPointData* FR2 = new FloatingRightKeyPoint(2, 301, 700);
	FR2 = validator.validateKeyPoint(FR2);
	EXPECT_EQ(301, FR2->getXPoint());
	EXPECT_EQ(1000, FR2->getYPoint());
	delete FR2;

	KeyPointData* FR0 = new FloatingRightKeyPoint(0, 301, 200);
	FR0 = validator.validateKeyPoint(FR0);
	EXPECT_EQ(601, FR0->getXPoint());
	EXPECT_EQ(200, FR0->getYPoint());
	delete FR0;
}

TEST(FrameKeyPointValidatorTests, ValidatorOnlyChangesFloatingPoints)
{
	FrameData testFrame;
	testFrame.setFrameRes(601, 1000);
	FrameKeyPointValidator validator(testFrame);

	KeyPointData* FL2 = new FloatingLeftKeyPoint(2, 301, 299);
	FL2 = validator.validateKeyPoint(FL2);
	EXPECT_EQ(301, FL2->getXPoint());
	EXPECT_EQ(0, FL2->getYPoint());
	delete FL2;

	KeyPointData* FR0 = new FloatingRightKeyPoint(0, 301, 200);
	FR0 = validator.validateKeyPoint(FR0);
	EXPECT_EQ(601, FR0->getXPoint());
	EXPECT_EQ(200, FR0->getYPoint());
	delete FR0;

	KeyPointData* pnt = NULL;
	pnt = new WallRightKeyPoint(0, 356, 224);
	pnt = validator.validateKeyPoint(pnt);
	EXPECT_EQ(356, pnt->getXPoint());
	EXPECT_EQ(224, pnt->getYPoint());
	delete pnt;

	pnt = new WallLeftKeyPoint(0, 356, 224);
	pnt = validator.validateKeyPoint(pnt);
	EXPECT_EQ(356, pnt->getXPoint());
	EXPECT_EQ(224, pnt->getYPoint());
	delete pnt;

	pnt = new BulkheadLeftKeyPoint(0, 356, 224);
	pnt = validator.validateKeyPoint(pnt);
	EXPECT_EQ(356, pnt->getXPoint());
	EXPECT_EQ(224, pnt->getYPoint());
	delete pnt;

	pnt = new BulkheadRightKeyPoint(0, 356, 224);
	pnt = validator.validateKeyPoint(pnt);
	EXPECT_EQ(356, pnt->getXPoint());
	EXPECT_EQ(224, pnt->getYPoint());
	delete pnt;

	pnt = new WallTopKeyPoint(0, 356, 224);
	pnt = validator.validateKeyPoint(pnt);
	EXPECT_EQ(356, pnt->getXPoint());
	EXPECT_EQ(224, pnt->getYPoint());
	delete pnt;

	pnt = new WallBottomKeyPoint(0, 356, 224);
	pnt = validator.validateKeyPoint(pnt);
	EXPECT_EQ(356, pnt->getXPoint());
	EXPECT_EQ(224, pnt->getYPoint());
	delete pnt;
}