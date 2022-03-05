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

	candidateKeypoint = modifyKeyPoint(candidateKeypoint);

	return candidateKeypoint;
}

KeyPointData* FrameKeyPointValidator::modifyKeyPoint(KeyPointData* candidateKeypoint)
{
	FloatingLeftKeyPoint chkPoint(1);
	if (candidateKeypoint->isTheSameClass(&chkPoint)){
		int x = candidateKeypoint->getXPoint();
		int xInv = mTheFrame.getFrameHeight() - x - 1;
		int dx = std::min(x, xInv);
		int dy = candidateKeypoint->getYPoint();

		if (dx >= dy)
			candidateKeypoint->setYPoint(0);
		else {// dx<dy
			if (xInv >= x)
				candidateKeypoint->setXPoint(0);
			else
				candidateKeypoint->setXPoint(mTheFrame.getFrameHeight());
		}
	}
	return candidateKeypoint;
}

bool FrameKeyPointValidator::keyPointNotInFrame(KeyPointData* candidateKeypoint)
{
	if (candidateKeypoint->getXPoint() >= mTheFrame.getFrameHeight() || candidateKeypoint->getYPoint() >= mTheFrame.getFrameWidth())
		return true;
	else
		return false;
}

