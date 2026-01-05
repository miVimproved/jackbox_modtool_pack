#include <iostream>
#include <fstream>
#include <string>

#include <nlohmann/json.hpp>

#include "error.hpp"
#include "liberinn/erinncsv.hpp"
#include "games/6/td2/td2.hpp"
#include "argholder/argholder.hpp"

// Currently just as simple as I can make it while still working
// to mod TMP 2's questions (just basic questions).
int main(int _iArgc, const char** _ppArgv) {
	ArgHolder::SetupArgs(_iArgc, _ppArgv);

	// Grab filepaths.
	std::string sSourceFile = ArgHolder::GetNext<std::string>("What source file do you want?");
	std::string sOutDir =  ArgHolder::GetNext<std::string>("What destination file do you want?");

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

	std::cout << "Saving to " << sOutDir << "TDQuestion.jet" << std::endl;
	std::ofstream o(sOutDir + "TDQuestion.jet");
	o << std::setw(4) << output << std::endl;
	o.close();

	return Error::OK;
}