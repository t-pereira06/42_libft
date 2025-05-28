#include <gtest/gtest.h>
#include <unistd.h>
#include <cstring>
#include <string>

extern "C" void ft_putendl_fd(char *s, int fd);

// Helper: capture the output of ft_putendl_fd
std::string capture_putendl_fd(char* s) {
    int pipefd[2];
    pipe(pipefd);  // [0] = read end, [1] = write end

    ft_putendl_fd(s, pipefd[1]);
    close(pipefd[1]);

    char buffer[1024] = {};
    read(pipefd[0], buffer, sizeof(buffer));
    close(pipefd[0]);

    return std::string(buffer);
}

TEST(FTPutendlFdTest, WritesStringWithNewline) {
    EXPECT_EQ(capture_putendl_fd((char*)"hello"), "hello\n");
    EXPECT_EQ(capture_putendl_fd((char*)""), "\n");
    EXPECT_EQ(capture_putendl_fd((char*)"test123"), "test123\n");
}

TEST(FTPutendlFdTest, NullInputDoesNothing) {
    // Should not crash or write anything
    EXPECT_NO_FATAL_FAILURE(ft_putendl_fd(NULL, 1));
}

TEST(FTPutendlFdTest, InvalidFileDescriptor) {
    // Should not crash or write anything
    EXPECT_NO_FATAL_FAILURE(ft_putendl_fd((char*)"ignored", -1));
}

TEST(FTPutendlFdTest, WritesToStandardOutput) {
	// This test checks if ft_putendl_fd can write to standard output
	// Note: This will actually print to the console during the test run
	EXPECT_NO_FATAL_FAILURE(ft_putendl_fd((char*)"stdout test", STDOUT_FILENO));
}

TEST(FTPutendlFdTest, WritesToStandardError) {
	// This test checks if ft_putendl_fd can write to standard error
	// Note: This will actually print to the console during the test run
	EXPECT_NO_FATAL_FAILURE(ft_putendl_fd((char*)"stderr test", STDERR_FILENO));
}

TEST(FTPutendlFdTest, HandlesLongStrings) {
	std::string long_string(1000, 'a');  // 1000 'a' characters
	std::string expected_output = long_string + "\n";
	EXPECT_EQ(capture_putendl_fd((char*)long_string.c_str()), expected_output);
}

TEST(FTPutendlFdTest, HandlesSpecialCharacters) {
	EXPECT_EQ(capture_putendl_fd((char*)"line1\nline2"), "line1\nline2\n");
	EXPECT_EQ(capture_putendl_fd((char*)"tab\tcharacter"), "tab\tcharacter\n");
	EXPECT_EQ(capture_putendl_fd((char*)"newline\n"), "newline\n\n");
}

TEST(FTPutendlFdTest, HandlesEmptyString) {
	EXPECT_EQ(capture_putendl_fd((char*)""), "\n");
}
