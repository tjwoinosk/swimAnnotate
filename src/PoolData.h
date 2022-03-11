#ifndef POOLDATA_H
#define POOLDATA_H

#include <exception>
#include <string>

class PoolData
{
public:
	PoolData() = default;
	PoolData(bool hasBumpers, bool hasMiddleBulkhead, int length, int numberLanes);
	PoolData(const PoolData& pool);
	int getNumberLanes() const;
	int getLengthPool() const;
	bool poolHasbumpers() const;
	bool poolHasMiddleBulkhead() const;
	bool isDefined() const;

	void setNumberLanes(int numberLanes);
	void setLengthPool(int lengthPool);
	void specifyBumpers(bool poolHasBumpers);
	void specifyMiddlePool(bool poolHasMiddleBulkhead);

	PoolData& operator= (const PoolData& newPool);

private:
	int mLengthPool{ 0 };
	int mNumberLanes{ 0 };
	int mHasBumpers{ -1 };
	int mHasMiddleBulkhead{ -1 };
};

class PoolDataError : public std::exception
{
public:
	PoolDataError(std::string errorDetails) : mErrorMessage(errorDetails) {}
	const char* what() const noexcept override { return mErrorMessage.c_str(); }
private:
	std::string mErrorMessage{};
};


#endif // !POOLDATA_H


