#include <gtest/gtest.h>
#include <cstring>  // for std::memcpy
#include <cstddef>  // for size_t

extern "C" void* ft_memcpy(void* dest, const void* src, size_t n);

TEST(FTMemcpyTest, BasicCopy) {
    char src[] = "hello";
    char dest1[6] = {};
    char dest2[6] = {};

    std::memcpy(dest1, src, 6);
    ft_memcpy(dest2, src, 6);

    EXPECT_STREQ(dest1, dest2);
}

TEST(FTMemcpyTest, ZeroLengthCopy) {
    char src[] = "42";
    char dest1[] = "ABC";
    char dest2[] = "ABC";

    std::memcpy(dest1, src, 0);
    ft_memcpy(dest2, src, 0);

    EXPECT_STREQ(dest1, dest2);
}

TEST(FTMemcpyTest, PartialCopy) {
    char src[] = "abcdef";
    char dest1[7] = "xxxxxx";
    char dest2[7] = "xxxxxx";

    std::memcpy(dest1, src, 3);
    ft_memcpy(dest2, src, 3);

    EXPECT_EQ(std::memcmp(dest1, dest2, 6), 0);
}

TEST(FTMemcpyTest, BinaryDataCopy) {
    unsigned char src[] = {0x00, 0xFF, 0x10, 0x20};
    unsigned char dest1[4];
    unsigned char dest2[4];

    std::memcpy(dest1, src, 4);
    ft_memcpy(dest2, src, 4);

    EXPECT_EQ(std::memcmp(dest1, dest2, 4), 0);
}

TEST(FTMemcpyTest, NullSrcAndDest) {
    EXPECT_EQ(ft_memcpy(NULL, NULL, 0), nullptr);
}

TEST(FTMemcpyTest, NullSrc) {
	char dest[10] = {};
	EXPECT_EQ(ft_memcpy(dest, NULL, 5), nullptr);
}

TEST(FTMemcpyTest, NullDest) {
	const char src[] = "test";
	EXPECT_EQ(ft_memcpy(NULL, src, 4), nullptr);
}
