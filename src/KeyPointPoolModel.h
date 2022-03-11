#ifndef KEYPOINTPOOLMODEL_H
#define KEYPOINTPOOLMODEL_H

//!!Class not used at all!!

#include "PoolData.h"

class keyPointCollector;

class KeyPointPoolModel : public PoolData //do we really want it to inherit poolData??
{
public:
	KeyPointPoolModel() = default;
	//generatePoolModel
	//getKeyPointIDs

private:
	//KeyPointCollector mCollector;
};


//inherit different versions of this 

class KeyPointPoolModelError : public std::exception
{
public:
	KeyPointPoolModelError(std::string errorDetails) : mErrorMessage(errorDetails) {}
	const char* what() const noexcept override { return mErrorMessage.c_str(); }
private:
	std::string mErrorMessage{};
};

#endif // !KEYPOINTPOOLMODEL_H

