#include <gtest/gtest.h>
#include <cstring>  // for std::memcmp
#include <cstddef>  // for size_t

extern "C" int ft_memcmp(const void* str1, const void* str2, size_t n);

TEST(FTMemcmpTest, EqualBuffers) {
    const char* s1 = "hello world";
    const char* s2 = "hello world";
    EXPECT_EQ(ft_memcmp(s1, s2, 11), std::memcmp(s1, s2, 11));
}

TEST(FTMemcmpTest, DifferentAtBeginning) {
    const char* s1 = "xello";
    const char* s2 = "hello";
    EXPECT_EQ(ft_memcmp(s1, s2, 5), std::memcmp(s1, s2, 5));
}

TEST(FTMemcmpTest, DifferentAtMiddle) {
    const char* s1 = "heLlo";
    const char* s2 = "hello";
    EXPECT_EQ(ft_memcmp(s1, s2, 5), std::memcmp(s1, s2, 5));
}

TEST(FTMemcmpTest, DifferentAtEnd) {
    const char* s1 = "hella";
    const char* s2 = "hello";
    EXPECT_EQ(ft_memcmp(s1, s2, 5), std::memcmp(s1, s2, 5));
}

TEST(FTMemcmpTest, ZeroLength) {
    const char* s1 = "abc";
    const char* s2 = "xyz";
    EXPECT_EQ(ft_memcmp(s1, s2, 0), std::memcmp(s1, s2, 0));
}

TEST(FTMemcmpTest, BinaryData) {
    const unsigned char a[] = {0x00, 0x01, 0x02};
    const unsigned char b[] = {0x00, 0x01, 0x03};
    EXPECT_EQ(ft_memcmp(a, b, 3), std::memcmp(a, b, 3));
}
