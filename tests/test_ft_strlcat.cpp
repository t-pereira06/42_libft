#include <gtest/gtest.h>
#include <cstring>  // for strlen
#include <string>

extern "C" size_t ft_strlcat(char *dest, char *src, size_t size);

TEST(FTStrlcatTest, NormalConcatenation) {
    char dest[20] = "Hello, ";
    char src[] = "World!";
    size_t result = ft_strlcat(dest, src, sizeof(dest));

    EXPECT_STREQ(dest, "Hello, World!");
    EXPECT_EQ(result, std::strlen("Hello, ") + std::strlen("World!"));
}

TEST(FTStrlcatTest, NoSpaceToAppend) {
    char dest[11] = "HelloWorld";
    char src[] = "42";
    size_t result = ft_strlcat(dest, src, 5);

    EXPECT_EQ(result, std::strlen(src) + 5);  // size < strlen(dest)
    EXPECT_STREQ(dest, "HelloWorld");        // should remain unchanged
}

TEST(FTStrlcatTest, ExactFit) {
    char dest[14] = "Hello, ";
    char src[] = "World!";
    size_t result = ft_strlcat(dest, src, 14);

    EXPECT_EQ(result, std::strlen("Hello, ") + std::strlen("World!"));
    EXPECT_STREQ(dest, "Hello, World!");
}

TEST(FTStrlcatTest, TruncationOccurs) {
    char dest[12] = "Hello, ";
    char src[] = "World!";
    size_t result = ft_strlcat(dest, src, sizeof(dest));

    EXPECT_EQ(result, std::strlen("Hello, ") + std::strlen("World!"));
    EXPECT_STREQ(dest, "Hello, Worl");  // fits up to last char + '\0'
}

TEST(FTStrlcatTest, SizeIsZero) {
    char dest[] = "data";
    char src[] = "ignored";
    size_t result = ft_strlcat(dest, src, 0);

    EXPECT_EQ(result, std::strlen(src));
}

TEST(FTStrlcatTest, EmptyDest) {
    char dest[10] = "";
    char src[] = "42";
    size_t result = ft_strlcat(dest, src, sizeof(dest));

    EXPECT_STREQ(dest, "42");
    EXPECT_EQ(result, std::strlen("42"));
}

TEST(FTStrlcatTest, EmptySrc) {
    char dest[10] = "init";
    char src[] = "";
    size_t result = ft_strlcat(dest, src, sizeof(dest));

    EXPECT_STREQ(dest, "init");
    EXPECT_EQ(result, std::strlen("init"));
}

TEST(FTStrlcatTest, NullDest) {
	char src[5] = "test";
	EXPECT_EQ(ft_strlcat(NULL, src, 10), 0);
}

TEST(FTStrlcatTest, NullSrc) {
	char dest[10] = "data";
	EXPECT_EQ(ft_strlcat(dest, NULL, sizeof(dest)), 0);
	EXPECT_STREQ(dest, "data");  // should remain unchanged
}
