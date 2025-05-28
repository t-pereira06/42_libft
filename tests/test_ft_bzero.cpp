#include <gtest/gtest.h>
#include <cstring>   // for std::memcmp and std::bzero (POSIX)
#include <cstdlib>   // for size_t

extern "C" void ft_bzero(void *str, size_t n);

TEST(FTBzeroTest, ZeroBytes) {
    char buf1[5] = "abcd";
    char buf2[5] = "abcd";

    ft_bzero(buf1, 0);
    bzero(buf2, 0);

    EXPECT_EQ(std::memcmp(buf1, buf2, 4), 0);
}

TEST(FTBzeroTest, BasicZero) {
    char buf1[8] = "ABCDEFG";
    char buf2[8] = "ABCDEFG";

    ft_bzero(buf1, 3);
    bzero(buf2, 3);

    EXPECT_EQ(std::memcmp(buf1, buf2, 8), 0);
}

TEST(FTBzeroTest, FullZero) {
    char buf1[8] = "ABCDEFG";
    char buf2[8] = "ABCDEFG";

    ft_bzero(buf1, 8);
    bzero(buf2, 8);

    EXPECT_EQ(std::memcmp(buf1, buf2, 8), 0);
}

TEST(FTBzeroTest, NullPointerZero) {
    // Should not crash if size == 0 and pointer is NULL
    EXPECT_NO_FATAL_FAILURE(ft_bzero(NULL, 0));
}
