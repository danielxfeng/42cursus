#include "../../src/pipe_x/pipe_x.h"
#include "unity.h"
#include <ctype.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// valgrind --leak-check=full --show-leak-kinds=all ./build/test_pipe_x

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

void test_create_ast(void)
{
    t_ast *ast = create_ast();
    TEST_ASSERT_NULL(ast->root);
    print_ast(ast);
    close_ast(&ast);
}

// Main function to run the tests
int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_create_ast);
	return (UNITY_END());
}