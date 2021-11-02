/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 10:59:14 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 11:01:18 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_check_caracter(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_ignore_whitespaces(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ft_check_caracter(line[j]))
		j++;
	i = j;
	while (line[i])
	{
		if (ft_check_caracter(line[i]))
			line[i] = ' ';
		i++;
	}
	return (j);
}

char	*check_spaces_between_comma(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == ',')
		{
			j = i - 1;
			while (ft_check_caracter(line[j]))
				line[j--] = '.';
			j = i + 1;
			while (ft_check_caracter(line[j]))
				line[j++] = '0';
			if (line[j] == '-' && line[j - 1] != ',')
			{
				line[j] = '0';
				line[j - i + 1] = '-';
			}
		}
		i++;
	}
	return (line);
}

t_vector	parser_vector(char **split)
{
	t_vector	coor;

	coor.x = ft_strtod(split[0]);
	coor.y = ft_strtod(split[1]);
	coor.z = ft_strtod(split[2]);
	return (coor);
}

t_color	parser_color(char **split)
{
	t_color	col;

	col.r = ft_strtod(split[0]);
	col.g = ft_strtod(split[1]);
	col.b = ft_strtod(split[2]);
	return (col);
}
