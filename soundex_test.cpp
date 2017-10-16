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
