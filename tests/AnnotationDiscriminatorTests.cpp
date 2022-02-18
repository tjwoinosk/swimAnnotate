#include "gtest/gtest.h"
#include "AnnotationData.h"
#include "PoolData.h"
#include "FrameData.h"
#include "AnnotationDiscriminator.h"

TEST(AnnotationDiscriminatorTests, KeyPointPresentBasicTest)
{
	std::vector<KeyPointData*> mKeyPoints;
	KeyPointData* FR6 = new FloatingRightKeyPoint(6);
	KeyPointData* FL7 = new FloatingLeftKeyPoint(7);
	//KeyPointData* T1 = new WallTopKeyPoint()


	KeyPointData* B2 = new WallBottomKeyPoint;
}


TEST(AnnotationDiscriminatorTests, KeyPointNotInFrameTest)
{

}

TEST(AnnotationDiscriminatorTests, KeyPointNotInPoolTests)
{

}