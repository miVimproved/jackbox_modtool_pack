#ifndef ARGHOLDER_HPP
#define ARGHOLDER_HPP

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class ArgHolder {
public:
	static void SetupArgs(int _iArgc, const char** _ppArgv);

	template <typename T>
	static T GetNext(std::string _sPrompt) {
		// If they want a string, just give it.
		// Templates hurt my brain and this f*cking works.
		if constexpr (std::is_same<T, std::string>::value) {
			return GetNextInput(_sPrompt);
		}

		std::stringstream input(GetNextInput(_sPrompt));
		T toReturn;
		input >> toReturn;
		return toReturn;
	}

private:
	static std::string GetNextInput(std::string _sPrompt);

	inline static std::vector<std::string> m_Args;
	inline static int m_iCurrentArg;
};

#endif // ARGHOLDER_HPP