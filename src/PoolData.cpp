#include "PoolData.h"
#include "PoolConstants.h"

PoolData::PoolData(bool hasBumpers, bool hasMiddleBulkhead, int length, int numberLanes)
{
	specifyBumpers(hasBumpers);
	setLengthPool(length);
	specifyMiddlePool(hasMiddleBulkhead);
	setNumberLanes(numberLanes);
}

PoolData::PoolData(const PoolData& newPool)
{
	*this = newPool;
}

PoolData& PoolData::operator=(const PoolData& newPool)
{
	mLengthPool = newPool.mLengthPool;
	mNumberLanes = newPool.mNumberLanes;
	mHasBumpers = newPool.mHasBumpers;
	mHasMiddleBulkhead = newPool.mHasMiddleBulkhead;
	return *this;
}

void PoolData::setNumberLanes(int numberLanes)
{
	bool validNumber = false;
	for (int number : PoolConstants::possibleNumberLanes)
		if (number == numberLanes)
			validNumber = true;
	
	if(!validNumber)
		throw PoolDataError("Number Lanes Error: Incorrect number of lanes given.");
	else
		mNumberLanes = numberLanes;
}

int PoolData::getNumberLanes() const 
{
	if (mNumberLanes == 0)
		throw PoolDataError("Number Lanes Error: Number Lanes has not been specified.");
	return mNumberLanes;
}

void PoolData::setLengthPool(int lengthPool)
{
	if (lengthPool != PoolConstants::LCM && lengthPool != PoolConstants::SCM)
		throw PoolDataError("Pool length Error: Pool can only be 50 or 25.");
	else {
		if (lengthPool == PoolConstants::SCM)
			mHasMiddleBulkhead = 0;

		mLengthPool = lengthPool;
	}
}

int PoolData::getLengthPool() const
{
	if (mLengthPool == 0)
		throw PoolDataError("Pool length Error: Length of pool has not been specified.");
	return mLengthPool;
}

void PoolData::specifyMiddlePool(bool poolHasMiddleBulkhead)
{
	if (poolHasMiddleBulkhead && mLengthPool == PoolConstants::SCM)
		throw PoolDataError("Middle Bulkhead Error: Pool can not be 25m long and have a middle bulkhead.");
	if (poolHasMiddleBulkhead)
		mHasMiddleBulkhead = 1;
	else
		mHasMiddleBulkhead = 0;
}

bool PoolData::poolHasMiddleBulkhead() const
{
	if (mHasMiddleBulkhead == -1)
		throw PoolDataError("Has Bumpers Error: Middle Bulkhead has not been specified.");
	return static_cast<bool>(mHasMiddleBulkhead);
}

void PoolData::specifyBumpers(bool poolHasBumpers)
{
	if (poolHasBumpers)
		mHasBumpers = 1;
	else
		mHasBumpers = 0;
}

bool PoolData::poolHasbumpers() const
{
	if (mHasBumpers == -1)
		throw PoolDataError("Has Bumpers Error: Bumpers has not been specified.");
	return static_cast<bool>(mHasBumpers);
}

bool PoolData::isDefined() const
{
	if (mNumberLanes == 0)
		return false;
	else if (mLengthPool == 0)
		return false;
	else if (mHasBumpers == -1)
		return false;
	else if (mHasMiddleBulkhead == -1)
		return false;
	else
		return true;
}
