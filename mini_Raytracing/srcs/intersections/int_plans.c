/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_plans.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:29:26 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 12:30:11 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	intersect_plan(t_data *data, t_objects *obj, t_ray *ray)
{
	t_vector	dist_ray_pl;
	double		dist_dot_n;
	double		d_dot_n;

	dist_ray_pl = ft_subtraction(&ray->origin, &obj->plane.point_at_pl);
	dist_dot_n = ft_prodt(dist_ray_pl, obj->plane.plane_norm);
	d_dot_n = ft_prodt(ray->dest, obj->plane.plane_norm);
	if (d_dot_n != 0.0 && ((d_dot_n > 0 && dist_dot_n < 0)
			|| (d_dot_n < 0 && dist_dot_n > 0)))
	{
		data->rec.t = -(dist_dot_n / d_dot_n);
		if (data->rec.t < 0.0)
			return (0);
		return (1.0);
	}
	return (0);
}
