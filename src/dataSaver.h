#ifndef DATASAVER_H
#define DATASAVER_H

#include <string>

class ExportData;

class DataSaver
{
public:
	DataSaver(ExportData* exportObject) : mTheExporter(exportObject) {}

	void saveData(int managerNumber);
	bool isConfigured() { return mIsConfigured; }
	void configureExporter(const std::string& fileName);

private:
	ExportData* mTheExporter;
	bool mIsConfigured{};
};

#endif // !DATASAVER_H

