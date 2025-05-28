#include <gtest/gtest.h>
#include <cstring>  // For strcmp
#include <cstdlib>

extern "C" char *ft_substr(const char *s, unsigned int start, size_t len);

static void free_if_not_null(char* ptr) {
    if (ptr)
        free(ptr);
}

TEST(FTSubstrTest, NormalCase) {
    char *result = ft_substr("Ola deus", 4, 4);
    ASSERT_STREQ(result, "deus");
    free_if_not_null(result);
}

TEST(FTSubstrTest, StartPastLength) {
    char *result = ft_substr("Ola deus", 20, 5);
    ASSERT_STREQ(result, "");
    free_if_not_null(result);
}

TEST(FTSubstrTest, ZeroLength) {
    char *result = ft_substr("Ola deus", 0, 0);
    ASSERT_STREQ(result, "");
    free_if_not_null(result);
}

TEST(FTSubstrTest, LengthExceedsEnd) {
    char *result = ft_substr("Ola deus", 2, 50);
    ASSERT_STREQ(result, "a deus");
    free_if_not_null(result);
}

TEST(FTSubstrTest, FullString) {
    char *result = ft_substr("testando", 0, 8);
    ASSERT_STREQ(result, "testando");
    free_if_not_null(result);
}

TEST(FTSubstrTest, SingleCharacter) {
    char *result = ft_substr("abc", 1, 1);
    ASSERT_STREQ(result, "b");
    free_if_not_null(result);
}

TEST(FTSubstrTest, EmptyString) {
	char *result = ft_substr("", 0, 5);
	ASSERT_STREQ(result, "");
	free_if_not_null(result);
}

TEST(FTSubstrTest, NullString) {
	char *result = ft_substr(nullptr, 0, 5);
	ASSERT_EQ(result, nullptr);  // Should handle null input gracefully
}

TEST(FTSubstrTest, StartAtZero) {
	char *result = ft_substr("Ola deus", 0, 3);
	ASSERT_STREQ(result, "Ola");
	free_if_not_null(result);
}
