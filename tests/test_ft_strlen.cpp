#include <gtest/gtest.h>
#include <cstring>  // for standard strlen
#include <string>

extern "C" size_t ft_strlen(const char *str);

TEST(FTStrlenTest, BasicStrings) {
    EXPECT_EQ(ft_strlen("hello"), 5);
    EXPECT_EQ(ft_strlen("42 Porto"), 8);
    EXPECT_EQ(ft_strlen(""), 0);
    EXPECT_EQ(ft_strlen(" "), 1);
}

TEST(FTStrlenTest, LongString) {
    std::string longStr(1000, 'a');
    EXPECT_EQ(ft_strlen(longStr.c_str()), 1000);
}

TEST(FTStrlenTest, SpecialCharacters) {
    EXPECT_EQ(ft_strlen("\n\t\r"), 3);
    EXPECT_EQ(ft_strlen("line1\nline2"), 11);
}

TEST(FTStrlenTest, NullCharInsideStringLiteral) {
    const char* s = "abc\0def";
    EXPECT_EQ(ft_strlen(s), 3);  // strlen should stop at null byte
}

TEST(FTStrlenTest, NonPrintableCharacters) {
	const char* s = "abc\0def";  // Contains a null character
	EXPECT_EQ(ft_strlen(s), 3);  // strlen should stop at null byte
}
