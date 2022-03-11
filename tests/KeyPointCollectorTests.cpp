#include "gtest/gtest.h"
#include "KeyPointCollector.h"
#include "KeyPointData.h"

TEST(CompositeKeyPointTests, SimpleTest)
{
	KeyPointCollector testCollector;
	KeyPointData* KPdata = nullptr;
	KPdata = new WallBottomKeyPoint(1);
	EXPECT_NO_THROW(testCollector.addKeyPoint(KPdata));
	delete KPdata;

	KPdata = new WallBottomKeyPoint(2);
	EXPECT_NO_THROW(testCollector.addKeyPoint(KPdata));
	EXPECT_NO_THROW(testCollector.addKeyPoint(KPdata));
	delete KPdata;

	KPdata = new WallBottomKeyPoint(2,2,3);
	EXPECT_NO_THROW(testCollector.addKeyPoint(KPdata));
	delete KPdata;

	KPdata = new WallTopKeyPoint(3);
	EXPECT_NO_THROW(testCollector.addKeyPoint(KPdata));
	delete KPdata;

	KPdata = new WallTopKeyPoint(3);
	EXPECT_TRUE(testCollector.hasBeenCollected(KPdata));
	EXPECT_TRUE(testCollector.hasBeenCollected(KPdata));
	delete KPdata;

	KPdata = new WallTopKeyPoint(4);
	EXPECT_FALSE(testCollector.hasBeenCollected(KPdata));
	delete KPdata;
}

TEST(CompositeKeyPointTests, TestThrow)
{
	KeyPointCollector testCollector;
	EXPECT_THROW(testCollector.addKeyPoint(nullptr), KeyPointCollectorError);
}