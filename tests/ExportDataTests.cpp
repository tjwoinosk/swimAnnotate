#include "gtest/gtest.h"

#include "ExportData.h"
#include "PoolConstants.h"
#include "ExportConstants.h"

#include "KeyPointData.h"
#include "PoolData.h"
#include "FrameData.h"

TEST(ExportDataTests, NullptrTests)
{
	ExportData dataExporter("Some/Destination");
	FrameData frameTest;
	PoolData poolTest;
	EXPECT_EQ("No Frame Data Found",dataExporter.formatFrameData(frameTest));
	EXPECT_EQ("No Key Point Data Found",dataExporter.formatKeyPointData(nullptr));
	EXPECT_EQ("No Pool Data Found",dataExporter.formatPoolData(poolTest));
}

TEST(ExportDataTests, SimpleFormatFrameData)
{
	ExportData dataExporter("Some/Destination");

	FrameData frame;
	frame.setFrameRes(300,400);
	frame.setFrameName("TestPool1.jpg");

	std::string expectedFormat{ "FrameData,File Name,TestPool1.jpg,Frame Resolution,300,400" };
	EXPECT_EQ(expectedFormat, dataExporter.formatFrameData(frame));
}

TEST(ExportDataTests, SimpleFormatPoolData)
{
	ExportData dataExporter("Some/Destination");
	PoolData pool(true, true, PoolConstants::LCM, PoolConstants::eightLanes);

	std::string expectedFormat{ "PoolData,Length Pool,50,Number Lanes,8,Bumpers,true,Middle Bulkhead,true" };

	EXPECT_EQ(expectedFormat, dataExporter.formatPoolData(pool));
}

TEST(ExportDataTests, SimpleFormatKeyPointData)
{
	ExportData dataExporter("Some/Destination");
	KeyPointData* keyPointData = new WallLeftKeyPoint(1,498,44);

	std::string expectedFormat{ "KPData,WL1,498,44" };

	EXPECT_EQ(expectedFormat, dataExporter.formatKeyPointData(keyPointData));
}
