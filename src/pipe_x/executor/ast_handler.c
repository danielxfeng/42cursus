/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:56:09 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/10 10:05:12 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipe_x.h"
#include "../libft/libft.h"
#include <sys/wait.h>

static void parse_full_cmd(t_ast *ast, char **args)
{    
}

// The handler for `cmd` nodes in the AST.
// This handler implements an `In-order Traversal`:
// 1. Execute the left child node (if any).
// 2. Execute the command in the current node:
//    2.1 Parse the command to get the executable path.
//    2.2 Create a new sub-process to execute the command.
//    2.3 In the parent process, wait for the sub-process to complete.
// 3. Execute the right child node (if any).
//
// Notes:
// - `execve` replaces the current process context with the new executable.
//   When `execve` is called, the sub-process will not return to this function.
// - This behavior is different from `pipe_handler`.
// - Because of the above reason, we have to start a new process for running 
//   this `cmd`, otherwise we can do NOTHING after `execve`, but we have to
//   deal with the right child.
// - also check the explain in `pipe_handler`.
int cmd_handler(t_ast *ast, t_ast_node *ast_node)
{
    t_cmd_prop *prop;
    int status;

    prop = (t_cmd_prop *)ast_node->prop;
    if (ast_node->left)
        ast_node->left->node_handler(ast, ast_node->left);
    parse_full_cmd(ast, prop->args);
    if ((prop->pid = fork()) < 0)
        exit_prog(&ast, "fork()", FORK_ERR, EXIT_FAILURE);
    if (prop->pid == 0)
        execve(prop->args[0], prop->args, ast->envp);
    waitpid(prop->pid, &status, 0);
    if (ast_node->right)
        return (ast_node->right->node_handler(ast, ast_node->right));
    if (WIFEXITED(status))
        return (WEXITSTATUS(status));
    return (EXIT_FAILURE);
}

// Build the AST tree.
// We trvesal the arguments from right to left.
// 1 The last 2 are the right node of root, which are 
//   a `RED` node with the last `CMD`.
// 2 We iterate the rest nodes until 2 nodes left, we create
//   a `PIPE` node at `curr`'s left, and a `CMD` node as its right child.
// 3 The first 2 are the leftmost nodes of the tree, which are
//   a `RED` node with the 1-st `CMD`.
// For example:
// ./pipex infile cmd1 cmd2 cmd3 outfile
// == < infile cmd1 | cmd2 | cmd3 > outfile
//               PIPE
//              /    \
//         PIPE     RED(> outfile)
//        /    \              /
// RED(<infile) CMD(cmd2)  CMD(cmd3)
//       /
//   CMD(cmd1)
void build_ast(t_ast *ast, int len, char **args, bool is_single)
{
    int i;
    t_ast_node *curr;
    
    ast->root = create_pipe_node(ast);
    ast->root->right = create_red_node(ast, args[len - 1], false, is_single);
    ast->root->right->left = create_cmd_node(ast, args[len - 2]);
    i = len - 3;
    curr = ast->root;
    while (i > 1)
    {
        curr->left = create_pipe_node(ast);
        curr = curr->left;
        curr->right = create_cmd_node(ast, args[i]);
        --i;
    }
    curr->left = create_red_node(ast, args[0], true, is_single);
    curr->left->right = create_cmd_node(ast, args[1]);
}
