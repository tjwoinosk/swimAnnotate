#ifndef ANNOTATIONDATA_H
#define ANNOTATIONDATA_H

#include <string>
#include <exception>

class AnnotationData
{
public:
	AnnotationData() = default;
	AnnotationData(int xPoint, int yPoint) : mXPoint(xPoint), mYPoint(yPoint) {}
	virtual std::string getObjectID() const = 0;
	bool isTheSamePointAs(AnnotationData* otherPoint);
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
	bool isTheSameNumberAs(KeyPointData* otherKeyPoint) const;
	bool isTheSameClass(KeyPointData* otherKeyPoint) const;
	bool isDefinedClass() const;
	virtual KeyPointData* deepCopy() const { return new KeyPointData(*this); };
	std::string getObjectID() const override { return baseGetObjectID(); }
protected:
	virtual void setClass(int itsNumber) { mNumber = itsNumber; }
	std::string baseGetObjectID() const;
	void baseSetClassNumber(int itsNumber);
	int mNumber{-1};
	std::string mClassName{""};
	int mMaxSubClass{-1};
	int mMinSubClass{-1};
};

class WallLeftKeyPoint : public KeyPointData
{
public:
	WallLeftKeyPoint(const WallLeftKeyPoint& copy) : KeyPointData(copy.mNumber, copy.mXPoint, copy.mYPoint) { setClass(copy.mNumber); }
	WallLeftKeyPoint(int itsNumber, int xPoint, int yPoint) : KeyPointData(itsNumber, xPoint, yPoint) { setClass(itsNumber); }
	WallLeftKeyPoint(int itsNumber) : KeyPointData() { setClass(itsNumber); }
	WallLeftKeyPoint* deepCopy() const override { return new WallLeftKeyPoint(*this); };
private:
	void setClass(int itsNumber) override;
};

class WallRightKeyPoint : public KeyPointData
{
public:
	WallRightKeyPoint(const WallRightKeyPoint& copy) : KeyPointData(copy.mNumber, copy.mXPoint, copy.mYPoint) { setClass(copy.mNumber); }
	WallRightKeyPoint(int itsNumber, int xPoint, int yPoint) : KeyPointData(itsNumber, xPoint, yPoint) { setClass(itsNumber); }
	WallRightKeyPoint(int itsNumber) : KeyPointData() { setClass(itsNumber); }
	WallRightKeyPoint* deepCopy() const override { return new WallRightKeyPoint(*this); };
private:
	void setClass(int itsNumber) override;
};


class WallTopKeyPoint : public KeyPointData
{
public:
	WallTopKeyPoint(const WallTopKeyPoint& copy) : KeyPointData(copy.mNumber, copy.mXPoint, copy.mYPoint) { setClass(copy.mNumber); }
	WallTopKeyPoint(int itsNumber, int xPoint, int yPoint) : KeyPointData(itsNumber, xPoint, yPoint) { setClass(itsNumber); }
	WallTopKeyPoint(int itsNumber) : KeyPointData() { setClass(itsNumber); }
private:
	void setClass(int itsNumber) override;
};

class WallBottomKeyPoint : public KeyPointData
{
public:
	WallBottomKeyPoint(const WallBottomKeyPoint& copy) : KeyPointData(copy.mNumber, copy.mXPoint, copy.mYPoint) { setClass(copy.mNumber); }
	WallBottomKeyPoint(int itsNumber, int xPoint, int yPoint) : KeyPointData(itsNumber, xPoint, yPoint) { setClass(itsNumber); }
	WallBottomKeyPoint(int itsNumber) : KeyPointData() { setClass(itsNumber); }
	WallBottomKeyPoint* deepCopy() const override { return new WallBottomKeyPoint(*this); };
private:
	void setClass(int itsNumber) override;
};

class FloatingRightKeyPoint : public KeyPointData
{
public:
	FloatingRightKeyPoint(const FloatingRightKeyPoint& copy) : KeyPointData(copy.mNumber, copy.mXPoint, copy.mYPoint) { setClass(copy.mNumber); }
	FloatingRightKeyPoint(int itsNumber, int xPoint, int yPoint) : KeyPointData(itsNumber, xPoint, yPoint) { setClass(itsNumber); }
	FloatingRightKeyPoint(int itsNumber) : KeyPointData() { setClass(itsNumber); }
	FloatingRightKeyPoint* deepCopy() const override { return new FloatingRightKeyPoint(*this); };
private:
	void setClass(int itsNumber) override;
};

class FloatingLeftKeyPoint : public KeyPointData
{
public:
	FloatingLeftKeyPoint(const FloatingLeftKeyPoint& copy) : KeyPointData(copy.mNumber, copy.mXPoint, copy.mYPoint) { setClass(copy.mNumber); }
	FloatingLeftKeyPoint(int itsNumber, int xPoint, int yPoint) : KeyPointData(itsNumber, xPoint, yPoint) { setClass(itsNumber); }
	FloatingLeftKeyPoint(int itsNumber) : KeyPointData() { setClass(itsNumber); }
	FloatingLeftKeyPoint* deepCopy() const override { return new FloatingLeftKeyPoint(*this); };
private:
	void setClass(int itsNumber) override;
};

class BulkheadLeftKeyPoint : public KeyPointData
{
public:
	BulkheadLeftKeyPoint(const BulkheadLeftKeyPoint& copy) : KeyPointData(copy.mNumber, copy.mXPoint, copy.mYPoint) { setClass(copy.mNumber); }
	BulkheadLeftKeyPoint(int itsNumber, int xPoint, int yPoint) : KeyPointData(itsNumber, xPoint, yPoint) { setClass(itsNumber); }
	BulkheadLeftKeyPoint(int itsNumber) : KeyPointData() { setClass(itsNumber); }
	BulkheadLeftKeyPoint* deepCopy() const override { return new BulkheadLeftKeyPoint(*this); };
private:
	void setClass(int itsNumber) override;
};

class BulkheadRightKeyPoint : public KeyPointData
{
public:
	BulkheadRightKeyPoint(const BulkheadRightKeyPoint& copy) : KeyPointData(copy.mNumber, copy.mXPoint, copy.mYPoint) { setClass(copy.mNumber); }
	BulkheadRightKeyPoint(int itsNumber, int xPoint, int yPoint) : KeyPointData(itsNumber, xPoint, yPoint) { setClass(itsNumber); }
	BulkheadRightKeyPoint(int itsNumber) : KeyPointData() { setClass(itsNumber); }
	BulkheadRightKeyPoint* deepCopy() const override { return new BulkheadRightKeyPoint(*this); };
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

