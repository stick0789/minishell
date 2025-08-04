/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:10:29 by jaacosta          #+#    #+#             */
/*   Updated: 2025/01/24 16:11:13 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_sqrt(int nb)
{
	int	low;
	int	high;
	int	mid;

	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (nb);
	low = 0;
	high = nb;
	mid = (low + high) / 2;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (mid * mid == nb)
			return (mid);
		else if (mid * mid < nb)
			low = mid + 1;
		else
			high = mid - 1;
	}
	if ((low * low - nb) < (nb - high * high))
		return (low);
	return (high);
}
