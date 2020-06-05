#include "SoundexEncoder.h"
#include <string>

namespace soundex
{
    static const size_t MaxCodeLength{ 4 };
	
    std::string SoundexEncoder::encode(const std::string& word)
    {
        return zeroPad(head(word) + encodedDigits((word)));
    }

    std::string SoundexEncoder::zeroPad(const std::string& word)
    {
        const auto zeroesNeeded = MaxCodeLength - word.length();
        return word + std::string(zeroesNeeded, '0');
    }

    std::string SoundexEncoder::head(const std::string& word)
    {
        return word.substr(0, 1);
    }

    std::string SoundexEncoder::encodedDigits(const std::string& word)
    {
        if (word.length() > 1) return encodedDigit();
        return "";
    }

    std::string SoundexEncoder::encodedDigit() 
    {
        return "1";
    }
}



