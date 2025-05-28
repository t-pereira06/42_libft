#include <gtest/gtest.h>
#include <unistd.h>
#include <string>

extern "C" void ft_putstr_fd(char *s, int fd);

// Helper: capture the output written by ft_putstr_fd
std::string capture_putstr_fd(char* s) {
    int pipefd[2];
    pipe(pipefd);  // pipefd[0] = read end, pipefd[1] = write end

    ft_putstr_fd(s, pipefd[1]);
    close(pipefd[1]);

    char buffer[1024] = {};
    read(pipefd[0], buffer, sizeof(buffer) - 1);
    close(pipefd[0]);

    return std::string(buffer);
}

TEST(FTPutstrFdTest, WritesFullString) {
    EXPECT_EQ(capture_putstr_fd((char*)"hello"), "hello");
    EXPECT_EQ(capture_putstr_fd((char*)""), "");
    EXPECT_EQ(capture_putstr_fd((char*)"123456"), "123456");
}

TEST(FTPutstrFdTest, NullInputShouldDoNothing) {
    EXPECT_NO_FATAL_FAILURE(ft_putstr_fd(NULL, 1));
}

TEST(FTPutstrFdTest, InvalidFdShouldDoNothing) {
    EXPECT_NO_FATAL_FAILURE(ft_putstr_fd((char*)"ignored", -1));
}

TEST(FTPutstrFdTest, WritesToStandardOutput) {
	// This test checks if ft_putstr_fd can write to standard output
	// Note: This will actually print to the console during the test run
	EXPECT_NO_FATAL_FAILURE(ft_putstr_fd((char*)"stdout test", STDOUT_FILENO));
}

TEST(FTPutstrFdTest, WritesToStandardError) {
	// This test checks if ft_putstr_fd can write to standard error
	// Note: This will actually print to the console during the test run
	EXPECT_NO_FATAL_FAILURE(ft_putstr_fd((char*)"stderr test", STDERR_FILENO));
}

TEST(FTPutstrFdTest, HandlesLongStrings) {
	std::string long_string(1000, 'a');  // 1000 'a' characters
	EXPECT_EQ(capture_putstr_fd((char*)long_string.c_str()), long_string);
}

TEST(FTPutstrFdTest, HandlesSpecialCharacters) {
	EXPECT_EQ(capture_putstr_fd((char*)"line1\nline2"), "line1\nline2");
	EXPECT_EQ(capture_putstr_fd((char*)"tab\tcharacter"), "tab\tcharacter");
	EXPECT_EQ(capture_putstr_fd((char*)"newline\n"), "newline\n");
}

TEST(FTPutstrFdTest, HandlesNonPrintableCharacters) {
	std::string non_printable = "abc\0def";  // Contains a null character
	EXPECT_EQ(capture_putstr_fd((char*)non_printable.c_str()), "abc");
}

TEST(FTPutstrFdTest, HandlesEmptyString) {
	EXPECT_EQ(capture_putstr_fd((char*)""), "");
}

TEST(FTPutstrFdTest, HandlesSingleCharacter) {
	EXPECT_EQ(capture_putstr_fd((char*)"A"), "A");
	EXPECT_EQ(capture_putstr_fd((char*)"\n"), "\n");
	EXPECT_EQ(capture_putstr_fd((char*)"\t"), "\t");
}

TEST(FTPutstrFdTest, HandlesMultipleWrites) {
	std::string output = capture_putstr_fd((char*)"Hello") + capture_putstr_fd((char*)" World");
	EXPECT_EQ(output, "Hello World");
}
