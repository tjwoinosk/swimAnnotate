#ifndef POOLDATA_H
#define POOLDATA_H

#include <exception>
#include <string>

class PoolData
{
public:
	void setNumberLanes(int numberLanes);
	int getNumberLanes();

	void setLengthPool(int lengthPool);
	int getLengthPool();

	void specifyBumpers(bool poolHasBumpers);
	bool poolHasbumpers();

	bool isDefined();

	PoolData& operator= (const PoolData& newPool);

private:
	int mLengthPool{ 0 };
	int mNumberLanes{ 0 };
	int mHasBumpers{ -1 };
	const int LCM = 50;
	const int SCM = 25;
	const int possibleNumberLanes[3]{ 6, 8, 10 };
};

class PoolDataError : public std::exception
{
public:
	const char* what() const noexcept override { return mErrorMessage.c_str(); }
private:
	const std::string mErrorMessage{ "Pool Data Error: Improper data was given" };
};

class LengthPoolError : public PoolDataError
{
public:
	LengthPoolError(std::string errorDetails)
		: mErrorDetails(errorDetails) {}
	const char* what() const noexcept override { return mErrorDetails.c_str(); }

private:
	std::string mErrorDetails{};
};

class NumberLanesError : public PoolDataError
{
public:
	NumberLanesError(std::string errorDetails)
		: mErrorDetails(errorDetails) {}
	const char* what() const noexcept override { return mErrorDetails.c_str(); }

private:
	const std::string mErrorDetails{};
};

class HasBumpersError : public PoolDataError
{
public:
	HasBumpersError(std::string errorDetails)
		: mErrorDetails(errorDetails) {}
	const char* what() const noexcept override { return mErrorDetails.c_str(); }

private:
	const std::string mErrorDetails{};
};


#endif // !POOLDATA_H


