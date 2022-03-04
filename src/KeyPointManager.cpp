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
	if(queryKeyPoint(keyPoint) != std::end(mKeyPoints))
		throw KeyPointManagerError("Key Point Manager Error: Input Key Point already exists.");

	if(wallConflictWith(keyPoint) != std::end(mKeyPoints))
		throw KeyPointManagerError("Key Point Manager Error: Input Key Point conflicts with existing wall key points.");

	if(floatingConflictWith(keyPoint) != std::end(mKeyPoints))
		throw KeyPointManagerError("Key Point Manager Error: Input Key Point conflicts with existing floating key points.");

	mKeyPoints.push_back(keyPoint->deepCopy());
}

void KeyPointManager::hardAddKeyPoint(KeyPointData* keyPoint)
{
	std::vector<KeyPointData*>::iterator repeateConflict = queryKeyPoint(keyPoint);
	std::vector<KeyPointData*>::iterator wallConflict = wallConflictWith(keyPoint);
	std::vector<KeyPointData*>::iterator floatingConflict = floatingConflictWith(keyPoint);

	KeyPointData* newKeyPoint = keyPoint->deepCopy();
	if(repeateConflict != std::end(mKeyPoints)) {
		delete (*repeateConflict);
		(*repeateConflict) = newKeyPoint;
	}
	else if (wallConflict != std::end(mKeyPoints)) {
		delete (*wallConflict);
		(*wallConflict) = newKeyPoint;
	}
	else if (floatingConflict != std::end(mKeyPoints)) {
		delete (*floatingConflict);
		(*floatingConflict) = newKeyPoint;
	}
	else	
		mKeyPoints.push_back(newKeyPoint);
}

void KeyPointManager::delKeyPoint(KeyPointData* keyPoint)
{
	std::vector<KeyPointData*>::iterator possiblePoint = queryKeyPoint(keyPoint);
	if (possiblePoint != std::end(mKeyPoints)){
		delete *possiblePoint;
		mKeyPoints.erase(possiblePoint);
	}	
}

KeyPointData* KeyPointManager::getKeyPoint(std::string keyPointID)
{
	for (std::size_t ii = 0; ii < mKeyPoints.size(); ii++) {
		if (mKeyPoints[ii]->getObjectID() == keyPointID)
			return mKeyPoints[ii];
	}
	return NULL;
}

std::vector<KeyPointData*>::iterator KeyPointManager::wallConflictWith(KeyPointData* keyPoint)
{
	WallRightKeyPoint WR(0);
	WallLeftKeyPoint WL(0);
	FloatingRightKeyPoint FR(0);
	FloatingLeftKeyPoint FL(0);

	std::vector<KeyPointData*>::iterator it = std::begin(mKeyPoints);
	for (it; it != std::end(mKeyPoints); ++it) {
		if ((*it)->isTheSameNumberAs(keyPoint)) {
			if ((*it)->isTheSameClass(&WR) && keyPoint->isTheSameClass(&FR))
				return it;
			if ((*it)->isTheSameClass(&WL) && keyPoint->isTheSameClass(&FL))
				return it;
		}
	}
	return it;
}

std::vector<KeyPointData*>::iterator KeyPointManager::floatingConflictWith(KeyPointData* keyPoint)
{
	WallRightKeyPoint WR(0);
	WallLeftKeyPoint WL(0);
	FloatingRightKeyPoint FR(0);
	FloatingLeftKeyPoint FL(0);

	std::vector<KeyPointData*>::iterator it = std::begin(mKeyPoints);
	for (it; it != std::end(mKeyPoints); ++it) {
		if ((*it)->isTheSameNumberAs(keyPoint)) {
			if ((*it)->isTheSameClass(&FR) && keyPoint->isTheSameClass(&WR))
				return it;
			if ((*it)->isTheSameClass(&FL) && keyPoint->isTheSameClass(&WL))
				return it;
		}
	}
	return it;
}

std::vector<KeyPointData*>::iterator KeyPointManager::queryKeyPoint(KeyPointData* keyPoint)
{
	if(keyPoint == NULL)
		throw KeyPointManagerError("Key Point Manager Error: Input Key Point was NULL.");

	std::vector<KeyPointData*>::iterator it = std::begin(mKeyPoints);
	for (it; it != std::end(mKeyPoints); ++it)
		if (keyPoint->getObjectID() == (*it)->getObjectID())
			return it;

	return it;
}

int KeyPointManager::keyPointCount()
{
	return static_cast<int>(mKeyPoints.size());
}

void KeyPointManager::deleteAllKeyPoints()
{
	KeyPointData test;
	for (int ii = 0; ii < mKeyPoints.size(); ii++)
		delete mKeyPoints[ii];
}

std::vector<KeyPointData*> KeyPointManager::getCopyOfKeyPoints()
{
	std::vector<KeyPointData*> copyOfKeyPoints;
	for (std::size_t ii = 0; ii < mKeyPoints.size(); ii++)
		copyOfKeyPoints.push_back(mKeyPoints[ii]->deepCopy());

	return copyOfKeyPoints;
}