#include "KeyPointManager.h"
#include "AnnotationData.h"
#include "PoolData.h"

#include <iostream>

KeyPointManager::~KeyPointManager()
{
	deleteAllKeyPoints();
}

void KeyPointManager::addKeyPoint(KeyPointData* keyPoint)
{
	if (keyPoint == NULL)
		throw KeyPointManagerError("Key Point Manager Error: Input Key Point was NULL.");

	for(int ii = 0; ii < keyPointCount(); ii++) {
		if(keyPoint->getClass() == mKeyPoints[ii]->getClass())
			throw KeyPointManagerError("Key Point Manager Error: Input Key Point already exists.");
	}

	mKeyPoints.push_back(keyPoint);
}

void KeyPointManager::hardAddKeyPoint(KeyPointData* keyPoint)
{
	if (keyPoint == NULL)
		return;

	for (int ii = 0; ii < keyPointCount(); ii++) {
		if (keyPoint->getClass() == mKeyPoints[ii]->getClass())
		{
			delete mKeyPoints[ii];
			mKeyPoints[ii] = keyPoint;
			return;
		}
	}

	mKeyPoints.push_back(keyPoint);
}

int KeyPointManager::keyPointCount()
{
	return static_cast<int>(mKeyPoints.size());
}

bool KeyPointManager::keyPointAlreadyExists(KeyPointData* keyPoint)
{
	return false;
}

KeyPointData* KeyPointManager::queryKeyPoint(KeyPointData* keyPoint)
{
	KeyPointData* returnValue = NULL;
	for (int ii = 0; ii < keyPointCount(); ii++) {
		if (keyPoint->getClass() == mKeyPoints[ii]->getClass())
		{
			returnValue = mKeyPoints[ii];
		}
	}
	return returnValue;
}

void KeyPointManager::deleteAllKeyPoints()
{
	for (int ii = 0; ii < mKeyPoints.size(); ii++)
		delete mKeyPoints[ii];
}