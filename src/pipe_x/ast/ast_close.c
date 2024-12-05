/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_close.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:58:36 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/03 22:05:06 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipe_x.h"
#include <stdlib.h>

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
