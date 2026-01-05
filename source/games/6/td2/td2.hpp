#pragma once

#include <string>
#include <nlohmann/json.hpp>

namespace TriviaDeath2 {
	class Answer {
	public:
		Answer();
		Answer(std::string _sOriginText);

		void ReadFromString(std::string _sOriginText);

		bool IsCorrect();
		void SetCorrect(bool _bCorrect);

		std::string GetText();
		void SetText(std::string _sNewText);

		nlohmann::json ToJson();

	private:
		bool m_bIsCorrect;
		std::string m_sText;
	};

	class Question {
	public:
		static const int ANSWER_COUNT = 4;

		Question(std::vector<std::string> _sTSVLine);

		nlohmann::json ToJson();

	private:
		std::string m_sText;
		Answer m_Answers[ANSWER_COUNT];
	};
}