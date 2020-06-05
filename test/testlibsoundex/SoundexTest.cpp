#include "gmock/gmock.h"
#include "SoundexEncoder.h"

using namespace testing;

class SoundexEncoding: public testing::Test
{
public:
	soundex::SoundexEncoder soundexEncoder;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord)
{
    ASSERT_THAT(soundexEncoder.encode("A"), Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits)
{
    ASSERT_THAT(soundexEncoder.encode("I"), Eq("I000"));
}

TEST_F(SoundexEncoding, ReplacesConsonantWithAppropriateDigits)
{
    ASSERT_THAT(soundexEncoder.encode("Ab"), Eq("A100"));
}