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

void test_create_params_valid5args(void)
{
	int argc = 6;
	char *argv[6] = {"cmd", "1", "20", "30", "40", "50"};
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

void test_create_params_valid4args(void)
{
	int argc = 5;
	char *argv[5] = {"cmd", "1", "20", "30", "40"};
	int args[5];
	t_th_param *params = create_params(argc, argv, args);
	TEST_ASSERT_EQUAL_INT(1, params[0].game->args[0]);
	TEST_ASSERT_EQUAL_INT(20, params[0].game->args[1]);
	TEST_ASSERT_EQUAL_INT(30, params[0].game->args[2]);
	TEST_ASSERT_EQUAL_INT(40, params[0].game->args[3]);
	TEST_ASSERT_EQUAL_INT(-1, params[0].game->args[4]);
	TEST_ASSERT_EQUAL_INT(1, params[0].game->even_or_odd);
	TEST_ASSERT_EQUAL_INT(0, params[0].i);
	close_game(&(params[0].game));
	free(params);
}

void test_create_params_invalid_wrong_type(void)
{
	int argc = 5;
	char *argv[5] = {"cmd", "1", "a", "30", "40"};
	int args[5];
	t_th_param *params = create_params(argc, argv, args);
	TEST_ASSERT_NULL(params);
}

void test_create_params_invalid_wrong_number(void)
{
	int argc = 5;
	char *argv[5] = {"cmd", "1", "-1", "30", "40"};
	int args[5];
	t_th_param *params = create_params(argc, argv, args);
	TEST_ASSERT_NULL(params);
}

void test_create_params_invalid_too_big(void)
{
	int argc = 5;
	char *argv[5] = {"cmd", "1", "2147483648", "30", "40"};
	int args[5];
	t_th_param *params = create_params(argc, argv, args);
	TEST_ASSERT_NULL(params);
}

void test_create_params_invalid_few_args(void)
{
	int argc = 1;
	char *argv[1] = {"cmd"};
	int args[5];
	t_th_param *params = create_params(argc, argv, args);
	TEST_ASSERT_NULL(params);
}

void test_create_params_invalid_too_many_args(void)
{
	int argc = 7;
	char *argv[7] = {"cmd", "1", "20", "30", "40", "50", "60"};;
	int args[5];
	t_th_param *params = create_params(argc, argv, args);
	TEST_ASSERT_NULL(params);
}

// Main function to run the tests
int	main(void)
{
	UNITY_BEGIN();
    RUN_TEST(test_create_params_valid5args);
	RUN_TEST(test_create_params_valid4args);
	RUN_TEST(test_create_params_invalid_wrong_type);
	RUN_TEST(test_create_params_invalid_wrong_number);
	RUN_TEST(test_create_params_invalid_too_big);
	RUN_TEST(test_create_params_invalid_few_args);
	RUN_TEST(test_create_params_invalid_too_many_args);
	return (UNITY_END());
}