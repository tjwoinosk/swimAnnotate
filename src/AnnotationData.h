#ifndef ANNOTATIONDATA_H
#define ANNOTATIONDATA_H

#include <exception>
#include <string>

class AnnotationData
{
public:
	AnnotationData() = default;
	AnnotationData(int xPoint, int yPoint) : mXPoint(xPoint), mYPoint(yPoint) {}
	virtual std::string getObjectID() const = 0;
	bool isTheSamePointAs(AnnotationData* otherPoint) const;
	virtual void setXPoint(int xPoint);
	virtual void setYPoint(int yPoint);
	virtual void setPoint(int xPoint, int yPoint);
	int getXPoint() const { return mXPoint; }
	int getYPoint() const { return mYPoint; }

	virtual ~AnnotationData() = default;

protected:
	int mXPoint{ 0 };
	int mYPoint{ 0 };
};

class AnnotationDataError : public std::exception
{
public:
	AnnotationDataError(std::string errorDetails)
		: mErrorDetails(errorDetails) {}
	const char* what() const noexcept override { return mErrorDetails.c_str(); }
private:
	std::string mErrorDetails{};
};


#endif // !ANNOTATIONDATA_H

