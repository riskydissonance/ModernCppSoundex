#include "charutil.h"
#include "gmock/gmock.h"

using namespace testing;

TEST(SoundexCharUtilUpperFront, ReturnsTheFirstLetterUppercased)
{
	ASSERT_THAT(soundex::upperFront("test"), Eq("T"));
}

TEST(SoundexCharUtilUpperFront, ReturnsEmptyStringIfEmptyStringPassed)
{
	ASSERT_THAT(soundex::upperFront(""), Eq(""));
}

TEST(SoundexCharUtilLower, ReturnsSameCharLowerCased)
{
	ASSERT_THAT(soundex::lower('T'), Eq('t'));
}

TEST(SoundexCharUtilLower, ReturnsSameCharIfAlreadyLowerCase)
{
	ASSERT_THAT(soundex::lower('a'), Eq('a'));
}

TEST(SoundexCharUtilIsVowel, ReturnsTrueIfVowelPassed)
{
	ASSERT_THAT(soundex::isVowel('a'), Eq(true));
}

TEST(SoundexCharUtilIsVowel, ReturnsTrueIfUppercaseVowelPassed)
{
	ASSERT_THAT(soundex::isVowel('E'), Eq(true));
}

TEST(SoundexCharUtilIsVowel, ReturnsFalseIfConsonantPassed)
{
	ASSERT_THAT(soundex::isVowel('f'), Eq(false));
}

TEST(SoundexCharUtilIsVowel, ReturnsFalseIfUppercaseConsonantPassed)
{
	ASSERT_THAT(soundex::isVowel('T'), Eq(false));
}

TEST(SoundexCharUtilIsVowel, ConsidersYAVowel)
{
	ASSERT_THAT(soundex::isVowel('y'), Eq(true));
}