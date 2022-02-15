#include "KeyPointMannager.h"
#include "PoolData.h"
#include "FrameData.h"
#include "AnnotationData.h"

void KeyPointMannager::addKeyPoint(AnnotationData* newKeyPoint)
{
	if (!enviromentValid())
		throw KeyPointMannagerError();

	KeyPointData* castedNewKeyPoint = NULL;
	KeyPointData* castedKeyPoint = NULL;
	castedNewKeyPoint = dynamic_cast<KeyPointData*>(newKeyPoint);
	if (castedKeyPoint == NULL)
		throw KeyPointMannagerKeyPointError("KPM Key Point Error: Invalid key point cast in add key point");

	for (int ii = 0; ii < mKeyPoints.size(); ii++) {
		castedKeyPoint = dynamic_cast<KeyPointData*>(mKeyPoints.at(ii));
		if (castedKeyPoint->isTheSameAs(castedKeyPoint))
			return;
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
