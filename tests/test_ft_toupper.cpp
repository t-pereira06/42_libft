#include <gtest/gtest.h>

extern "C" int ft_toupper(int a);

TEST(FTToupperTest, UppercaseLettersStaySame) {
    for (char c = 'A'; c <= 'Z'; ++c) {
        EXPECT_EQ(ft_toupper(c), c);
    }
}

TEST(FTToupperTest, LowercaseLettersAreConverted) {
    for (char c = 'a'; c <= 'z'; ++c) {
        EXPECT_EQ(ft_toupper(c), c - 32);
    }
}

TEST(FTToupperTest, NonAlphabetCharactersUnchanged) {
    EXPECT_EQ(ft_toupper('1'), '1');
    EXPECT_EQ(ft_toupper('@'), '@');
    EXPECT_EQ(ft_toupper(' '), ' ');
    EXPECT_EQ(ft_toupper('\n'), '\n');
}

TEST(FTToupperTest, BoundaryValues) {
    EXPECT_EQ(ft_toupper(0), 0);
    EXPECT_EQ(ft_toupper(127), 127);
}

TEST(FTToupperTest, ExtendedASCII) {
	// Assuming ft_toupper handles extended ASCII correctly
	EXPECT_EQ(ft_toupper(128), 128);  // Should remain unchanged
	EXPECT_EQ(ft_toupper(255), 255);  // Should remain unchanged
}

TEST(FTToupperTest, NullCharacter) {
	EXPECT_EQ(ft_toupper('\0'), '\0');  // Null character should remain unchanged
}

TEST(FTToupperTest, SingleCharacterInput) {
	EXPECT_EQ(ft_toupper('z'), 'Z');  // Single lowercase character
	EXPECT_EQ(ft_toupper('A'), 'A');  // Single uppercase character
	EXPECT_EQ(ft_toupper('!'), '!');  // Non-alphabetic character
}

TEST(FTToupperTest, MultipleCharacters) {
	std::string input = "Hello World!";
	std::string expected = "HELLO WORLD!";
	for (size_t i = 0; i < input.size(); ++i) {
		EXPECT_EQ(ft_toupper(input[i]), expected[i]);
	}
}
