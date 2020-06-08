#include "gmock/gmock.h"
#include "stringutil.h"

using namespace testing;

TEST(StringUtilHead, ReturnsFirstCharacterOfString)
{
	EXPECT_THAT(soundex::head("ASDF"), Eq("A"));
	EXPECT_THAT(soundex::head("hjkl"), Eq("h"));
}

TEST(StringUtilTail, ReturnsAllButFirstCharacterOfString)
{
	EXPECT_THAT(soundex::tail("ASDF"), Eq("SDF"));
	EXPECT_THAT(soundex::tail("hjkl"), Eq("jkl"));
}

TEST(StringUtilZeroPad, ZeroPadsAWordToExpectedLength)
{
	EXPECT_THAT(soundex::zeroPad("ASD", 6), Eq("ASD000"));
}

TEST(StringUtilZeroPad, TrimsStringIfExceedsLength)
{
	ASSERT_THAT(soundex::zeroPad("ABCD", 3), Eq("ABC"));
}