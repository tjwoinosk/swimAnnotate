#ifndef EXPORTDATA_H
#define EXPORTDATA_H

#include <string>
#include <fstream>

class FrameData;
class PoolData;
class KeyPointData;

class ExportData
{
public:
	~ExportData() { closeFileStream(); }
	ExportData(std::string fileName = "test.txt") : mFileName(fileName) { }

	void writeData(const std::string &DataToWrite);

	std::string formatFrameData(const FrameData& frameDataToWrite);
	std::string formatPoolData(const PoolData& poolDataToWrite);
	std::string formatKeyPointData(const KeyPointData* dataToWrite);

	bool isConfigured() { return mOut.is_open(); };
	bool openWriteStream(const std::string& fileName);
	void closeFileStream();

private:
	std::string mFileName{};
	std::fstream mOut{};
};


#endif // !EXPORTDATA_H

