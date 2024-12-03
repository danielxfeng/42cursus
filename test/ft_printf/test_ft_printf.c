#include "../../src/ft_printf/ft_printf.h"
#include "../../src/ft_printf/ft_printf_helper.h"
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

void    test_print_nbr()
{
    TEST_ASSERT_EQUAL_INT(2, print_nbr(23));
    printf("%s", "\n");
    TEST_ASSERT_EQUAL_INT(3, print_nbr(-23));
    printf("%s", "\n");
    TEST_ASSERT_EQUAL_INT(1, print_nbr(-0));
    printf("%s", "\n");
    TEST_ASSERT_EQUAL_INT(1, print_nbr(004));
    printf("%s", "\n"); 
    TEST_ASSERT_EQUAL_INT(3, print_nbr(100));
    printf("%s", "\n");
    TEST_ASSERT_EQUAL_INT(10, print_nbr(INT_MAX));
    printf("%s", "\n");
    TEST_ASSERT_EQUAL_INT(11, print_nbr(INT_MIN));
    printf("%s", "\n");
    TEST_ASSERT_EQUAL_INT(11, print_nbr(INT_MIN));
    printf("%s", "\n");
    TEST_ASSERT_EQUAL_INT(10, print_nbr(INT_MIN - 1));
    printf("%s", "\n");
}

void test_print_none()
{
    printf("-------------------printf-none------------------------\n");
    TEST_ASSERT_EQUAL_INT(printf("normalcasetest-without-parameter\n"), ft_printf("normalcasetest-without-parameter\n"));
}

void test_print_c()
{
    printf("-------------------printf-c------------------------\n");
    TEST_ASSERT_EQUAL_INT(printf("normalcasetest-c-%c-end\n", 'c'), ft_printf("normalcasetest-c-%c-end\n", 'c'));
    TEST_ASSERT_EQUAL_INT(printf("edgecasetest-c-invalid200-%c-end\n", 200), ft_printf("edgecasetest-c-invalid200-%c-end\n", 200));
    TEST_ASSERT_EQUAL_INT(printf("edgecasetest-c-0-%c-end\n", 0), ft_printf("edgecasetest-c-0-%c-end\n", 0));
    TEST_ASSERT_EQUAL_INT(printf("edgecasetest-c-str-%c-end\n", "str"), ft_printf("edgecasetest-c-str-%c-end\n", "str"));
}

void test_print_s()
{
    printf("-------------------printf-s------------------------\n");
    TEST_ASSERT_EQUAL_INT(printf("normalcasetest-s-%s-end\n", "str"), ft_printf("normalcasetest-s-%s-end\n", "str"));
    TEST_ASSERT_EQUAL_INT(printf("normalcasetest-s-empty-%s-end\n", ""), ft_printf("normalcasetest-s-empty-%s-end\n", ""));
    TEST_ASSERT_EQUAL_INT(printf("edgecasetest-s-zero-%s-end\n", 0), ft_printf("edgecasetest-s-zero-%s-end\n", 0));
}

void test_print_p()
{
    printf("-------------------printf-p------------------------\n");
    int i = 100;
    TEST_ASSERT_EQUAL_INT(printf("normalcasetest-p-%p-end\n", &i), ft_printf("normalcasetest-p-%p-end\n", &i));
    TEST_ASSERT_EQUAL_INT(printf("edgecasetest-p-invalid-str-%p-end\n", "str"), ft_printf("edgecasetest-p-invalid-str-%p-end\n", "str"));
    TEST_ASSERT_EQUAL_INT(printf("edgecasetest-p-zero-%p-end\n", 0), ft_printf("edgecasetest-p-zero-%p-end\n", 0));
    TEST_ASSERT_EQUAL_INT(printf("edgecasetest-p-max-%p-end\n", SIZE_MAX), ft_printf("edgecasetest-p-max-%p-end\n", SIZE_MAX));
    TEST_ASSERT_EQUAL_INT(printf("edgecasetest-p-max+1-%p-end\n", SIZE_MAX + 1), ft_printf("edgecasetest-p-max+1-%p-end\n", SIZE_MAX + 1));
    TEST_ASSERT_EQUAL_INT(printf("edgecasetest-p-max+2-%p-end\n", SIZE_MAX + 2), ft_printf("edgecasetest-p-max+2-%p-end\n", SIZE_MAX + 2));
}

