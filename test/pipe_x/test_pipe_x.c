#include "../../src/pipe_x/pipe_x.h"
#include "../../src/pipe_x/get_next_line/get_next_line.h"
#include "unity.h"
#include <ctype.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

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
    char **envp = NULL;
    char **path = parse_path(envp);
    t_ast *ast = create_ast(envp, path);
    TEST_ASSERT_NULL(ast->root);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(path, ast->path, 2);
    print_ast(ast);
    close_ast(&ast);
}

void test_create_pipe_node(void)
{
    char *envp[] = {"PATH=a"};
    char **path = parse_path(envp);
    t_ast *ast = create_ast(envp, path);
    ast->root = create_pipe_node(ast);
    TEST_ASSERT_EQUAL_INT(PIPE, ast->root->type);
    t_pipe_prop *prop = ast->root->prop;
    TEST_ASSERT_EQUAL_INT(-1, prop->fds[0]);
    TEST_ASSERT_EQUAL_INT(-1, prop->fds[1]);
    TEST_ASSERT_EQUAL_INT(0, prop->pids[0]);
    TEST_ASSERT_EQUAL_INT(0, prop->pids[1]);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(path, ast->path, 2);
    print_ast(ast);
    close_ast(&ast);
}

void test_create_cmd_node(void)
{
    char *envp[] = {"PATH=a"};
    char **path = parse_path(envp);
    t_ast *ast = create_ast(envp, path);
    ast->root = create_cmd_node(ast, "ls -r 000");
    TEST_ASSERT_EQUAL_INT(CMD, ast->root->type);
    t_cmd_prop *prop = ast->root->prop;
    TEST_ASSERT_EQUAL_STRING("ls", prop->args[0]);
    TEST_ASSERT_EQUAL_STRING("-r", prop->args[1]);
    TEST_ASSERT_EQUAL_STRING("000", prop->args[2]);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(path, ast->path, 2);
    print_ast(ast);
    close_ast(&ast);
}

void test_create_red_node(void)
{
    char *envp[] = {"PATH=a"};
    char **path = parse_path(envp);
    t_ast *ast = create_ast(envp, path);
    ast->root = create_red_node(ast, "here", true, true);
    TEST_ASSERT_EQUAL_INT(RED, ast->root->type);
    t_red_prop *prop = ast->root->prop;
    TEST_ASSERT_EQUAL_STRING("here", prop->file_name);
    TEST_ASSERT_EQUAL_INT(-1, prop->fd);
    TEST_ASSERT_EQUAL_INT(true, prop->is_in);
    TEST_ASSERT_EQUAL_INT(true, prop->is_single);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(path, ast->path, 2);
    print_ast(ast);
    close_ast(&ast);
    path = parse_path(envp);
    ast = create_ast(envp, path);
    ast->root = create_red_node(ast, "here", false, false);
    prop = ast->root->prop;
    TEST_ASSERT_EQUAL_INT(false, prop->is_in);
    TEST_ASSERT_EQUAL_INT(false, prop->is_single);
    print_ast(ast);
    close_ast(&ast);
}

// here < ls -r 000 | >> here
void test_create_multi_nodes_ast(void)
{
    char *envp[] = {"PATH=a"};
    char **path = parse_path(envp);
    t_ast *ast = create_ast(envp, path);
    ast->root = create_pipe_node(ast);
    ast->root->left = create_red_node(ast, "here", true, true);
    ast->root->right = create_red_node(ast, "here", false, false);
    ast->root->left->right = create_cmd_node(ast, "ls -r 000");
    TEST_ASSERT_EQUAL_INT(PIPE, ast->root->type);
    t_pipe_prop *prop = ast->root->prop;
    TEST_ASSERT_EQUAL_INT(-1, prop->fds[0]);
    TEST_ASSERT_EQUAL_INT(-1, prop->fds[1]);
    TEST_ASSERT_EQUAL_INT(0, prop->pids[0]);
    TEST_ASSERT_EQUAL_INT(0, prop->pids[1]);
    TEST_ASSERT_EQUAL_INT(CMD, ast->root->left->right->type);
    t_cmd_prop *prop2 = ast->root->left->right->prop;
    TEST_ASSERT_EQUAL_STRING("ls", prop2->args[0]);
    TEST_ASSERT_EQUAL_STRING("-r", prop2->args[1]);
    TEST_ASSERT_EQUAL_STRING("000", prop2->args[2]);
    TEST_ASSERT_EQUAL_INT(RED, ast->root->right->type);
    t_red_prop *prop3 = ast->root->right->prop;
    TEST_ASSERT_EQUAL_STRING("here", prop3->file_name);
    TEST_ASSERT_EQUAL_INT(-1, prop3->fd);
    TEST_ASSERT_EQUAL_INT(false, prop3->is_in);
    TEST_ASSERT_EQUAL_INT(false, prop3->is_single);
    t_red_prop *prop4 = ast->root->left->prop;
    TEST_ASSERT_EQUAL_STRING("here", prop4->file_name);
    TEST_ASSERT_EQUAL_INT(-1, prop4->fd);
    TEST_ASSERT_EQUAL_INT(true, prop4->is_in);
    TEST_ASSERT_EQUAL_INT(true, prop4->is_single);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(path, ast->path, 2);
    print_ast(ast);
    close_ast(&ast);
}

