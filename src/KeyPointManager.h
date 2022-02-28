#ifndef KEYPOINTMANNAGER_H
#define KEYPOINTMANNAGER_H

#include <exception>
#include <string>
#include <vector>

class KeyPointData;
class PoolData;

class KeyPointManager
{
public:
	KeyPointManager(PoolData& pool) : mThePool(pool) {}
	virtual ~KeyPointManager();

	void addKeyPoint(KeyPointData* keyPoint);
	void hardAddKeyPoint(KeyPointData* keyPoint);
	//void delKeyPoint(KeyPointData* keyPointClass);
	//void chgKeyPoint(KeyPointData* keyPointClass);
	//AnnotationData& getKeyPoint(KeyPointData* keyPointClass);
	int keyPointCount();
	bool keyPointAlreadyExists(KeyPointData* keyPoint);
	//bool conflictsWithCurrentKeyPoints();
	
private:
	KeyPointData* queryKeyPoint(KeyPointData* keyPoint);
	std::vector<KeyPointData*> mKeyPoints;
	PoolData &mThePool;
	void deleteAllKeyPoints();
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


