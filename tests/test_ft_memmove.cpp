#include <gtest/gtest.h>
#include <cstring>  // for std::memmove
#include <cstddef>  // for size_t

extern "C" void* ft_memmove(void* dest, void* src, size_t n);

TEST(FTMemmoveTest, BasicForwardCopy) {
    char src[] = "abcdef";
    char dest1[7] = {};
    char dest2[7] = {};

    std::memmove(dest1, src, 7);
    ft_memmove(dest2, src, 7);

    EXPECT_STREQ(dest1, dest2);
}

TEST(FTMemmoveTest, OverlappingBackward) {
    char buffer1[20] = "123456789";
    char buffer2[20] = "123456789";

    std::memmove(buffer1 + 2, buffer1, 7);  // Overlapping
    ft_memmove(buffer2 + 2, buffer2, 7);

    EXPECT_EQ(std::memcmp(buffer1, buffer2, 12), 0);
}

TEST(FTMemmoveTest, OverlappingForward) {
    char buffer1[20] = "123456789";
    char buffer2[20] = "123456789";

    std::memmove(buffer1, buffer1 + 2, 7);  // Overlapping
    ft_memmove(buffer2, buffer2 + 2, 7);

    EXPECT_EQ(std::memcmp(buffer1, buffer2, 12), 0);
}

TEST(FTMemmoveTest, ZeroLength) {
    char src[] = "hello";
    char dest1[] = "world";
    char dest2[] = "world";

    std::memmove(dest1, src, 0);
    ft_memmove(dest2, src, 0);

    EXPECT_STREQ(dest1, dest2);
}

TEST(FTMemmoveTest, NullPointersWithZeroLength) {
    EXPECT_EQ(ft_memmove(NULL, NULL, 0), nullptr);
}

TEST(FTMemmoveTest, NullSrc) {
	char dest[10] = {};
	EXPECT_EQ(ft_memmove(dest, NULL, 5), nullptr);
}

TEST(FTMemmoveTest, NullDest) {
	char src[] = "test";
	EXPECT_EQ(ft_memmove(NULL, src, 4), nullptr);
}
