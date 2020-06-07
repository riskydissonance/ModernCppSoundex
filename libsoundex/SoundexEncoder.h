#ifndef SoundexEncoder_h
#define SoundexEncoder_h
#include <string>

namespace soundex
{
	class SoundexEncoder
	{
	public:
		static std::string encode(const std::string& word);

	private:
		static std::string encodeDigit(const char letter);
		static std::string upperFront(const std::string& string);
		static char lower(char letter);
		static std::string head(const std::string& word);
		static std::string lastDigit(const std::string& encoding);
		static std::string encodeDigits(const std::string& word);
		static std::string tail(const std::string& word);
		static bool isComplete(const std::string& encoding);
		static std::string zeroPad(const std::string& word);
	};
}

#endif