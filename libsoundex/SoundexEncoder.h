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
		static std::string head(const std::string& word);
		static std::string encodedDigits(const std::string& word);
		static std::string encodedDigit();
		static std::string zeroPad(const std::string& word);
	};
}

#endif