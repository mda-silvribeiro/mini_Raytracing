/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 12:47:23 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 09:00:20 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	if (!n)
		return (0);
	while ((s1[count] == s2[count] && s1[count] && s2[count] && n > count + 1))
		count++;
	return (((unsigned char *)s1)[count] - ((unsigned char *)s2)[count]);
}
