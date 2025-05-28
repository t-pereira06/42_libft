#include <gtest/gtest.h>
#include <cstring>  // for std::strchr

extern "C" char* ft_strchr(const char *str, int c);

TEST(FTStrchrTest, FindCharacterInMiddle) {
    const char *s = "suspensao";
    EXPECT_EQ(ft_strchr(s, 'p'), std::strchr(s, 'p'));
}

TEST(FTStrchrTest, FindFirstCharacter) {
    const char *s = "hello";
    EXPECT_EQ(ft_strchr(s, 'h'), std::strchr(s, 'h'));
}

TEST(FTStrchrTest, FindLastCharacter) {
    const char *s = "abcdef";
    EXPECT_EQ(ft_strchr(s, 'f'), std::strchr(s, 'f'));
}

TEST(FTStrchrTest, FindNullTerminator) {
    const char *s = "end";
    EXPECT_EQ(ft_strchr(s, '\0'), std::strchr(s, '\0'));
}

TEST(FTStrchrTest, CharacterNotFound) {
    const char *s = "testing";
    EXPECT_EQ(ft_strchr(s, 'z'), std::strchr(s, 'z'));
}

TEST(FTStrchrTest, EmptyString) {
    const char *s = "";
    EXPECT_EQ(ft_strchr(s, 'a'), std::strchr(s, 'a'));
    EXPECT_EQ(ft_strchr(s, '\0'), std::strchr(s, '\0'));
}

TEST(FTStrchrTest, MultipleOccurrences) {
	const char *s = "banana";
	EXPECT_EQ(ft_strchr(s, 'a'), std::strchr(s, 'a'));
	EXPECT_EQ(ft_strchr(s + 1, 'a'), std::strchr(s + 1, 'a'));
}

TEST(FTStrchrTest, NonPrintableCharacters) {
	const char *s = "abc\0def";  // Contains a null character
	EXPECT_EQ(ft_strchr(s, '\0'), std::strchr(s, '\0'));
	EXPECT_EQ(ft_strchr(s, 'b'), std::strchr(s, 'b'));
}

TEST(FTStrchrTest, ExtendedASCII) {
	const char *s = "café";
	EXPECT_EQ(ft_strchr(s, 233), strchr(s, 233));
	EXPECT_EQ(ft_strchr(s, 'c'), std::strchr(s, 'c'));
}

TEST(FTStrchrTest, CaseSensitivity) {
	const char *s = "HelloWorld";
	EXPECT_EQ(ft_strchr(s, 'H'), std::strchr(s, 'H'));
	EXPECT_EQ(ft_strchr(s, 'h'), std::strchr(s, 'h'));  // Should not find lowercase 'h'
}
