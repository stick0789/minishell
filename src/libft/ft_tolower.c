/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 08:25:40 by jaacosta          #+#    #+#             */
/*   Updated: 2024/09/18 06:32:03 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_tolower(int c)
{
	unsigned char	local_c;

	local_c = (unsigned char)c;
	while (local_c >= 'A' && local_c <= 'Z')
		return (c += 32);
	return (c);
}
/*
int main(void)
{
	char str[] = "HOLA MUNDO";
	int i = 0;

	while (str[i])
	{
		printf("%c", ft_tolower(str[i]));
		i++;
	}
}*/	
