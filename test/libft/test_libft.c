#include "unity.h"
#include "../../src/libft/libft.h"
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
// #include <bsd/string.h>

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

void test_ft_strlen(void)
{
    char *test_arrs[] = {"", "test"};
    for (int i = 0; i < 2; ++i)
    {
        TEST_ASSERT_EQUAL_INT(strlen(test_arrs[i]), ft_strlen(test_arrs[i]));
    }
}

void test_ft_memset()
{
    char test[8] = "aaaaaaaa";
    char test2[8] = "aaaaaaaa";
    memset((void *)test, '0', 2);
    ft_memset((void *)test2, '0', 2);
    TEST_ASSERT_EQUAL_STRING("00aaaaaa", test2);
    TEST_ASSERT_EQUAL_MEMORY(test, test2, sizeof(test));
    memset((void *)test, 1000, 4);
    ft_memset((void *)test2, 1000, 4);
    TEST_ASSERT_EQUAL_MEMORY(test, test2, sizeof(test));
}

void test_bzero()
{
    char test[8] = "aaaaaaaa";
    char test2[8] = "aaaaaaaa";
    bzero(test, 2);
    ft_bzero(test2, 2);
    TEST_ASSERT_EQUAL_MEMORY(test, test2, sizeof(test));
}

void test_memcpy()
{
    char test[8] = "aaaaaaaa";
    char test2[10] = "bbbbbbbbbb";
    char test3[8] = "aaaaaaaa";
    char test4[10] = "bbbbbbbbbb";
    memcpy(test, test2, 1);
    ft_memcpy(test3, test4, 1);
    TEST_ASSERT_EQUAL_MEMORY(test, test3, sizeof(test));
    memcpy(test, test2, 10);
    ft_memcpy(test3, test4, 10);
    TEST_ASSERT_EQUAL_MEMORY(test, test3, sizeof(test));
    memcpy(0, 0, 10);
    ft_memcpy(0, 0, 10);
}

void test_memmove()
{
    char test1[20] = "aaaaaaaa";
    char test2[20] = "aaaaaaaa";
    char test3[20] = "bbbbbbbbbb";
    char test4[20] = "bbbbbbbbbb";
    char test5[20] = "cccccccccc";
    char test6[20] = "cccccccccc";
    ft_memmove(test1 + 8, test1, 6);
    memmove(test2 + 8, test2, 6);
    TEST_ASSERT_EQUAL_MEMORY(test1, test2, sizeof(test2));
    ft_memmove(test3 + 2, test3, 9);
    memmove(test4 + 2, test4, 9);
    TEST_ASSERT_EQUAL_MEMORY(test3, test4, sizeof(test4));
    ft_memmove(test5, test5 + 2, 9);
    memmove(test6, test6 + 2, 9);
    TEST_ASSERT_EQUAL_MEMORY(test5, test6, sizeof(test6));
    TEST_ASSERT_EQUAL_INT(0, ft_memmove(0, 0, 9));
}

