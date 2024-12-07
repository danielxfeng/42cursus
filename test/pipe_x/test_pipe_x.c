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

void test_create_pipe_node(void)
{
    t_ast *ast = create_ast();
    ast->root = create_pipe_node(ast);
    TEST_ASSERT_EQUAL_INT(PIPE, ast->root->type);
    t_pipe_prop *prop = ast->root->prop;
    TEST_ASSERT_EQUAL_INT(-1, prop->fds[0]);
    TEST_ASSERT_EQUAL_INT(-1, prop->fds[1]);
    TEST_ASSERT_EQUAL_INT(0, prop->pid);
    print_ast(ast);
    close_ast(&ast);
}

void test_create_cmd_node(void)
{
    t_ast *ast = create_ast();
    ast->root = create_cmd_node(ast, "ls -r 000");
    TEST_ASSERT_EQUAL_INT(CMD, ast->root->type);
    t_cmd_prop *prop = ast->root->prop;
    TEST_ASSERT_EQUAL_STRING("ls", prop->cmd);
    TEST_ASSERT_EQUAL_STRING("ls", prop->args[0]);
    TEST_ASSERT_EQUAL_STRING("-r", prop->args[1]);
    TEST_ASSERT_EQUAL_STRING("000", prop->args[2]);
    print_ast(ast);
    close_ast(&ast);
}

void test_create_red_node(void)
{
    t_ast *ast = create_ast();
    ast->root = create_red_node(ast, "here", true, true);
    TEST_ASSERT_EQUAL_INT(RED, ast->root->type);
    t_red_prop *prop = ast->root->prop;
    TEST_ASSERT_EQUAL_STRING("here", prop->file_name);
    TEST_ASSERT_EQUAL_INT(-1, prop->fd);
    TEST_ASSERT_EQUAL_INT(true, prop->is_in);
    TEST_ASSERT_EQUAL_INT(true, prop->is_single);
    print_ast(ast);
    close_ast(&ast);
    ast = create_ast();
    ast->root = create_red_node(ast, "here", false, false);
    prop = ast->root->prop;
    TEST_ASSERT_EQUAL_INT(false, prop->is_in);
    TEST_ASSERT_EQUAL_INT(false, prop->is_single);
    print_ast(ast);
    close_ast(&ast);
}

void test_create_multi_nodes_ast(void)
{
    t_ast *ast = create_ast();
    ast->root = create_pipe_node(ast);
    ast->root->left = create_cmd_node(ast, "ls -r 000");
    ast->root->right = create_red_node(ast, "here", false, true);
    ast->root->left->left = create_red_node(ast, "here", true, false);
    TEST_ASSERT_EQUAL_INT(PIPE, ast->root->type);
    t_pipe_prop *prop = ast->root->prop;
    TEST_ASSERT_EQUAL_INT(-1, prop->fds[0]);
    TEST_ASSERT_EQUAL_INT(-1, prop->fds[1]);
    TEST_ASSERT_EQUAL_INT(0, prop->pid);
    TEST_ASSERT_EQUAL_INT(CMD, ast->root->left->type);
    t_cmd_prop *prop2 = ast->root->left->prop;
    TEST_ASSERT_EQUAL_STRING("ls", prop2->cmd);
    TEST_ASSERT_EQUAL_STRING("ls", prop2->args[0]);
    TEST_ASSERT_EQUAL_STRING("-r", prop2->args[1]);
    TEST_ASSERT_EQUAL_STRING("000", prop2->args[2]);
    TEST_ASSERT_EQUAL_INT(RED, ast->root->right->type);
    t_red_prop *prop3 = ast->root->right->prop;
    TEST_ASSERT_EQUAL_STRING("here", prop3->file_name);
    TEST_ASSERT_EQUAL_INT(-1, prop3->fd);
    TEST_ASSERT_EQUAL_INT(false, prop3->is_in);
    TEST_ASSERT_EQUAL_INT(true, prop3->is_single);
    t_red_prop *prop4 = ast->root->left->left->prop;
    TEST_ASSERT_EQUAL_STRING("here", prop4->file_name);
    TEST_ASSERT_EQUAL_INT(-1, prop4->fd);
    TEST_ASSERT_EQUAL_INT(true, prop4->is_in);
    TEST_ASSERT_EQUAL_INT(false, prop4->is_single);
    print_ast(ast);
    close_ast(&ast);
}

// Main function to run the tests
int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_create_ast);
    RUN_TEST(test_create_pipe_node);
    RUN_TEST(test_create_cmd_node);
    RUN_TEST(test_create_red_node);
    RUN_TEST(test_create_multi_nodes_ast);
	return (UNITY_END());
}