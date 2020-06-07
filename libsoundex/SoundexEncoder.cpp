#include "SoundexEncoder.h"
#include <string>
#include <unordered_map>

#include "charutil.h"
#include "stringutil.h"

namespace soundex
{
    static const size_t MaxCodeLength{ 4 };
    static const std::string NotADigit{ "*" };
	
    std::string SoundexEncoder::encode(const std::string& word)
    {
        return zeroPad(upperFront(head(word)) + tail(encodeDigits(word)), MaxCodeLength);
    }

    bool SoundexEncoder::isComplete(const std::string& encoding)
    {
	    return encoding.length() == MaxCodeLength;
    }

    std::string SoundexEncoder::lastDigit(const std::string& encoding)
    {
        if (encoding.empty()) return NotADigit;
        return std::string(1, encoding.back());
    }

    void SoundexEncoder::encodeHead(std::string& encoding, const std::string& word)
    {
	    encoding += encodeDigit(word.front());
    }


    void SoundexEncoder::encodeLetter(std::string& encoding, const char letter, const char lastLetter)
    {
	    auto digit = encodeDigit(letter);
	    if(digit != NotADigit && (digit != lastDigit(encoding) || isVowel(lastLetter)))
		    encoding += digit;
    }

    void SoundexEncoder::encodeTail(std::string& encoding, const std::string& word)
    {
	    for (auto i = 1u; i < word.length(); i++)
		    if (!isComplete(encoding))
				encodeLetter(encoding, word[i], word[i - 1]);
    }

    std::string SoundexEncoder::encodeDigits(const std::string& word)
    {
        std::string encoding;
        encodeHead(encoding, word);
        encodeTail(encoding, word);
        return encoding;
    }

    std::string SoundexEncoder::encodeDigit(const char letter) 
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
        const auto it =  encodings.find(lower(letter));
        return it == encodings.end() ? NotADigit : it->second;
    }
}
