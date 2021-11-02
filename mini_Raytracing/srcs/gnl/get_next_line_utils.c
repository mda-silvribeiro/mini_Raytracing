/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:06:28 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 13:06:40 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_index(char const *s, char c)
{
	long	i;

	i = -1;
	while (s[++i])
		if (s[i] == c)
			return (i);
	return (-1);
}

unsigned long	ft_strlen(const char *s)
{
	unsigned long	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memmove(void *dest, const void *src, unsigned long n)
{
	unsigned long		i;
	unsigned char		*cdest;
	const unsigned char	*csrc;

	if ((!dest && !src) || dest == src)
		return (dest);
	cdest = dest;
	csrc = src;
	i = 0;
	if (dest <= src)
		while (i++ < n)
			cdest[i - 1] = csrc[i - 1];
	else
		while (n-- > 0)
			cdest[n] = csrc[n];
	return (dest);
}

char	*ft_strnjoin_gnl(char *s1, char const *s2, long n)
{
	long			j;
	char			*new;
	unsigned long	i;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (n == -1 || n > j)
		n = j;
	new = (char *)malloc(sizeof(char) * (i + n + 1));
	if (new == NULL)
		return (NULL);
	if (s1)
	{
		i = -1;
		while (s1[++i] != '\0')
			new[i] = s1[i];
		free(s1);
	}
	j = -1;
	while (j < n && s2[++j] != '\0')
		new[i + j] = s2[j];
	new[i + j] = '\0';
	return (new);
}
