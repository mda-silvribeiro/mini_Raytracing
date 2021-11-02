/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_squares.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:34:27 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 12:35:50 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	intersect_supPlan(t_plane *plane, t_data *data, t_ray *ray)
{
	t_vector	dist_ray_pl;
	double		dist_dot_n;
	double		d_dot_n;

	dist_ray_pl = ft_subtraction(&ray->origin, &plane->point_at_pl);
	d_dot_n = ft_prodt(ray->dest, plane->plane_norm);
	if (d_dot_n != 0)
	{
		dist_dot_n = ft_prodt(dist_ray_pl, plane->plane_norm);
		data->rec.t = -dist_dot_n / d_dot_n;
		if (data->rec.t < 0)
			return (0);
		return (1);
	}
	return (0);
}

double	intersect_square(t_data *data, t_objects *obj, t_ray *ray)
{
	t_plane		plane;
	t_vector	tmp;
	double		i;
	t_vector	point;

	plane.point_at_pl = obj->square.sq_center;
	plane.plane_norm = obj->square.or_vec;
	i = intersect_supPlan(&plane, data, ray);
	if (i == 1)
	{
		point = point_of_hit(data->rec.t, *ray);
		tmp = ft_subtraction(&obj->square.sq_center, &point);
		if (fabs(tmp.x) <= (obj->square.size_side / 2)
			&& fabs(tmp.y) <= (obj->square.size_side / 2)
			&& fabs(tmp.z) <= (obj->square.size_side / 2))
			return (1.0);
		return (0);
	}
	return (0);
}
