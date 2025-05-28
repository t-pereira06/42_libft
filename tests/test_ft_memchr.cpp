#include <gtest/gtest.h>
#include <cstring>  // for std::memchr
#include <cstddef>  // for size_t

extern "C" void* ft_memchr(const void* str, int c, size_t n);

TEST(FTMemchrTest, CharacterFoundEarly) {
    const char* input = "abcdef";
    EXPECT_EQ(ft_memchr(input, 'b', 3), std::memchr(input, 'b', 3));
}

TEST(FTMemchrTest, CharacterFoundAtEnd) {
    const char* input = "abcdef";
    EXPECT_EQ(ft_memchr(input, 'f', 6), std::memchr(input, 'f', 6));
}

TEST(FTMemchrTest, CharacterNotFound) {
    const char* input = "abcdef";
    EXPECT_EQ(ft_memchr(input, 'z', 6), std::memchr(input, 'z', 6));
}

TEST(FTMemchrTest, ZeroLengthSearch) {
    const char* input = "abcdef";
    EXPECT_EQ(ft_memchr(input, 'a', 0), std::memchr(input, 'a', 0));
}

TEST(FTMemchrTest, BinaryDataWithNullByte) {
    const unsigned char input[] = {0x00, 0x01, 0x02, 0x00, 0x03};
    EXPECT_EQ(ft_memchr(input, 0x00, 5), std::memchr(input, 0x00, 5));
    EXPECT_EQ(ft_memchr(input, 0x03, 5), std::memchr(input, 0x03, 5));
}

TEST(FTMemchrTest, EmptyString) {
    const char* input = "";
    EXPECT_EQ(ft_memchr(input, 'a', 0), std::memchr(input, 'a', 0));
}
