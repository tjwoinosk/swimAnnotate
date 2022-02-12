#include "PoolData.h"

void PoolData::setNumberLanes(int numberLanes)
{
	bool validNumber = false;
	for (int number : possibleNumberLanes)
		if (number == numberLanes)
			validNumber = true;
	
	if(!validNumber)
		throw NumberLanesError("Number Lanes Error: Incorrect number of lanes given.");
	else
		mNumberLanes = numberLanes;
}

int PoolData::getNumberLanes()
{
	if (mNumberLanes == 0)
		throw NumberLanesError("Number Lanes Error: Number Lanes has not been specifed.");
	return mNumberLanes;
}

void PoolData::setLengthPool(int lengthPool)
{
	if (lengthPool != LCM && lengthPool != SCM)
		throw LengthPoolError("Pool length Error: Pool can only be 50 or 25.");
	else
		mLengthPool = lengthPool;
}

int PoolData::getLengthPool()
{
	if (mLengthPool == 0)
		throw LengthPoolError("Pool length Error: Length of pool has not been specifed.");
	return mLengthPool;
}

void PoolData::specifyBumpers(bool poolHasBumpers)
{
	if (poolHasBumpers)
		mHasBumpers = 1;
	else
		mHasBumpers = 0;
}

bool PoolData::poolHasbumpers()
{
	if (mHasBumpers == -1)
		throw HasBumpersError("Has Bumpers Error: Bumpers has not been specifed.");
	return static_cast<bool>(mHasBumpers);
}

bool PoolData::poolIsDefined()
{
	if (mNumberLanes == 0)
		return false;
	else if (mLengthPool == 0)
		return false;
	else if (mHasBumpers == -1)
		return false;
	else
		return true;
}
