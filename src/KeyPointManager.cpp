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

	mPoolValidator.validateKeyPoint(keyPointClass);
	mKeyPoints.push_back(keyPointClass);
}



int KeyPointManager::keyPointCount()
{
	return static_cast<int>(mKeyPoints.size());
}

/*
void  AnnotationDiscriminator::validateKeyPoint(KeyPointData* candidateKeypoint, const std::vector<KeyPointData*>& mannagersList)
{
	if (candidateKeypoint == NULL)
		throw AnnotationDiscriminatorError("Annotation Discriminator Error: validator was passed a NULL pointer");

	if (keyPointInPool(candidateKeypoint, mannagersList))
		throw AnnotationDiscriminatorError("Annotation Discriminator Error: Input key point already exists in this manager");

	if (keyPointNotInFrame(candidateKeypoint))
		throw AnnotationDiscriminatorError("Annotation Discriminator Error: Input key point was out of the frame in the x or y direction");

	if (!keyPointInPool(candidateKeypoint))
		throw AnnotationDiscriminatorError("Annotation Discriminator Error: Input key point does not exist in this pool setting.");
}
*/