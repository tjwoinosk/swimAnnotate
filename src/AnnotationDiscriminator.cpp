#include "AnnotationDiscriminator.h"
#include "PoolData.h"
#include "FrameData.h"
#include "AnnotationData.h"

bool AnnotationDiscriminator::discriminationIsNotPossible()
{
	if (!mThePool.isDefined())
		return true;
	else if (!mTheFrame.isDefined())
		return true;
	else
		return false;
}

AnnotationDiscriminator::AnnotationDiscriminator(PoolData& inputPool, FrameData& inputFrame) : mThePool(inputPool), mTheFrame(inputFrame)
{
	if (discriminationIsNotPossible())
		throw AnnotationDiscriminatorError("Annotation Discriminator Error: Pool or frame data is under-defined can not create discriminator");
	createKeyPointPoolModel();
}

void AnnotationDiscriminator::createKeyPointPoolModel()
{
	const int maxValueVerticalPoints = 13;
	const int maxValueHorazontalPoints = 9;
	const int topBumper = 11;
	const int bottomBumper = 1;
	const int SCM = 25;
	const int LCM = 50;

	int poolLength = mThePool.getLengthPool();
	int numberLanes = mThePool.getNumberLanes();
	bool bumpersPresent = mThePool.poolHasbumpers();
	bool pointIsInThisPool = false;
	bool pointIsAbumper = false;
	bool addPoint = false;

	for (int ii = 0; ii < maxValueVerticalPoints; ii++) {
		
		pointIsInThisPool = numberLanes >= ii || ii >= topBumper;
		pointIsAbumper = ii == bottomBumper || ii == topBumper;

		if (pointIsInThisPool)
			addPoint = true;
		else
			addPoint = false;

		if (addPoint)
			if (pointIsAbumper && !bumpersPresent)
				addPoint = false;

		if (addPoint) {
			mKeyPointPoolModel.push_back(new WallLeftKeyPoint(ii));
			mKeyPointPoolModel.push_back(new WallRightKeyPoint(ii));
			mKeyPointPoolModel.push_back(new FloatingRightKeyPoint(ii));
			mKeyPointPoolModel.push_back(new FloatingLeftKeyPoint(ii));
		}
	}

	bool alwaysAPoint = false;
	for (int ii = 0; ii < maxValueHorazontalPoints; ii++) {
		
		alwaysAPoint = (ii == 0 || ii == 1 || ii == 7 || ii == 8);
		
		if (alwaysAPoint)
			addPoint = true;
		else if (poolLength == LCM)
			addPoint = true;
		else
			addPoint = false;

		if (addPoint) {
			mKeyPointPoolModel.push_back(new WallTopKeyPoint(ii));
			mKeyPointPoolModel.push_back(new WallBottomKeyPoint(ii));
		}
	}
}

bool AnnotationDiscriminator::keyPointIsPresent(KeyPointData* candidateKeypoint, const std::vector<KeyPointData*>& listToCheck)
{
	//check if key point already exists
	std::string newClassName = candidateKeypoint->getClass();

	for (int ii = 0; ii < listToCheck.size(); ii++) {
		const KeyPointData* temp = listToCheck.at(ii);
		if (temp == NULL)
			throw AnnotationDiscriminatorError("Annotation Discriminator Error: KeyPointIsPresent, listToCheck contained a null item.");
		if (temp->getClass() == newClassName)
			return true;
	}
	return false;
}

bool AnnotationDiscriminator::keyPointInPool(KeyPointData* candidateKeypoint)
{
	if (keyPointIsPresent(candidateKeypoint, mKeyPointPoolModel))
		return true;
	else
		return false;
}

void  AnnotationDiscriminator::validateKeyPoint(KeyPointData* candidateKeypoint, const std::vector<KeyPointData*>& mannagersList)
{
	if (candidateKeypoint == NULL)
		throw AnnotationDiscriminatorError("Annotation Discriminator Error: validator was passed a NULL pointer");

	if(keyPointIsPresent(candidateKeypoint, mannagersList))
		throw AnnotationDiscriminatorError("Annotation Discriminator Error: Input key point already exists in this manager");

	if(keyPointNotInFrame(candidateKeypoint))
		throw AnnotationDiscriminatorError("Annotation Discriminator Error: Input key point was out of the frame in the x or y direction");

	if (!keyPointInPool(candidateKeypoint))
		throw AnnotationDiscriminatorError("Annotation Discriminator Error: Input key point does not exist in this pool setting.");

}

bool AnnotationDiscriminator::keyPointNotInFrame(KeyPointData* candidateKeypoint)
{	
	if (candidateKeypoint->getXPoint() >= mTheFrame.getFrameHeight() || candidateKeypoint->getYPoint() >= mTheFrame.getFrameWidth())
		return true;
	else
		return false;
}



void AnnotationDiscriminator::deallocateKeyPointPoolModel()
{
	for (int ii = 0; ii < mKeyPointPoolModel.size(); ii++)
		delete mKeyPointPoolModel[ii];
}