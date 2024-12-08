/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:56:09 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/08 18:00:47 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipe_x.h"

void pipe_handler(t_ast *ast, t_ast_node *ast_node)
{
    
}

void cmd_handler(t_ast *ast, t_ast_node *ast_node)
{
    
}

void red_handler(t_ast *ast, t_ast_node *ast_node)
{
    
}

// Build the AST tree.
// We trvesal the arguments from right to left.
// 1 The last 2 are the right node of root, which are 
//   a `RED` node with the last `CMD`.
// 2 We iterate the rest nodes until 2 nodes left, we create
//   a `PIPE` node at `curr`'s left, and a `CMD` node as its right child.
// 3 The first 2 are the leftmost nodes of the tree, which are
//   a `RED` node with the 1-st `CMD`.
// For example:
// ./pipex infile cmd1 cmd2 cmd3 outfile
// == < infile cmd1 | cmd2 | cmd3 > outfile
//               PIPE
//              /    \
//         PIPE     RED(> outfile)
//        /    \              /
// RED(<infile) CMD(cmd2)  CMD(cmd3)
//       /
//   CMD(cmd1)
void build_ast(t_ast *ast, int len, char **args, bool is_single)
{
    int i;
    t_ast_node *curr;
    
    ast->root = create_pipe_node(ast);
    ast->root->right = create_red_node(ast, args[len - 1], false, is_single);
    ast->root->right->left = create_cmd_node(ast, args[len - 2]);
    i = len - 3;
    curr = ast->root;
    while (i > 1)
    {
        curr->left = create_pipe_node(ast);
        curr = curr->left;
        curr->right = create_cmd_node(ast, args[i]);
        --i;
    }
    curr->left = create_red_node(ast, args[0], true, is_single);
    curr->left->right = create_cmd_node(ast, args[1]);
}
