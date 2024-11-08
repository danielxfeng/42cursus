#include "../../src/ft_printf/ft_printf.h"
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

void    test_sys_func(void)
{
    printf("-------------none--------------\n");
    printf("normalcasetest-without-parameter\n");
    printf("-------------c--------------");
    printf("normalcasetest-c-%c-end\n", 'c');
    printf("edgecasetest-c-invalid200-%c-end\n", 200);
    printf("edgecasetest-c-0-%c-end\n", 0);
    printf("edgecasetest-c-str-%c-end\n", "str");
    printf("-------------s--------------\n");
    printf("normalcasetest-s-%s-end\n", "str");
    printf("normalcasetest-s-empty-%s-end\n", "");
    printf("edgecasetest-s-non-%s-end\n");
    printf("edgecasetest-s-zero-%s-end\n", 0);
    printf("-------------p--------------\n");
    int i = 100;
    printf("normalcasetest-p-%p-end\n", &i);
    printf("edgecasetest-p-invalid-str-%p-end\n", "str");
    printf("edgecasetest-p-non-%p-end\n");
    printf("edgecasetest-p-zero-%p-end\n", 0);
    printf("edgecasetest-p-max-%p-end\n", SIZE_MAX);
    printf("edgecasetest-p-max+1-%p-end\n", SIZE_MAX + 1);
    printf("edgecasetest-p-max+2-%p-end\n", SIZE_MAX + 2);
    printf("-------------d--------------\n");
    printf("normalcasetest-d-%d-end\n", 100);
    printf("normalcasetest-d-max-%d-end\n", INT_MAX);
    printf("normalcasetest-d-min-%d-end\n", INT_MIN);
    printf("edgecasetest-d-invalid-str-%d-end\n", "str");
    printf("edgecasetest-d-non-%d-end\n");
    printf("edgecasetest-d-zero-%d-end\n", 0);
    printf("eagecasetest-d-overflow-%d-end\n", INT_MAX + 1);
    printf("eagecasetest-d-overflow-%d-end\n", 99999999999999999999999999);
    printf("eagecasetest-d-overflow-%d-end\n", -99999999999999999999999999);
    printf("-------------i--------------\n");
    printf("normalcasetest-i-%i-end\n", 100);
    printf("normalcasetest-i-max-%i-end\n", INT_MAX);
    printf("normalcasetest-i-min-%i-end\n", INT_MIN);
    printf("edgecasetest-i-invalid-str-%i-end\n", "str");
    printf("edgecasetest-i-non-%i-end\n");
    printf("edgecasetest-i-zero-%i-end\n", 0);
    printf("eagecasetest-i-overflow-%i-end\n", INT_MAX + 1);
    printf("eagecasetest-i-overflow-%i-end\n", 99999999999999999999999999);
    printf("eagecasetest-i-overflow-%i-end\n", -99999999999999999999999999);
    printf("-------------u--------------\n");
    printf("normalcasetest-u-%u-end\n", 100);
    printf("normalcasetest-u-max-%u-end\n", INT_MAX);
    printf("normalcasetest-u-min-%u-end\n", INT_MIN);
    printf("edgecasetest-u-invalid-str-%u-end\n", "str");
    printf("edgecasetest-u-non-%u-end\n");
    printf("edgecasetest-u-zero-%u-end\n", 0);
    printf("eagecasetest-u-overflow-%u-end\n", INT_MAX + 1);
    printf("eagecasetest-u-overflow-%u-end\n", 99999999999999999999999999);
    printf("eagecasetest-u-overflow-%u-end\n", -99999999999999999999999999);
    printf("-------------x--------------\n");
    printf("normalcasetest-x-%x-end\n", 100);
    printf("normalcasetest-x-max-%x-end\n", INT_MAX);
    printf("normalcasetest-x-min-%x-end\n", INT_MIN);
    printf("edgecasetest-x-invalid-str-%x-end\n", "str");
    printf("edgecasetest-x-non-%x-end\n");
    printf("edgecasetest-x-zero-%x-end\n", 0);
    printf("eagecasetest-x-overflow-%x-end\n", INT_MAX + 1);
    printf("eagecasetest-x-overflow-%x-end\n", 99999999999999999999999999);
    printf("eagecasetest-x-overflow-%x-end\n", -99999999999999999999999999);
    printf("-------------X--------------\n");
    printf("normalcasetest-X-%X-end\n", 100);
    printf("normalcasetest-X-max-%X-end\n", INT_MAX);
    printf("normalcasetest-X-min-%X-end\n", INT_MIN);
    printf("edgecasetest-X-invalid-str-%X-end\n", "str");
    printf("edgecasetest-X-non-%X-end\n");
    printf("edgecasetest-X-zero-%X-end\n", 0);
    printf("eagecasetest-X-overflow-%X-end\n", INT_MAX + 1);
    printf("eagecasetest-X-overflow-%X-end\n", 99999999999999999999999999);
    printf("eagecasetest-X-overflow-%X-end\n", -99999999999999999999999999);
    printf("-------------Combined--------------\n");
    printf("normalcasetest-%%%c%d%i%p%x%X-end\n", 'c', 100, 100, 100, &i, 100, 100);
    printf("s-normalcasetest-%%%c%d%i%p%x%X\n", 'c', 100, 100, 100, &i, 100, 100);
    printf("edgecasetest-%%%c%d%i%p%x%X%\n", 'c', 100, 100, 100, &i, 100, 100);
    printf("edgecasetest-%%%%d%i%p%x%X%\n", 'c', 100, 100, 100, &i, 100, 100);
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

// Main function to run the tests
int	main(void)
{
	UNITY_BEGIN();
    RUN_TEST(test_print_nbr);
	RUN_TEST(test_sys_func);

	return (UNITY_END());
}