/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:56:13 by jaacosta          #+#    #+#             */
/*   Updated: 2025/07/03 14:26:42 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef REDIRECTIONS_H
# define REDIRECTIONS_H

// -- redirections.h -- //
int		ft_open(char *file, int mode);

// -- here doc's -- //
int		ft_here_doc(char *delimiter);
void	ft_here_doc_child(char *delimiter, int *p_fd);

#endif
