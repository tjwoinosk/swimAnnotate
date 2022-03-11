#include "FrameData.h"

void FrameData::setFrameRes(int height, int width)
{
	if (height < 51)
		throw FrameDataError("Frame Data Error: Frame height must be larger than 50.");
	if (width < 51)
		throw FrameDataError("Frame Data Error: Frame width must be larger than 50.");

	mFrameHeight = height;
	mFrameWidth = width;
}

int FrameData::getFrameHeight() const
{
	if(mFrameHeight == 0)
		throw FrameDataError("Frame Data Error: Frame height has not been specified.");
	return mFrameHeight;
}

int FrameData::getFrameWidth() const
{
	if (mFrameWidth == 0)
		throw FrameDataError("Frame Data Error: Frame width has not been specified.");
	return mFrameWidth;
}

void FrameData::setFrameName(std::string name)
{
	mFrameName = name;
}

std::string FrameData::getFrameName() const
{
	if (mFrameName == "")
		throw FrameDataError("Frame Data Error: Frame name has not been defined.");
	return mFrameName;
}

bool FrameData::isDefined() const
{
	if (mFrameHeight != 0 && mFrameWidth != 0)
		return true;
	else
		return false;
}

FrameData& FrameData::operator=(const FrameData& newFrame)
{
	mFrameHeight = newFrame.mFrameHeight;
	mFrameWidth = newFrame.mFrameWidth;
	mFrameName = newFrame.mFrameName;
	return *this;
}
