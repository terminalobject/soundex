#include "gmock/gmock.h"
#include "gtest/gtest.h"
using ::testing::Eq;

class Soundex {
public:
    std::string encode(const std::string& word) const {
        return zeroPad(word);
    }  
private:
    std::string zeroPad(const std::string& word) const {
      return word + "000";
    }
};

TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
    Soundex soundex;

    auto encoded = soundex.encode("A");

    ASSERT_THAT(encoded, Eq("A000"));

}

TEST(SoundexEncoding, PadsWithZeroesToEnsureThreeDigits) {
    Soundex soundex;

    auto encoded = soundex.encode("I");

    ASSERT_THAT(encoded, Eq("I000"));
}
