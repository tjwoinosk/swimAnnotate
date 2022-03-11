#include "ImportData.h"

#include "KeyPointData.h"
#include "PoolData.h"
#include "FrameData.h"
#include "PoolConstants.h"
#include "ExportConstants.h"

#include <sstream>
#include <iostream>
#include <fstream>
#include <exception>

KeyPointData* ImportData::readKeyPointData(const std::string& line)
{
	std::vector<std::string> tokens = tokenizeString(line);
	std::size_t numberExpectedTokens = 4;
	if (tokens.size() != numberExpectedTokens)
		return nullptr;

	KeyPointData* returnData = nullptr;

	for (std::size_t ii = 0; ii < mPossibleKeyPoints.size(); ii++) {
		if (mPossibleKeyPoints[ii]->getObjectID() == tokens[1]) {
			returnData = mPossibleKeyPoints[ii]->deepCopy();
			break;
		}
	}

	if (returnData != nullptr) {
		returnData->setXPoint(std::stoi(tokens[2]));
		returnData->setYPoint(std::stoi(tokens[3]));
	}

	return returnData;
}

PoolData ImportData::readPoolData(const std::string& line)
{
	std::size_t numberExpectedTokens = 9;
	PoolData newPool;

	std::vector<std::string> tokens = tokenizeString(line);
	if (tokens.size() != numberExpectedTokens)
		return newPool;

	bool tempBool;
	for (std::size_t ii = 0; ii < tokens.size(); ii++) {
		if (tokens[ii] == ExportConstants::LengthPoolToken) {
			if (ii + 1 >= numberExpectedTokens)
				continue;
			newPool.setLengthPool(std::stoi(tokens[ii + 1]));
		}
		else if (tokens[ii] == ExportConstants::NumberLanesToken) {
			if (ii + 1 >= numberExpectedTokens)
				continue;
			newPool.setNumberLanes(std::stoi(tokens[ii + 1]));
		}
		else if (tokens[ii] == ExportConstants::BumpersToken) {
			if (ii + 1 >= numberExpectedTokens)
				continue;
			std::istringstream(tokens[ii + 1]) >> std::boolalpha >> tempBool;
			newPool.specifyBumpers(tempBool);
		}
		else if (tokens[ii] == ExportConstants::MiddleBulkheadToken) {
			if (ii + 1 >= numberExpectedTokens)
				continue;
			std::istringstream(tokens[ii + 1]) >> std::boolalpha >> tempBool;
			try {
				newPool.specifyMiddlePool(tempBool);
			}
			catch (PoolDataError e) {
				std::cerr << e.what() << std::endl;
			}
		}
	}
	return newPool;
}

FrameData ImportData::readFrameData(const std::string& line)
{
	std::size_t numberExpectedTokens = 6;
	FrameData newFrame;

	std::vector<std::string> tokens = tokenizeString(line);
	if (tokens.size() != numberExpectedTokens)
		return newFrame;

	for (std::size_t ii = 0; ii < tokens.size(); ii++) {
		if (tokens[ii] == ExportConstants::FileNameToken) {
			if (ii + 1 >= numberExpectedTokens)
				continue;
			newFrame.setFrameName(tokens[ii + 1]);
		}
		else if (tokens[ii] == ExportConstants::FrameResToken) {
			if (ii + 2 >= numberExpectedTokens)
				continue;
			newFrame.setFrameRes(std::stoi(tokens[ii + 1]), std::stoi(tokens[ii + 2]));
		}
	}
	return newFrame;
}

std::vector<std::string> ImportData::tokenizeString(const std::string& input)
{
	char delim{ ExportConstants::delim[0] };//convert to char
	std::vector<std::string> results{};
	std::vector<std::size_t> delimIndx{};

	//ensure delimiter is at front and end
	std::string copyIn{ delim };
	copyIn += input;
	copyIn.push_back(delim);

	for (std::size_t ii = 0; ii < copyIn.size(); ii++) {
		if (copyIn[ii] == delim) {
			delimIndx.push_back(ii);
		}
	}

	std::size_t pos{ 0 }; std::size_t subSize{ 0 };
	for (std::size_t ii = 0; ii < delimIndx.size() - 1; ii++) {
		if (delimIndx[ii] + 1 == delimIndx[ii + 1])
			continue;
		pos = delimIndx[ii] + 1;
		subSize = delimIndx[ii + 1] - pos;
		results.push_back(copyIn.substr(pos, subSize));
	}

	return results;
}

void ImportData::fillPossibleKeyPoints()
{
	for (int ii = 0; ii < PoolConstants::maxVerticalPoints; ii++) {
		mPossibleKeyPoints.push_back(new WallLeftKeyPoint(ii));
		mPossibleKeyPoints.push_back(new WallRightKeyPoint(ii));
		mPossibleKeyPoints.push_back(new FloatingRightKeyPoint(ii));
		mPossibleKeyPoints.push_back(new FloatingLeftKeyPoint(ii));
		mPossibleKeyPoints.push_back(new BulkheadLeftKeyPoint(ii));
		mPossibleKeyPoints.push_back(new BulkheadRightKeyPoint(ii));
	}

	for (int ii = 0; ii < PoolConstants::maxHorizontalPoints; ii++) {
		mPossibleKeyPoints.push_back(new WallTopKeyPoint(ii));
		mPossibleKeyPoints.push_back(new WallBottomKeyPoint(ii));
	}
}

void ImportData::destoryPossibleKeyPoints()
{
	for (std::size_t ii = 0; ii < mPossibleKeyPoints.size(); ii++) {
		delete mPossibleKeyPoints[ii];
	}
}

std::string ImportData::getLine()
{
	std::string returnStr{};
	if (mIn.is_open())
		std::getline(mIn, returnStr);

	return returnStr;
}

bool ImportData::openReadStream()
{
	try {
		mIn.open(mFileName, std::ios_base::in);
		return true;
	}
	catch (const std::ifstream::failure& e) {
		std::cerr << "Exception opening file: " << e.what() << std::endl;
		mIn.clear();
		return false;
	}
}

void ImportData::closeFileStream()
{
	if (mIn.is_open())
		mIn.close();
}