#include "ExportData.h"

#include "KeyPointData.h"
#include "PoolData.h"
#include "FrameData.h"
#include "ExportConstants.h"

#include <sstream>
#include <iostream>
#include <fstream>
#include <exception>

void ExportData::writeData(const std::string& dataToWrite)
{
	if(mOut.is_open())
		mOut << dataToWrite << std::endl;
}

std::string ExportData::formatFrameData(const FrameData& frameDataToWrite)
{
	if (!frameDataToWrite.isDefined())
		return "No Frame Data Found";

	std::stringstream buffer;

	buffer << ExportConstants::FrameStartingToken << ExportConstants::delim;
	buffer << ExportConstants::FileNameToken << ExportConstants::delim << frameDataToWrite.getFrameName() << ExportConstants::delim;
	buffer << ExportConstants::FrameResToken << ExportConstants::delim << frameDataToWrite.getFrameHeight() << ExportConstants::delim << frameDataToWrite.getFrameWidth();

	return buffer.str();
}

std::string ExportData::formatPoolData(const PoolData& poolDataToWrite)
{
	if (!poolDataToWrite.isDefined())
		return "No Pool Data Found";

	std::stringstream buffer;
	buffer << ExportConstants::PoolStartingToken << ExportConstants::delim;
	buffer << ExportConstants::LengthPoolToken << ExportConstants::delim << poolDataToWrite.getLengthPool() << ExportConstants::delim;
	buffer << ExportConstants::NumberLanesToken << ExportConstants::delim << poolDataToWrite.getNumberLanes() << ExportConstants::delim;
	buffer << ExportConstants::BumpersToken << ExportConstants::delim << std::boolalpha << poolDataToWrite.poolHasbumpers() << ExportConstants::delim;
	buffer << ExportConstants::MiddleBulkheadToken << ExportConstants::delim << poolDataToWrite.poolHasMiddleBulkhead();

	return buffer.str();
}

std::string ExportData::formatKeyPointData(const KeyPointData* dataToWrite)
{
	if (dataToWrite == nullptr)
		return "No Key Point Data Found";

	std::stringstream buffer;

	buffer << ExportConstants::KeyPointStartingToken << ExportConstants::delim;
	buffer << dataToWrite->getObjectID() << ExportConstants::delim;
	buffer << dataToWrite->getXPoint() << ExportConstants::delim;
	buffer << dataToWrite->getYPoint();

	return buffer.str();
}

bool ExportData::openWriteStream(const std::string& fileName)
{
	mFileName = fileName;
	closeFileStream();
	try {
		mOut.open(mFileName, std::ios_base::out);
		return true;
	}
	catch (const std::ifstream::failure& e) {
		std::cerr << "Exception opening file: " << e.what() << std::endl;
		mOut.clear();
		return false;
	}
}

void ExportData::closeFileStream()
{
	if (mOut.is_open())
		mOut.close();
}
