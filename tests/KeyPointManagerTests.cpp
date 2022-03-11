#include "gtest/gtest.h"
#include "KeyPointManager.h"
#include "KeyPointData.h"
#include "PoolData.h"
#include "PoolConstants.h"

#include <vector>

TEST(KeyPointManagerTests, SimpleAddKeyPointTest)
{
	PoolData simple8laneSCMPool(false, false, PoolConstants::SCM, PoolConstants::eightLanes);
	KeyPointManager manager(simple8laneSCMPool);
	EXPECT_EQ(0, manager.keyPointCount());
	KeyPointData* inputData = nullptr;
	
	inputData = new WallLeftKeyPoint(3);
	EXPECT_NO_THROW(manager.addKeyPoint(inputData));
	EXPECT_EQ(1, manager.keyPointCount());
	delete inputData;

	inputData = new WallRightKeyPoint(2);
	EXPECT_NO_THROW(manager.addKeyPoint(inputData));
	EXPECT_EQ(2, manager.keyPointCount());
	delete inputData;

	EXPECT_THROW(manager.addKeyPoint(nullptr), KeyPointManagerError);
	EXPECT_EQ(2, manager.keyPointCount());
}

TEST(KeyPointManagerTests, RepeateKeyPointTest)
{
	PoolData simple8laneSCMPool(false, false, PoolConstants::SCM, PoolConstants::eightLanes);
	KeyPointManager manager(simple8laneSCMPool);
	KeyPointData* inputData = nullptr;

	inputData = new BulkheadLeftKeyPoint(2);
	EXPECT_NO_THROW(manager.addKeyPoint(inputData));
	EXPECT_EQ(1, manager.keyPointCount());
	delete inputData;

	KeyPointData* repeatePoint = new BulkheadLeftKeyPoint(2);
	EXPECT_THROW(manager.addKeyPoint(repeatePoint), KeyPointManagerError);
	EXPECT_EQ(1, manager.keyPointCount());
	delete repeatePoint;

	inputData = new WallLeftKeyPoint(2);
	manager.addKeyPoint(inputData);
	EXPECT_EQ(2, manager.keyPointCount());
	delete inputData;
}

TEST(KeyPointManagerTests, GetKeyPointTest)
{
	PoolData simple8laneSCMPool(false, false, PoolConstants::SCM, PoolConstants::eightLanes);
	KeyPointManager manager(simple8laneSCMPool);

	WallRightKeyPoint* test = new WallRightKeyPoint(2, 10, 20);
	EXPECT_EQ(nullptr, manager.getKeyPoint("WR2"));
	EXPECT_NO_THROW(manager.addKeyPoint(test));
	EXPECT_TRUE(manager.getKeyPoint("WR2")->isTheSamePointAs(test));
	delete test;
	EXPECT_EQ(nullptr, manager.getKeyPoint("WR1"));
}

TEST(KeyPointManagerTests, hardAddkeyPointTest)
{
	PoolData simple8laneSCMPool(false, false, PoolConstants::SCM, PoolConstants::eightLanes);
	KeyPointManager manager(simple8laneSCMPool);

	KeyPointData* addData = new WallRightKeyPoint(2, 10, 20);
	EXPECT_NO_THROW(manager.hardAddKeyPoint(addData));
	delete addData;
	EXPECT_EQ(1, manager.keyPointCount());

	KeyPointData* test = new WallRightKeyPoint(2, 10, 30);
	EXPECT_NO_THROW(manager.hardAddKeyPoint(test));
	EXPECT_EQ(1, manager.keyPointCount());
	EXPECT_TRUE(manager.getKeyPoint("WR2")->isTheSamePointAs(test));
	delete test;

	addData = new WallRightKeyPoint(3);
	EXPECT_NO_THROW(manager.hardAddKeyPoint(addData));
	delete addData;
	EXPECT_EQ(2, manager.keyPointCount());
}

