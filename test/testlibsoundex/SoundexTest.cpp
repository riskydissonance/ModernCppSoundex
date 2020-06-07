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
    EXPECT_THAT(soundexEncoder.encode("Ab"), Eq("A100"));
    EXPECT_THAT(soundexEncoder.encode("Fc"), Eq("F200"));
    EXPECT_THAT(soundexEncoder.encode("Ag"), Eq("A200"));
    EXPECT_THAT(soundexEncoder.encode("Bd"), Eq("B300"));
    EXPECT_THAT(soundexEncoder.encode("Al"), Eq("A400"));
    EXPECT_THAT(soundexEncoder.encode("Fm"), Eq("F500"));
    EXPECT_THAT(soundexEncoder.encode("Ar"), Eq("A600"));
}

TEST_F(SoundexEncoding, IgnoresNonAlphabetics)
{
    ASSERT_THAT(soundexEncoder.encode("A#"), Eq("A000"));
}

TEST_F(SoundexEncoding, ReplacesMultipleConsonantsWithDigits)
{
    ASSERT_THAT(soundexEncoder.encode("Acdl"), Eq("A234"));
}

TEST_F(SoundexEncoding, LimitsLengthToFourCharacters)
{
    ASSERT_THAT(soundexEncoder.encode("Dcdlb").length(), Eq(4u));
}

TEST_F(SoundexEncoding, IgnoresVowelLikeLetters)
{
    ASSERT_THAT(soundexEncoder.encode("Baeiouhycdl"), Eq("B234"));
}

TEST_F(SoundexEncoding, CombinesDuplicateEncodings)
{
    ASSERT_THAT(soundexEncoder.encodedDigit('b'), Eq(soundexEncoder.encodedDigit('f')));
    ASSERT_THAT(soundexEncoder.encodedDigit('c'), Eq(soundexEncoder.encodedDigit('g')));
    ASSERT_THAT(soundexEncoder.encodedDigit('d'), Eq(soundexEncoder.encodedDigit('t')));

	ASSERT_THAT(soundexEncoder.encode("Abfcgdt"), Eq("A123"));
}
