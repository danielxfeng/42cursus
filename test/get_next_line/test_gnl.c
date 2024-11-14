#include "../../src/get_next_line/get_next_line.h"
#include "unity.h"
#include <ctype.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
// valgrind --leak-check=full --show-leak-kinds=all ./build/test_gnl 

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
    s1[i - 1] = '\0';
    return s1;
}


void    test_append_str()
{
    char *s1 = fill_str();
    char *s2 = "this is the second str";
    size_t len = 3;
    append_str_in_heap(&s1, s2, len);
    TEST_ASSERT_EQUAL_STRING("hello worldthi", s1);
    free(s1);
    s1 = NULL;
    append_str_in_heap(&s1, s2, len);
    TEST_ASSERT_EQUAL_STRING("thi", s1);
    free(s1);
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
    char *v1 = extract_line(&s1, 0);
    TEST_ASSERT_EQUAL_STRING("h", v1);
    TEST_ASSERT_EQUAL_STRING("ello world", s1);
    free(s1);
    free(v1);
    char *s2 = fill_str();
    char *v2 = extract_line(&s2, 4);
    TEST_ASSERT_EQUAL_STRING("hello", v2);
    TEST_ASSERT_EQUAL_STRING(" world", s2);
    free(s2);
    free(v2);
    char *s3 = fill_str();
    char *v3 = extract_line(&s3, 10);
    TEST_ASSERT_EQUAL_STRING("hello world", v3);
    printf("----a%sa------", s3);
    TEST_ASSERT_NULL(s3);
    free(v3);
}

void test_wrong_file()
{
    TEST_ASSERT_NULL(get_next_line(-1));
    TEST_ASSERT_NULL(get_next_line(-1));
}

void test_empty_file()
{
    int fd = open("./test/get_next_line/files/empty", O_RDWR);
    TEST_ASSERT_NULL(get_next_line(fd));
    TEST_ASSERT_NULL(get_next_line(fd));
    close(fd);
}

void test_empty_2lines()
{
    int fd = open("./test/get_next_line/files/nl", O_RDWR);
    char *v1 = get_next_line(fd);
    TEST_ASSERT_EQUAL_STRING("\n", v1);
    TEST_ASSERT_NULL(get_next_line(fd));
    free(v1);
    close(fd);    
}

void test_41nl()
{
    int fd = open("./test/get_next_line/files/41_with_nl", O_RDWR);
    char *v1 = get_next_line(fd);
    TEST_ASSERT_EQUAL_STRING("0123456789012345678901234567890123456789\n", v1);
    char *v2 = get_next_line(fd);
    TEST_ASSERT_EQUAL_STRING("0", v2);
    TEST_ASSERT_NULL(get_next_line(fd));
    free(v1);
    free(v2);
    close(fd);    
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_append_str);
    RUN_TEST(test_first_lb);
    RUN_TEST(test_extract_line);
    RUN_TEST(test_wrong_file);
    RUN_TEST(test_empty_file);
    RUN_TEST(test_empty_2lines);
    RUN_TEST(test_41nl);
	return (UNITY_END());
}