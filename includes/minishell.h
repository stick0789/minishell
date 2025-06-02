/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:30:29 by jaacosta          #+#    #+#             */
/*   Updated: 2025/06/02 20:37:33 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>
# include <limits.h>
# include <errno.h>
# include <signal.h>
# include <readline/history.h>
# include <readline/readline.h>

typedef enum e_token_type
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	HEREDOC,
	APPEND,
	AND,
	OR,
	UNKNOWN
}				t_tkn_type;

typedef struct s_token
{
	t_tkn_type		type;
	char			*value;
	struct s_token	*next;
}					t_token;

typedef struct s_env
{
	char			*value;// Valor de la variable (ej: "PATH=/usr/bin")
	struct s_env	*next;
}					t_env;

typedef struct s_cmd
{
	char			**args;// Comando y argumentos (ej: ["ls", "-la"])
	int				in_fd;
	int				out_fd;
	int				is_pipe;// 1 si hay pipe después
	struct s_cmd	*next;// Siguiente comando en la cadena
	pid_t			pid;
}				t_cmd;

typedef struct s_mini
{
	t_token		*start;
	t_token		*last_token;
	t_env		*env;
	t_env		*secret_env;// Variables temporales/no exportadas
	int			in;// Descriptor de entrada actual (STDIN_FILENO)
	int			out;// Descriptor de salida actual (STDOUT_FILENO)
	int			fdin;
	int			fdout;
	int			pipein;
	int			pipeout;
	int			pid;
	int			charge;// Flag para controlar procesos en background
	int			parent;// PID del proceso padre (shell principal)
	int			last;
	int			ret;// Código de retorno temporal
	int			exit;// Flag para terminar el shell
	int			no_exec// Flag para evitar ejecución (ej: error de sintaxis)
}				t_mini;

typedef struct s_signal
{
	int		sigint;
	int		sigquit;
	int		exit_status;
	pid_t	pid;
}				t_signal;

typedef struct s_expansion
{
	char			*new_arg;
	int		i;
	int		j;
}				t_expansion;


#endif
