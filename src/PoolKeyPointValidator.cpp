#include "PoolKeyPointValidator.h"
#include "PoolData.h"
#include "AnnotationData.h"
#include "PoolConstants.h"

bool PoolKeyPointValidator::discriminationIsNotPossible()
{
	if (!mThePool.isDefined())
		return true;
	else
		return false;
}

PoolKeyPointValidator::PoolKeyPointValidator(PoolData& inputPool) : mThePool(inputPool)
{
	if (discriminationIsNotPossible())
		throw PoolKeyPointValidatorError("Pool key Point Validator Error: Pool is under-defined can not create validator.");
	createKeyPointPoolModel();
}

void PoolKeyPointValidator::createKeyPointPoolModel()
{
	addVerticalPoints();
	addHorizontalPoints();
}

void PoolKeyPointValidator::addVerticalPoints()
{
	for (int ii = 0; ii < PoolConstants::maxVerticalPoints; ii++) {
		if (isValidVerticalPoint(ii)) {
			mKeyPointPoolModel.push_back(new WallLeftKeyPoint(ii));
			mKeyPointPoolModel.push_back(new WallRightKeyPoint(ii));
			mKeyPointPoolModel.push_back(new FloatingRightKeyPoint(ii));
			mKeyPointPoolModel.push_back(new FloatingLeftKeyPoint(ii));
			mKeyPointPoolModel.push_back(new BulkheadLeftKeyPoint(ii));
			mKeyPointPoolModel.push_back(new BulkheadRightKeyPoint(ii));
		}
	}
}

bool PoolKeyPointValidator::isValidVerticalPoint(int keyPoint)
{
	bool pointIsInThisPool = false;
	bool addPoint = false;
	bool pointIsAbumper = false;

	pointIsInThisPool = mThePool.getNumberLanes() >= keyPoint || keyPoint >= PoolConstants::topBumper;
	pointIsAbumper = keyPoint == PoolConstants::bottomBumper || keyPoint == PoolConstants::topBumper;

	if (pointIsInThisPool)
		if (pointIsAbumper && !mThePool.poolHasbumpers())
			addPoint = false;
		else
			addPoint = true;
	else
		addPoint = false;

	return addPoint;
}

void PoolKeyPointValidator::addHorizontalPoints()
{
	for (int ii = 0; ii < PoolConstants::maxHorizontalPoints; ii++) {
		if (isValidHorizontalPoint(ii)) {
			mKeyPointPoolModel.push_back(new WallTopKeyPoint(ii));
			mKeyPointPoolModel.push_back(new WallBottomKeyPoint(ii));
		}
	}
}

bool PoolKeyPointValidator::isValidHorizontalPoint(int keyPoint)
{
	bool addPoint = false;
	bool alwaysAPoint = false;

	for (int number : PoolConstants::horizontalPointAlwaysPresent)
		alwaysAPoint |= (keyPoint == number);

	if (alwaysAPoint)
		addPoint = true;
	else if (mThePool.getLengthPool() == PoolConstants::LCM)
		addPoint = true;
	else
		addPoint = false;

	return addPoint;
}

void  PoolKeyPointValidator::validateKeyPoint(KeyPointData* candidateKeypoint)
{
	if (candidateKeypoint == NULL)
		throw PoolKeyPointValidatorError("Pool key Point Validator Error: validator was passed a NULL pointer.");

	if (keyPointNotInPool(candidateKeypoint))
		throw PoolKeyPointValidatorError("Pool key Point Validator Error: Input key point does not exist in this pool setting.");
}

bool PoolKeyPointValidator::keyPointNotInPool(KeyPointData* candidateKeypoint)
{
	std::string newClassName = candidateKeypoint->getClass();

	for (int ii = 0; ii < mKeyPointPoolModel.size(); ii++) {
		const KeyPointData* temp = mKeyPointPoolModel.at(ii);
		if (temp == NULL)
			throw PoolKeyPointValidatorError("Pool key Point Validator Error: internal pool is not valid (should not happen).");
		if (temp->getClass() == newClassName)
			return false;
	}
	return true;
}

void PoolKeyPointValidator::deallocateKeyPointPoolModel()
{
	for (int ii = 0; ii < mKeyPointPoolModel.size(); ii++)
		delete mKeyPointPoolModel[ii];
}