TEST(KeyPointManagerTests, AddFloatingConflict)
{
	PoolData simple8laneSCMPool(true, false, PoolConstants::SCM, PoolConstants::eightLanes);
	KeyPointManager manager(simple8laneSCMPool);

	KeyPointData* addData = nullptr;

	addData = new WallLeftKeyPoint(1);
	EXPECT_NO_THROW(manager.addKeyPoint(addData));
	delete addData;
	addData = new WallRightKeyPoint(0);
	EXPECT_NO_THROW(manager.addKeyPoint(addData));
	delete addData;

	FloatingLeftKeyPoint* FL1 = new FloatingLeftKeyPoint(1);
	EXPECT_THROW(manager.addKeyPoint(FL1), KeyPointManagerError);
	delete FL1;
	EXPECT_EQ(2, manager.keyPointCount());

	FloatingRightKeyPoint* FR0 = new FloatingRightKeyPoint(0);
	EXPECT_THROW(manager.addKeyPoint(FR0), KeyPointManagerError);
	delete FR0;
	EXPECT_EQ(2, manager.keyPointCount());
}

TEST(KeyPointManagerTests, HardAddFloatingConflict)
{
	PoolData simple8laneSCMPool(true, false, PoolConstants::SCM, PoolConstants::eightLanes);
	KeyPointManager manager(simple8laneSCMPool);
	KeyPointData* addData = nullptr;

	addData = new WallLeftKeyPoint(1);
	EXPECT_NO_THROW(manager.addKeyPoint(addData));
	delete addData;
	
	addData = new WallRightKeyPoint(0);
	EXPECT_NO_THROW(manager.addKeyPoint(addData));
	delete addData;

	addData = new FloatingLeftKeyPoint(1);
	EXPECT_NO_THROW(manager.hardAddKeyPoint(addData));
	delete addData;
	EXPECT_EQ(2, manager.keyPointCount());

	addData = new FloatingRightKeyPoint(0);
	EXPECT_NO_THROW(manager.hardAddKeyPoint(addData));
	delete addData;
	EXPECT_EQ(2, manager.keyPointCount());
}

TEST(KeyPointManagerTests, AddWallConflict)
{
	PoolData simple8laneSCMPool(true, false, PoolConstants::SCM, PoolConstants::eightLanes);
	KeyPointManager manager(simple8laneSCMPool);
	KeyPointData* addData = nullptr;

	addData = new FloatingLeftKeyPoint(1);
	EXPECT_NO_THROW(manager.addKeyPoint(addData));
	delete addData;
	addData = new FloatingRightKeyPoint(0);
	EXPECT_NO_THROW(manager.addKeyPoint(addData));
	delete addData;

	WallLeftKeyPoint* WL1 = new WallLeftKeyPoint(1);
	EXPECT_THROW(manager.addKeyPoint(WL1), KeyPointManagerError);
	delete WL1;
	EXPECT_EQ(2, manager.keyPointCount());

	WallRightKeyPoint* WR0 = new WallRightKeyPoint(0);
	EXPECT_THROW(manager.addKeyPoint(WR0), KeyPointManagerError);
	delete WR0;
	EXPECT_EQ(2, manager.keyPointCount());
}

TEST(KeyPointManagerTests, HardAddWallConflict)
{
	PoolData simple8laneSCMPool(true, false, PoolConstants::SCM, PoolConstants::eightLanes);
	KeyPointManager manager(simple8laneSCMPool);
	KeyPointData* addData = nullptr;

	addData = new FloatingLeftKeyPoint(1);
	EXPECT_NO_THROW(manager.addKeyPoint(addData));
	delete addData;

	addData = new FloatingRightKeyPoint(0);
	EXPECT_NO_THROW(manager.addKeyPoint(addData));
	delete addData;

	addData = new WallLeftKeyPoint(1);
	EXPECT_NO_THROW(manager.hardAddKeyPoint(addData));
	delete addData;
	EXPECT_EQ(2, manager.keyPointCount());

	addData = new WallRightKeyPoint(0);
	EXPECT_NO_THROW(manager.hardAddKeyPoint(addData));
	delete addData;
	EXPECT_EQ(2, manager.keyPointCount());
}

