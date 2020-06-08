#ifndef soundexencoder_h
#define soundexencoder_h

#include <string>

namespace soundex
{
	class SoundexEncoder
	{

	public:
		std::string encode(const std::string& word);

	private:
		std::string encodeDigit(char letter);
		std::string lastDigit(const std::string& encoding);
		void encodeHead(std::string& encoding, const std::string& word);
		void encodeLetter(std::string& encoding, char letter, char lastLetter);
		void encodeTail(std::string& encoding, const std::string& word);
		std::string encodeDigits(const std::string& word);
		bool isComplete(const std::string& encoding);
	};
}

#endif