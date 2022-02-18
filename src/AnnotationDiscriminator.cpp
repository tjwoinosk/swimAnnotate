#include "AnnotationDiscriminator.h"
#include "PoolData.h"
#include "FrameData.h"
#include "AnnotationData.h"

AnnotationDiscriminator::AnnotationDiscriminator(PoolData& inputPool, FrameData& inputFrame) : mThePool(inputPool), mTheFrame(inputFrame)
{
	if (discriminationIsNotPossible())
		throw AnnotationDiscriminatorError("Annotation Discriminator Error: Pool or frame data is under-defined can not create discriminator");
}

void  AnnotationDiscriminator::validateKeyPoint(KeyPointData* candidateKeypoint, const std::vector<KeyPointData*>& mannagersList)
{
	if (candidateKeypoint == NULL)
		throw AnnotationDiscriminatorError("Annotation Discriminator Error: validator was passed a NULL pointer");

	if(keyPointIsAlreadyPresent(candidateKeypoint, mannagersList))
		throw AnnotationDiscriminatorError("Annotation Discriminator Error: Input key point already exists in this manager");

	if(keyPointNotInFrame(candidateKeypoint))
		throw AnnotationDiscriminatorError("Annotation Discriminator Error: Input key point was out of the frame in the x or y direction");

	if (keyPointNotInPool(candidateKeypoint))
		throw AnnotationDiscriminatorError("Annotation Discriminator Error: Input key point does not exist in this pool setting.");

}

bool AnnotationDiscriminator::keyPointIsAlreadyPresent(KeyPointData* candidateKeypoint, const std::vector<KeyPointData*>& mannagersList)
{
	//check if key point already exists
	std::string newClassName = candidateKeypoint->getClass();

	for (int ii = 0; ii < mannagersList.size(); ii++) {
		const KeyPointData* temp = mannagersList.at(ii);
		if (temp->getClass() == newClassName)
		{
			return true;
		}
	}
	return false;
}

bool AnnotationDiscriminator::keyPointNotInFrame(KeyPointData* candidateKeypoint)
{	
	if (candidateKeypoint->getXPoint() >= mTheFrame.getFrameHeight() || candidateKeypoint->getYPoint() >= mTheFrame.getFrameWidth())
		return true;
	else
		return false;
}

bool AnnotationDiscriminator::keyPointNotInPool(KeyPointData* candidateKeypoint)
{
	for (int ii = 0; ii < 4; ii++) {
		WallRightKeyPoint WRn(ii+7);
		if (candidateKeypoint->getClass() == WRn.getClass())
			return true;
	}
	return false;
}

bool AnnotationDiscriminator::discriminationIsNotPossible()
{
	if (!mThePool.isDefined())
		return true;
	else if (!mTheFrame.isDefined())
		return true;
	else
		return false;
}
