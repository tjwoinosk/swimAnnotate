#ifndef FRAMEDATA_H
#define FRAMEDATA_H

#include <string>

class FrameData
{
public:
	void setFrameRes(int height, int width);
	int getFrameHeight() const;
	int getFrameWidth() const;
	void setFrameName(std::string name);
	std::string getFrameName() const;
	bool isDefined() const;
	FrameData& operator= (const FrameData& newFrame);

private:
	int mFrameHeight{ 0 };
	int mFrameWidth{ 0 };
	std::string mFrameName{ "" };
};


class FrameDataError : public std::exception
{
public:
	FrameDataError(std::string errorDetails)
		: mErrorDetails(errorDetails) {}
	const char* what() const noexcept override { return mErrorDetails.c_str(); }
private:
	std::string mErrorDetails{};
};

#endif // !FRAMEDATA_H
