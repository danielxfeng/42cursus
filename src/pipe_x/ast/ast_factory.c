/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_factory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:41:30 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/08 15:10:31 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipe_x.h"
#include "../libft/libft.h"

// Constructor of a AST node for PIPE.
t_ast_node *create_pipe_node(t_ast *ast)
{
    t_ast_node *node;
    t_pipe_prop *prop;

    node = ft_calloc(1, sizeof(t_ast_node));
    if (!node)
        exit_prog(&ast, "create_pipe_node()", MALLOC_ERR, EXIT_FAILURE);
    prop = ft_calloc(1, sizeof(t_pipe_prop));
    if (!(prop))
    {
        free(node);
        exit_prog(&ast, "create_pipe_node()", MALLOC_ERR, EXIT_FAILURE);
    }
    prop->fds[0] = -1;
    prop->fds[1] = -1;
    node->type = PIPE;
    node->prop = prop;
    node->node_handler = pipe_handler;
    node->node_closer = close_pipe_node;
    return (node);
}

// Constructor of a AST node for CMD.
t_ast_node *create_cmd_node(t_ast *ast, char *argv)
{
    t_ast_node *node;
    t_cmd_prop *prop;

    node = ft_calloc(1, sizeof(t_ast_node));
    if (!node)
        exit_prog(&ast, "create_cmd_node()", MALLOC_ERR, EXIT_FAILURE);
    prop = ft_calloc(1, sizeof(t_cmd_prop));
    if (!prop)
    {
        free(node);
        exit_prog(&ast, "create_cmd_node()", MALLOC_ERR, EXIT_FAILURE);
    }
    prop->args = ft_split(argv, ' ');
    if (!(prop->args))
    {
        free(node);
        free(prop);
        exit_prog(&ast, "ft_split()", MALLOC_ERR, EXIT_FAILURE);
    }
    prop->cmd = prop->args[0];
    node->type = CMD;
    node->prop = prop;
    node->node_handler = cmd_handler;
    node->node_closer = close_cmd_node;
    return (node);
}

// Constructor of a AST node for REDIRECT.
t_ast_node *create_red_node(t_ast *ast, char *file_name, bool is_in, bool is_single)
{
    t_ast_node *node;
    t_red_prop *prop;
    
    node = ft_calloc(1, sizeof(t_ast_node));
    if (!node)
        exit_prog(&ast, "create_red_node()", MALLOC_ERR, EXIT_FAILURE);
    prop = ft_calloc(1, sizeof(t_red_prop));
    if (!prop)
    {
        free(node);
        exit_prog(&ast, "create_red_node()", MALLOC_ERR, EXIT_FAILURE);
    }
    prop->file_name = file_name;
    prop->is_in = is_in;
    prop->is_single = is_single;
    prop->fd = -1;
    node->type = RED;
    node->prop = prop;
    node->node_handler = red_handler;
    node->node_closer = close_red_node;
    return (node);
}

// Constructor of AST tree.
t_ast *create_ast(char **envp)
{
    t_ast *ast;

    ast = ft_calloc(1, sizeof(t_ast));
    if (!ast)
        exit_prog(&ast, "create_ast()", MALLOC_ERR, EXIT_FAILURE);;
    ast->root = NULL;
    ast->envp = envp;
    return (ast);
}
