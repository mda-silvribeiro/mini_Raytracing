/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 09:57:51 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 08:08:16 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	pos;
	int	result;

	result = 0;
	pos = 1;
	while ((*str > 8 && *str < 14) || *str == 32)
		++str;
	if (*str == 45 || *str == 43)
		if (*(str++) == 45)
			pos *= -1;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			result *= 10;
			result += (*(str++) - '0');
		}
		else
			return (result * pos);
	}
	return (result * pos);
}
