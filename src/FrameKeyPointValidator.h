#ifndef FRAMEKEYPOINTVALIDATOR_H
#define FRAMEKEYPOINTVALIDATOR_H

#include <vector>
#include <exception>
#include <string>

class FrameData;
class KeyPointData;

class FrameKeyPointValidator
{
public:
	FrameKeyPointValidator(FrameData& inputFrame);
	KeyPointData* validateKeyPoint(KeyPointData* candidateKeypoint);

private:
	KeyPointData* modifyKeyPoint(KeyPointData* candidateKeypoint);
	void modifyFloatingRight(KeyPointData* candidateKeypoint);
	void modifyFloatingLeft(KeyPointData* candidateKeypoint);
	bool keyPointNotInFrame(KeyPointData* candidateKeypoint);
	bool discriminationIsNotPossible();
	FrameData& mTheFrame;
};

class FrameKeyPointValidatorError : public std::exception
{
public:
	FrameKeyPointValidatorError(std::string errorDetails) : mErrorMessage(errorDetails) {}
	const char* what() const noexcept override { return mErrorMessage.c_str(); }
private:
	std::string mErrorMessage{};
};

#endif // !FRAMEKEYPOINTVALIDATOR_H

