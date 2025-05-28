#include <gtest/gtest.h>
#include <string>    // for std::string
#include <climits>   // for INT_MAX, INT_MIN
#include <cstdlib>   // for free

extern "C" char* ft_itoa(int n);

TEST(FTItoaTest, Zero) {
    char* result = ft_itoa(0);
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "0");
    free(result);
}

TEST(FTItoaTest, PositiveNumber) {
    char* result = ft_itoa(123456);
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "123456");
    free(result);
}

TEST(FTItoaTest, NegativeNumber) {
    char* result = ft_itoa(-7890);
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "-7890");
    free(result);
}

TEST(FTItoaTest, INT_MIN_Value) {
    char* result = ft_itoa(INT_MIN);
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "-2147483648");
    free(result);
}

TEST(FTItoaTest, INT_MAX_Value) {
    char* result = ft_itoa(INT_MAX);
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "2147483647");
    free(result);
}

TEST(FTItoaTest, NegativeSingleDigit) {
    char* result = ft_itoa(-5);
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "-5");
    free(result);
}

TEST(FTItoaTest, PositiveSingleDigit) {
    char* result = ft_itoa(8);
    ASSERT_NE(result, nullptr);
    EXPECT_STREQ(result, "8");
    free(result);
}

TEST(FTItoaTest, LargePositiveNumber) {
	char* result = ft_itoa(1234567890);
	ASSERT_NE(result, nullptr);
	EXPECT_STREQ(result, "1234567890");
	free(result);
}
