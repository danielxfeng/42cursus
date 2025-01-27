#include "../../src/philo/philo/philo.h"
#include "unity.h"
#include <ctype.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

// valgrind --leak-check=full --show-leak-kinds=all ./build/test_philo.c

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

void test_create_params(void)
{
	int argc = 6;
	char *argv[6] = {"cmd", "1", "20", "30", "40", "50"};
	t_th_param *params = create_params(argc, argv);
	for (int i = 0; i < 5; i++)
	{
        printf("%d, %d\n", i, params[0].game->args[i]); 
        TEST_ASSERT_EQUAL_INT(atoi(argv[i + 1]), params[0].game->args[i]); 
	}
	TEST_ASSERT_EQUAL_INT(1, params[0].game->even_or_odd);
	TEST_ASSERT_EQUAL_INT(0, params[0].i);
}

// Main function to run the tests
int	main(void)
{
	UNITY_BEGIN();
    RUN_TEST(test_create_params);
	return (UNITY_END());
}