/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 10:49:09 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 10:50:28 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parser_sphere(t_data *data, char *line)
{
	char		**split_line;
	char		**split_arg;
	t_objects	*obj;

	obj = malloc(sizeof(t_objects));
	if (!obj)
		exit_error(data, "Allocation error.");
	obj->obj_type = SP;
	split_line = ft_split(line, ' ');
	if (ft_argumentsCount(split_line) < 4
		|| ft_argumentsCount(split_line) > 5)
		exit_error(data, "Please check the sphere infos in scene.");
	split_arg = ft_split(split_line[1], ',');
	ft_checkVector(data, split_arg);
	obj->sphere.center = parser_vector(split_arg);
	if (ft_strtod(split_line[2]) < 0 || ft_strchr(split_line[2], ','))
		exit_error(data, "Check the radius sphere.");
	obj->sphere.radius = ft_strtod(split_line[2]);
	split_arg = ft_split(split_line[3], ',');
	ft_checkColor(data, split_arg);
	obj->sphere.s_color = parser_color(split_arg);
	ft_checkObjs(data, obj, split_line);
	ft_free_split(split_line);
	obj->next = NULL;
	ft_configObjects(&data->objects, obj);
}

void	parser_plane(t_data *data, char *line)
{
	char		**split_line;
	char		**split_arg;
	t_objects	*obj;

	obj = malloc(sizeof(t_objects));
	if (!obj)
		exit_error(data, "Allocation error.");
	obj->obj_type = PL;
	split_line = ft_split(line, ' ');
	if (ft_argumentsCount(split_line) < 4
		&& ft_argumentsCount(split_line) > 6)
		exit_error(data, "Check plane line in scene.");
	split_arg = ft_split(split_line[1], ',');
	ft_checkVector(data, split_arg);
	obj->plane.point_at_pl = parser_vector(split_arg);
	split_arg = ft_split(split_line[2], ',');
	ft_checkVector2(data, split_arg);
	obj->plane.plane_norm = parser_vector(split_arg);
	split_arg = ft_split(split_line[3], ',');
	ft_checkColor(data, split_arg);
	obj->plane.pl_col = parser_color(split_arg);
	ft_checkObjs(data, obj, split_line);
	ft_free_split(split_line);
	obj->next = NULL;
	ft_configObjects(&data->objects, obj);
}

static void	parser_square_2(t_data *data, char **split_line, t_objects *obj)
{
	char	**split_arg;

	if (ft_strtod(split_line[3]) < 0 || ft_strchr(split_line[3], ','))
		exit_error(data, "Check the square size_side it's mybe negative.");
	obj->square.size_side = ft_strtod(split_line[3]);
	split_arg = ft_split(split_line[4], ',');
	ft_checkColor(data, split_arg);
	obj->square.sq_col = parser_color(split_arg);
}

void	parser_square(t_data *data, char *line)
{
	char		**split_line;
	char		**split_arg;
	t_objects	*obj;

	obj = malloc(sizeof(t_objects));
	if (!obj)
		exit_error(data, "Allocation error.");
	obj->obj_type = SQ;
	split_line = ft_split(line, ' ');
	if (ft_argumentsCount(split_line) < 5
		|| ft_argumentsCount(split_line) > 7)
		exit_error(data, "Check the square struct in scene.");
	split_arg = ft_split(split_line[1], ',');
	ft_checkVector(data, split_arg);
	obj->square.sq_center = parser_vector(split_arg);
	split_arg = ft_split(split_line[2], ',');
	ft_checkVector2(data, split_arg);
	obj->square.or_vec = parser_vector(split_arg);
	parser_square_2(data, split_line, obj);
	ft_checkObjs(data, obj, split_line);
	ft_free_split(split_line);
	obj->next = NULL;
	ft_configObjects(&data->objects, obj);
}
