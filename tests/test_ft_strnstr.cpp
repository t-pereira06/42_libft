#include <gtest/gtest.h>
#include <cstring>  // for strnstr (if available on system)

extern "C" char *ft_strnstr(const char *big, const char *little, size_t len);

TEST(FTStrnstrTest, BasicMatch) {
    const char *big = "Tudo bem";
    EXPECT_STREQ(ft_strnstr(big, "bem", 9), strstr(big, "bem"));  // should match
}

TEST(FTStrnstrTest, NoMatchWithinLength) {
    EXPECT_EQ(ft_strnstr("Tudo bem", "bem", 4), nullptr);  // only "Tudo" is searched
}

TEST(FTStrnstrTest, EmptyLittle) {
    const char *big = "Tudo bem";
    EXPECT_EQ(ft_strnstr(big, "", 5), big);  // empty needle returns full haystack
}

TEST(FTStrnstrTest, EmptyLittleZeroLen) {
    const char *big = "Tudo bem";
    EXPECT_EQ(ft_strnstr(big, "", 0), big);  // even with len 0, empty needle returns big
}

TEST(FTStrnstrTest, ZeroLenNoMatch) {
    EXPECT_EQ(ft_strnstr("Tudo bem", "bem", 0), nullptr);  // nothing can match with len 0
}

TEST(FTStrnstrTest, SubstringAtEnd) {
    EXPECT_STREQ(ft_strnstr("abcde", "e", 5), "e");
}

TEST(FTStrnstrTest, SubstringTooFar) {
    EXPECT_EQ(ft_strnstr("abcde", "de", 4), nullptr);  // 'de' starts after len 4
}

TEST(FTStrnstrTest, MatchAtStart) {
	EXPECT_STREQ(ft_strnstr("abcde", "a", 5), "abcde");
}

TEST(FTStrnstrTest, MatchWithSpecialChars) {
	const char *big = "Hello, world!";
	EXPECT_STREQ(ft_strnstr(big, "world", 13), strstr(big, "world"));  // should match
}
