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
	void validateKeyPoint(KeyPointData* candidateKeypoint);

private:
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

