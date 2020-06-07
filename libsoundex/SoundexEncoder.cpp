#include "SoundexEncoder.h"
#include <string>
#include <unordered_map>

namespace soundex
{
    static const size_t MaxCodeLength{ 4 };
	
    std::string SoundexEncoder::encode(const std::string& word)
    {
        return zeroPad(head(word) + encodedDigits(tail(word)));
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



    std::string SoundexEncoder::tail(const std::string& word)
    {
        return word.substr(1);
    }

    bool SoundexEncoder::isComplete(const std::string& encoding)
    {
	    return encoding.length() == MaxCodeLength - 1;
    }

    std::string SoundexEncoder::lastDigit(const std::string& encoding)
    {
        if (encoding.empty()) return "";
        return std::string(1, encoding.back());
    }

    std::string SoundexEncoder::encodedDigits(const std::string& word)
    {
        std::string encoding;
        for (auto letter : word)
        {
            if (isComplete(encoding)) break;
        	if(encodedDigit(letter) != lastDigit(encoding))
				encoding += encodedDigit((letter));
        }
    	
        return encoding;
    }

    std::string SoundexEncoder::encodedDigit(const char letter) 
    {
        const std::unordered_map<char, std::string> encodings
        {
            {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"}, 
        	{'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"},
        				{'s', "2"}, {'x', "2"}, {'z', "2"},
        	{'d', "3"}, {'t', "3"},
        	{'l', "4"},
        	{'m', "5"}, {'n', "5"},
        	{'r', "6"},
        };
        return encodings.find(letter)->second;
    }

	
	
}



