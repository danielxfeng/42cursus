/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_factory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:41:30 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/03 22:04:43 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipe_x.h"
#include "../libft/libft.h"
#include <stdlib.h>

// Constructor of a AST node for PIPE.
t_ast_node *create_pipe_node()
{
    t_ast_node *node;

    node = ft_calloc(1, sizeof(t_ast_node));
    if (!node)
        return (NULL);
    node->type = PIPE;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

// Constructor of a AST node for CMD.
t_ast_node *create_cmd_node(int cmd_idx, int args_idx, int args_len)
{
    t_ast_node *node;

    node = ft_calloc(1, sizeof(t_ast_node));
    if (!node)
        return (NULL);
    node->type = CMD;
    node->cmd_idx = cmd_idx;
    node->args_idx = args_idx;
    node->args_len = args_len;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

// Constructor of a AST node for REDIRECT.
t_ast_node *create_red_node(t_node_type type, int file_idx)
{
    t_ast_node *node;
    
    node = ft_calloc(1, sizeof(t_ast_node));
    if (!node)
        return (NULL);
    node->type = type;
    node->file_idx = file_idx;
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
