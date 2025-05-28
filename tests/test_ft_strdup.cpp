#include <gtest/gtest.h>
#include <cstring>   // for std::strcmp, std::strdup
#include <cstdlib>   // for std::free

extern "C" char* ft_strdup(const char* src);

TEST(FTStrdupTest, DuplicatesRegularString) {
    const char* original = "Ola meus queridos";
    char* result = ft_strdup(original);

    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, original);
    EXPECT_NE(result, original);  // Ensure it's a new allocation

    free(result);
}

TEST(FTStrdupTest, DuplicatesEmptyString) {
    const char* original = "";
    char* result = ft_strdup(original);

    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, original);
    EXPECT_NE(result, original);

    free(result);
}

TEST(FTStrdupTest, DuplicatesSingleCharacter) {
    const char* original = "x";
    char* result = ft_strdup(original);

    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, original);
    EXPECT_NE(result, original);

    free(result);
}

TEST(FTStrdupTest, HandlesLongString) {
    std::string long_input(1000, 'a');
    char* result = ft_strdup(long_input.c_str());

    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, long_input.c_str());
    EXPECT_NE(result, long_input.c_str());

    free(result);
}

TEST(FTStrdupTest, HandlesNullInput) {
	char* result = ft_strdup(nullptr);
	EXPECT_EQ(result, nullptr);  // Should return nullptr for null input
}

TEST(FTStrdupTest, HandlesNonPrintableCharacters) {
	const char* original = "abc\0def";  // Contains a null character
	char* result = ft_strdup(original);

	ASSERT_NE(result, nullptr);
	EXPECT_EQ(std::strcmp(result, "abc"), 0);  // Only compares up to the first null character
	EXPECT_NE(result, original);  // Ensure it's a new allocation

	free(result);
}

TEST(FTStrdupTest, HandlesExtendedASCII) {
	const char* original = "café";  // Contains an accented character
	char* result = ft_strdup(original);

	ASSERT_NE(result, nullptr);
	EXPECT_STREQ(result, original);
	EXPECT_NE(result, original);

	free(result);
}
