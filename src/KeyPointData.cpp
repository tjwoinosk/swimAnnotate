#include "KeyPointData.h"
#include "AnnotationData.h"
#include "PoolConstants.h"

bool KeyPointData::isDefinedClass() const
{
	if (mNumber == -1)
		return false;
	else
		return true;
}

void KeyPointData::baseSetClassNumber(int itsNumber)
{
	std::string rangeString = "[" + std::to_string(mMinSubClass) + "," + std::to_string(mMaxSubClass)+"].";
	if (itsNumber > mMaxSubClass)
		throw KeyPointDataError("Key Point Data Error: Key Point Number too large for this class, must be in range of" + rangeString);
	else if (itsNumber < mMinSubClass)
		throw KeyPointDataError("Key Point Data Error: Key Point Number too small for this class, must be in range of" + rangeString);
	else
		mNumber = itsNumber;
}

std::string KeyPointData::baseGetObjectID() const
{
	if (!this->isDefinedClass())
		throw KeyPointDataError("Key Point Data Error: Class is not valid, can not return class.");
	else
		return mClassName + std::to_string(mNumber);
}

bool KeyPointData::isTheSameNumberAs(KeyPointData* otherKeyPoint) const
{
	if(otherKeyPoint == nullptr)
		throw KeyPointDataError("Key Point Data Error: Is the same number as function received a nullptr ptr.");

	if (otherKeyPoint->mNumber == mNumber)
		return true;
	else
		return false;
}

bool KeyPointData::isTheSameClass(KeyPointData* otherKeyPoint) const
{
	if (otherKeyPoint == nullptr)
		throw KeyPointDataError("Key Point Data Error: Is the same class function received a nullptr ptr.");

	if (otherKeyPoint->mClassName == mClassName)
		return true;
	else
		return false;
}

void WallLeftKeyPoint::setClass(int itsNumber)
{
	mClassName = "WL";
	mMaxSubClass = PoolConstants::maxVerticalPoints-1;
	mMinSubClass = 0;
	baseSetClassNumber(itsNumber);
}

void WallRightKeyPoint::setClass(int itsNumber)
{
	mClassName = "WR";
	mMaxSubClass = PoolConstants::maxVerticalPoints - 1;
	mMinSubClass = 0;
	baseSetClassNumber(itsNumber);
}

void WallTopKeyPoint::setClass(int itsNumber)
{
	mClassName = "WT";
	mMaxSubClass = PoolConstants::maxHorizontalPoints - 1;
	mMinSubClass = 0;
	baseSetClassNumber(itsNumber);
}

void WallBottomKeyPoint::setClass(int itsNumber)
{
	mClassName = "WB";
	mMaxSubClass = PoolConstants::maxHorizontalPoints - 1;
	mMinSubClass = 0;
	baseSetClassNumber(itsNumber);
}

void FloatingRightKeyPoint::setClass(int itsNumber)
{
	mClassName = "FR";
	mMaxSubClass = PoolConstants::maxVerticalPoints - 1;
	mMinSubClass = 0;
	baseSetClassNumber(itsNumber);
}

void FloatingLeftKeyPoint::setClass(int itsNumber)
{
	mClassName = "FL";
	mMaxSubClass = PoolConstants::maxVerticalPoints - 1;
	mMinSubClass = 0;
	baseSetClassNumber(itsNumber);
}

void BulkheadLeftKeyPoint::setClass(int itsNumber)
{
	mClassName = "BL";
	mMaxSubClass = PoolConstants::maxVerticalPoints - 1;
	mMinSubClass = 0;
	baseSetClassNumber(itsNumber);
}

void BulkheadRightKeyPoint::setClass(int itsNumber)
{
	mClassName = "BR";
	mMaxSubClass = PoolConstants::maxVerticalPoints - 1;
	mMinSubClass = 0;
	baseSetClassNumber(itsNumber);
}