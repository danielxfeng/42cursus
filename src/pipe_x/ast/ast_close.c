/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_close.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:58:36 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/08 15:12:34 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipe_x.h"
#include "../libft/libft.h"
#include <stdlib.h>

// Helper function to free a pipe node.
void close_pipe_node(t_ast_node *node)
{
    t_pipe_prop *prop;

    prop = (t_pipe_prop *) node->prop;
    if (prop)
    {
        if (prop->fds[0] >= 0)
            close(prop->fds[0]);
        if (prop->fds[1] >= 0)
            close(prop->fds[1]);
        free(prop);
        node->prop = NULL;        
    }
}

// Helper function to free a cmd node.
void close_cmd_node(t_ast_node *node)
{
    t_cmd_prop *prop;
    int i;

    prop = (t_cmd_prop *) node->prop;
    if (prop)
    {
        if (prop->args)
        {
            i = 0;
            while (prop->args[i])
            {
                free(prop->args[i]);
                prop->args[i++] = NULL;
            }
            free(prop->args);
            prop->args = NULL;
        }
        free(prop);
        node->prop = NULL;       
    }
}

// Helper function to free a red node.
void close_red_node(t_ast_node *node)
{
    t_red_prop *prop;
    
    prop = (t_red_prop *)node->prop;
    if (prop)
    {
        if (prop->fd >= 0)
            close(prop->fd);
        free(prop);
        node->prop = NULL;
    }
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
        if (node->node_closer)
            node->node_closer(node);
        free(node);
    }
}

// Deconstructor of the AST tree.
void close_ast(t_ast **ast)
{
    int i = 0;

    if (ast && *ast)
    {
        if ((*ast)->root)
            free_ast_node((*ast)->root);
        if ((*ast)->envp)
        {
            while(((*ast)->envp)[i])
            {
                free(((*ast)->envp)[i]);
                ((*ast)->envp)[i++] = NULL;
            }
            free((*ast)->envp);
            (*ast)->envp = NULL;
        }
        free(*ast);
        *ast = NULL;
    }
}