#ifndef KEYPOINTMANNAGER_H
#define KEYPOINTMANNAGER_H

#include "KeyPointData.h"
#include <map>

class KeyPointMannager
{
public:
	void addKeyPoint(KeyPointData* newKeyPoint);
	void deleteKeyPoint(KeyPointData* keyPointToRemove);
	KeyPointData* getKeyPoint();

	

private:
	//std::map<KeyPointData*, KeyPointData> mKeyPoints;

};


#endif // !KEYPOINTMANNAGER_H


