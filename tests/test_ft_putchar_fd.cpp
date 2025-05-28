#include <gtest/gtest.h>
#include <unistd.h>    // for write(), pipe(), dup2(), close()
#include <fcntl.h>     // for O_CLOEXEC
#include <cstring>     // for std::memcmp

extern "C" void ft_putchar_fd(char c, int fd);

// Helper: capture a single character written to a file descriptor
std::string capture_putchar(char input_char) {
    int pipefd[2];
    pipe(pipefd);  // pipefd[0] = read end, pipefd[1] = write end

    ft_putchar_fd(input_char, pipefd[1]);
    close(pipefd[1]);  // close write end so read gets EOF

    char buffer[2] = {};
    read(pipefd[0], buffer, 1);
    close(pipefd[0]);

    return std::string(buffer);
}

TEST(FTPutchardFdTest, WritesCharacterToPipe) {
    EXPECT_EQ(capture_putchar('x'), "x");
    EXPECT_EQ(capture_putchar('A'), "A");
    EXPECT_EQ(capture_putchar('\n'), "\n");
}

TEST(FTPutchardFdTest, InvalidFdShouldDoNothing) {
    // Should not crash or write anything
    // Writing to a closed fd returns -1 inside write()
    EXPECT_NO_FATAL_FAILURE(ft_putchar_fd('x', -1));
}

TEST(FTPutchardFdTest, InvalidCharacter) {
	// ft_putchar_fd should handle invalid characters gracefully
	// This test assumes ft_putchar_fd does not crash on invalid input
	EXPECT_NO_FATAL_FAILURE(ft_putchar_fd((char)256, 1));  // 256 is out of char range
	EXPECT_NO_FATAL_FAILURE(ft_putchar_fd(-1, 1));   // -1 is also out of char range
}

TEST(FTPutchardFdTest, MultipleWrites) {
	std::string output = capture_putchar('H') + capture_putchar('i');
	EXPECT_EQ(output, "Hi");
}

TEST(FTPutchardFdTest, EmptyWrite) {
	// Writing an empty character should not produce any output
	EXPECT_EQ(capture_putchar('\0'), "");
}

TEST(FTPutchardFdTest, WriteToStandardOutput) {
	// This test checks if ft_putchar_fd can write to standard output
	// Note: This will actually print to the console during the test run
	EXPECT_NO_FATAL_FAILURE(ft_putchar_fd('A', STDOUT_FILENO));
}

TEST(FTPutchardFdTest, WriteToStandardError) {
	// This test checks if ft_putchar_fd can write to standard error
	// Note: This will actually print to the console during the test run
	EXPECT_NO_FATAL_FAILURE(ft_putchar_fd('E', STDERR_FILENO));
}

TEST(FTPutchardFdTest, WriteToClosedFd) {
	// Writing to a closed file descriptor should not crash
	int fd = open("/dev/null", O_WRONLY | O_CLOEXEC);
	close(fd);  // Close the file descriptor
	EXPECT_NO_FATAL_FAILURE(ft_putchar_fd('x', fd));  // Should not crash
}
