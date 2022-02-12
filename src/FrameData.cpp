#include "FrameData.h"

void FrameData::setFrameRes(int height, int width)
{
	if (height < 1)
		throw FrameResError("Frame Res Error: Frame height must be larger than 0.");
	if (width < 1)
		throw FrameResError("Frame Res Error: Frame width must be larger than 0.");

	mFrameHeight = height;
	mFrameWidth = width;
}

int FrameData::getFrameHeight()
{
	if(mFrameHeight == 0)
		throw FrameResError("Frame Res Error: Frame height has not been specified.");
	return mFrameHeight;
}

int FrameData::getFrameWidth()
{
	if (mFrameWidth == 0)
		throw FrameResError("Frame Res Error: Frame width has not been specified.");
	return mFrameWidth;
}

void FrameData::setFrameName(std::string name)
{
	mFrameName = name;
}

std::string FrameData::getFrameName()
{
	if (mFrameName == "")
		throw FrameNameError("Frame Name Error: Frame name has not been defined.");
	return mFrameName;
}

bool FrameData::frameIsDefined()
{
	if (mFrameHeight != 0 && mFrameWidth != 0)
		return true;
	else
		return false;
}
