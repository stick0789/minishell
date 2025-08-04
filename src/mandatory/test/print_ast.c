/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 05:24:25 by jaacosta          #+#    #+#             */
/*   Updated: 2025/07/22 05:24:28 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../include/minishell.h"

void	print_ast(t_ast *node, int depth)
{
	int	i;

	i = 0;
	while (i++ < depth)
		printf("  ");
	if (!node)
	{
		printf("(null)\n");
		return ;
	}
	if (node->type == NODE_COMMAND)
	{
		printf("COMMAND:\n");
		print_command(node->cmd);
	}
	else if (node->type == NODE_PIPE)
		printf("PIPE\n");
	else if (node->type == NODE_AND)
		printf("AND\n");
	else if (node->type == NODE_OR)
		printf("OR\n");
	else if (node->type == NODE_SUBSHELL)
		printf("SUBSHELL\n");
	print_ast(node->left, depth + 1);
	print_ast(node->right, depth + 1);
}
