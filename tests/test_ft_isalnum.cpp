#include <gtest/gtest.h>
#include <cctype>  // for std::isalnum

extern "C" int ft_isalnum(int a);

TEST(FTIsalnumTest, Digits) {
    for (int c = '0'; c <= '9'; ++c) {
        EXPECT_EQ(!!ft_isalnum(c), !!std::isalnum(c)) << "Failed on: " << c;
    }
}

TEST(FTIsalnumTest, UppercaseLetters) {
    for (int c = 'A'; c <= 'Z'; ++c) {
        EXPECT_EQ(!!ft_isalnum(c), !!std::isalnum(c)) << "Failed on: " << c;
    }
}

TEST(FTIsalnumTest, LowercaseLetters) {
    for (int c = 'a'; c <= 'z'; ++c) {
        EXPECT_EQ(!!ft_isalnum(c), !!std::isalnum(c)) << "Failed on: " << c;
    }
}

TEST(FTIsalnumTest, SpecialCharacters) {
    const char specialChars[] = {'@', '[', '`', '{', '~', '!', '#', '$', '%', '&'};
    for (char c : specialChars) {
        EXPECT_EQ(ft_isalnum(c), std::isalnum(c)) << "Failed on: " << c;
    }
}

TEST(FTIsalnumTest, ControlCharacters) {
    for (int c = 0; c < 32; ++c) {
        EXPECT_EQ(ft_isalnum(c), std::isalnum(c)) << "Failed on control char: " << c;
    }
    EXPECT_EQ(ft_isalnum(127), std::isalnum(127));  // DEL character
}
