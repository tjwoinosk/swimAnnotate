#include "gtest/gtest.h"
#include "KeyPointManager.h"
#include "AnnotationData.h"
#include "PoolData.h"


TEST(KeyPointMannagerTests, SimpleAddKeyPointTest)
{
	PoolData simple8laneSCMPool(false, false, 25, 8);
	KeyPointManager manager(simple8laneSCMPool);
	EXPECT_EQ(0, manager.keyPointCount());

	manager.addKeyPoint(new WallLeftKeyPoint(3));
	EXPECT_EQ(1, manager.keyPointCount());

	manager.addKeyPoint(new WallRightKeyPoint(2));
	EXPECT_EQ(2, manager.keyPointCount());
	
	EXPECT_THROW(manager.addKeyPoint(NULL), KeyPointManagerError);
	EXPECT_EQ(2, manager.keyPointCount());
}

TEST(KeyPointMannagerTests, RepeateKeyPointTest)
{
	PoolData simple8laneSCMPool(false, false, 25, 8);
	KeyPointManager manager(simple8laneSCMPool);

	manager.addKeyPoint(new WallRightKeyPoint(2));
	EXPECT_EQ(1, manager.keyPointCount());

	KeyPointData* repeatePoint = new WallRightKeyPoint(2);
	EXPECT_THROW(manager.addKeyPoint(repeatePoint), KeyPointManagerError);
	EXPECT_EQ(1, manager.keyPointCount());
	delete repeatePoint;

	manager.addKeyPoint(new WallLeftKeyPoint(2));
	EXPECT_EQ(2, manager.keyPointCount());
}

TEST(KeyPointMannagerTests, hardAddkeyPointTest)
{
	PoolData simple8laneSCMPool(false, false, 25, 8);
	KeyPointManager manager(simple8laneSCMPool);

	manager.hardAddKeyPoint(new WallRightKeyPoint(2));
	EXPECT_EQ(1, manager.keyPointCount());

	EXPECT_NO_THROW(manager.hardAddKeyPoint(new WallRightKeyPoint(2)));
	EXPECT_EQ(1, manager.keyPointCount());

	EXPECT_NO_THROW(manager.hardAddKeyPoint(new WallRightKeyPoint(3)));
	EXPECT_EQ(2, manager.keyPointCount());
}

TEST(KeyPointMannagerTests, AlreadyExistsFunctionTest)
{
	PoolData simple8laneSCMPool(false, false, 25, 8);
	KeyPointManager manager(simple8laneSCMPool);

	KeyPointData* alreadyExisting = new WallRightKeyPoint(2);

	EXPECT_FALSE(manager.keyPointAlreadyExists(alreadyExisting));

	manager.addKeyPoint(new WallRightKeyPoint(2));
	EXPECT_EQ(1, manager.keyPointCount());
	EXPECT_TRUE(manager.keyPointAlreadyExists(alreadyExisting));

	delete alreadyExisting;

}
