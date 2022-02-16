#include "KeyPointMannager.h"
#include "PoolData.h"
#include "FrameData.h"
#include "AnnotationData.h"

#include <iostream>

void KeyPointMannager::addKeyPoint(AnnotationData* newKeyPoint)
{
	if (!enviromentValid())
		throw KeyPointMannagerError();

	KeyPointData* castedNewKeyPoint = NULL;
	KeyPointData* castedKeyPoint = NULL;
	castedNewKeyPoint = dynamic_cast<KeyPointData*>(newKeyPoint);
	if (castedNewKeyPoint == NULL)
		throw KeyPointMannagerKeyPointError("KPM Key Point Error: Invalid key point cast in add key point");

	if(castedNewKeyPoint->getXPoint() >= mTheFrame.getFrameHeight() && castedNewKeyPoint->getYPoint() >= mTheFrame.getFrameWidth())
		throw KeyPointMannagerFrameError("KPM Frame Error: Input Key point was out of the frame in the x and y direction");
	else if (castedNewKeyPoint->getXPoint() >= mTheFrame.getFrameHeight())
		throw KeyPointMannagerFrameError("KPM Frame Error: Input Key point was out of the frame in the x direction");
	else if(castedNewKeyPoint->getYPoint() >= mTheFrame.getFrameWidth())
		throw KeyPointMannagerFrameError("KPM Frame Error: Input Key point was out of the frame in the y direction");

	WallRightKeyPoint* WRptr = dynamic_cast<WallRightKeyPoint*>(newKeyPoint);

	for (int ii = 0; ii < 4; ii++) {
		WallRightKeyPoint WRn(ii+7);
		if (WRptr->getClass() == WRn.getClass())
		{
			std::string message = "KPM Pool Error: ";
			message.append(WRn.getClass() + "is not valid for this pool");
			throw KeyPointMannagerPoolError(message);
		}
	}

	std::string newClassName = castedNewKeyPoint->getClass();

	for (int ii = 0; ii < mKeyPoints.size(); ii++) {
		castedKeyPoint = dynamic_cast<KeyPointData*>(mKeyPoints.at(ii));
		if (castedKeyPoint->getClass() == newClassName)
			throw KeyPointMannagerKeyPointError("KPM Key Point Error: Key Point already has been added");
	}

	mKeyPoints.push_back(newKeyPoint);
}

void KeyPointMannager::delKeyPoint(AnnotationData& existingKeyPoint)
{
}

void KeyPointMannager::chgKeyPoint(AnnotationData& existingKeyPoint)
{
}

AnnotationData& KeyPointMannager::chkKeyPoint(AnnotationData& existingKeyPoint)
{
	return existingKeyPoint;
}

int KeyPointMannager::keyPointCount()
{
	return static_cast<int>(mKeyPoints.size());
}

bool KeyPointMannager::enviromentValid()
{
	if(!mThePool.isDefined())
		return false;
	else if (!mTheFrame.isDefined())
		return false;
	else
		return true;
}
