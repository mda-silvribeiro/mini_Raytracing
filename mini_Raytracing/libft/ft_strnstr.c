/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:56:01 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 09:00:42 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	count;
	size_t	aux;

	count = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[count] != '\0')
	{
		aux = 0;
		while (haystack[count + aux] == needle[aux] && (count + aux) < len)
		{
			if (haystack[count + aux] == '\0' && needle[aux] == '\0')
				return ((char *)&haystack[count]);
			aux++;
		}
		if (needle[aux] == '\0')
			return ((char *)haystack + count);
		count++;
	}
	return (0);
}
