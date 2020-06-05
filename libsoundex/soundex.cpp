
#include "soundex.h"
#include <string>

std::string Soundex::encode(const std::string& word)
{
      return zeroPad(word);
   }

std::string Soundex::zeroPad(const std::string& word)
{
       return word + "000";
}