#include <gtest/gtest.h>
#include <cctype>  // for std::isalpha

extern "C" int ft_isalpha(int a);

TEST(FTIsalphaTest, UppercaseLetters) {
    for (int c = 'A'; c <= 'Z'; ++c) {
        EXPECT_EQ(!!ft_isalpha(c), !!std::isalpha(c)) << "Failed on: " << c;
    }
}

TEST(FTIsalphaTest, LowercaseLetters) {
    for (int c = 'a'; c <= 'z'; ++c) {
        EXPECT_EQ(!!ft_isalpha(c), !!std::isalpha(c)) << "Failed on: " << c;
    }
}

TEST(FTIsalphaTest, Digits) {
    for (int c = '0'; c <= '9'; ++c) {
        EXPECT_EQ(ft_isalpha(c), std::isalpha(c)) << "Failed on: " << c;
    }
}

TEST(FTIsalphaTest, SymbolsAndPunctuation) {
    const char symbols[] = {'@', '[', '`', '{', '!', '#', '$', '%', '^', '&', '*'};
    for (char c : symbols) {
        EXPECT_EQ(ft_isalpha(c), std::isalpha(c)) << "Failed on: " << c;
    }
}

TEST(FTIsalphaTest, ControlCharacters) {
    for (int c = 0; c < 32; ++c) {
        EXPECT_EQ(ft_isalpha(c), std::isalpha(c)) << "Failed on control char: " << c;
    }
    EXPECT_EQ(ft_isalpha(127), std::isalpha(127));  // DEL character
}
