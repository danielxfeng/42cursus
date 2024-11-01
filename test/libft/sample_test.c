#include "unity.h"
#include "../../src/libft/includes/libft.h"

// Setup function called before each test
void setUp(void) {
    // Initialize or allocate resources if needed (optional)
}

// Teardown function called after each test
void tearDown(void) {
    // Clean up resources if needed (optional)
}

// Test function for `sample`
void test_sample_function_should_return_sum(void) {
    int result = sample_func();
    TEST_ASSERT_EQUAL_INT(1, result);  // Expecting the sum of 0 + 1 to be 1
}

// Main function to run the tests
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_sample_function_should_return_sum);
    return UNITY_END();
}