/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_tokenizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:07:34 by jaacosta          #+#    #+#             */
/*   Updated: 2025/06/01 20:05:18 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*tokenizer(char *input)
{
	t_token	*tokens;
	int		i;

	tokens = NULL;
	i = 0;
	while (input[i])
	{
		if (ft_isspace(input[i])) // TD
		{
			i++;
			continue ;
		}
		if (is_operator(input[i])) // TD check op: <<, >>, &&
			tokens = add_operator_token(input, &i, &tokens); // TD
		else if (input[i] == '\'' || input[i] == '\"')
			tokens = add_quoted_token(input, &i, &tokens); // TD
		else
			tokens = add_word_token(input, &i, &tokens); // TD
	}
	return (tokens);
}
// rl_replace_line -> util para autocompletado
// add_history -> util para guardar el histoial de comandos ejecutados/pasados
// getcwd obtiene el directorio del trabajo actaul (pwd)
// chdir cambia al directorio de trabajo (int chdir(const char *path); path: Ruta del nuevo directorio.)
// unlink elimmina un archivo del sistema de archivos (para eliminar)
// execve para ejecutar comandos int execve(const char *pathname,char *const argv[], char *const envp[]);
// opendir abre directorios DIR *opendir(const char *name);
