#include "erinncsv.hpp"

ErinnCSV::ErinnCSV(std::string _sFilePath) {
	m_InputFile.open(_sFilePath);
}

ErinnCSV::~ErinnCSV() {
	m_InputFile.close();
}

std::vector<std::string> ErinnCSV::GetLine() {
	// Get var to return with.
	std::vector<std::string> toReturn;

	// Grab the line.
	char pcLine[MAX_LINE_LENGTH];
	m_InputFile.getline(pcLine, MAX_LINE_LENGTH);
	std::string sLine = pcLine;

	// Collect each string, I'm just being lazy because I doubt
	// a tab is gonna be used in any question or answer.
	std::string sTempLine;
	for (int i = 0; i < sLine.length(); i++) {
		if (sLine[i] == '\t') {
			toReturn.push_back(sTempLine);
			sTempLine.clear();
		}
		else {
			sTempLine.push_back(sLine[i]);
		}
	}
	// If the last char is a tab, we good. If it isn't, then add the last one.
	if (sLine[sLine.length() - 1] != '\t') {
		toReturn.push_back(sTempLine);
	}

	// Return it.
	return toReturn;
}

bool ErinnCSV::IsEOF() {
	return m_InputFile.eof();
}
