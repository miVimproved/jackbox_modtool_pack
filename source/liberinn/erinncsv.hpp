#pragma once

#include <string>
#include <fstream>
#include <vector>

class ErinnCSV {
public:
	static const int MAX_LINE_LENGTH = 256;

	ErinnCSV(std::string _sFilePath);
	~ErinnCSV();
	std::vector<std::string> GetLine();
	bool IsEOF();

private:
	std::ifstream m_InputFile;

};