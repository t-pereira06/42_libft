#include <gtest/gtest.h>
extern "C" int ft_atoi(char *str);

TEST(FTAtoiTest, BasicPositiveNumber) {
    EXPECT_EQ(ft_atoi((char *)"1234"), 1234);
}

TEST(FTAtoiTest, BasicNegativeNumber) {
    EXPECT_EQ(ft_atoi((char *)"-5678"), -5678);
}

TEST(FTAtoiTest, PositiveWithSpaces) {
    EXPECT_EQ(ft_atoi((char *)"   +42"), 42);
}

TEST(FTAtoiTest, NegativeWithTabs) {
    EXPECT_EQ(ft_atoi((char *)"\t\n  -99"), -99);
}

TEST(FTAtoiTest, Zero) {
    EXPECT_EQ(ft_atoi((char *)"0"), 0);
}

TEST(FTAtoiTest, StopsAtNonDigit) {
    EXPECT_EQ(ft_atoi((char *)"123abc456"), 123);
}

TEST(FTAtoiTest, OnlyWhitespace) {
    EXPECT_EQ(ft_atoi((char *)"   \n\t "), 0);
}

TEST(FTAtoiTest, NoDigits) {
    EXPECT_EQ(ft_atoi((char *)"abc"), 0);
}

TEST(FTAtoiTest, MaxInt) {
    EXPECT_EQ(ft_atoi((char *)"2147483647"), 2147483647);
}

TEST(FTAtoiTest, MinInt) {
    EXPECT_EQ(ft_atoi((char *)"-2147483648"), -2147483648);
}
