#ifndef FRAMEDATA_H
#define FRAMEDATA_H

#include <string>

class FrameData
{
public:
	void setFrameRes(int height, int width);
	int getFrameHeight();
	int getFrameWidth();
	void setFrameName(std::string name);
	std::string getFrameName();
	bool isDefined();
	FrameData& operator= (const FrameData& newFrame);

private:
	int mFrameHeight{ 0 };
	int mFrameWidth{ 0 };
	std::string mFrameName{ "" };
};


class FrameDataError : public std::exception
{
public:
	const char* what() const noexcept override { return mErrorMessage.c_str(); }
private:
	const std::string mErrorMessage{ "Frame Data Error: Improper data was given" };
};

class FrameResError : public FrameDataError
{
public:
	FrameResError(std::string errorDetails)
		: mErrorDetails(errorDetails) {}
	const char* what() const noexcept override { return mErrorDetails.c_str(); }

private:
	std::string mErrorDetails{};
};

class FrameNameError : public FrameDataError
{
public:
	FrameNameError(std::string errorDetails)
		: mErrorDetails(errorDetails) {}
	const char* what() const noexcept override { return mErrorDetails.c_str(); }

private:
	std::string mErrorDetails{};
};

#endif // !FRAMEDATA_H
