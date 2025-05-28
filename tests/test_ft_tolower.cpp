#include <gtest/gtest.h>

extern "C" int ft_tolower(int a);

TEST(FTTolowerTest, LowercaseLettersStaySame) {
    for (char c = 'a'; c <= 'z'; ++c) {
        EXPECT_EQ(ft_tolower(c), c);
    }
}

TEST(FTTolowerTest, UppercaseLettersAreConverted) {
    for (char c = 'A'; c <= 'Z'; ++c) {
        EXPECT_EQ(ft_tolower(c), c + 32);
    }
}

TEST(FTTolowerTest, NonAlphabetCharactersUnchanged) {
    EXPECT_EQ(ft_tolower('1'), '1');
    EXPECT_EQ(ft_tolower('@'), '@');
    EXPECT_EQ(ft_tolower(' '), ' ');
    EXPECT_EQ(ft_tolower('\n'), '\n');
}

TEST(FTTolowerTest, BoundaryValues) {
    EXPECT_EQ(ft_tolower(0), 0);
    EXPECT_EQ(ft_tolower(127), 127);
}

TEST(FTTolowerTest, ExtendedASCII) {
	// Assuming ft_tolower handles extended ASCII correctly
	EXPECT_EQ(ft_tolower(128), 128);  // Should remain unchanged
	EXPECT_EQ(ft_tolower(255), 255);  // Should remain unchanged
}

TEST(FTTolowerTest, NullCharacter) {
	EXPECT_EQ(ft_tolower('\0'), '\0');  // Null character should remain unchanged
}

TEST(FTTolowerTest, SingleCharacterInput) {
	EXPECT_EQ(ft_tolower('Z'), 'z');  // Single uppercase character
	EXPECT_EQ(ft_tolower('a'), 'a');  // Single lowercase character
	EXPECT_EQ(ft_tolower('!'), '!');  // Non-alphabetic character
}

TEST(FTTolowerTest, MultipleCharacters) {
	std::string input = "Hello World!";
	std::string expected = "hello world!";
	for (size_t i = 0; i < input.size(); ++i) {
		EXPECT_EQ(ft_tolower(input[i]), expected[i]);
	}
}
