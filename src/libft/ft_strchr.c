/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:40:32 by jaacosta          #+#    #+#             */
/*   Updated: 2024/09/18 06:39:35 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const unsigned char	*local_s;
	size_t				i;

	i = 0;
	local_s = (const unsigned char *)s;
	while (local_s[i])
	{
		if (local_s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
/*
int	main(void)
{
    char str[] = "hola mundo new world";
    char c = 'u';

    printf("%s", ft_strchr(str, c));
    return 0;
}*/
