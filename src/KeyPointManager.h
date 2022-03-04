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
	void delKeyPoint(KeyPointData* keyPoint);
	int keyPointCount();
	KeyPointData* getKeyPoint(std::string keyPointID);
	std::vector<KeyPointData*> getCopyOfKeyPoints();
	
	KeyPointManager(const KeyPointManager& newManager) = delete;
	KeyPointManager& operator=(const KeyPointManager& newManager) = delete;

private:
	std::vector<KeyPointData*>::iterator wallConflictWith(KeyPointData* keyPoint);
	std::vector<KeyPointData*>::iterator floatingConflictWith(KeyPointData* keyPoint);
	std::vector<KeyPointData*>::iterator queryKeyPoint(KeyPointData* keyPoint);
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


