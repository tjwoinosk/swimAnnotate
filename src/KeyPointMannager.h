#ifndef KEYPOINTMANNAGER_H
#define KEYPOINTMANNAGER_H

#include <exception>
#include <string>
#include <vector>

class PoolData;
class FrameData;
class AnnotationData;

class KeyPointMannager
{
public:
	KeyPointMannager(PoolData& inPoolData, FrameData& inFrameData) : mThePool(inPoolData), mTheFrame(inFrameData) {}

	void addKeyPoint(AnnotationData* newKeyPoint);
	void delKeyPoint(AnnotationData& existingKeyPoint);
	void chgKeyPoint(AnnotationData& existingKeyPoint);
	AnnotationData& chkKeyPoint(AnnotationData&);
	int keyPointCount();
	
private:
	bool enviromentValid();
	PoolData& mThePool;
	FrameData& mTheFrame;
	std::vector<AnnotationData*> mKeyPoints;
	KeyPointMannager() = default;//force the user to add the requred data
};

class KeyPointMannagerError : public std::exception
{
public:
	const char* what() const noexcept override { return mErrorMessage.c_str(); }
private:
	const std::string mErrorMessage{ "Key Point Mannager Error: General Message" };
};


class KeyPointMannagerPoolError : public KeyPointMannagerError
{
public:
	KeyPointMannagerPoolError(std::string errorDetails)
		: mErrorDetails(errorDetails) {}
	const char* what() const noexcept override { return mErrorDetails.c_str(); }

private:
	std::string mErrorDetails{};
};

class KeyPointMannagerFrameError : public KeyPointMannagerError
{
public:
	KeyPointMannagerFrameError(std::string errorDetails)
		: mErrorDetails(errorDetails) {}
	const char* what() const noexcept override { return mErrorDetails.c_str(); }

private:
	std::string mErrorDetails{};
};

class KeyPointMannagerKeyPointError : public KeyPointMannagerError
{
public:
	KeyPointMannagerKeyPointError(std::string errorDetails)
		: mErrorDetails(errorDetails) {}
	const char* what() const noexcept override { return mErrorDetails.c_str(); }

private:
	std::string mErrorDetails{};
};


#endif // !KEYPOINTMANNAGER_H


