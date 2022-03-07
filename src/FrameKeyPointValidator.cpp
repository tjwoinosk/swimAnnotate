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
	modifyFloatingLeft(candidateKeypoint);
	modifyFloatingRight(candidateKeypoint);
	return candidateKeypoint;
}

void FrameKeyPointValidator::modifyFloatingRight(KeyPointData* candidateKeypoint)
{
	FloatingRightKeyPoint chkPointRight(1);

	if (candidateKeypoint->isTheSameClass(&chkPointRight)) {
		int x = candidateKeypoint->getXPoint();
		int xInv = mTheFrame.getFrameHeight() - x - 1;
		int dx = std::min(x, xInv);

		int y = candidateKeypoint->getYPoint();
		int yInv = mTheFrame.getFrameWidth() - y - 1;
		int dy = yInv;

		if (dx >= dy)
			candidateKeypoint->setYPoint(mTheFrame.getFrameWidth());
		else {// dx<dy
			if (xInv >= x)
				candidateKeypoint->setXPoint(0);
			else
				candidateKeypoint->setXPoint(mTheFrame.getFrameHeight());
		}
	}
}

void FrameKeyPointValidator::modifyFloatingLeft(KeyPointData* candidateKeypoint)
{
	FloatingLeftKeyPoint chkPointLeft(1);
	if (candidateKeypoint->isTheSameClass(&chkPointLeft)) {
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
}

bool FrameKeyPointValidator::keyPointNotInFrame(KeyPointData* candidateKeypoint)
{
	if (candidateKeypoint->getXPoint() >= mTheFrame.getFrameHeight() || candidateKeypoint->getYPoint() >= mTheFrame.getFrameWidth())
		return true;
	else
		return false;
}

