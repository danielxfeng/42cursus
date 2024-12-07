/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:45:09 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/07 20:28:47 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe_x.h"
#include "ft_printf/ft_printf.h"

static void print_pipe_helper(t_ast_node *node)
{
    t_pipe_prop *prop;

    prop = (t_pipe_prop *)node->prop;
    ft_printf("PIPE, fd0: %d, fd1: %d, pid: %d\n", 
    prop->fds[0], prop->fds[1], prop->pid);
}

static void print_cmd_helper(t_ast_node *node)
{
    t_cmd_prop *prop;
    int i;

    prop = (t_cmd_prop *)node->prop;
    ft_printf("CMD, cmd: %s, args: ", prop->cmd);
    i = 0;
    while (prop->args[i])
        ft_printf("%s, ", prop->args[i++]);
    ft_printf("\n");
}

static void print_red_helper(t_ast_node *node)
{
    t_red_prop *prop;

    prop = (t_red_prop *)node->prop;
    ft_printf("RED, file: %s, fd: %d, is_in: %d, is_single: %d\n", 
    prop->file_name, prop->fd, prop->is_in, prop->is_single);
}

static void print_ast_helper(t_ast_node *node, int layer)
{
    int i;

    i = 0;
    while (i++ < layer)
        ft_printf("  ");
    if (!node)
    {
        ft_printf("NULL\n");
        return ;
    }
    print_ast_helper(node->left, layer + 1);
    if (node->type == PIPE)
        print_pipe_helper(node);
    else if (node->type == CMD)
        print_cmd_helper(node);
    else if (node->type == RED)
        print_red_helper(node);
    print_ast_helper(node->right, layer + 1);
}

// Print the AST tree by In-order Traversal.
void print_ast(t_ast *ast)
{
    ft_printf("-----------------------AST Tree-----------------------\n");
    if (!ast || !(ast->root))
    {
        ft_printf("NULL\n");
        return ;
    }
    print_ast_helper(ast->root, 0);
    ft_printf("------------------------------------------------------\n");
}
