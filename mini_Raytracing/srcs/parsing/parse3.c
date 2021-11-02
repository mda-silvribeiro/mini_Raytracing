/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 10:53:05 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 10:54:37 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	parser_cylinder_2(t_data *data, char **split_line, t_objects *obj)
{
	char	**split_arg;

	split_arg = ft_split(split_line[3], ',');
	ft_checkColor(data, split_arg);
	obj->cylinder.col = parser_color(split_arg);
	ft_free_split(split_arg);
	if (ft_strtod(split_line[4]) < 0 || ft_strchr(split_line[4], ','))
		exit_error(data, "Check cylinder diameter.");
	obj->cylinder.diameter = ft_strtod(split_line[4]);
	if (ft_strtod(split_line[5]) < 0 || ft_strchr(split_line[5], ','))
		exit_error(data, "Check cylinder height.");
	obj->cylinder.height = ft_strtod(split_line[5]);
}

void	parser_cylinder(t_data *data, char *line)
{
	char		**split_line;
	char		**split_arg;
	t_objects	*obj;

	obj = malloc(sizeof(t_objects));
	if (!obj)
		exit_error(data, "Allocation error.");
	obj->obj_type = CY;
	split_line = ft_split(line, ' ');
	if (ft_argumentsCount(split_line) < 6
		|| ft_argumentsCount(split_line) > 8)
		exit_error(data, "Check the cylinder infos in scene.");
	split_arg = ft_split(split_line[1], ',');
	ft_checkVector(data, split_arg);
	obj->cylinder.pos = parser_vector(split_arg);
	split_arg = ft_split(split_line[2], ',');
	ft_checkVector2(data, split_arg);
	obj->cylinder.n = parser_vector(split_arg);
	ft_free_split(split_arg);
	parser_cylinder_2(data, split_line, obj);
	ft_checkObjs(data, obj, split_line);
	obj->next = NULL;
	ft_free_split(split_line);
	ft_configObjects(&data->objects, obj);
}

static void	parser_triangle_2(t_data *data, char **split_line, t_objects *obj)
{
	char	**split_arg;

	split_arg = ft_split(split_line[1], ',');
	ft_checkVector(data, split_arg);
	obj->triangle.fp = parser_vector(split_arg);
	ft_free_split(split_arg);
	split_arg = ft_split(split_line[2], ',');
	ft_checkVector(data, split_arg);
	obj->triangle.spt = parser_vector(split_arg);
	split_arg = ft_split(split_line[3], ',');
	ft_checkVector(data, split_arg);
	obj->triangle.tpt = parser_vector(split_arg);
	ft_free_split(split_arg);
	split_arg = ft_split(split_line[4], ',');
	ft_checkColor(data, split_arg);
	obj->triangle.tr_col = parser_color(split_arg);
	ft_free_split(split_arg);
}

void	parser_triangle(t_data *data, char *line)
{
	char		**split_line;
	t_objects	*obj;

	obj = malloc(sizeof(t_objects));
	if (!obj)
		exit_error(data, "Allocation error.");
	obj->obj_type = TR;
	split_line = ft_split(line, ' ');
	if (ft_argumentsCount(split_line) < 5
		|| ft_argumentsCount(split_line) > 6)
		exit_error(data, "Check the triangle line.");
	parser_triangle_2(data, split_line, obj);
	ft_checkObjs(data, obj, split_line);
	ft_free_split(split_line);
	obj->next = NULL;
	ft_configObjects(&data->objects, obj);
}

int	ft_argumentsCount(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
