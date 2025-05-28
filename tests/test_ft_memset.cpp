#include <gtest/gtest.h>
#include <cstring>  // for std::memset
#include <cstddef>  // for size_t

extern "C" void* ft_memset(void* str, int c, size_t n);

TEST(FTMemsetTest, BasicFill) {
    char buf1[10] = "abcdefgh";
    char buf2[10] = "abcdefgh";

    std::memset(buf1, 'X', 4);
    ft_memset(buf2, 'X', 4);

    EXPECT_EQ(std::memcmp(buf1, buf2, 10), 0);
}

TEST(FTMemsetTest, FillWithZero) {
    char buf1[6] = "hello";
    char buf2[6] = "hello";

    std::memset(buf1, 0, 6);
    ft_memset(buf2, 0, 6);

    EXPECT_EQ(std::memcmp(buf1, buf2, 6), 0);
}

TEST(FTMemsetTest, ZeroLength) {
    char buf1[5] = "1234";
    char buf2[5] = "1234";

    volatile size_t zero = 0;
    std::memset(buf1, '*', zero);
    ft_memset(buf2, '*', 0);

    EXPECT_EQ(std::memcmp(buf1, buf2, 5), 0);
}

TEST(FTMemsetTest, FillWithNegativeValue) {
	char buf1[5] = "1234";
	char buf2[5] = "1234";

	std::memset(buf1, -1, 5);  // -1 is treated as 255 in unsigned char
	ft_memset(buf2, -1, 5);

	EXPECT_EQ(std::memcmp(buf1, buf2, 5), 0);
}

TEST(FTMemsetTest, NullPointer) {
	EXPECT_EQ(ft_memset(NULL, 'A', 5), nullptr);
}

TEST(FTMemsetTest, NullPointerWithZeroLength) {
	EXPECT_EQ(ft_memset(NULL, 'A', 0), nullptr);
}

TEST(FTMemsetTest, FillWithMultipleBytes) {
	char buf1[10] = "abcdefgh";
	char buf2[10] = "abcdefgh";

	std::memset(buf1, 'A', 3);
	ft_memset(buf2, 'A', 3);

	EXPECT_EQ(std::memcmp(buf1, buf2, 10), 0);
}
