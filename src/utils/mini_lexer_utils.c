/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lexer_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 19:12:24 by jaacosta          #+#    #+#             */
/*   Updated: 2025/06/06 18:57:32 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	add_token(t_token **tokens, t_tkn_type type, char *value, t_mini *mini)
{
	t_token		*new;

	if ((type == PIPE || type == AND || type == OR) && (*tokens)
		&& (ft_isoperator((*tokens)->type)))
	{
		ft_putstr_fd("minishell: syntax error near unexpected token\n", 2);
		exit_shell(mini, 258);//TD
	}
	new = malloc(sizeof(t_token));
	if (!new)
	{
		perror("malloc");
		exit_shell(mini, 1);
	}
	new->type = type;
	if (value)
		new->value = ft_strdup(value);
	else
		new->value = operator_to_str(type);//TD
	new->next = NULL;
	if (!*tokens)
	{
		*tokens = new;
		mini->last_token = new;
	}
	else
	{
		mini->last_token->next = new;
		mini->last_token = new;
	}
}

int	get_operator_len(char *input, int i, char *op)
{
	op[0] = input[i];
	op[1] = '\0';
	if (input[i + 1] && ((input[i] == '>' && input[i + 1] == '>')
			|| (input[i] == '<' && input[i + 1] == '<')
			|| (input[i] == '|' && input[i + 1] == '|')
			|| (input[i] == '&' && input[i + 1] == '&')))
	{
		op[1] = input[i + 1];
		op[2] = '\0';
		i = 2;
	}
	else
		i = 1;
	return (i);
}

int	handle_operator(char *input, int i, t_token **tokens, t_mini *mini)
{
	char	op[3];
	int		len;

	len = get_operator_len(input, i, op);
	if (ft_strncmp(op, '|', 1) == 0)
		add_token(tokens, PIPE, op, mini);
	else if (ft_strncmp(op, "<", 1) == 0)
		add_token(tokens, REDIR_IN, op, mini);
	else if (ft_strncmp(op, ">", 1) == 0)
		add_token(tokens, REDIR_OUT, op, mini);
	else if (ft_strncmp(op, "<<", 2) == 0)
		add_token(tokens, HEREDOC, op, mini);
	else if (ft_strncmp(op, ">>", 2) == 0)
		add_token(tokens, APPEND, op, mini);
	else if (ft_strncmp(op, "&&", 2) == 0)
		add_token(tokens, AND, op, mini);
	else if (ft_strncmp(op, "||", 2) == 0)
		add_token(tokens, OR, op, mini);
	return (i);
}

int	handle_quotes(char *input, int i, t_token **tokens, t_mini *mini)
{
	char	*value;
	char	quote;
	int		start;

	quote = input[i];
	start = ++i;
	while (input[i] && input[i] != quote)
	{
		if (input[i] == '\\' && input[i] == '\"')
			i++;
		i++;
	}
	value = ft_substr(input, start, i - start);
	add_token(tokens, WORD, value, mini);
	free(value);
	if (input[i])
		return (i + 1);
	else
		return (i);
}

int	handle_word(char *input, int i, t_token **tokens, t_mini *mini)
{
	char	*value;
	int		start;

	start = i;
	while (input[i] && !ft_isspace(input[i]) && !ft_isoperator(input[i]))
	{
		if (input[i] == '\\')
			i++;
		i++;
	}
	value = ft_substr(input, start, i - start);
	add_token(tokens, WORD, value, mini);
	free(value);
	return (i);
}
