#include <gtest/gtest.h>
#include <cstring>  // for std::strcmp
#include <string>

extern "C" void ft_striteri(char *s, void (*f)(unsigned int, char *));

// Callback: uppercase every character
void to_upper(unsigned int i, char *c) {
    (void)i;
    if (*c >= 'a' && *c <= 'z')
        *c -= 32;
}

// Callback: replace char with its index digit (mod 10)
void index_digit(unsigned int i, char *c) {
    *c = '0' + (i % 10);
}

TEST(FTStriteriTest, UppercaseConversion) {
    char str[] = "hello world";
    ft_striteri(str, to_upper);
    EXPECT_STREQ(str, "HELLO WORLD");
}

TEST(FTStriteriTest, IndexDigitConversion) {
    char str[] = "abcdef";
    ft_striteri(str, index_digit);
    EXPECT_STREQ(str, "012345");
}

TEST(FTStriteriTest, NullStringNoCrash) {
    EXPECT_NO_FATAL_FAILURE(ft_striteri(NULL, to_upper));
}

TEST(FTStriteriTest, NullFunctionNoCrash) {
    char str[] = "test";
    EXPECT_NO_FATAL_FAILURE(ft_striteri(str, NULL));
    EXPECT_STREQ(str, "test");  // unchanged
}

TEST(FTStriteriTest, EmptyStringNoChange) {
	char str[] = "";
	ft_striteri(str, to_upper);
	EXPECT_STREQ(str, "");
}

TEST(FTStriteriTest, SingleCharacterString) {
	char str[] = "a";
	ft_striteri(str, to_upper);
	EXPECT_STREQ(str, "A");

	ft_striteri(str, index_digit);
	EXPECT_STREQ(str, "0");  // index 0
}

TEST(FTStriteriTest, MultipleCalls) {
	char str[] = "abc";
	ft_striteri(str, to_upper);
	EXPECT_STREQ(str, "ABC");

	ft_striteri(str, index_digit);
	EXPECT_STREQ(str, "012");
}
