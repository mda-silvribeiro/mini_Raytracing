/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_cylinders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:12:35 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 12:29:00 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	check_the_solutions(t_data *data, double m, double t)
{
	data->rec.t = t;
	data->rec.m = m;
	return (1);
}

double	intersect_stCylinder(t_data *data, t_objects *obj, t_ray *ray)
{
	double		k[4];
	double		t[2];
	double		m[2];
	t_vector	oc;

	oc = ft_subtraction(&ray->origin, &obj->cylinder.pos);
	k[0] = 1 - pow(ft_prodt(ray->dest, obj->cylinder.n), 2);
	k[1] = 2 * (ft_prodt(ray->dest, oc) - (ft_prodt(ray->dest,
					obj->cylinder.n) * ft_prodt(oc, obj->cylinder.n)));
	k[2] = ft_prodt(oc, oc) - pow(ft_prodt(oc, obj->cylinder.n), 2)
		- pow(obj->cylinder.diameter / 2, 2);
	k[3] = k[1] * k[1] - 4 * k[0] * k[2];
	if (k[3] < 0.0)
		return (0);
	t[0] = (-k[1] - sqrt(k[3])) / (2.0 * k[0]);
	t[1] = (-k[1] + sqrt(k[3])) / (2.0 * k[0]);
	m[0] = ft_prodt(ray->dest, obj->cylinder.n)
		* t[0] + ft_prodt(oc, obj->cylinder.n);
	m[1] = ft_prodt(ray->dest, obj->cylinder.n)
		* t[1] + ft_prodt(oc, obj->cylinder.n);
	if (m[0] >= 0 && m[0] <= obj->cylinder.height)
		return (check_the_solutions(data, m[0], t[0]));
	else if (m[1] >= 0 && m[1] <= obj->cylinder.height)
		return (check_the_solutions(data, m[1], t[1]));
	return (0);
}
