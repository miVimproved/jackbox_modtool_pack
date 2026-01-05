#include "argholder.hpp"

std::vector<std::string> ArgHolder::m_Args;
int ArgHolder::m_iCurrentArg;

void ArgHolder::SetupArgs(int _iArgc, const char **_ppArgv) {
	for (int i = 1; i < _iArgc; i++) {
		m_Args.push_back(_ppArgv[i]);
	}
}

std::string ArgHolder::GetNextInput(std::string _sPrompt) {
	// If we still have args remaining, give them
	// that and move on.
	if (m_iCurrentArg < m_Args.size()) {
		return m_Args[m_iCurrentArg++];
	}

	// If we don't, then ask the user for what they want.
	std::string toReturn;
	std::cout << _sPrompt << "\n> ";
	std::getline(std::cin, toReturn);
	return toReturn;
}
