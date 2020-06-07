#pragma once
#include <string>

std::string head(const std::string& word)
{
    return word.substr(0, 1);
}

std::string tail(const std::string& word)
{
    return word.substr(1);
}

std::string zeroPad(const std::string& word, const int maxLength)
{
    const auto zeroesNeeded = maxLength - word.length();
    return word + std::string(zeroesNeeded, '0');
}