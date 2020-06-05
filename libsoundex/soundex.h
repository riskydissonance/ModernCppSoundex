#ifndef Soundex_h
#define Soundex_h
#include <string>


class Soundex
{
public:
	static std::string encode(const std::string& word);

private:
	static std::string head(const std::string& word);
	static std::string encodedDigits(const std::string& word);
	static std::string zeroPad(const std::string& word);
};

#endif