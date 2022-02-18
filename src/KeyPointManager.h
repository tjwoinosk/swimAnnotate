#ifndef KEYPOINTMANNAGER_H
#define KEYPOINTMANNAGER_H

#include <exception>
#include <string>
#include <vector>

#include "AnnotationDiscriminator.h"

class AnnotationData;
class PoolData;
class FrameData;

class KeyPointManager
{
public:
	KeyPointManager() = default;
	KeyPointManager(PoolData& pool, FrameData& frame) : mDiscriminator(pool, frame) {}

	~KeyPointManager();

	void addKeyPoint(KeyPointData* keyPointClass);
	void addKeyPoint(KeyPointData* keyPointClass, int xLocation, int yLocation);
	//void delKeyPoint(KeyPointData* keyPointClass);
	//void chgKeyPoint(KeyPointData* keyPointClass);
	//AnnotationData& getKeyPoint(KeyPointData* keyPointClass);
	int keyPointCount();
	
private:
	AnnotationDiscriminator mDiscriminator;
	std::vector<KeyPointData*> mKeyPoints;
};

class KeyPointManagerError : public std::exception
{
public:
	KeyPointManagerError(std::string errorDetails)
		: mErrorDetails(errorDetails) {}
	const char* what() const noexcept override { return mErrorDetails.c_str(); }
private:
	std::string mErrorDetails{};
};

#endif // !KEYPOINTMANNAGER_H


