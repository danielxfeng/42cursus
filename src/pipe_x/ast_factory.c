/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:33:10 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/03 21:35:58 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe_x.h"
#include "libft/libft.h"
#include <stdlib.h>

// Constructor of a AST node.
t_ast_node *create_ast_node(t_node_type type, int cmd_idx, int args_idx, int args_len)
{
    t_ast_node *node;

    node = ft_calloc(1, sizeof(t_ast_node));
    if (!node)
        return (NULL);
    node->type = type;
    if (node->type == CMD)
    {
        node->cmd_idx = cmd_idx;
        node->args_idx = args_idx;
        node->args_len = args_len;
    }
    node->left = NULL;
    node->right = NULL;
    return (node);
}

// Constructor of AST tree.
t_ast *create_ast()
{
    t_ast *ast;

    ast = ft_calloc(1, sizeof(t_ast));
    if (!ast)
        return (NULL);
    ast->root = NULL;
    return (ast);
}

// Helper function to free a AST node.
static void free_ast_node (t_ast_node *node)
{
    if (node)
    {
        if (node->left)
        {
            free_ast_node(node->left);
            node->left = NULL;
        }
        if (node->right)
        {
            free_ast_node(node->right);
            node->right = NULL;
        }
        free(node);
    }
}

// Deconstructor of the AST tree.
void close_ast(t_ast **ast)
{
    if (ast && *ast)
    {
        free_ast_node((*ast)->root);
        free(*ast);
        *ast = NULL;
    }
}
