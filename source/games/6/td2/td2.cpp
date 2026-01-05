#include <iostream>

#include "td2.hpp"


//*********************************
// Answer
//*********************************

TriviaDeath2::Answer::Answer() {

}

TriviaDeath2::Answer::Answer(std::string _sOriginText) {
	ReadFromString(_sOriginText);
}

void TriviaDeath2::Answer::ReadFromString(std::string _sOriginText) {
	// Stupid but it works
	m_bIsCorrect = true;
	std::string sStartChars = "[C] ";
	for (int i = 0; i < sStartChars.length(); i++) {
		if (_sOriginText[i] != sStartChars[i]) {
			m_bIsCorrect = false;
			break;
		}
	}
	if (m_bIsCorrect) {
		_sOriginText = _sOriginText.erase(0, sStartChars.length() - 1);
	}
	m_sText = _sOriginText;
}

bool TriviaDeath2::Answer::IsCorrect() {
	return m_bIsCorrect;
}

void TriviaDeath2::Answer::SetCorrect(bool _bCorrect) {
	m_bIsCorrect = _bCorrect;
}

std::string TriviaDeath2::Answer::GetText() {
	return m_sText;
}

void TriviaDeath2::Answer::SetText(std::string _sNewText) {
	m_sText = _sNewText;
}

nlohmann::json TriviaDeath2::Answer::ToJson() {
	nlohmann::json toReturn;
	toReturn["correct"] = m_bIsCorrect;
	toReturn["text"] = m_sText;
	return toReturn;
}

//*********************************
// Question
//*********************************

TriviaDeath2::Question::Question(std::vector<std::string> _sTSVLine) {
	m_sText = _sTSVLine[0];
	for (int i = 0; i < ANSWER_COUNT; i++) {
		m_Answers[i].ReadFromString(_sTSVLine[i + 1]);
	}
}

nlohmann::json TriviaDeath2::Question::ToJson() {
	nlohmann::json toReturn;
	
	// Setup question info.
	toReturn["id"] = "0"; // Yes, this is a string.
	toReturn["text"] = m_sText;

	// Generate answer list.
	nlohmann::json answerList;
	for (int i = 0; i < ANSWER_COUNT; i++) {
		answerList[i] = m_Answers[i].ToJson();
	}
	toReturn["choices"] = answerList;

	// Return our lovely json.
	return toReturn;
}
