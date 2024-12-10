/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:20:12 by Xifeng            #+#    #+#             */
/*   Updated: 2024/12/10 14:13:40 by Xifeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe_x.h"

// pipe_x.h: difinition of AST.
// ast: implementation of AST.
// core: main logic of the program:
//   -  program entry
//   -  build the tree, and execute the tree.
int	main(int argc, char **argv, char **envp)
{
	return (pipe_x(argc, argv, envp, false));
}