void test_print_d()
{
    printf("-------------------printf-d------------------------\n");
    TEST_ASSERT_EQUAL_INT(printf("normalcasetest-d-%d-end\n", 100), ft_printf("normalcasetest-d-%d-end\n", 100));
    TEST_ASSERT_EQUAL_INT(printf("normalcasetest-d-max-%d-end\n", INT_MAX), ft_printf("normalcasetest-d-max-%d-end\n", INT_MAX));
    TEST_ASSERT_EQUAL_INT(printf("normalcasetest-d-min-%d-end\n", INT_MIN), ft_printf("normalcasetest-d-min-%d-end\n", INT_MIN));
    TEST_ASSERT_EQUAL_INT(printf("edgecasetest-d-invalid-str-%d-end\n", "str"), ft_printf("edgecasetest-d-invalid-str-%d-end\n", "str"));
    TEST_ASSERT_EQUAL_INT(printf("eagecasetest-d-overflow-%d-end\n", INT_MAX + 1), ft_printf("eagecasetest-d-overflow-%d-end\n", INT_MAX + 1));
    TEST_ASSERT_EQUAL_INT(printf("eagecasetest-d-overflow-%d-end\n", 99999999999999999999999999), ft_printf("eagecasetest-d-overflow-%d-end\n", 99999999999999999999999999));
    TEST_ASSERT_EQUAL_INT(printf("eagecasetest-d-overflow-%d-end\n", -99999999999999999999999999), ft_printf("eagecasetest-d-overflow-%d-end\n", -99999999999999999999999999));
}

void test_print_i()
{
    printf("-------------------printf-i------------------------\n");
    TEST_ASSERT_EQUAL_INT(printf("normalcasetest-i-%i-end\n", 100), ft_printf("normalcasetest-i-%i-end\n", 100));
    TEST_ASSERT_EQUAL_INT(printf("normalcasetest-i-max-%i-end\n", INT_MAX), ft_printf("normalcasetest-i-max-%i-end\n", INT_MAX));
    TEST_ASSERT_EQUAL_INT(printf("normalcasetest-i-min-%i-end\n", INT_MIN), ft_printf("normalcasetest-i-min-%i-end\n", INT_MIN));
    TEST_ASSERT_EQUAL_INT(printf("edgecasetest-i-invalid-str-%i-end\n", "str"), ft_printf("edgecasetest-i-invalid-str-%i-end\n", "str"));
    TEST_ASSERT_EQUAL_INT(printf("edgecasetest-i-zero-%i-end\n", 0), ft_printf("edgecasetest-i-zero-%i-end\n", 0));
    TEST_ASSERT_EQUAL_INT(printf("eagecasetest-i-overflow-%i-end\n", INT_MAX + 1), ft_printf("eagecasetest-i-overflow-%i-end\n", INT_MAX + 1));
    TEST_ASSERT_EQUAL_INT(printf("eagecasetest-i-overflow-%i-end\n", 99999999999999999999999999), ft_printf("eagecasetest-i-overflow-%i-end\n", 99999999999999999999999999));
    TEST_ASSERT_EQUAL_INT(printf("eagecasetest-i-overflow-%i-end\n", -99999999999999999999999999), ft_printf("eagecasetest-i-overflow-%i-end\n", -99999999999999999999999999));
}

void test_print_u()
{
    printf("-------------------printf-u------------------------\n");
    TEST_ASSERT_EQUAL_INT(printf("normalcasetest-u-%u-end\n", 100), ft_printf("normalcasetest-u-%u-end\n", 100));
    TEST_ASSERT_EQUAL_INT(printf("normalcasetest-u-max-%u-end\n", INT_MAX), ft_printf("normalcasetest-u-max-%u-end\n", INT_MAX));
    TEST_ASSERT_EQUAL_INT(printf("normalcasetest-u-min-%u-end\n", INT_MIN), ft_printf("normalcasetest-u-min-%u-end\n", INT_MIN));
    TEST_ASSERT_EQUAL_INT(printf("edgecasetest-u-invalid-str-%u-end\n", "str"), ft_printf("edgecasetest-u-invalid-str-%u-end\n", "str"));
    TEST_ASSERT_EQUAL_INT(printf("edgecasetest-u-zero-%u-end\n", 0), ft_printf("edgecasetest-u-zero-%u-end\n", 0));
    TEST_ASSERT_EQUAL_INT(printf("eagecasetest-u-overflow-%u-end\n", INT_MAX + 1), ft_printf("eagecasetest-u-overflow-%u-end\n", INT_MAX + 1));
    TEST_ASSERT_EQUAL_INT(printf("eagecasetest-u-overflow-%u-end\n", 99999999999999999999999999), ft_printf("eagecasetest-u-overflow-%u-end\n", 99999999999999999999999999));
    TEST_ASSERT_EQUAL_INT(printf("eagecasetest-u-overflow-%u-end\n", -99999999999999999999999999), ft_printf("eagecasetest-u-overflow-%u-end\n", -99999999999999999999999999));
}

