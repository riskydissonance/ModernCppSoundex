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
		static std::string encodeDigit(char letter);
		static std::string lastDigit(const std::string& encoding);
		static void encodeHead(std::string& encoding, const std::string& word);
		static void encodeLetter(std::string& encoding, char letter, char lastLetter);
		static void encodeTail(std::string& encoding, const std::string& word);
		static std::string encodeDigits(const std::string& word);
		static bool isComplete(const std::string& encoding);
	};
}

#endif