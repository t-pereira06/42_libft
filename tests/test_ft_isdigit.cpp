#include <gtest/gtest.h>
#include <cctype>  // for std::isdigit

extern "C" int ft_isdigit(int a);

TEST(FTIsdigitTest, Digits) {
    for (int c = '0'; c <= '9'; ++c) {
        EXPECT_EQ(ft_isdigit(c), std::isdigit(c)) << "Failed on: " << c;
    }
}

TEST(FTIsdigitTest, Letters) {
    for (int c = 'A'; c <= 'Z'; ++c) {
        EXPECT_EQ(ft_isdigit(c), std::isdigit(c)) << "Failed on: " << c;
    }
    for (int c = 'a'; c <= 'z'; ++c) {
        EXPECT_EQ(ft_isdigit(c), std::isdigit(c)) << "Failed on: " << c;
    }
}

TEST(FTIsdigitTest, SpecialCharacters) {
    const char symbols[] = {'-', '+', '.', '/', ':', ';', '@', '[', '`', '{'};
    for (char c : symbols) {
        EXPECT_EQ(ft_isdigit(c), std::isdigit(c)) << "Failed on: " << c;
    }
}

TEST(FTIsdigitTest, ControlAndNegativeValues) {
    for (int c = -20; c < 32; ++c) {
        EXPECT_EQ(ft_isdigit(c), std::isdigit(c)) << "Failed on: " << c;
    }
    EXPECT_EQ(ft_isdigit(127), std::isdigit(127));
    EXPECT_EQ(ft_isdigit(200), std::isdigit(200));
}

TEST(FTIsdigitTest, ExtendedASCII) {
	for (int c = 128; c < 256; ++c) {
		EXPECT_EQ(ft_isdigit(c), std::isdigit(c)) << "Failed on: " << c;
	}
}
