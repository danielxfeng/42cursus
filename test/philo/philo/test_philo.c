#include "../../src/philo/philo/philo.h"
#include "unity.h"
#include <ctype.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>

// valgrind --leak-check=full --show-leak-kinds=all ./build/test_philo

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
	int argv_int[5] = {1, 20, 30, 40, 50};
	int args[5];
	t_th_param *params = create_params(argc, argv, args);
	TEST_ASSERT_EQUAL_INT(1, params[0].game->args[0]);
	TEST_ASSERT_EQUAL_INT(20, params[0].game->args[1]);
	TEST_ASSERT_EQUAL_INT(30, params[0].game->args[2]);
	TEST_ASSERT_EQUAL_INT(40, params[0].game->args[3]);
	TEST_ASSERT_EQUAL_INT(50, params[0].game->args[4]);
	TEST_ASSERT_EQUAL_INT(1, params[0].game->even_or_odd);
	TEST_ASSERT_EQUAL_INT(0, params[0].i);
	close_game(&(params[0].game));
	free(params);
}

// Main function to run the tests
int	main(void)
{
	UNITY_BEGIN();
    RUN_TEST(test_create_params);
	return (UNITY_END());
}