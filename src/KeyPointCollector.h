#ifndef KEYPOINTCOLELCTOR_H
#define KEYPOINTCOLELCTOR_H

#include <vector>
#include <exception>
#include <string>

class KeyPointData;

class KeyPointCollector
{
public:
	~KeyPointCollector() { deleteAllKeyPointsInList(); }
	KeyPointCollector() = default;

	bool hasBeenCollected(KeyPointData* keyPoint);
	void addKeyPoint(KeyPointData* newPoint);

private:
	std::vector<KeyPointData*> mKeyPointList;
	void deleteAllKeyPointsInList();
};

class KeyPointCollectorError : public std::exception
{
public:
	KeyPointCollectorError(std::string errorDetails)
		: mErrorDetails(errorDetails) {}
	const char* what() const noexcept override { return mErrorDetails.c_str(); }
private:
	std::string mErrorDetails{};
};

#endif // !KEYPOINTCOLELCTOR_H

