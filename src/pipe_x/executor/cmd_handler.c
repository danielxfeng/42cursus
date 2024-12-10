/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:08:19 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/10 14:08:30 by Xifeng           ###   ########.fr       */
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
