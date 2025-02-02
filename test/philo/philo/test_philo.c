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

void test_create_params_invalid_zero(void)
{
	int argc = 5;
	char *argv[5] = {"cmd", "0", "2", "30", "40"};
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

void test_mq(void)
{
	t_mq *mq = create_mq(4);
	TEST_ASSERT_TRUE(print_message(mq));
	TEST_ASSERT_TRUE(send_message(mq, 0, 1, EATING));
	TEST_ASSERT_TRUE(send_message(mq, 1, 1, GET_FORK));
	TEST_ASSERT_EQUAL_INT(4, mq->capacity);
	TEST_ASSERT_EQUAL_INT64(0, mq->ts[0]);
	TEST_ASSERT_EQUAL_INT64(1, mq->ids[0]);
	TEST_ASSERT_EQUAL_INT64(EATING, mq->events[0]);
	TEST_ASSERT_EQUAL_INT64(1, mq->ts[1]);
	TEST_ASSERT_EQUAL_INT64(1, mq->ids[1]);
	TEST_ASSERT_EQUAL_INT64(GET_FORK, mq->events[1]);
	TEST_ASSERT_EQUAL_INT(2, mq->write);
	TEST_ASSERT_EQUAL_INT(0, mq->read);
	TEST_ASSERT_TRUE(print_message(mq));
	TEST_ASSERT_EQUAL_INT(2, mq->write);
	TEST_ASSERT_EQUAL_INT(2, mq->read);	
	TEST_ASSERT_TRUE(send_message(mq, 2, 1, EATING));
	TEST_ASSERT_TRUE(send_message(mq, 3, 1, GET_FORK));
	TEST_ASSERT_TRUE(send_message(mq, 4, 1, SLEEPING));
	TEST_ASSERT_EQUAL_INT(1, mq->write);
	TEST_ASSERT_EQUAL_INT(2, mq->read);
	TEST_ASSERT_TRUE(print_message(mq));
	TEST_ASSERT_EQUAL_INT(1, mq->write);
	TEST_ASSERT_EQUAL_INT(1, mq->read);
	TEST_ASSERT_TRUE(send_message(mq, 5, 1, DEAD));
	TEST_ASSERT_EQUAL_INT(2, mq->write);
	TEST_ASSERT_EQUAL_INT(1, mq->read);
	TEST_ASSERT_FALSE(print_message(mq));
	TEST_ASSERT_TRUE(mq->is_closed);
	close_mq(&mq, true);
}

void test_philo_1_philo(void)
{
	char *argv[5] = {"cmd", "1", "200", "100", "100"};
	start_game(5, argv);
	// dead after 200 ms.
}

void test_philo_2_philos_eat_less(void)
{
	char *argv[6] = {"cmd", "2", "410", "100", "200", "30"};
	start_game(6, argv);
	// will stop after certain "eating".
}

void test_philo_2_philos_eat_more(void)
{
	char *argv[6] = {"cmd", "2", "410", "200", "100", "30"};
	start_game(6, argv);
	// will stop after certain "eating".
}

void test_philo_2_philos_eat(void)
{
	char *argv[6] = {"cmd", "2", "410", "200", "200", "30"};
	start_game(6, argv);
	// will stop after certain "eating".
}

void test_philo_2_philos_dead_eat_less(void)
{
	char *argv[6] = {"cmd", "2", "310", "120", "200", "30"};
	start_game(6, argv);
	// will stop after certain "eating".
}

void test_philo_2_philos_dead_eat_more(void)
{
	char *argv[6] = {"cmd", "2", "310", "200", "100", "30"};
	start_game(6, argv);
	// will stop after certain "eating".
}

void test_philo_2_philos_dead_eat(void)
{
	char *argv[6] = {"cmd", "2", "310", "200", "200", "30"};
	start_game(6, argv);
	// will stop after certain "eating".
}

void test_philo_3_philos_eat_less(void)
{
	char *argv[6] = {"cmd", "3", "610", "100", "200", "30"};
	start_game(6, argv);
	// will stop after certain "eating".
}

void test_philo_3_philos_eat_more(void)
{
	char *argv[6] = {"cmd", "3", "610", "200", "100", "30"};
	start_game(6, argv);
	// will stop after certain "eating".
}

void test_philo_3_philos_eat(void)
{
	char *argv[6] = {"cmd", "3", "610", "200", "200", "30"};
	start_game(6, argv);
	// will stop after certain "eating".
}

void test_philo_3_philos_dead_eat_more(void)
{
	char *argv[6] = {"cmd", "3", "410", "200", "100", "30"};
	start_game(6, argv);
	// will stop after certain "eating".
}

void test_philo_3_philos_dead_eat(void)
{
	char *argv[6] = {"cmd", "3", "410", "200", "200", "30"};
	start_game(6, argv);
	// will stop after certain "eating".
}

void test_philo_200_philos(void)
{
	char *argv[6] = {"cmd", "200", "410", "200", "100", "100"};
	start_game(6, argv);
	// will stop after certain "eating".
}

void test_philo_199_philos(void)
{
	char *argv[6] = {"cmd", "199", "610", "200", "200", "100"};
	start_game(6, argv);
	// will stop after certain "eating".
}

void test_1822(void)
{
	char *argv[6] = {"cmd", "1", "800", "200", "200", "100"};
	start_game(6, argv);
	// will stop after certain "eating".
}

void test_5822(void)
{
	char *argv[6] = {"cmd", "5", "800", "200", "200", "10"};
	start_game(6, argv);
	// will stop after certain "eating".
}

void test_58227(void)
{
	char *argv[6] = {"cmd", "5", "800", "200", "200", "7"};
	start_game(6, argv);
	// will stop after certain "eating".
}

void test_4422(void)
{
	char *argv[6] = {"cmd", "4", "410", "200", "200", "30"};
	start_game(6, argv);
	// will stop after certain "eating".
}

void test_4321(void)
{
	char *argv[6] = {"cmd", "4", "310", "200", "100", "30"};
	start_game(6, argv);
	// will stop after certain "eating".
}

// Main function to run the tests
int	main(void)
{
	UNITY_BEGIN();
    RUN_TEST(test_create_params_valid5args);
	RUN_TEST(test_create_params_valid4args);
	RUN_TEST(test_create_params_invalid_wrong_type);
	RUN_TEST(test_create_params_invalid_wrong_number);
	RUN_TEST(test_create_params_invalid_zero);
	RUN_TEST(test_create_params_invalid_too_big);
	RUN_TEST(test_create_params_invalid_few_args);
	RUN_TEST(test_create_params_invalid_too_many_args);
	RUN_TEST(test_mq);
	RUN_TEST(test_philo_1_philo);
	// RUN_TEST(test_philo_2_philos_eat_less);
	// RUN_TEST(test_philo_2_philos_eat_more);
	// RUN_TEST(test_philo_2_philos_eat);
	// RUN_TEST(test_philo_2_philos_dead_eat_less);
	// RUN_TEST(test_philo_2_philos_dead_eat_more);
	// RUN_TEST(test_philo_2_philos_dead_eat);
	// RUN_TEST(test_philo_3_philos_eat_less);
	// RUN_TEST(test_philo_3_philos_eat_more);
	// RUN_TEST(test_philo_3_philos_eat);
	// RUN_TEST(test_philo_3_philos_dead_eat_more);
	// RUN_TEST(test_philo_3_philos_dead_eat);
	RUN_TEST(test_philo_200_philos);
	// RUN_TEST(test_philo_199_philos);
	// RUN_TEST(test_1822);
	// RUN_TEST(test_5822);
	// RUN_TEST(test_58227);
	// RUN_TEST(test_4422);
	// RUN_TEST(test_4321);
	return (UNITY_END());
}