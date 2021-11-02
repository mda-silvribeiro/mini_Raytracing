/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:10:47 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 08:29:03 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*result;

	if (!dst && !src)
		return (0);
	result = dst;
	if (src < dst)
	{
		src += len;
		dst += len;
		while (len--)
			(*(char*)--dst) = (*(char*)--src);
	}
	else
		while (len--)
			(*(char *)dst++) = (*(char *)src++);
	return (result);
}
