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

TEST_F(SoundexEncoding, IgnoresVowelLikeLetters) {
   ASSERT_THAT(soundex.encode("BaAeEiIoOuUhHyYcdl"), Eq("B234"));
}

TEST_F(SoundexEncoding, CombinesDuplicateEncodings) {
   
   ASSERT_THAT(soundex.encodedDigit('b'), Eq(soundex.encodedDigit('f')));

   ASSERT_THAT(soundex.encodedDigit('c'), Eq(soundex.encodedDigit('g')));

   ASSERT_THAT(soundex.encodedDigit('d'), Eq(soundex.encodedDigit('t')));

   ASSERT_THAT(soundex.encode("Abfcgdt"), Eq("A123"));
}

TEST_F(SoundexEncoding, UppercasesFirstLetter) {
   ASSERT_THAT(soundex.encode("abcd"), StartsWith("A"));
}

TEST_F(SoundexEncoding, IgnoresCaseWhenEncodingConsonants) {
   ASSERT_THAT(soundex.encode("BCDL"), Eq(soundex.encode("Bcdl")));
}

TEST_F(SoundexEncoding, CombinesDuplicateCodesWhen2ndLetterDuplicates1st) {
   ASSERT_THAT(soundex.encode("Bbcd"), Eq("B230"));
}
