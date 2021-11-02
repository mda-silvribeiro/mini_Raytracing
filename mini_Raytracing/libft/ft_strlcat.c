/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:14:02 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 08:57:47 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	count_src;
	size_t	count_dest;
	size_t	count;
	size_t	aux;

	aux = 0;
	count_src = ft_strlen(src);
	count_dest = ft_strlen(dst);
	if (dstsize == 0)
		return (count_src);
	else if (dstsize < count_dest)
		return (count_src + dstsize);
	count = count_dest;
	while (src[aux] && count + 1 < dstsize)
	{
		dst[count] = src[aux];
		aux++;
		count++;
	}
	dst[count] = '\0';
	return (count_src + count_dest);
}
