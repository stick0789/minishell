/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 20:07:29 by jaacosta          #+#    #+#             */
/*   Updated: 2025/07/16 20:07:33 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../include/minishell.h"

/**
 * Executes an 'OR' logical operation in the Abstract Syntax Tree (AST).
 * It executes the left-hand side command first. If that 
 	command fails (returns a non-zero status),
 * it then executes the right-hand side command.
 * Returns the status of the last executed command.
 */
int	execute_or(t_ast *node, t_myenv *myenv, t_minishell *minishell)
{
	int	status;

	status = 0;
	status = execute_ast(node->left, myenv, minishell, status);
	if (status != 0)
		status = execute_ast(node->right, myenv, minishell, status);
	return (status);
}
