/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:37:36 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 08:58:20 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;

	if (!dst && !src)
		return (0);
	count = 0;
	while (src[count] && count + 1 < dstsize)
	{
		dst[count] = src[count];
		++count;
	}
	if (dstsize != 0)
		dst[count] = 0;
	while (src[count])
		++count;
	return (count);
}
