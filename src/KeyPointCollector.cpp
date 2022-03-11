#include "KeyPointCollector.h"
#include "KeyPointData.h"

bool KeyPointCollector::hasBeenCollected(KeyPointData* keyPoint)
{
	for (std::size_t ii = 0; ii < mKeyPointList.size(); ii++)
		if (mKeyPointList[ii]->getObjectID() == keyPoint->getObjectID())
			return true;
	return false;
}

void KeyPointCollector::addKeyPoint(KeyPointData* newPoint)
{
	if (newPoint == nullptr)
		throw KeyPointCollectorError("Key Point Collector Error: Can not add nullptr to key point collector class.");
	mKeyPointList.push_back(newPoint->deepCopy());
}

void KeyPointCollector::deleteAllKeyPointsInList()
{
	for (int ii = 0; ii < mKeyPointList.size(); ii++)
		delete mKeyPointList[ii];
}