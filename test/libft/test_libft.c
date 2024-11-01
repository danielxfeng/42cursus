#include "unity.h"
#include "../../src/libft/includes/libft.h"
#include <ctype.h>
#include <limits.h>

// Setup function called before each test
void setUp(void) {
    // Initialize or allocate resources if needed (optional)
}

// Teardown function called after each test
void tearDown(void) {
    // Clean up resources if needed (optional)
}

void test_isalpha(void) {
    int n;

    n = 65;
    TEST_ASSERT_EQUAL_INT(1, ft_isalpha(n));
    TEST_ASSERT_EQUAL_INT(isalpha(n) != 0, ft_isalpha(n));
    
    n = 64;
    TEST_ASSERT_EQUAL_INT(0, ft_isalpha(n));
    TEST_ASSERT_EQUAL_INT(isalpha(n) != 0, ft_isalpha(n));
    
    n = 122;
    TEST_ASSERT_EQUAL_INT(1, ft_isalpha(n));
    TEST_ASSERT_EQUAL_INT(isalpha(n) != 0, ft_isalpha(n));

    n = 123;
    TEST_ASSERT_EQUAL_INT(0, ft_isalpha(n));
    TEST_ASSERT_EQUAL_INT(isalpha(n) != 0, ft_isalpha(n));

    n = -1;  
    TEST_ASSERT_EQUAL_INT(0, ft_isalpha(n));
    TEST_ASSERT_EQUAL_INT(isalpha(n) != 0, ft_isalpha(n));

    n = 70;  
    TEST_ASSERT_EQUAL_INT(1, ft_isalpha(n));
    TEST_ASSERT_EQUAL_INT(isalpha(n) != 0, ft_isalpha(n));  
}

void test_isdigit(void) {
    int n;

    n = '0';
    TEST_ASSERT_EQUAL_INT(1, ft_isdigit(n));
    TEST_ASSERT_EQUAL_INT(isdigit(n) != 0, ft_isdigit(n));
    
    n = 'a';
    TEST_ASSERT_EQUAL_INT(0, ft_isdigit(n));
    TEST_ASSERT_EQUAL_INT(isdigit(n) != 0, ft_isdigit(n));
    
    n = '9';
    TEST_ASSERT_EQUAL_INT(1, ft_isdigit(n));
    TEST_ASSERT_EQUAL_INT(isdigit(n) != 0, ft_isdigit(n));

    n = 'Z';
    TEST_ASSERT_EQUAL_INT(0, ft_isdigit(n));
    TEST_ASSERT_EQUAL_INT(isdigit(n) != 0, ft_isdigit(n));

    n = -1;  
    TEST_ASSERT_EQUAL_INT(0, ft_isdigit(n));
    TEST_ASSERT_EQUAL_INT(isdigit(n) != 0, ft_isdigit(n));
}

void test_isalnum(void) {
    int n;

    n = '0';
    TEST_ASSERT_EQUAL_INT(1, ft_isalnum(n));
    TEST_ASSERT_EQUAL_INT(isalnum(n) != 0, ft_isalnum(n));
    
    n = 'a';
    TEST_ASSERT_EQUAL_INT(1, ft_isalnum(n));
    TEST_ASSERT_EQUAL_INT(isalnum(n) != 0, ft_isalnum(n));
    
    n = '9';
    TEST_ASSERT_EQUAL_INT(1, ft_isalnum(n));
    TEST_ASSERT_EQUAL_INT(isalnum(n) != 0, ft_isalnum(n));

    n = 'Z';
    TEST_ASSERT_EQUAL_INT(1, ft_isalnum(n));
    TEST_ASSERT_EQUAL_INT(isalnum(n) != 0, ft_isalnum(n));

    n = -1;  
    TEST_ASSERT_EQUAL_INT(0, ft_isalnum(n));
    TEST_ASSERT_EQUAL_INT(isalnum(n) != 0, ft_isalnum(n));

    n = '-';  
    TEST_ASSERT_EQUAL_INT(0, ft_isalnum(n));
    TEST_ASSERT_EQUAL_INT(isalnum(n) != 0, ft_isalnum(n));
}

void test_isascii(void) {
    int n;

    n = '0';
    TEST_ASSERT_EQUAL_INT(1, ft_isascii(n));
    TEST_ASSERT_EQUAL_INT(isascii(n) != 0, ft_isascii(n));
    
    n = 'a';
    TEST_ASSERT_EQUAL_INT(1, ft_isascii(n));
    TEST_ASSERT_EQUAL_INT(isascii(n) != 0, ft_isascii(n));
    
    n = '9';
    TEST_ASSERT_EQUAL_INT(1, ft_isascii(n));
    TEST_ASSERT_EQUAL_INT(isascii(n) != 0, ft_isascii(n));

    n = 'Z';
    TEST_ASSERT_EQUAL_INT(1, ft_isascii(n));
    TEST_ASSERT_EQUAL_INT(isascii(n) != 0, ft_isascii(n));

    n = -1;  
    TEST_ASSERT_EQUAL_INT(0, ft_isascii(n));
    TEST_ASSERT_EQUAL_INT(isascii(n) != 0, ft_isascii(n));

    n = '-';  
    TEST_ASSERT_EQUAL_INT(1, ft_isascii(n));
    TEST_ASSERT_EQUAL_INT(isascii(n) != 0, ft_isascii(n));

    n = 130;  
    TEST_ASSERT_EQUAL_INT(0, ft_isascii(n));
    TEST_ASSERT_EQUAL_INT(isascii(n) != 0, ft_isascii(n));
}

void test_isprint(void) {
    for (int i = 0; i < 128; ++i)
    {
       TEST_ASSERT_EQUAL_INT(isprint(i) != 0, ft_isprint(i)); 
    }

    int n;

    n = -1;  
    TEST_ASSERT_EQUAL_INT(0, ft_isprint(n));
    TEST_ASSERT_EQUAL_INT(isprint(n) != 0, ft_isprint(n));

    n = 130;  
    TEST_ASSERT_EQUAL_INT(0, ft_isprint(n));
    TEST_ASSERT_EQUAL_INT(isprint(n) != 0, ft_isprint(n));
}

// Main function to run the tests
int main(void) {
    UNITY_BEGIN();
    // RUN_TEST(test_isalpha);
    // RUN_TEST(test_isdigit);
    // RUN_TEST(test_isalnum);
    // RUN_TEST(test_isascii);
    RUN_TEST(test_isprint);
    return UNITY_END();
}