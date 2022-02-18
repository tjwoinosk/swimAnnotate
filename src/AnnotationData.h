#ifndef ANNOTATIONDATA_H
#define ANNOTATIONDATA_H

#include <string>
#include <exception>

class AnnotationData
{
public:
	AnnotationData() = default;
	AnnotationData(int xPoint, int yPoint) : mXPoint(xPoint), mYPoint(yPoint) {}
	virtual std::string getClass() const = 0;
	virtual void setXPoint(int xPoint);
	virtual void setYPoint(int yPoint);
	virtual void setPoint(int xPoint, int yPoint);
	int getXPoint() { return mXPoint; }
	int getYPoint() { return mYPoint; }

	virtual ~AnnotationData() = default;

protected:
	int mXPoint{ 0 };
	int mYPoint{ 0 };
};

class KeyPointData : public AnnotationData
{
public:
	KeyPointData::KeyPointData() : AnnotationData() {}
	KeyPointData(int itsNumber, int xPoint, int yPoint) : AnnotationData(xPoint, yPoint) { setClass(itsNumber); }
	KeyPointData(int itsNumber) : AnnotationData() { setClass(itsNumber); }
	bool isTheSameAs(KeyPointData* otherKeyPoint);
	bool isDefinedClass() const;
	std::string getClass() const override { return baseGetClass(); }
protected:
	virtual void setClass(int itsNumber) { mNumber = itsNumber; }
	std::string baseGetClass() const;
	void baseSetClassNumber(int itsNumber);
	int mNumber{-1};
	std::string mClassName{""};
	int mMaxSubClass{-1};
	int mMinSubClass{-1};
};

class WallLeftKeyPoint : public KeyPointData
{
public:
	WallLeftKeyPoint(int itsNumber, int xPoint, int yPoint) : KeyPointData(itsNumber, xPoint, yPoint) { setClass(itsNumber); }
	WallLeftKeyPoint(int itsNumber) : KeyPointData() { setClass(itsNumber); }
private:
	void setClass(int itsNumber) override;
};

class WallRightKeyPoint : public KeyPointData
{
public:
	WallRightKeyPoint(int itsNumber, int xPoint, int yPoint) : KeyPointData(itsNumber, xPoint, yPoint) { setClass(itsNumber); }
	WallRightKeyPoint(int itsNumber) : KeyPointData() { setClass(itsNumber); }
private:
	void setClass(int itsNumber) override;
};


class WallTopKeyPoint : public KeyPointData
{
public:
	WallTopKeyPoint(int itsNumber, int xPoint, int yPoint) : KeyPointData(itsNumber, xPoint, yPoint) { setClass(itsNumber); }
	WallTopKeyPoint(int itsNumber) : KeyPointData() { setClass(itsNumber); }
private:
	void setClass(int itsNumber) override;
};

class WallBottomKeyPoint : public KeyPointData
{
public:
	WallBottomKeyPoint(int itsNumber, int xPoint, int yPoint) : KeyPointData(itsNumber, xPoint, yPoint) { setClass(itsNumber); }
	WallBottomKeyPoint(int itsNumber) : KeyPointData() { setClass(itsNumber); }
private:
	void setClass(int itsNumber) override;
};

class FloatingRightKeyPoint : public KeyPointData
{
public:
	FloatingRightKeyPoint(int itsNumber, int xPoint, int yPoint) : KeyPointData(itsNumber, xPoint, yPoint) { setClass(itsNumber); }
	FloatingRightKeyPoint(int itsNumber) : KeyPointData() { setClass(itsNumber); }
private:
	void setClass(int itsNumber) override;
};

class FloatingLeftKeyPoint : public KeyPointData
{
public:
	FloatingLeftKeyPoint(int itsNumber, int xPoint, int yPoint) : KeyPointData(itsNumber, xPoint, yPoint) { setClass(itsNumber); }
	FloatingLeftKeyPoint(int itsNumber) : KeyPointData() { setClass(itsNumber); }
private:
	void setClass(int itsNumber) override;
};

class KeyPointDataError : public std::exception
{
public:
	KeyPointDataError(std::string errorDetails)
		: mErrorDetails(errorDetails) {}
	const char* what() const noexcept override { return mErrorDetails.c_str(); }
private:
	std::string mErrorDetails{};
};


#endif // !ANNOTATIONDATA_H

