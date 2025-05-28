#include <gtest/gtest.h>
#include <cstring>  // for std::strncmp

extern "C" int ft_strncmp(const char *str1, const char *str2, size_t n);

TEST(FTStrncmpTest, EqualStrings) {
    EXPECT_EQ(ft_strncmp("hello", "hello", 5), 0);
    EXPECT_EQ(ft_strncmp("hello", "hello", 0), 0);  // special case
}

TEST(FTStrncmpTest, CaseDifference) {
    EXPECT_GT(ft_strncmp("hello", "Hello", 5), 0);
    EXPECT_LT(ft_strncmp("Hello", "hello", 5), 0);
}

TEST(FTStrncmpTest, PrefixEqualButThenDiffers) {
    EXPECT_LT(ft_strncmp("abcde", "abcdf", 5), 0);
    EXPECT_GT(ft_strncmp("abcdf", "abcde", 5), 0);
}

TEST(FTStrncmpTest, NLessThanDifferencePoint) {
    EXPECT_EQ(ft_strncmp("abcdef", "abcxyz", 3), 0);  // only first 3 chars compared
}

TEST(FTStrncmpTest, OneEmptyString) {
    EXPECT_GT(ft_strncmp("abc", "", 3), 0);
    EXPECT_LT(ft_strncmp("", "abc", 3), 0);
}

TEST(FTStrncmpTest, BothEmptyStrings) {
    EXPECT_EQ(ft_strncmp("", "", 5), 0);
    EXPECT_EQ(ft_strncmp("", "", 0), 0);
}

TEST(FTStrncmpTest, NullPointers) {
	EXPECT_EQ(ft_strncmp(nullptr, nullptr, 0), 0);
	EXPECT_EQ(ft_strncmp(nullptr, "test", 4), -1);  // null vs non-null
	EXPECT_EQ(ft_strncmp("test", nullptr, 4), 1);   // non-null vs null
	EXPECT_EQ(ft_strncmp(nullptr, nullptr, 5), 0);  // both null with size > 0
}

TEST(FTStrncmpTest, SizeZero) {
	EXPECT_EQ(ft_strncmp("hello", "world", 0), 0);  // size zero means no comparison
	EXPECT_EQ(ft_strncmp("", "", 0), 0);             // both empty with size zero
}
