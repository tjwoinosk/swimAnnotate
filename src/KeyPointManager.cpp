#include "KeyPointManager.h"

#include "AnnotationData.h"
#include "PoolData.h"
#include "FrameData.h"

#include <iostream>

KeyPointManager::~KeyPointManager()
{
	for (int ii = 0; ii < mKeyPoints.size(); ii++)
		delete mKeyPoints[ii];
}

void KeyPointManager::addKeyPoint(KeyPointData* keyPointClass, int xLocation, int yLocation)
{
	if (keyPointClass == NULL)
		throw KeyPointManagerError("Input Key Point was NULL");

	keyPointClass->setPoint(xLocation, yLocation);
	addKeyPoint(keyPointClass);
}

void KeyPointManager::addKeyPoint(KeyPointData* keyPointClass)
{
	if (keyPointClass == NULL)
		throw KeyPointManagerError("Input Key Point was NULL");

	mDiscriminator.validateKeyPoint(keyPointClass, mKeyPoints);
	mKeyPoints.push_back(keyPointClass);
}



int KeyPointManager::keyPointCount()
{
	return static_cast<int>(mKeyPoints.size());
}