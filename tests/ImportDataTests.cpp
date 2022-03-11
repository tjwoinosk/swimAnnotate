#include "gtest/gtest.h"

#include "ImportData.h"
#include "PoolConstants.h"

#include "ExportConstants.h"

#include "KeyPointData.h"
#include "PoolData.h"
#include "FrameData.h"

TEST(ImportDataTests, SimpleReadFormattedPoolString)
{
	ImportData dataExporter("Some/Destination");
	std::string inputFormat{ "PoolData,Length Pool,25,Number Lanes,8,Bumpers,true,Middle Bulkhead,false" };
	PoolData poolData;

	poolData = dataExporter.readPoolData(inputFormat);

	EXPECT_EQ(PoolConstants::SCM, poolData.getLengthPool());
	EXPECT_EQ(PoolConstants::eightLanes, poolData.getNumberLanes());
	EXPECT_TRUE(poolData.poolHasbumpers());
	EXPECT_FALSE(poolData.poolHasMiddleBulkhead());
}

TEST(ImportDataTests, SimpleReadFormattedKeyPointString)
{
	ImportData dataExporter("Some/Destination");
	std::string inputFormat{ "KPData,WT3,498,44" };

	KeyPointData* keyPoint = dataExporter.readKeyPointData(inputFormat);

	ASSERT_NE(nullptr, keyPoint);
	EXPECT_EQ("WT3", keyPoint->getObjectID());
	EXPECT_EQ(498, keyPoint->getXPoint());
	EXPECT_EQ(44, keyPoint->getYPoint());
	delete keyPoint;
}

TEST(ImportDataTests, SimpleReadFormattedFrameString)
{
	ImportData dataExporter("Some/Destination");
	std::string inputFormat{ "FrameData,File Name,readTest.jpg,Frame Resolution,555,666" };
	FrameData frame;

	frame = dataExporter.readFrameData(inputFormat);

	EXPECT_TRUE(frame.isDefined());
	EXPECT_EQ("readTest.jpg", frame.getFrameName());
	EXPECT_EQ(555, frame.getFrameHeight());
	EXPECT_EQ(666, frame.getFrameWidth());
}

TEST(ImportDataTests, TestTokenizer)
{
	ImportData dataExporter("Some/Destination");
	std::vector<std::string> tokens{};

	tokens = dataExporter.tokenizeString("");
	EXPECT_EQ(0, tokens.size());
	tokens.clear();

	tokens = dataExporter.tokenizeString(",");
	EXPECT_EQ(0, tokens.size());
	tokens.clear();

	tokens = dataExporter.tokenizeString(",a,");
	EXPECT_EQ(1, tokens.size());
	tokens.clear();

	tokens = dataExporter.tokenizeString("a");
	EXPECT_EQ(1, tokens.size());
	tokens.clear();

	tokens = dataExporter.tokenizeString("a,b");
	EXPECT_EQ(2, tokens.size());
	tokens.clear();

	tokens = dataExporter.tokenizeString(",File Name,readTest.jpg,Frame Resolution,555,");
	EXPECT_EQ(4, tokens.size());
	tokens.clear();

	tokens = dataExporter.tokenizeString(",File Name,readTest.jpg,Frame Resolution,555,666");
	EXPECT_EQ(5, tokens.size());
	tokens.clear();

	tokens = dataExporter.tokenizeString("FrameData,File Name,readTest.jpg,Frame Resolution,555,666");
	EXPECT_EQ(6, tokens.size());
}

