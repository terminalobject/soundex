#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "Soundex.h"

using namespace testing;

class SoundexEncoding: public testing::Test {
public:
   Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
    auto encoded = soundex.encode("A");

    ASSERT_THAT(encoded, Eq("A000"));
};

TEST_F(SoundexEncoding, PadsWithZeroesToEnsureThreeDigits) {
    auto encoded = soundex.encode("I");

    ASSERT_THAT(encoded, Eq("I000"));
};

TEST_F(SoundexEncoding, ReplaceConsonantsWithAppropriateDigits) {
   EXPECT_THAT(soundex.encode("Ab"), Eq("A100"));
   EXPECT_THAT(soundex.encode("Ac"), Eq("A200"));
   EXPECT_THAT(soundex.encode("Ad"), Eq("A300"));
};

TEST_F(SoundexEncoding, IgnoresNonAlphabetics) {
   ASSERT_THAT(soundex.encode("A#"), Eq("A000"));
};

TEST_F(SoundexEncoding, ReplaceMutipleConsonantsWithDigits) {
   ASSERT_THAT(soundex.encode("Acdl"), Eq("A234"));
};

TEST_F(SoundexEncoding, LimitsLengthToFourCharacters) {
   ASSERT_THAT(soundex.encode("Dcdlb").length(), Eq(4u));
}
