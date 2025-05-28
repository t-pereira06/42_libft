#include <gtest/gtest.h>
#include <cctype>  // for std::isprint

extern "C" int ft_isprint(int a);

TEST(FTIsprintTest, PrintableAsciiCharacters) {
    for (int c = 32; c <= 126; ++c) {
        EXPECT_EQ(ft_isprint(c) != 0, std::isprint(c) != 0) << "Failed on: " << c;
    }
}

TEST(FTIsprintTest, NonPrintableAsciiCharacters) {
    for (int c = 0; c < 32; ++c) {
        EXPECT_EQ(ft_isprint(c), std::isprint(c)) << "Failed on: " << c;
    }
    EXPECT_EQ(ft_isprint(127), std::isprint(127));  // DEL
}

TEST(FTIsprintTest, ExtendedAndNegativeValues) {
    for (int c = -50; c < 0; ++c) {
        EXPECT_EQ(ft_isprint(c), std::isprint(c)) << "Failed on: " << c;
    }
    for (int c = 127; c <= 140; ++c) {
        EXPECT_EQ(ft_isprint(c), std::isprint(c)) << "Failed on: " << c;
    }
}

TEST(FTIsprintTest, ExtendedASCII) {
	for (int c = 128; c < 256; ++c) {
		EXPECT_EQ(ft_isprint(c), std::isprint(c)) << "Failed on: " << c;
	}
}
