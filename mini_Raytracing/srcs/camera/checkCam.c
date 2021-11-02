/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkCam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 10:31:23 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 10:31:25 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_trans_sphere(t_data *data, t_objects *obj, char **s_line)
{
	char	**s_arg;

	if (ft_argumentsCount(s_line) > 4)
	{
		s_arg = ft_split(s_line[4], ',');
		if (ft_argumentsCount(s_arg) != 3)
			exit_error(data, "Please check the rotation in sphere.");
		data->translation = parser_vector(s_arg);
		obj->sphere.center = ft_trans(obj->sphere.center,
				data->translation);
		ft_free_split(s_arg);
	}
}

void	ft_transRotCylinder(t_data *data, t_objects *obj, char **s_line)
{
	char	**s_arg;

	if (ft_argumentsCount(s_line) > 6)
	{
		if (s_line[6])
		{
			s_arg = ft_split(s_line[6], ',');
			if (ft_argumentsCount(s_arg) != 3)
				exit_error(data, "Please check the rotation in cylinder.");
			data->rotation = parser_vector(s_arg);
			obj->cylinder.n = ft_rotation(data->rotation,
					obj->cylinder.n);
			ft_free_split(s_arg);
		}
		if (s_line[7])
		{
			s_arg = ft_split(s_line[7], ',');
			if (ft_argumentsCount(s_arg) != 3)
				exit_error(data, "Please check the translation in cylinder.");
			data->translation = parser_vector(s_arg);
			obj->cylinder.pos = ft_trans(obj->cylinder.pos,
					data->translation);
			ft_free_split(s_arg);
		}
	}
}

void	ft_transRotPlane(t_data *data, t_objects *obj, char **s_line)
{
	char	**s_arg;

	if (ft_argumentsCount(s_line) > 4)
	{
		if (s_line[4])
		{
			s_arg = ft_split(s_line[4], ',');
			if (ft_argumentsCount(s_arg) != 3)
				exit_error(data, "Please check the rotation plane.");
			data->rotation = parser_vector(s_arg);
			obj->plane.plane_norm = ft_rotation(data->rotation,
					obj->plane.plane_norm);
			ft_free_split(s_arg);
		}
		if (s_line[5])
		{
			s_arg = ft_split(s_line[5], ',');
			if (ft_argumentsCount(s_arg) != 3)
				exit_error(data, "Please check the translation plane.");
			data->translation = parser_vector(s_arg);
			obj->plane.point_at_pl = ft_trans(obj->plane.point_at_pl,
					data->translation);
			ft_free_split(s_arg);
		}
	}
}

void	ft_transRotSquare(t_data *data, t_objects *obj, char **s_line)
{
	char	**s_arg;

	if (ft_argumentsCount(s_line) > 5)
	{
		if (s_line[4])
		{
			s_arg = ft_split(s_line[4], ',');
			if (ft_argumentsCount(s_arg) != 3)
				exit_error(data, "Please check the rotation square.");
			data->rotation = parser_vector(s_arg);
			obj->square.or_vec = ft_rotation(data->rotation,
					obj->square.or_vec);
			ft_free_split(s_arg);
		}
		if (s_line[5])
		{
			s_arg = ft_split(s_line[5], ',');
			if (ft_argumentsCount(s_arg) != 3)
				exit_error(data, "Please check the translation square.");
			data->translation = parser_vector(s_arg);
			obj->square.sq_center = ft_trans(obj->square.sq_center,
					data->translation);
			ft_free_split(s_arg);
		}
	}
}

void	ft_checkObjs(t_data *data, t_objects *obj, char **s_line)
{
	char	**s_arg;

	if (obj->obj_type == SP)
		ft_trans_sphere(data, obj, s_line);
	else if (obj->obj_type == CY)
		ft_transRotCylinder(data, obj, s_line);
	else if (obj->obj_type == PL)
		ft_transRotPlane(data, obj, s_line);
	else if (obj->obj_type == SQ)
		ft_transRotSquare(data, obj, s_line);
	else if (obj->obj_type == TR)
	{
		if (ft_argumentsCount(s_line) == 6)
		{
			s_arg = ft_split(s_line[5], ',');
			if (ft_argumentsCount(s_arg) != 3)
				exit_error(data, "Please check the translation triangle.");
			data->translation = parser_vector(s_arg);
			obj->triangle.fp = ft_trans(obj->triangle.fp, data->translation);
			obj->triangle.spt = ft_trans(obj->triangle.spt,
					data->translation);
			obj->triangle.tpt = ft_trans(obj->triangle.tpt, data->translation);
			ft_free_split(s_arg);
		}
	}
}