void test_create_tree(void)
{
    char *envp[] = {"PATH=a"};
    t_ast *ast = create_ast(envp, parse_path(envp));
    char *argv[] = {"infile", "cmd1 -r", "cmd2 -r -s", "cmd3", "cmd4", "outfile"};
    build_ast(ast, 6, argv, true);
    TEST_ASSERT_EQUAL_INT(PIPE, ast->root->type);
    TEST_ASSERT_EQUAL_INT(PIPE, ast->root->left->type);
    TEST_ASSERT_EQUAL_INT(RED, ast->root->right->type);
    t_red_prop *red_prop = (t_red_prop *)ast->root->right->prop; 
    TEST_ASSERT_EQUAL_STRING("outfile", red_prop->file_name);
    t_cmd_prop *cmd_prop = (t_cmd_prop *)ast->root->right->left->prop;
    TEST_ASSERT_EQUAL_STRING("cmd4", cmd_prop->args[0]);
    cmd_prop = (t_cmd_prop *)ast->root->left->right->prop;
    TEST_ASSERT_EQUAL_STRING("cmd3", cmd_prop->args[0]);
    TEST_ASSERT_EQUAL_INT(PIPE, ast->root->left->left->type);
    cmd_prop = (t_cmd_prop *)ast->root->left->left->right->prop;
    TEST_ASSERT_EQUAL_STRING("cmd2", cmd_prop->args[0]);
    TEST_ASSERT_EQUAL_STRING("-r", cmd_prop->args[1]);
    TEST_ASSERT_EQUAL_STRING("-s", cmd_prop->args[2]);    
    TEST_ASSERT_EQUAL_INT(RED, ast->root->left->left->left->type);
    red_prop = (t_red_prop *)ast->root->left->left->left->prop; 
    TEST_ASSERT_EQUAL_STRING("infile", red_prop->file_name);
    TEST_ASSERT_EQUAL_INT(CMD, ast->root->left->left->left->right->type);
    cmd_prop = (t_cmd_prop *)ast->root->left->left->left->right->prop;
    TEST_ASSERT_EQUAL_STRING("cmd1", cmd_prop->args[0]);
    TEST_ASSERT_EQUAL_STRING("-r", cmd_prop->args[1]);        
    print_ast(ast);
    close_ast(&ast);
}

void test_cmd_handler(void)
{
    char *envp[] = {
    "USER=username",
    "HOME=/home/username",
    "PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin",
    "SHELL=/bin/bash",
    "LANG=en_US.UTF-8",
    "PWD=/home/username",
    "LOGNAME=username",
    "TERM=xterm-256color",
    NULL
    };
    t_ast *ast = create_ast(envp, parse_path(envp));
    ast->root = create_cmd_node(ast, "/usr/bin/ls");
    TEST_ASSERT_EQUAL_INT(0, ast->root->node_handler(ast, ast->root));
    print_ast(ast);
    close_ast(&ast);
    ast = create_ast(envp, parse_path(envp));
    ast->root = create_cmd_node(ast, "ls");
    TEST_ASSERT_EQUAL_INT(0, ast->root->node_handler(ast, ast->root));
    print_ast(ast);
    close_ast(&ast);
    ast = create_ast(envp, parse_path(envp));
    ast->root = create_cmd_node(ast, "ls");
    ast->root->left = create_cmd_node(ast, "ls");
    ast->root->right = create_cmd_node(ast, "ls");
    TEST_ASSERT_EQUAL_INT(0, ast->root->node_handler(ast, ast->root));
    print_ast(ast);
    close_ast(&ast);         
}

