/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:37:49 by jaacosta          #+#    #+#             */
/*   Updated: 2025/05/26 18:39:53 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(void)
{
	char *input;

	while (1)
	{
		input = readline("minishell> "); // Muestra el prompt
		if (!input)                      // Maneja Ctrl-D (EOF)
			break ;
		if (*input)             // Evita guardar líneas vacías
			add_history(input); // Añade al historial

		// Procesa el input (ej: tokenización)
		free(input); // Libera memoria
	}
	return (0);
}