#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <cstring>  // for strcmp
#include <cstdlib>  // for free

extern "C" char **ft_split(const char *s, char c);

// Helper to convert result to a vector for easier testing
std::vector<std::string> split_to_vector(char **result) {
    std::vector<std::string> vec;
    if (!result) return vec;

    for (int i = 0; result[i] != nullptr; ++i) {
        vec.push_back(result[i]);
        free(result[i]);  // free each allocated string
    }
    free(result);  // free the array itself
    return vec;
}

TEST(FTSplitTest, BasicSplit) {
    const char *input = "one,two,three";
    char **res = ft_split(input, ',');
    std::vector<std::string> result = split_to_vector(res);
    std::vector<std::string> expected = {"one", "two", "three"};

    EXPECT_EQ(result, expected);
}

TEST(FTSplitTest, SpaceDelimiter) {
    const char *input = "hello world test";
    char **res = ft_split(input, ' ');
    std::vector<std::string> result = split_to_vector(res);
    std::vector<std::string> expected = {"hello", "world", "test"};

    EXPECT_EQ(result, expected);
}

TEST(FTSplitTest, EmptyString) {
    const char *input = "";
    char **res = ft_split(input, ',');
    std::vector<std::string> result = split_to_vector(res);
    std::vector<std::string> expected = {};

    EXPECT_EQ(result, expected);
}

TEST(FTSplitTest, OnlyDelimiters) {
    const char *input = ",,,";
    char **res = ft_split(input, ',');
    std::vector<std::string> result = split_to_vector(res);
    std::vector<std::string> expected = {};

    EXPECT_EQ(result, expected);
}

TEST(FTSplitTest, ConsecutiveDelimiters) {
    const char *input = "a,,b";
    char **res = ft_split(input, ',');
    std::vector<std::string> result = split_to_vector(res);
    std::vector<std::string> expected = {"a", "b"};

    EXPECT_EQ(result, expected);
}

TEST(FTSplitTest, DelimiterAtEnds) {
    const char *input = ",hello,world,";
    char **res = ft_split(input, ',');
    std::vector<std::string> result = split_to_vector(res);
    std::vector<std::string> expected = {"hello", "world"};

    EXPECT_EQ(result, expected);
}

TEST(FTSplitTest, NullInputReturnsNull) {
    EXPECT_EQ(ft_split(nullptr, ','), nullptr);
}

TEST(FTSplitTest, SingleCharacterInput) {
	const char *input = "a";
	char **res = ft_split(input, ',');
	std::vector<std::string> result = split_to_vector(res);
	std::vector<std::string> expected = {"a"};

	EXPECT_EQ(result, expected);
}

TEST(FTSplitTest, MultipleDelimiters) {
	const char *input = "a,b,c,d,e";
	char **res = ft_split(input, ',');
	std::vector<std::string> result = split_to_vector(res);
	std::vector<std::string> expected = {"a", "b", "c", "d", "e"};

	EXPECT_EQ(result, expected);
}

TEST(FTSplitTest, SpecialCharacters) {
	const char *input = "a@b#c$d%e";
	char **res = ft_split(input, '@');
	std::vector<std::string> result = split_to_vector(res);
	std::vector<std::string> expected = {"a", "b#c$d%e"};

	EXPECT_EQ(result, expected);
}