void test_print_x()
{
    printf("-------------------printf-x------------------------\n");
    TEST_ASSERT_EQUAL_INT(printf("normalcasetest-x-%x-end\n", 100), ft_printf("normalcasetest-x-%x-end\n", 100));
    TEST_ASSERT_EQUAL_INT(printf("normalcasetest-x-max-%x-end\n", INT_MAX), ft_printf("normalcasetest-x-max-%x-end\n", INT_MAX));
    TEST_ASSERT_EQUAL_INT(printf("normalcasetest-x-min-%x-end\n", INT_MIN), ft_printf("normalcasetest-x-min-%x-end\n", INT_MIN));
    TEST_ASSERT_EQUAL_INT(printf("edgecasetest-x-invalid-str-%x-end\n", "str"), ft_printf("edgecasetest-x-invalid-str-%x-end\n", "str"));
    TEST_ASSERT_EQUAL_INT(printf("edgecasetest-x-zero-%x-end\n", 0), ft_printf("edgecasetest-x-zero-%x-end\n", 0));
    TEST_ASSERT_EQUAL_INT(printf("eagecasetest-x-overflow-%x-end\n", INT_MAX + 1), ft_printf("eagecasetest-x-overflow-%x-end\n", INT_MAX + 1));
    TEST_ASSERT_EQUAL_INT(printf("eagecasetest-x-overflow-%x-end\n", 99999999999999999999999999), ft_printf("eagecasetest-x-overflow-%x-end\n", 99999999999999999999999999));
    TEST_ASSERT_EQUAL_INT(printf("eagecasetest-x-overflow-%x-end\n", -99999999999999999999999999), ft_printf("eagecasetest-x-overflow-%x-end\n", -99999999999999999999999999));
}

void test_print_X()
{
    printf("-------------------printf-x------------------------\n");
    TEST_ASSERT_EQUAL_INT(printf("normalcasetest-X-%X-end\n", 100), ft_printf("normalcasetest-X-%X-end\n", 100));
    TEST_ASSERT_EQUAL_INT(printf("normalcasetest-X-max-%X-end\n", INT_MAX), ft_printf("normalcasetest-X-max-%X-end\n", INT_MAX));
    TEST_ASSERT_EQUAL_INT(printf("normalcasetest-X-min-%X-end\n", INT_MIN), ft_printf("normalcasetest-X-min-%X-end\n", INT_MIN));
    TEST_ASSERT_EQUAL_INT(printf("edgecasetest-X-invalid-str-%X-end\n", "str"), ft_printf("edgecasetest-X-invalid-str-%X-end\n", "str"));
    TEST_ASSERT_EQUAL_INT(printf("edgecasetest-X-zero-%X-end\n", 0), ft_printf("edgecasetest-X-zero-%X-end\n", 0));
    TEST_ASSERT_EQUAL_INT(printf("eagecasetest-X-overflow-%X-end\n", INT_MAX + 1), ft_printf("eagecasetest-X-overflow-%X-end\n", INT_MAX + 1));
    TEST_ASSERT_EQUAL_INT(printf("eagecasetest-X-overflow-%X-end\n", 99999999999999999999999999), ft_printf("eagecasetest-X-overflow-%X-end\n", 99999999999999999999999999));
    TEST_ASSERT_EQUAL_INT(printf("eagecasetest-X-overflow-%X-end\n", -99999999999999999999999999), ft_printf("eagecasetest-X-overflow-%X-end\n", -99999999999999999999999999));
}

void test_print_combined()
{
    printf("-------------------printf-combined------------------------\n");
    int i = 100;
    TEST_ASSERT_EQUAL_INT(printf("normalcasetest-%%%c%d%i%p%x%X-end\n", 'c', 100, 100, 100, &i, 100, 100), ft_printf("normalcasetest-%%%c%d%i%p%x%X-end\n", 'c', 100, 100, 100, &i, 100, 100));
    TEST_ASSERT_EQUAL_INT(printf("s-normalcasetest-%%%c%d%i%p%x%X\n", 'c', 100, 100, 100, &i, 100, 100), ft_printf("s-normalcasetest-%%%c%d%i%p%x%X\n", 'c', 100, 100, 100, &i, 100, 100));
    TEST_ASSERT_EQUAL_INT(printf("edgecasetest-%%%c%d%i%p%x%X\n", 'c', 100, 100, 100, &i, 100, 100), ft_printf("edgecasetest-%%%c%d%i%p%x%X\n", 'c', 100, 100, 100, &i, 100, 100));
    TEST_ASSERT_EQUAL_INT(printf("edgecasetest-%%%%d%i%p%x%X\n", 'c', 100, 100, 100, &i, 100, 100), ft_printf("edgecasetest-%%%%d%i%p%x%X\n", 'c', 100, 100, 100, &i, 100, 100));
}

// Main function to run the tests
int	main(void)
{
	UNITY_BEGIN();
    // RUN_TEST(test_print_nbr);
    RUN_TEST(test_print_none);
    RUN_TEST(test_print_c);
    RUN_TEST(test_print_s);
    RUN_TEST(test_print_p);
    RUN_TEST(test_print_d);
    RUN_TEST(test_print_i);
    RUN_TEST(test_print_u);
    RUN_TEST(test_print_x);
    RUN_TEST(test_print_X);
    RUN_TEST(test_print_combined);

	return (UNITY_END());
}