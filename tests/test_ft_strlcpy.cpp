#include <gtest/gtest.h>
#include <cstring>  // for std::strlen
#include <string>

extern "C" size_t ft_strlcpy(char *dest, char *src, size_t size);

TEST(FTStrlcpyTest, FullCopyWithSufficientSpace) {
    char dest[20];
    char src[] = "mexico";
    size_t ret = ft_strlcpy(dest, src, sizeof(dest));

    EXPECT_EQ(ret, std::strlen(src));
    EXPECT_STREQ(dest, src);
}

TEST(FTStrlcpyTest, PartialCopyDueToSizeLimit) {
    char dest[10];
    char src[] = "south africa";

    size_t ret = ft_strlcpy(dest, src, 8);  // space for 7 + null
    EXPECT_EQ(ret, std::strlen(src));
    EXPECT_EQ(dest[7], '\0');
    EXPECT_STREQ(dest, "south a");
}

TEST(FTStrlcpyTest, SizeIsZero) {
    char dest[] = "unchanged";
    char src[] = "ignored";
    size_t ret = ft_strlcpy(dest, src, 0);

    EXPECT_EQ(ret, std::strlen(src));
    EXPECT_STREQ(dest, "unchanged");
}

TEST(FTStrlcpyTest, EmptySource) {
    char dest[10] = "fill";
    char src[] = "";
    size_t ret = ft_strlcpy(dest, src, sizeof(dest));

    EXPECT_EQ(ret, 0);
    EXPECT_STREQ(dest, "");
}

TEST(FTStrlcpyTest, CopyToEmptyDestWithSize) {
    char dest[5] = {};
    char src[] = "hi!";
    size_t ret = ft_strlcpy(dest, src, 5);

    EXPECT_EQ(ret, std::strlen(src));
    EXPECT_STREQ(dest, "hi!");
}

TEST(FTStrlcpyTest, CopyWithExactFit) {
    char dest[6];
    char src[] = "hello";
    size_t ret = ft_strlcpy(dest, src, 6);

    EXPECT_EQ(ret, 5);
    EXPECT_STREQ(dest, "hello");
}

TEST(FTStrlcpyTest, CopyWithNullCharacter) {
	char dest[10];
	char src[] = "abc\0def";  // Contains a null character
	size_t ret = ft_strlcpy(dest, src, sizeof(dest));

	EXPECT_EQ(ret, 3);  // Only copies up to the first null character
	EXPECT_STREQ(dest, "abc");
}

TEST(FTStrlcpyTest, NullSource) {
	char dest[10] = "initial";
	size_t ret = ft_strlcpy(dest, nullptr, sizeof(dest));

	EXPECT_EQ(ret, 0);
	EXPECT_STREQ(dest, "initial");  // Should remain unchanged
}

TEST(FTStrlcpyTest, NullDestination) {
	char src[5] = "test";
	size_t ret = ft_strlcpy(nullptr, src, 10);

	EXPECT_EQ(ret, 0);
}
