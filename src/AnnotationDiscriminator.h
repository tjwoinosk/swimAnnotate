#ifndef ANNOTATIONDISCRIMINATOR_H
#define ANNOTATIONDISCRIMINATOR_H

#include <functional>
#include <vector>
#include <exception>
#include <string>

#include "AnnotationData.h"

class PoolData;
class FrameData;
class KeyPointData;

class AnnotationDiscriminator
{
public:
	AnnotationDiscriminator(PoolData& inputPool, FrameData& inputFrame);
	virtual ~AnnotationDiscriminator() { deallocateKeyPointPoolModel(); }

	void validateKeyPoint(KeyPointData* candidateKeypoint, const std::vector<KeyPointData*>& mannagersList);

protected:
	bool keyPointIsPresent(KeyPointData* candidateKeypoint, const std::vector<KeyPointData*>& mannagersList);
	bool keyPointNotInFrame(KeyPointData* candidateKeypoint);
	bool keyPointInPool(KeyPointData* candidateKeypoint);
	bool discriminationIsNotPossible();
	void createKeyPointPoolModel();
	void deallocateKeyPointPoolModel();

private:
	PoolData& mThePool;
	FrameData& mTheFrame;
	std::vector<KeyPointData*> mKeyPointPoolModel;
};

class AnnotationDiscriminatorError : public std::exception
{
public:
	AnnotationDiscriminatorError(std::string errorDetails) : mErrorMessage(errorDetails) {}
	const char* what() const noexcept override { return mErrorMessage.c_str(); }
private:
	std::string mErrorMessage{};
};


#endif // !ANNOTATIONDISCRIMINATOR_H

