#include "KeyPointAnnotator.h"

KeyPointAnnotator::KeyPointAnnotator()
{
}

KeyPointAnnotator::~KeyPointAnnotator()
{
}

void KeyPointAnnotator::addPoolLength(int length)
{
	mPoolLength = length;
}

int KeyPointAnnotator::getPoolLength()
{
	return mPoolLength;
}
