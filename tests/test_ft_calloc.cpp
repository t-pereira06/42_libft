#include <gtest/gtest.h>
#include <cstdlib>   // for calloc, malloc, free
#include <cstring>   // for memset, memcmp

extern "C" void* ft_calloc(size_t nitems, size_t size);

TEST(FTCallocTest, BasicZeroInitializedMemory) {
    size_t n = 5, size = 4;
    void* ft_ptr = ft_calloc(n, size);
    void* std_ptr = calloc(n, size);

    ASSERT_NE(ft_ptr, nullptr);
    ASSERT_NE(std_ptr, nullptr);
    EXPECT_EQ(std::memcmp(ft_ptr, std_ptr, n * size), 0);

    free(ft_ptr);
    free(std_ptr);
}

TEST(FTCallocTest, ZeroElements) {
    void* ft_ptr = ft_calloc(0, 4);
    void* std_ptr = calloc(0, 4);

    // Both may return either NULL or non-NULL, but should not crash
    EXPECT_TRUE(ft_ptr == nullptr || ft_ptr != nullptr);
    EXPECT_TRUE(std_ptr == nullptr || std_ptr != nullptr);

    free(ft_ptr);
    free(std_ptr);
}

TEST(FTCallocTest, ZeroSize) {
    void* ft_ptr = ft_calloc(4, 0);
    void* std_ptr = calloc(4, 0);

    EXPECT_TRUE(ft_ptr == nullptr || ft_ptr != nullptr);
    EXPECT_TRUE(std_ptr == nullptr || std_ptr != nullptr);

    free(ft_ptr);
    free(std_ptr);
}

TEST(FTCallocTest, LargeAllocationShouldReturnNullOrValid) {
    // Attempt a large allocation — don't expect success, but no crash
    size_t n = 1024 * 1024, size = 1024 * 1024;  // 1 GiB

    void* ft_ptr = ft_calloc(n, size);
    if (ft_ptr != nullptr) free(ft_ptr);  // cleanup if successful

    SUCCEED();  // Test passes if it doesn't crash
}
