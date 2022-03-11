#ifndef POOLKEYPOINTVALIDATOR_H
#define POOLKEYPOINTVALIDATOR_H

#include <vector>
#include <exception>
#include <string>

class PoolData;
class KeyPointData;

class PoolKeyPointValidator
{
public:
	PoolKeyPointValidator(PoolData& inputPool);
	virtual ~PoolKeyPointValidator() { deallocateKeyPointPoolModel(); }

	bool validateKeyPoint(KeyPointData* candidateKeypoint);
	std::vector<KeyPointData*> getCopyOfPoolModel();

protected:
	bool keyPointNotInPool(KeyPointData* candidateKeypoint);

private:
	void addVerticalPoints();
	bool isValidVerticalPoint(int keyPoint);
	void addHorizontalPoints();
	bool isValidHorizontalPoint(int keyPoint);
	
	bool discriminationIsNotPossible();
	void createKeyPointPoolModel();
	void deallocateKeyPointPoolModel();

	PoolData& mThePool;
	std::vector<KeyPointData*> mKeyPointPoolModel;
};

class PoolKeyPointValidatorError : public std::exception
{
public:
	PoolKeyPointValidatorError(std::string errorDetails) : mErrorMessage(errorDetails) {}
	const char* what() const noexcept override { return mErrorMessage.c_str(); }
private:
	std::string mErrorMessage{};
};


#endif // !POOLKEYPOINTVALIDATOR_H

