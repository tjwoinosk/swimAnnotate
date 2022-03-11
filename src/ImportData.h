#ifndef IMPORTDATA_H
#define IMPORTDATA_H

#include <vector>
#include <string>
#include <fstream>
#include "ExportConstants.h"

class FrameData;
class PoolData;
class KeyPointData;

class ImportData
{
public:
	~ImportData() { destoryPossibleKeyPoints(); closeFileStream(); }
	ImportData(std::string fileName = "test.txt") : mFileName(fileName) { fillPossibleKeyPoints(); }

	std::string getLine();
	FrameData readFrameData(const std::string& line);
	PoolData readPoolData(const std::string& line);
	KeyPointData* readKeyPointData(const std::string& line);
	std::vector<std::string> tokenizeString(const std::string& input);

	bool openReadStream();

private:
	void closeFileStream();
	void fillPossibleKeyPoints();
	void destoryPossibleKeyPoints();
	std::vector<KeyPointData*> mPossibleKeyPoints{};
	std::string mFileName{};
	std::fstream mIn{};

};

#endif // !IMPORTDATA_H

