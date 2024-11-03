#include "unity.h"
#include "../../src/libft/libft.h"
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
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

void test_tolower()
{
    TEST_ASSERT_EQUAL_CHAR('a', ft_tolower('A'));
    TEST_ASSERT_EQUAL_CHAR('a', ft_tolower('a'));
    TEST_ASSERT_EQUAL_CHAR('-', ft_tolower('-'));
}

void test_toupper()
{
    TEST_ASSERT_EQUAL_CHAR('A', ft_toupper('A'));
    TEST_ASSERT_EQUAL_CHAR('A', ft_toupper('a'));
    TEST_ASSERT_EQUAL_CHAR('-', ft_toupper('-'));    
}

void test_strchr()
{
    char *s1 = "abcbd";
    TEST_ASSERT_EQUAL_PTR(s1 + 1, ft_strchr(s1, 'b'));
    TEST_ASSERT_EQUAL_PTR(strchr(s1, 'b'), ft_strchr(s1, 'b'));
    char *s2 = "abc";
    TEST_ASSERT_EQUAL_PTR(s2 + 3, ft_strchr(s2, '\0'));
    TEST_ASSERT_EQUAL_PTR(strchr(s2, '\0'), ft_strchr(s2, '\0'));
    char *s3 = "abc";
    TEST_ASSERT_EQUAL_PTR(NULL, ft_strchr(s3, 'd'));
    TEST_ASSERT_EQUAL_PTR(strchr(s3, 'd'), ft_strchr(s3, 'd'));
}

void test_strrchr()
{
    char *s1 = "abcbd";
    TEST_ASSERT_EQUAL_PTR(s1 + 3, ft_strrchr(s1, 'b'));
    TEST_ASSERT_EQUAL_PTR(strrchr(s1, 'b'), ft_strrchr(s1, 'b'));
    char *s2 = "abc";
    TEST_ASSERT_EQUAL_PTR(s2 + 3, ft_strchr(s2, '\0'));
    TEST_ASSERT_EQUAL_PTR(strrchr(s2, '\0'), ft_strrchr(s2, '\0'));
    char *s3 = "abc";
    TEST_ASSERT_EQUAL_PTR(NULL, ft_strchr(s3, 'd'));
    TEST_ASSERT_EQUAL_PTR(strrchr(s3, 'd'), ft_strrchr(s3, 'd'));
}

void test_strncmp()
{
    char *s1 = "hi";
    char *s2 = "hi";
    TEST_ASSERT_EQUAL_INT(strncmp(s1, s2, 2), ft_strncmp(s1, s2, 2));
    char *s3 = "hir";
    TEST_ASSERT_EQUAL_INT(strncmp(s3, s1, 2), ft_strncmp(s3, s1, 2));
    TEST_ASSERT_EQUAL_INT(strncmp(s3, s1, 3), ft_strncmp(s3, s1, 3));
    char *s4 = "";
    TEST_ASSERT_EQUAL_INT(strncmp(s4, s4, 3), ft_strncmp(s4, s4, 3));
    TEST_ASSERT_EQUAL_INT(strncmp(s2, s4, 3), ft_strncmp(s2, s4, 3));
    TEST_ASSERT_EQUAL_INT(strncmp(s1, s3, 0), ft_strncmp(s1, s3, 0));
    char *s5 = "Hi";
    TEST_ASSERT_EQUAL_INT(strncmp(s5, s2, 2), ft_strncmp(s5, s2, 2));
    char *s6 = "hello";
    TEST_ASSERT_EQUAL_INT(strncmp(s1, s6, 5), ft_strncmp(s1, s6, 5));
    char *s7 = "hi!";
    TEST_ASSERT_EQUAL_INT(strncmp(s7, s1, 3), ft_strncmp(s7, s1, 3));
    char *s8 = "hi\0hello";
    TEST_ASSERT_EQUAL_INT(strncmp(s8, s1, 5), ft_strncmp(s8, s1, 5));
}

void test_memchr()
{
    char *s = "abc";
    TEST_ASSERT_EQUAL_PTR(memchr((void *)s, 'b', 3), ft_memchr((void *)s, 'b', 3));
    TEST_ASSERT_EQUAL_PTR(memchr((void *)s, 'd', 3), ft_memchr((void *)s, 'd', 3));
    memchr(0, 'd', 3);
    ft_memchr(0, 'd', 3);
}

void test_memcmp()
{
    char *s = "abc";
    char *s2 = "abcd";
    char *s3 = "abc";
    TEST_ASSERT_EQUAL_INT(memcmp((void *)s, (void *)s2, 3), ft_memcmp((void *)s, (void *)s2, 3));
    TEST_ASSERT_EQUAL_INT(memcmp((void *)s, (void *)s2, 4), ft_memcmp((void *)s, (void *)s2, 4));
    TEST_ASSERT_EQUAL_INT(memcmp((void *)s, (void *)s3, 4), ft_memcmp((void *)s, (void *)s3, 4));
    memchr(0, (void *)s, 3);
    memchr((void *)s, 0, 3);
    memchr(0, 0, 3);
    ft_memchr(0, (void *)s, 3);
    ft_memchr((void *)s, 0, 3);
    ft_memchr(0, 0, 3);
}

void test_strnstr()
{
    char *big = "abcde";
    char *l1 = "bc";
    char *l2 = "ab";
    char *l3 = "de";
    TEST_ASSERT_EQUAL_PTR(big + 1, ft_strnstr(big, l1, 5));
    TEST_ASSERT_EQUAL_PTR(0, ft_strnstr(big, l1, 2));
    TEST_ASSERT_EQUAL_PTR(big, ft_strnstr(big, l2, 2));
    TEST_ASSERT_EQUAL_PTR(big, ft_strnstr(big, l2, 0));
    TEST_ASSERT_EQUAL_PTR(big + 3, ft_strnstr(big, l3, 5));
}

