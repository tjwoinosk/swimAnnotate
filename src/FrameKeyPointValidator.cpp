#include "FrameKeyPointValidator.h"
#include "FrameData.h"
#include "AnnotationData.h"

bool FrameKeyPointValidator::discriminationIsNotPossible()
{
	if (!mTheFrame.isDefined())
		return true;
	else
		return false;
}

FrameKeyPointValidator::FrameKeyPointValidator(FrameData& inputFrame) : mTheFrame(inputFrame)
{
	if (discriminationIsNotPossible())
		throw FrameKeyPointValidatorError("Frame Key Point Validation Error: Frame data is under-defined can not create validator");
}

KeyPointData* FrameKeyPointValidator::validateKeyPoint(KeyPointData* candidateKeypoint)
{
	if (candidateKeypoint == NULL)
		throw FrameKeyPointValidatorError("Frame Key Point Validation Error: validator was passed a NULL pointer");

	if (keyPointNotInFrame(candidateKeypoint))
		throw FrameKeyPointValidatorError("Frame Key Point Validation Error: Input key point was out of the frame in the x or y direction");

	return candidateKeypoint;
}

bool FrameKeyPointValidator::keyPointNotInFrame(KeyPointData* candidateKeypoint)
{
	if (candidateKeypoint->getXPoint() >= mTheFrame.getFrameHeight() || candidateKeypoint->getYPoint() >= mTheFrame.getFrameWidth())
		return true;
	else
		return false;
}

