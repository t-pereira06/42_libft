#include <gtest/gtest.h>
#include <cstring>  // For strcmp
#include <cstdlib>

extern "C" char *ft_strtrim(const char *s1, const char *set);

// Helper to avoid leaks in tests
void free_if_not_null(char* ptr) {
    if (ptr) free(ptr);
}

TEST(FTStrtrimTest, TrimFrontAndBack) {
    char *result = ft_strtrim("abracadabra", "abr");
    ASSERT_STREQ(result, "cad");
    free_if_not_null(result);
}

TEST(FTStrtrimTest, TrimSpaces) {
    char *result = ft_strtrim("   hello world   ", " ");
    ASSERT_STREQ(result, "hello world");
    free_if_not_null(result);
}

TEST(FTStrtrimTest, NoTrim) {
    char *result = ft_strtrim("hello", "xyz");
    ASSERT_STREQ(result, "hello");
    free_if_not_null(result);
}

TEST(FTStrtrimTest, AllTrimmed) {
    char *result = ft_strtrim("aaaaa", "a");
    ASSERT_STREQ(result, "");
    free_if_not_null(result);
}

TEST(FTStrtrimTest, EmptyInput) {
    char *result = ft_strtrim("", " ");
    ASSERT_STREQ(result, "");
    free_if_not_null(result);
}

TEST(FTStrtrimTest, EmptySet) {
    char *result = ft_strtrim("hello", "");
    ASSERT_STREQ(result, "hello");
    free_if_not_null(result);
}

TEST(FTStrtrimTest, NullInput) {
	char *result = ft_strtrim(nullptr, "set");
	ASSERT_EQ(result, nullptr);  // Should handle null input gracefully
}

TEST(FTStrtrimTest, NullSet) {
	char *result = ft_strtrim("hello", nullptr);
	ASSERT_STREQ(result, nullptr);
	free_if_not_null(result);
}

TEST(FTStrtrimTest, SetContainsOnlySpaces) {
	char *result = ft_strtrim("   test   ", " ");
	ASSERT_STREQ(result, "test");
	free_if_not_null(result);
}

TEST(FTStrtrimTest, SetContainsSpecialCharacters) {
	char *result = ft_strtrim("!@#hello$%^", "!@#$%^");
	ASSERT_STREQ(result, "hello");
	free_if_not_null(result);
}
