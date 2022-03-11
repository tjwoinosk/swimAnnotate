#include "dataSaver.h"

#include "ExportData.h"
#include <string>
#include <vector>

#include "PoolData.h"
#include "FrameData.h"
#include "KeyPointManager.h"
#include "KeyPointData.h"

void DataSaver::saveData(int managerNumber)
{
	PoolData poolData;
	FrameData frameData;
	KeyPointManager managerData(poolData);

	mTheExporter->writeData(mTheExporter->formatFrameData(frameData));
	mTheExporter->writeData(mTheExporter->formatPoolData(poolData));

	std::vector<KeyPointData*> theKPData = managerData.getCopyOfKeyPoints();
	for (KeyPointData* point : theKPData)
		mTheExporter->writeData(mTheExporter->formatKeyPointData(point));
}

void DataSaver::configureExporter(const std::string& fileName)
{
	mIsConfigured = mTheExporter->openWriteStream(fileName);
}
