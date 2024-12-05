/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_x.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:24:37 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/03 22:05:27 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_X_H
# define PIPE_X_H

typedef enum a_node_type
{
    PIPE,
    REDIRECT_IN,
    REDIRECT_OUT,
    CMD
} t_node_type;

typedef struct s_ast_node
{
    t_node_type type;
    int cmd_idx;
    int args_idx;
    int args_len;
    int file_idx;
    t_ast_node *left;
    t_ast_node *right;
} t_ast_node;

typedef struct s_ast
{
    t_ast_node *root;
} t_ast;

t_ast_node *create_pipe_node();
t_ast_node *create_cmd_node(int cmd_idx, int args_idx, int args_len);
t_ast_node *create_red_node(t_node_type type, int file_idx);
t_ast *create_ast();
t_ast *create_ast();
void close_ast(t_ast **ast);
void print_ast(t_ast *ast);

#endif