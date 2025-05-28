#include <gtest/gtest.h>
#include <cstring>  // for standard strrchr

extern "C" char *ft_strrchr(const char *str, int c);

TEST(FTStrrchrTest, Basic) {
    const char *s = "suspensao";
    EXPECT_STREQ(ft_strrchr(s, 's'), strrchr(s, 's'));
}

TEST(FTStrrchrTest, NotFound) {
    const char *s = "hello world";
    EXPECT_EQ(ft_strrchr(s, 'z'), nullptr);
}

TEST(FTStrrchrTest, LastChar) {
    const char *s = "abcabcabc";
    EXPECT_STREQ(ft_strrchr(s, 'c'), strrchr(s, 'c'));
}

TEST(FTStrrchrTest, SearchNullChar) {
    const char *s = "abc";
    EXPECT_STREQ(ft_strrchr(s, '\0'), strrchr(s, '\0'));
}

TEST(FTStrrchrTest, FirstCharOnly) {
    const char *s = "a";
    EXPECT_STREQ(ft_strrchr(s, 'a'), strrchr(s, 'a'));
}

TEST(FTStrrchrTest, EmptyString) {
	const char *s = "";
	EXPECT_EQ(ft_strrchr(s, 'a'), nullptr);  // No character in empty string
}

TEST(FTStrrchrTest, NullPointer) {
	EXPECT_EQ(ft_strrchr(nullptr, 'a'), nullptr);  // Should handle null pointer gracefully
}

TEST(FTStrrchrTest, MultipleOccurrences) {
	const char *s = "banana";
	EXPECT_STREQ(ft_strrchr(s, 'a'), strrchr(s, 'a'));  // Should return last occurrence
}