void test_red_handler(void)
{
    char *envp[] = {
    "USER=username",
    "HOME=/home/username",
    "PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin",
    "SHELL=/bin/bash",
    "LANG=en_US.UTF-8",
    "PWD=/home/username",
    "LOGNAME=username",
    "TERM=xterm-256color",
    NULL
    };
    int saved_stdout = dup(STDOUT_FILENO);
    t_ast *ast = create_ast(envp, parse_path(envp));
    ast->root = create_red_node(ast, "/home/xifeng/42/test/pipe_x/test.out.txt", false, true);
    ast->root->left = create_cmd_node(ast, "echo line1");
    TEST_ASSERT_EQUAL_INT(0, ast->root->node_handler(ast, ast->root));
    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdout);
    int outfile = open("/home/xifeng/42/test/pipe_x/test.out.txt", 0);
    char *first = get_next_line(outfile);
    TEST_ASSERT_EQUAL_STRING("line1\n", first);
    free(first);
    close(outfile);
    print_ast(ast);
    close_ast(&ast);
    ast = create_ast(envp, parse_path(envp));
    ast->root = create_red_node(ast, "/home/xifeng/42/test/pipe_x/test.out.txt", false, false);
    ast->root->left = create_cmd_node(ast, "echo line2");
    saved_stdout = dup(STDOUT_FILENO);
    TEST_ASSERT_EQUAL_INT(0, ast->root->node_handler(ast, ast->root));
    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdout);
    outfile = open("/home/xifeng/42/test/pipe_x/test.out.txt", 0);
    first = get_next_line(outfile);
    free(first);
    first = get_next_line(outfile);
    TEST_ASSERT_EQUAL_STRING("line2\n", first);
    free(first);
    close(outfile);
    print_ast(ast);
    close_ast(&ast);
    ast = create_ast(envp, parse_path(envp));
    ast->root = create_red_node(ast, "/home/xifeng/42/test/pipe_x/test.in.txt", true, true);
    ast->root->right = create_cmd_node(ast, "cat");
    TEST_ASSERT_EQUAL_INT(0, ast->root->node_handler(ast, ast->root));
    print_ast(ast);
    close_ast(&ast);
}

void test_pipe_handler(void)
{
    char *envp[] = {
    "USER=username",
    "HOME=/home/username",
    "PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin",
    "SHELL=/bin/bash",
    "LANG=en_US.UTF-8",
    "PWD=/home/username",
    "LOGNAME=username",
    "TERM=xterm-256color",
    NULL
    };
    t_ast *ast = create_ast(envp, parse_path(envp));
    ast->root = create_pipe_node(ast);
    ast->root->left = create_cmd_node(ast, "echo line1");
    ast->root->right = create_red_node(ast, "/home/xifeng/42/test/pipe_x/test.out.txt", false, true);
    ast->root->right->left = create_cmd_node(ast, "cat");
    TEST_ASSERT_EQUAL_INT(0, ast->root->node_handler(ast, ast->root));
    print_ast(ast);
    close_ast(&ast);
    int fd = open("/home/xifeng/42/test/pipe_x/test.out.txt", 0);
    char *first = get_next_line(fd);
    TEST_ASSERT_EQUAL_STRING("line1\n", first);
    free(first);
    close(fd);
}

void test_here_doc(void)
{
    char *envp[] = {
    "USER=username",
    "HOME=/home/username",
    "PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin",
    "SHELL=/bin/bash",
    "LANG=en_US.UTF-8",
    "PWD=/home/username",
    "LOGNAME=username",
    "TERM=xterm-256color",
    NULL
    };
    t_ast *ast = create_ast(envp, parse_path(envp));
    char *argv[] = {"eof", "cmd1", "cmd2", "outfile"};
    build_ast(ast, 4, argv, false);
    print_ast(ast);
    close_ast(&ast);
    ast = create_ast(envp, parse_path(envp));
    char *argv2[] = {"eof", "cat", "cat", "/home/xifeng/42/test/pipe_x/test.out.txt"};
    build_ast(ast, 4, argv2, false);
    ast->root->node_handler(ast, ast->root);
    print_ast(ast);
    close_ast(&ast);
}

void debug()
{
    char *envp[] = {
    "USER=username",
    "HOME=/home/username",
    "PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin",
    "SHELL=/bin/bash",
    "LANG=en_US.UTF-8",
    "PWD=/home/username",
    "LOGNAME=username",
    "TERM=xterm-256color",
    NULL
    };
    char *argv[] = {"pipex", "here_doc", "eof", "cat", "cat", "/home/xifeng/42/test/pipe_x/test.out.txt"};
    pipe_x(6, argv, envp, true);
}

// Main function to run the tests
int	main(void)
{
	UNITY_BEGIN();
	//RUN_TEST(test_create_ast);
    //RUN_TEST(test_create_pipe_node);
    //RUN_TEST(test_create_cmd_node);
    //RUN_TEST(test_create_red_node);
    //RUN_TEST(test_create_multi_nodes_ast);
    //RUN_TEST(test_create_tree);
    //RUN_TEST(test_cmd_handler);
    //RUN_TEST(test_red_handler);
    //RUN_TEST(test_pipe_handler);
    //RUN_TEST(test_here_doc);
    RUN_TEST(debug);
	return (UNITY_END());
}