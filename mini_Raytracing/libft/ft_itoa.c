/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:13:26 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 08:18:00 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_signal(int number, char *result)
{
	if (number == 0)
		result[0] = '0';
	else if (number < 0)
		result[0] = '-';
}

int	ft_aux(int n)
{
	if (n < 1)
		return (1);
	return (0);
}

long	ft_aux2(long count, int n)
{
	if (count < 0)
		return (-(long)n);
	return ((long)n);
}

long	ft_aux3(int n)
{
	if (n < 0)
		return (-(long)n);
	return ((long)n);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	long	aux;
	long	count;

	count = ft_aux(n);
	aux = ft_aux2(count, n);
	while (aux)
	{
		aux /= 10;
		count++;
	}
	ptr = (char *)malloc(sizeof(char) * (count + 1));
	if (!ptr)
		return (0);
	ptr[count] = '\0';
	aux = ft_aux3(n);
	while (count >= 0)
	{
		ptr[count - 1] = aux % 10 + '0';
		aux /= 10;
		count--;
	}
	ft_signal(n, ptr);
	return (ptr);
}