void test_atoi()
{
    TEST_ASSERT_EQUAL_INT(999, ft_atoi("999"));
    TEST_ASSERT_EQUAL_INT(999, ft_atoi("+999"));
    TEST_ASSERT_EQUAL_INT(999, ft_atoi("   +999"));
    TEST_ASSERT_EQUAL_INT(-999, ft_atoi("   -999"));
    TEST_ASSERT_EQUAL_INT(-999, ft_atoi("   -999sss"));
    TEST_ASSERT_EQUAL_INT(-999, ft_atoi("   -999  "));
    TEST_ASSERT_EQUAL_INT(0, ft_atoi("   --999  "));
    TEST_ASSERT_EQUAL_INT(atoi("9999999999999999999999999"), ft_atoi("9999999999999999999999999"));
    TEST_ASSERT_EQUAL_INT(atoi("-9999999999999999999999999"), ft_atoi("-9999999999999999999999999"));
}

void test_calloc()
{
    TEST_ASSERT_EQUAL_MEMORY(calloc(2, 3), ft_calloc(2, 3), 6);
    TEST_ASSERT_EQUAL_MEMORY(calloc(0, 3), ft_calloc(0, 3), 1);
    TEST_ASSERT_EQUAL_MEMORY(calloc(0, 0), ft_calloc(0, 0), 1);
    TEST_ASSERT_EQUAL_INT(calloc(SIZE_MAX - 1, SIZE_MAX - 1), ft_calloc(SIZE_MAX - 1, SIZE_MAX - 1));
}

void test_strdup()
{
    TEST_ASSERT_EACH_EQUAL_STRING(strdup("str"), ft_strdup("str"), 4);
    TEST_ASSERT_EACH_EQUAL_STRING(strdup("string"), ft_strdup("string"), 6);
    TEST_ASSERT_EACH_EQUAL_STRING(strdup(""), ft_strdup(""), 1);
}

void test_substr()
{
    TEST_ASSERT_EQUAL_STRING("tri", ft_substr("string", 1, 3));
    TEST_ASSERT_EQUAL_STRING("st", ft_substr("string", 0, 2));
    TEST_ASSERT_EQUAL_STRING("g", ft_substr("string", 5, 3));
    TEST_ASSERT_EQUAL_STRING("", ft_substr("string", 10, 3));
    TEST_ASSERT_EQUAL_STRING("", ft_substr("string", 2, 0));
    TEST_ASSERT_EQUAL_INT(0, ft_substr(0, 2, 0));
}

void test_strjoin()
{
    TEST_ASSERT_EQUAL_STRING("s1s2", ft_strjoin("s1", "s2"));
    TEST_ASSERT_EQUAL_STRING("s1", ft_strjoin("s1", ""));
    TEST_ASSERT_EQUAL_STRING("s2", ft_strjoin("", "s2"));
}

void test_strtrim()
{
    TEST_ASSERT_EQUAL_STRING("strs", ft_strtrim("trstrstr","rt"));
    TEST_ASSERT_EQUAL_INT(0, ft_strtrim(0,"rt"));
    TEST_ASSERT_EQUAL_STRING("trstrstr", ft_strtrim("trstrstr",0));
}

void test_split()
{
    char *res1[] = {"a", "bb", "cc", NULL};
    char **ret1 = ft_split("aebbecc", 'e');
    int i = 0;
    TEST_ASSERT_EQUAL_STRING_ARRAY(res1, ret1, 4);
    char *res2[] = {"a", "bb", "cc", NULL};
    char **ret2 = ft_split("eeaebbeecce", 'e');
    TEST_ASSERT_EQUAL_STRING_ARRAY(res2, ret2, 4);
    char *res3[] = {NULL};
    char **ret3 = ft_split("", 'e');
    TEST_ASSERT_EQUAL_STRING_ARRAY(res3, ret3, 1);
    char *res4[] = {NULL};
    char **ret4 = ft_split("eeeeeeeee", 'e');
    TEST_ASSERT_EQUAL_STRING_ARRAY(res4, ret4, 1);
}

void test_itoa()
{
    TEST_ASSERT_EQUAL_STRING("0", ft_itoa(0));
    TEST_ASSERT_EQUAL_STRING("100", ft_itoa(100));
    TEST_ASSERT_EQUAL_STRING("-234", ft_itoa(-234));
    TEST_ASSERT_EQUAL_STRING("1234", ft_itoa(1234));
    TEST_ASSERT_EQUAL_STRING("2147483647", ft_itoa(2147483647));
    TEST_ASSERT_EQUAL_STRING("-2147483648", ft_itoa(-2147483648));
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
    // RUN_TEST(test_tolower);
    // RUN_TEST(test_toupper);
    // RUN_TEST(test_strchr);
    // RUN_TEST(test_strrchr);
    // RUN_TEST(test_strncmp);
    // RUN_TEST(test_memchr);
    // RUN_TEST(test_memcmp);
    // RUN_TEST(test_strnstr);
    // RUN_TEST(test_atoi);
    // RUN_TEST(test_calloc);
    // RUN_TEST(test_substr);
    // RUN_TEST(test_strjoin);
    // RUN_TEST(test_strtrim);
    // RUN_TEST(test_split);
    RUN_TEST(test_itoa);

    return UNITY_END();
}