#include <gtest/gtest.h>
#include <cctype>  // for isascii

extern "C" int ft_isascii(int a);

TEST(FTIsasciiTest, ValidAsciiRange) {
    for (int c = 0; c <= 127; ++c) {
        EXPECT_EQ(ft_isascii(c), isascii(c)) << "Failed on: " << c;
    }
}

TEST(FTIsasciiTest, AboveAsciiRange) {
    for (int c = 128; c < 140; ++c) {
        EXPECT_EQ(ft_isascii(c), isascii(c)) << "Failed on: " << c;
    }
}

TEST(FTIsasciiTest, NegativeValues) {
    for (int c = -20; c < 0; ++c) {
        EXPECT_EQ(ft_isascii(c), isascii(c)) << "Failed on: " << c;
    }
}

TEST(FTIsasciiTest, BoundaryValues) {
    EXPECT_EQ(ft_isascii(0), isascii(0));
    EXPECT_EQ(ft_isascii(127), isascii(127));
    EXPECT_EQ(ft_isascii(-1), isascii(-1));
    EXPECT_EQ(ft_isascii(128), isascii(128));
}

TEST(FTIsasciiTest, NonAsciiCharacters) {
	for (int c = 128; c < 256; ++c) {
		EXPECT_EQ(ft_isascii(c), isascii(c)) << "Failed on: " << c;
	}
}
