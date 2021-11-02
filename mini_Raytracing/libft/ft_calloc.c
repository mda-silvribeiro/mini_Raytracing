/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 10:37:41 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/19 11:53:52 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	c;
	size_t	aux;

	c = (size * count);
	aux = 0;
	ptr = (void *)malloc(c);
	if (ptr)
	{
		while (aux < c)
		{
			((unsigned char *)ptr)[aux] = 0;
			aux++;
		}
		return (ptr);
	}
	else
		return (0);
}
