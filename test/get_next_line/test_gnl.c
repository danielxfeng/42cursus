#include "../../src/get_next_line/get_next_line.h"
#include "unity.h"
#include <ctype.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Setup function called before each test
void	setUp(void)
{
	// Initialize or allocate resources if needed (optional)
}

// Teardown function called after each test
void	tearDown(void)
{
	// Clean up resources if needed (optional)
}

char *fill_str()
{
    int i = 0;
    char *str = "hello world";
    char *s1 = malloc(100 * sizeof(char));
    while (str[i++])
        s1[i - 1] = str[i - 1];
    return s1;
}


void    test_append_str()
{
    char *s1 = fill_str();
    char *s2 = "this is the second str";
    size_t len = 3;
    append_str_in_heap(&s1, s2, len);
    TEST_ASSERT_EQUAL_STRING("hello worldthi", s1);
    s1 = NULL;
    append_str_in_heap(&s1, s2, len);
    TEST_ASSERT_EQUAL_STRING("thi", s1);
}

void test_first_lb()
{
    char *s1 = "\nssks\n";
    TEST_ASSERT_EQUAL_INT(0, first_lb(s1));
    char *s2 = "s\n";
    TEST_ASSERT_EQUAL_INT(1, first_lb(s2));
    char *s3 = "spppp";
    TEST_ASSERT_EQUAL_INT(-1, first_lb(s3));
}

void test_extract_line()
{
    char *s1 = fill_str();
    TEST_ASSERT_EQUAL_STRING("h", extract_line(&s1, 0));
    TEST_ASSERT_EQUAL_STRING("ello world", s1);
    char *s2 = fill_str();
    TEST_ASSERT_EQUAL_STRING("hello", extract_line(&s2, 4));
    TEST_ASSERT_EQUAL_STRING(" world", s2);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_append_str);
    RUN_TEST(test_first_lb);
    RUN_TEST(test_extract_line);

	return (UNITY_END());
}