/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_x.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:24:37 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/03 21:37:09 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_X_H
# define PIPE_X_H

typedef enum a_node_side
{
    LEFT,
    RIGHT
} t_node_side;

typedef enum a_node_type
{
    PIPE,
    CMD
} t_node_type;

typedef struct s_ast_node
{
    t_node_type type;
    int cmd_idx;
    int args_idx;
    int args_len;
    t_ast_node *left;
    t_ast_node *right;
} t_ast_node;

typedef struct s_ast
{
    t_ast_node *root;
} t_ast;

t_ast_node *create_ast_node(t_node_type type, int cmd_idx, int args_idx, int args_len);
t_ast *create_ast();
void close_ast(t_ast **ast);

#endif