TEST(KeyPointManagerTests, DeleteKeyPointTest)
{
	PoolData simple8laneSCMPool(true, false, PoolConstants::SCM, PoolConstants::eightLanes);
	KeyPointManager manager(simple8laneSCMPool);
	KeyPointData* addData = nullptr;

	EXPECT_THROW(manager.delKeyPoint(manager.getKeyPoint("FL2")), KeyPointManagerError);
	
	addData = new FloatingLeftKeyPoint(1);
	EXPECT_NO_THROW(manager.addKeyPoint(addData));
	delete addData;

	addData = new FloatingRightKeyPoint(0);
	EXPECT_NO_THROW(manager.addKeyPoint(addData));
	delete addData;

	EXPECT_THROW(manager.delKeyPoint(manager.getKeyPoint("FL3")), KeyPointManagerError);
	EXPECT_EQ(2, manager.keyPointCount());
	EXPECT_NO_THROW(manager.delKeyPoint(manager.getKeyPoint("FL1")));
	EXPECT_EQ(1, manager.keyPointCount());
	EXPECT_NO_THROW(manager.delKeyPoint(manager.getKeyPoint("FR0")));
	EXPECT_EQ(0, manager.keyPointCount());
}

TEST(KeyPointManagerTests, GetCopyOfKeyPointsTest)
{
	PoolData simple8laneSCMPool(true, false, PoolConstants::SCM, PoolConstants::eightLanes);
	KeyPointManager manager(simple8laneSCMPool);
	KeyPointData* addData = nullptr;

	addData = new FloatingLeftKeyPoint(1);
	EXPECT_NO_THROW(manager.addKeyPoint(addData));
	delete addData;
	addData = new WallRightKeyPoint(1);
	EXPECT_NO_THROW(manager.addKeyPoint(addData));
	delete addData;
	addData = new WallTopKeyPoint(1);
	EXPECT_NO_THROW(manager.addKeyPoint(addData));
	delete addData;
	addData = new WallTopKeyPoint(2);
	EXPECT_NO_THROW(manager.addKeyPoint(addData));
	delete addData;

	std::vector<KeyPointData*> manCopy = manager.getCopyOfKeyPoints();
	EXPECT_EQ(4, manCopy.size());

	bool isTrue = false;
	for (int ii = 0; ii < manCopy.size(); ii++) {
		isTrue = true;
		if (manager.getKeyPoint(manCopy[ii]->getObjectID()) == nullptr)
			isTrue = false;
		EXPECT_TRUE(isTrue) << "Key point " << ii << " was not the same.";
	}

	EXPECT_EQ(4, manager.keyPointCount());
	manager.delKeyPoint(manager.getKeyPoint("FL1"));
	manager.delKeyPoint(manager.getKeyPoint("WR1"));
	manager.delKeyPoint(manager.getKeyPoint("WT1"));
	manager.delKeyPoint(manager.getKeyPoint("WT2"));

	for (int ii = 0; ii < manCopy.size(); ii++) {
		EXPECT_NO_THROW(delete manCopy[ii]);
	}
}

TEST(KeyPointManagerTests, CopyAndAssignmentTest)
{
	PoolData simple8laneSCMPool(true, false, PoolConstants::SCM, PoolConstants::eightLanes);
	PoolData someOtherPool(false, true, PoolConstants::LCM, PoolConstants::tenLanes);
	KeyPointManager manager(simple8laneSCMPool);
	//KeyPointManager newManager(manager); // will not compile
	KeyPointManager newManager(someOtherPool);
	//newManager = manager; // will not compile
	EXPECT_TRUE(true);
}