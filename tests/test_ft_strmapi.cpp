#include <gtest/gtest.h>
#include <cstring>  // for strcmp
#include <string>

extern "C" char* ft_strmapi(const char* s, char (*f)(unsigned int, char));

// Function: Converts to uppercase
char to_upper(unsigned int i, char c) {
    (void)i;
    if (c >= 'a' && c <= 'z')
        return c - 32;
    return c;
}

// Function: Shifts each char by index
char shift_by_index(unsigned int i, char c) {
    return c + i;
}

TEST(FTStrmapiTest, UppercaseConversion) {
    const char* input = "hello world";
    char* result = ft_strmapi(input, to_upper);
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "HELLO WORLD");
    free(result);
}

TEST(FTStrmapiTest, ShiftByIndex) {
    const char* input = "abcd";
    char* result = ft_strmapi(input, shift_by_index);
    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result[0], 'a');
    EXPECT_EQ(result[1], 'c');  // b + 1
    EXPECT_EQ(result[2], 'e');  // c + 2
    EXPECT_EQ(result[3], 'g');  // d + 3
    result[4] = '\0';
    free(result);
}

TEST(FTStrmapiTest, EmptyStringReturnsEmpty) {
    char* result = ft_strmapi("", to_upper);
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "");
    free(result);
}

TEST(FTStrmapiTest, NullStringReturnsNull) {
    EXPECT_EQ(ft_strmapi(nullptr, to_upper), nullptr);
}

TEST(FTStrmapiTest, NullFunctionReturnsNull) {
    const char* input = "test";
    EXPECT_EQ(ft_strmapi(input, nullptr), nullptr);
}

TEST(FTStrmapiTest, SingleCharacterString) {
	const char* input = "a";
	char* result = ft_strmapi(input, to_upper);
	ASSERT_NE(result, nullptr);
	EXPECT_STREQ(result, "A");
	free(result);
}
