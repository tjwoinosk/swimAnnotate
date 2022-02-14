#ifndef ANNOTATIONDATA_H
#define ANNOTATIONDATA_H

#include <string>
#include <exception>

class AnnotationData
{
public:
	AnnotationData() = default;
	AnnotationData(int xPoint, int yPoint) : mXPoint(xPoint), mYPoint(yPoint) {}
	virtual std::string getClass() = 0;
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
	KeyPointData() = default;
	KeyPointData(int xPoint, int yPoint) : AnnotationData(xPoint, yPoint) {}
	KeyPointData(int xPoint, int yPoint, int itsNumber) : AnnotationData(xPoint, yPoint) { setClassNumber(itsNumber); }
	KeyPointData(int itsNumber) { setClassNumber(itsNumber); }
	bool isTheSameAs(KeyPointData* otherKeyPoint);
	bool isValid();
	virtual std::string getClass() = 0;
protected:
	virtual void setClassNumber(int itsNumber) = 0;
	std::string baseGetClass();
	void baseSetClassNumber(int itsNumber);
	int mNumber{ -1 };
	std::string mClassName{ "" };
	int mMaxSubClass{ -1 };
	int mMinSubClass{ -1 };
};

class WallLeftKeyPoint : public KeyPointData
{
public:
	WallLeftKeyPoint() = default;
	WallLeftKeyPoint(int xPoint, int yPoint) : KeyPointData(xPoint, yPoint) {}
	WallLeftKeyPoint(int xPoint, int yPoint, int itsNumber) : KeyPointData(xPoint, yPoint) { setClassNumber(itsNumber); }
	WallLeftKeyPoint(int itsNumber) { setClassNumber(itsNumber); }
	std::string getClass() override;
private:
	void setClassNumber(int itsNumber) override;
};

class WallRightKeyPoint : public KeyPointData
{
public:
	WallRightKeyPoint() = default;
	WallRightKeyPoint(int xPoint, int yPoint) : KeyPointData(xPoint, yPoint) {}
	WallRightKeyPoint(int xPoint, int yPoint, int itsNumber) : KeyPointData(xPoint, yPoint) { setClassNumber(itsNumber); }
	WallRightKeyPoint(int itsNumber) { setClassNumber(itsNumber); }
	std::string getClass() override;
private:
	void setClassNumber(int itsNumber) override;
};


class WallTopKeyPoint : public KeyPointData
{
public:
	WallTopKeyPoint() = default;
	WallTopKeyPoint(int xPoint, int yPoint) : KeyPointData(xPoint, yPoint) {}
	WallTopKeyPoint(int xPoint, int yPoint, int itsNumber) : KeyPointData(xPoint, yPoint) { setClassNumber(itsNumber); }
	WallTopKeyPoint(int itsNumber) { setClassNumber(itsNumber); }
	std::string getClass() override;
private:
	void setClassNumber(int itsNumber) override;
};

class WallBottomKeyPoint : public KeyPointData
{
public:
	WallBottomKeyPoint() = default;
	WallBottomKeyPoint(int xPoint, int yPoint) : KeyPointData(xPoint, yPoint) {}
	WallBottomKeyPoint(int xPoint, int yPoint, int itsNumber) : KeyPointData(xPoint, yPoint) { setClassNumber(itsNumber); }
	WallBottomKeyPoint(int itsNumber) { setClassNumber(itsNumber); }
	std::string getClass() override;
private:
	void setClassNumber(int itsNumber) override;
};

class FloatingRightKeyPoint : public KeyPointData
{
public:
	FloatingRightKeyPoint() = default;
	FloatingRightKeyPoint(int xPoint, int yPoint) : KeyPointData(xPoint, yPoint) {}
	FloatingRightKeyPoint(int xPoint, int yPoint, int itsNumber) : KeyPointData(xPoint, yPoint) { setClassNumber(itsNumber); }
	FloatingRightKeyPoint(int itsNumber) { setClassNumber(itsNumber); }
	std::string getClass() override;
private:
	void setClassNumber(int itsNumber) override;
};

class FloatingLeftKeyPoint : public KeyPointData
{
public:
	FloatingLeftKeyPoint() = default;
	FloatingLeftKeyPoint(int xPoint, int yPoint) : KeyPointData(xPoint, yPoint) {}
	FloatingLeftKeyPoint(int xPoint, int yPoint, int itsNumber) : KeyPointData(xPoint, yPoint) { setClassNumber(itsNumber); }
	FloatingLeftKeyPoint(int itsNumber) { setClassNumber(itsNumber); }
	std::string getClass() override;
private:
	void setClassNumber(int itsNumber) override;
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

