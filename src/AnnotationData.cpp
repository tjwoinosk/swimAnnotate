#include "AnnotationData.h"
#include "PoolConstants.h"

void AnnotationData::setXPoint(int xPoint)
{
	if (xPoint < 0)
		throw KeyPointDataError("Key Point Data Error: Key Point can not have a negative X value.");
	else
		mXPoint = xPoint;
}

void AnnotationData::setYPoint(int yPoint)
{
	if (yPoint < 0)
		throw KeyPointDataError("Key Point Data Error: Key Point can not have a negative Y value.");
	else
		mYPoint = yPoint;
}

void AnnotationData::setPoint(int xPoint, int yPoint)
{
	setXPoint(xPoint);
	setYPoint(yPoint);
}

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

std::string KeyPointData::baseGetClass() const
{
	if (!this->isDefinedClass())
		throw KeyPointDataError("Key Point Data Error: Class is not valid, can not return class.");
	else
		return mClassName + std::to_string(mNumber);
}

bool KeyPointData::isTheSameAs(KeyPointData* otherKeyPoint)
{
	if(!otherKeyPoint->isDefinedClass())
		return false;
	if (otherKeyPoint->mNumber == mNumber)
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
