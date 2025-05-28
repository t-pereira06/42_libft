#include <gtest/gtest.h>
#include <cstring>
#include <string>
#include <cstdlib>  // for free

extern "C" char* ft_strjoin(const char* s1, const char* s2);

TEST(FTStrjoinTest, JoinsTwoNormalStrings) {
    const char* s1 = "Ola ";
    const char* s2 = "Deus";
    char* result = ft_strjoin(s1, s2);

    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "Ola Deus");

    free(result);
}

TEST(FTStrjoinTest, JoinWithEmptySecondString) {
    const char* s1 = "Test";
    const char* s2 = "";
    char* result = ft_strjoin(s1, s2);

    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "Test");

    free(result);
}

TEST(FTStrjoinTest, JoinWithEmptyFirstString) {
    const char* s1 = "";
    const char* s2 = "World";
    char* result = ft_strjoin(s1, s2);

    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "World");

    free(result);
}

TEST(FTStrjoinTest, BothEmptyStrings) {
    const char* s1 = "";
    const char* s2 = "";
    char* result = ft_strjoin(s1, s2);

    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "");

    free(result);
}

TEST(FTStrjoinTest, NullFirstStringReturnsNull) {
    EXPECT_EQ(ft_strjoin(nullptr, "hello"), nullptr);
}

TEST(FTStrjoinTest, NullSecondStringReturnsFirst) {
    const char* s1 = "hello";
    char* result = ft_strjoin(s1, nullptr);

    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, s1);  // returns pointer to s1, not a copy (based on your implementation)
}

TEST(FTStrjoinTest, JoinsLongStrings) {
	const char* s1 = "This is a long string that will be joined ";
	const char* s2 = "with another long string to test the function.";
	char* result = ft_strjoin(s1, s2);

	ASSERT_NE(result, nullptr);
	std::string expected = std::string(s1) + s2;
	EXPECT_STREQ(result, expected.c_str());

	free(result);
}

TEST(FTStrjoinTest, JoinsStringsWithSpecialCharacters) {
	const char* s1 = "Hello\n";
	const char* s2 = "World\t!";
	char* result = ft_strjoin(s1, s2);

	ASSERT_NE(result, nullptr);
	EXPECT_STREQ(result, "Hello\nWorld\t!");

	free(result);
}
