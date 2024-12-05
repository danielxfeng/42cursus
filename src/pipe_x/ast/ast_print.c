/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:04:05 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/03 22:05:11 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipe_x.h"
#include "../ft_printf/ft_printf.h"

// Print the AST tree.
void print_ast(t_ast *ast)
{
    ft_printf("------AST Tree------\n");
    if (ast || !(ast->root))
    {
        ft_printf("NULL\n");
        return ;
    }
}