#include <iostream>
#include <fstream>
#include <string>

#include <nlohmann/json.hpp>

#include "error.hpp"
#include "liberinn/erinncsv.hpp"
#include "games/6/td2/td2.hpp"

// Currently just as simple as I can make it while still working
// to mod TMP 2's questions (just basic questions).
int main(int _iArgc, const char** _ppArgv) {
	// Verify usage.
	if (_iArgc != 3) {
		std::cerr << "Usage: ./jbmtp <source_file> <output_dir>." << std::endl;
		return Error::IncorrectArgs;
	}

	// Grab filepaths.
	std::string sSourceFile = _ppArgv[1];
	std::string sOutDir = _ppArgv[2];

	// Create questions.
	std::cout << "Generating questions." << std::endl;
	ErinnCSV csv(sSourceFile);
	std::vector<TriviaDeath2::Question> questions;
	while (!csv.IsEOF()) {
		questions.push_back(csv.GetLine());
	}

	// Generate output.
	nlohmann::json output;
	nlohmann::json questionList;
	for (int i = 0; i < questions.size(); i++) {
		questionList[i] = questions[i].ToJson();
	}
	output["content"] = questionList;

	std::ofstream o(sOutDir + "TDQuestion.jet");
	o << std::setw(4) << output << std::endl;
	o.close();

	return Error::OK;
}