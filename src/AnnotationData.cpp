#include "AnnotationData.h"

bool AnnotationData::isTheSamePointAs(AnnotationData* otherPoint) const
{
	if (otherPoint == nullptr)
		throw AnnotationDataError("Annotation Data Error: input point was nullptr.");

	if (mXPoint != otherPoint->getXPoint())
		return false;
	else if (mYPoint != otherPoint->getYPoint())
		return false;
	else
		return true;
}

void AnnotationData::setXPoint(int xPoint)
{
	if (xPoint < 0)
		throw AnnotationDataError("Annotation Data Error: Key Point can not have a negative X value.");
	else
		mXPoint = xPoint;
}

void AnnotationData::setYPoint(int yPoint)
{
	if (yPoint < 0)
		throw AnnotationDataError("Annotation Data Error: Key Point can not have a negative Y value.");
	else
		mYPoint = yPoint;
}

void AnnotationData::setPoint(int xPoint, int yPoint)
{
	setXPoint(xPoint);
	setYPoint(yPoint);
}