/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:06:09 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 13:13:50 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1];
	int			ret;
	int			i;

	if (!line || fd < 0 || BUFFER_SIZE < 0)
		return (-1);
	i = ft_index(buf, '\n');
	*line = ft_strnjoin_gnl(NULL, buf, i);
	ft_memmove(buf, &buf[i + 1], BUFFER_SIZE - i);
	if (i != -1)
		return (1);
	ret = read(fd, buf, BUFFER_SIZE);
	while (ret != -1)
	{
		buf[ret] = '\0';
		if (ret == 0)
			return (0);
		i = ft_index(buf, '\n');
		*line = ft_strnjoin_gnl(*line, buf, i);
		ft_memmove(buf, &buf[i + 1], BUFFER_SIZE - i);
		if (i != -1)
			return (1);
		ret = read(fd, buf, BUFFER_SIZE);
	}
	return (ret);
}
