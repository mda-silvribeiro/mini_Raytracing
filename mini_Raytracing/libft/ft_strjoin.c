/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:11:37 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 08:57:15 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		aux;
	int		count;

	ptr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s1 || !s2 || !ptr)
		return (0);
	aux = 0;
	while (s1[aux] != '\0')
	{
		ptr[aux] = s1[aux];
		aux++;
	}
	count = 0;
	while (s2[count] != '\0')
		ptr[aux++] = s2[count++];
	ptr[aux] = '\0';
	return (ptr);
}
