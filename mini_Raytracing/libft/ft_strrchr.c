/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:07:56 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 09:01:09 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	count;
	int	result;

	count = 0;
	result = -1;
	while ((size_t)count <= ft_strlen(s))
	{
		if (s[count] == (char)c)
			result = count;
		count++;
	}
	if (result >= 0)
		return ((char *)s + result);
	return (NULL);
}
