#ifndef stringutil_h
#define stringutil_h

#include <string>

namespace soundex
{
	inline std::string head(const std::string& word)
	{
		return word.substr(0, 1);
	}

	inline std::string tail(const std::string& word)
	{
		return word.substr(1);
	}

	inline std::string zeroPad(const std::string& word, const unsigned long long maxLength)
	{
		if (word.length() >= maxLength)
			return word.substr(0, maxLength);
		const auto zeroesNeeded = maxLength - word.length();
		return word + std::string(zeroesNeeded, '0');
	}
}
#endif