/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_x.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:24:37 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/08 15:07:48 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_X_H
# define PIPE_X_H

#include <stdbool.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

# define MALLOC_ERR ": malloc() failed"
# define FORK_ERR "fork() error"
# define PIPE_ERR "pipe() creation failed"
# define PERMISSION_ERR ": Permission denied"
# define FILE_ERR ": No such file or directory"
# define DIRECTORY_ERR ": Is a directory"
# define DUP_ERR "dup2() error"
# define CMD_ERR ": command not found"

typedef struct s_ast_node t_ast_node;

// Enum: type of AST nodes.
typedef enum a_node_type
{
    PIPE,
    RED,
    CMD
} t_node_type;

// The AST tree.
// `root` the root node of AST tree.
// `envp` the string array of `env`.
typedef struct s_ast
{
    t_ast_node *root;
    char **envp;
} t_ast;

// Represents a node of AST.
// `prop`: the specific properties depends on `t_node_type`.
// `node_handler`: the pointer to handler function.
// `node_closer`: the pointer to closer function.
// `left` `right`: left/right node.
typedef struct s_ast_node
{
    t_node_type type;
    void *prop;
    void (*node_handler)(t_ast *t_ast, t_ast_node *t_ast_node);
    void (*node_closer)(t_ast_node *t_ast_node);
    t_ast_node *left;
    t_ast_node *right;
} t_ast_node;

// Represents properties of CMD.
// `args` the cmd and argumens.
typedef struct s_cmd_prop
{
    char *cmd;
    char **args;
} t_cmd_prop;

// Represents properties of RED.
// `file_name`: the filename of `RED`.
// `fd`: the file descriptor of a file.
// `is_in`: `true` for `<` or `<<`.
// `is_single`: `true` for `<` or '>'.
typedef struct s_red_prop
{
    char *file_name;
    int fd;
    bool is_in;
    bool is_single;
} t_red_prop;

// Represents properties of PIPE.
// `fds`: file descriptor of pipe.
// `pid`: pid of sub-process.
typedef struct s_pipe_prop
{
    int fds[2];
    pid_t pid; 
} t_pipe_prop;

// AST

// The constructors of AST.

t_ast *create_ast(char **envp);
t_ast_node *create_pipe_node(t_ast *ast);
t_ast_node *create_cmd_node(t_ast *ast, char *argv);
t_ast_node *create_red_node(t_ast *ast, char *file_name, bool is_in, bool is_single);

// The deconstructors of AST.

void close_ast(t_ast **ast);
void close_pipe_node(t_ast_node *node);
void close_cmd_node(t_ast_node *node);
void close_red_node(t_ast_node *node);

// Other methods of AST.

void print_ast(t_ast *ast);

// The handlers.

void pipe_handler(t_ast *t_ast, t_ast_node *t_ast_node);
void cmd_handler(t_ast *t_ast, t_ast_node *t_ast_node);
void red_handler(t_ast *t_ast, t_ast_node *t_ast_node);

void exit_prog(t_ast **ast, char *context, char *msg, int code);

#endif