#include <gtest/gtest.h>
#include <unistd.h>
#include <climits>    // for INT_MIN, INT_MAX
#include <string>

extern "C" void ft_putnbr_fd(int n, int fd);
extern "C" void ft_putchar_fd(char c, int fd);  // needed since used internally

// Helper: capture the output written by ft_putnbr_fd
std::string capture_putnbr_fd(int n) {
    int pipefd[2];
    pipe(pipefd);  // pipefd[0] = read end, pipefd[1] = write end

    ft_putnbr_fd(n, pipefd[1]);
    close(pipefd[1]);

    char buffer[64] = {};
    read(pipefd[0], buffer, sizeof(buffer) - 1);
    close(pipefd[0]);

    return std::string(buffer);
}

TEST(FTPutnbrFdTest, PositiveNumber) {
    EXPECT_EQ(capture_putnbr_fd(123), "123");
    EXPECT_EQ(capture_putnbr_fd(0), "0");
    EXPECT_EQ(capture_putnbr_fd(42), "42");
}

TEST(FTPutnbrFdTest, NegativeNumber) {
    EXPECT_EQ(capture_putnbr_fd(-1), "-1");
    EXPECT_EQ(capture_putnbr_fd(-42), "-42");
    EXPECT_EQ(capture_putnbr_fd(-9999), "-9999");
}

TEST(FTPutnbrFdTest, IntLimits) {
    EXPECT_EQ(capture_putnbr_fd(INT_MIN), "-2147483648");
    EXPECT_EQ(capture_putnbr_fd(INT_MAX), "2147483647");
}

TEST(FTPutnbrFdTest, InvalidFdShouldNotCrash) {
    EXPECT_NO_FATAL_FAILURE(ft_putnbr_fd(123, -1));
}

TEST(FTPutnbrFdTest, ZeroLengthWrite) {
	// Writing zero should not produce any output
	EXPECT_EQ(capture_putnbr_fd(0), "0");
}

TEST(FTPutnbrFdTest, HandlesSingleDigit) {
	EXPECT_EQ(capture_putnbr_fd(5), "5");
	EXPECT_EQ(capture_putnbr_fd(-3), "-3");
}

TEST(FTPutnbrFdTest, HandlesLargeNumbers) {
	EXPECT_EQ(capture_putnbr_fd(1234567890), "1234567890");
	EXPECT_EQ(capture_putnbr_fd(-987654321), "-987654321");
}

TEST(FTPutnbrFdTest, HandlesZero) {
	EXPECT_EQ(capture_putnbr_fd(0), "0");
}

TEST(FTPutnbrFdTest, HandlesNegativeZero) {
	// Negative zero is not a valid integer representation
	EXPECT_EQ(capture_putnbr_fd(-0), "0");
}

TEST(FTPutnbrFdTest, HandlesMinNegativeSingleDigit) {
	EXPECT_EQ(capture_putnbr_fd(-9), "-9");
}

TEST(FTPutnbrFdTest, HandlesMaxPositiveSingleDigit) {
	EXPECT_EQ(capture_putnbr_fd(9), "9");
}

TEST(FTPutnbrFdTest, HandlesNegativeSingleDigit) {
	EXPECT_EQ(capture_putnbr_fd(-5), "-5");
}

TEST(FTPutnbrFdTest, HandlesPositiveSingleDigit) {
	EXPECT_EQ(capture_putnbr_fd(8), "8");
}