void test_strlcpy()
{
    char src1[] = "hi";
    char dest1[10] = "look";
    char dest2[10] = "look";
    int res1;
    int res2;
    res1 = strlcpy(dest1, src1, 2);
    res2 = ft_strlcpy(dest1, src1, 2);
    TEST_ASSERT_EQUAL_INT(res1, res2);
    TEST_ASSERT_EQUAL_MEMORY(dest1, dest2, sizeof(dest1));
    strcpy(dest1, "look");
    strcpy(dest2, "look");
    res1 = ft_strlcpy(dest1, src1, 0);
    res2 = ft_strlcpy(dest2, src1, 0);
    TEST_ASSERT_EQUAL_INT(res1, res2);
    TEST_ASSERT_EQUAL_MEMORY(dest1, dest2, sizeof(dest1));
    strcpy(dest1, "look");
    strcpy(dest2, "look");
    res1 = ft_strlcpy(dest1, src1, 10);
    res2 = ft_strlcpy(dest2, src1, 10);
    TEST_ASSERT_EQUAL_INT(res1, res2);
    TEST_ASSERT_EQUAL_MEMORY(dest1, dest2, sizeof(dest1));
    strcpy(src1, "look");
    strcpy(dest1, "hi");
    strcpy(dest2, "hi");
    res1 = strlcpy(dest1, src1, 2);
    res2 = ft_strlcpy(dest1, src1, 2);
    TEST_ASSERT_EQUAL_INT(res1, res2);
    TEST_ASSERT_EQUAL_MEMORY(dest1, dest2, sizeof(dest1));
    strcpy(dest1, "hi");
    strcpy(dest2, "hi");
    res1 = ft_strlcpy(dest1, src1, 0);
    res2 = ft_strlcpy(dest2, src1, 0);
    TEST_ASSERT_EQUAL_INT(res1, res2);
    TEST_ASSERT_EQUAL_MEMORY(dest1, dest2, sizeof(dest1));
    strcpy(dest1, "hi");
    strcpy(dest2, "hi");
    res1 = ft_strlcpy(dest1, src1, 4);
    res2 = ft_strlcpy(dest2, src1, 4);
    TEST_ASSERT_EQUAL_INT(res1, res2);
    TEST_ASSERT_EQUAL_MEMORY(dest1, dest2, sizeof(dest1));
    strcpy(src1, "");
    strcpy(dest1, "hi");
    strcpy(dest2, "hi");
    res1 = strlcpy(dest1, src1, 2);
    res2 = ft_strlcpy(dest1, src1, 2);
    TEST_ASSERT_EQUAL_INT(res1, res2);
    TEST_ASSERT_EQUAL_MEMORY(dest1, dest2, sizeof(dest1));
    strcpy(dest1, "hi");
    strcpy(dest2, "hi");
    res1 = strlcpy(dest1, src1, 0);
    res2 = ft_strlcpy(dest1, src1, 0);
    TEST_ASSERT_EQUAL_INT(res1, res2);
    TEST_ASSERT_EQUAL_MEMORY(dest1, dest2, sizeof(dest1));
    strcpy(dest1, "hi");
    strcpy(dest2, "hi");
    res1 = strlcpy(dest1, src1, 4);
    res2 = ft_strlcpy(dest1, src1, 4);
    TEST_ASSERT_EQUAL_INT(res1, res2);
    TEST_ASSERT_EQUAL_MEMORY(dest1, dest2, sizeof(dest1));
    strcpy(src1, "hi");
    strcpy(dest1, "");
    strcpy(dest2, "");
    res1 = strlcpy(dest1, src1, 2);
    res2 = ft_strlcpy(dest1, src1, 2);
    TEST_ASSERT_EQUAL_INT(res1, res2);
    TEST_ASSERT_EQUAL_MEMORY(dest1, dest2, sizeof(dest1));
    strcpy(dest1, "");
    strcpy(dest2, "");
    res1 = strlcpy(dest1, src1, 0);
    res2 = ft_strlcpy(dest1, src1, 0);
    TEST_ASSERT_EQUAL_INT(res1, res2);
    TEST_ASSERT_EQUAL_MEMORY(dest1, dest2, sizeof(dest1));
    strcpy(dest1, "");
    strcpy(dest2, "");
    res1 = strlcpy(dest1, src1, 4);
    res2 = ft_strlcpy(dest1, src1, 4);
    TEST_ASSERT_EQUAL_INT(res1, res2);
    TEST_ASSERT_EQUAL_MEMORY(dest1, dest2, sizeof(dest1));
    strcpy(src1, "");
    strcpy(dest1, "");
    strcpy(dest2, "");
    res1 = strlcpy(dest1, src1, 2);
    res2 = ft_strlcpy(dest1, src1, 2);
    TEST_ASSERT_EQUAL_INT(res1, res2);
    TEST_ASSERT_EQUAL_MEMORY(dest1, dest2, sizeof(dest1));
    strcpy(dest1, "");
    strcpy(dest2, "");
    res1 = strlcpy(dest1, src1, 0);
    res2 = ft_strlcpy(dest1, src1, 0);
    TEST_ASSERT_EQUAL_INT(res1, res2);
    TEST_ASSERT_EQUAL_MEMORY(dest1, dest2, sizeof(dest1));
    strcpy(dest1, "");
    strcpy(dest2, "");
    res1 = strlcpy(dest1, src1, 4);
    res2 = ft_strlcpy(dest1, src1, 4);
    TEST_ASSERT_EQUAL_INT(res1, res2);
    TEST_ASSERT_EQUAL_MEMORY(dest1, dest2, sizeof(dest1));
}

// Main function to run the tests
int main(void) {
    UNITY_BEGIN();
    // RUN_TEST(test_isalpha);
    // RUN_TEST(test_isdigit);
    // RUN_TEST(test_isalnum);
    // RUN_TEST(test_isascii);
    // RUN_TEST(test_isprint);
    // RUN_TEST(test_ft_strlen);
    // RUN_TEST(test_ft_memset);
    // RUN_TEST(test_bzero);
    // RUN_TEST(test_memcpy);
    // RUN_TEST(test_memmove);
    // RUN_TEST(test_strlcpy);
    return UNITY_END();
}