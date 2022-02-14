#include "KeyPointData.h"

//----------

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

//----------

bool KeyPointData::isValid()
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

std::string KeyPointData::baseGetClass()
{
	if (!this->isValid())
		throw KeyPointDataError("Key Point Data Error: Class is not valid, can not return class.");
	else
		return mClassName + std::to_string(mNumber);
}

bool KeyPointData::isTheSameAs(KeyPointData* otherKeyPoint)
{
	if(!otherKeyPoint->isValid())
		return false;
	if (otherKeyPoint->mNumber == mNumber)
		return true;
	else
		return false;
}

//----------

void WallLeftKeyPoint::setClassNumber(int itsNumber)
{
	mMaxSubClass = 12;
	mMinSubClass = 0;
	baseSetClassNumber(itsNumber);
}

std::string WallLeftKeyPoint::getClass()
{
	mClassName = "WL";
	return baseGetClass();
}

//----------

void WallRightKeyPoint::setClassNumber(int itsNumber)
{
	mMaxSubClass = 12;
	mMinSubClass = 0;
	baseSetClassNumber(itsNumber);
}

std::string WallRightKeyPoint::getClass()
{
	mClassName = "WR";
	return baseGetClass();
}

//----------

void WallTopKeyPoint::setClassNumber(int itsNumber)
{
	mMaxSubClass = 8;
	mMinSubClass = 0;
	baseSetClassNumber(itsNumber);
}

std::string WallTopKeyPoint::getClass()
{
	mClassName = "WT";
	return baseGetClass();
}

//----------

std::string WallBottomKeyPoint::getClass()
{
	mClassName = "WB";
	return baseGetClass();
}

void WallBottomKeyPoint::setClassNumber(int itsNumber)
{
	mMaxSubClass = 8;
	mMinSubClass = 0;
	baseSetClassNumber(itsNumber);
}

//----------

std::string FloatingRightKeyPoint::getClass()
{
	mClassName = "FR";
	return baseGetClass();
}

void FloatingRightKeyPoint::setClassNumber(int itsNumber)
{
	mMaxSubClass = 12;
	mMinSubClass = 0;
	baseSetClassNumber(itsNumber);
}

//----------

std::string FloatingLeftKeyPoint::getClass()
{
	mClassName = "FL";
	return baseGetClass();
}

void FloatingLeftKeyPoint::setClassNumber(int itsNumber)
{
	mMaxSubClass = 12;
	mMinSubClass = 0;
	baseSetClassNumber(itsNumber);
}
