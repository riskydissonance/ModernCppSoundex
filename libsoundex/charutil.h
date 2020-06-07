#pragma once
#include <string>

static  std::string upperFront(const std::string& string)
{
    return std::string(1, std::toupper(static_cast<unsigned char>(string.front())));
}

static  char lower(const char letter)
{
    return std::tolower(static_cast<unsigned char>(letter));
}

static bool isVowel(const char letter)
{
    return std::string("aeiouy").find(lower(letter)) != std::string::npos;
}