/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_spheres.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:30:23 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 12:34:11 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	intersect_sphere(t_data *data, t_objects *object, t_ray *ray)
{
	double		k[4];
	t_vector	oc;
	double		t[2];

	k[0] = ft_prodt(ray->dest, ray->dest);
	oc = ft_subtraction(&ray->origin, &object->sphere.center);
	k[1] = 2.0 * ft_prodt(ray->dest, oc);
	k[2] = ft_prodt(oc, oc) - (object->sphere.radius * object->sphere.radius);
	k[3] = k[1] * k[1] - 4 * k[0] * k[2];
	if (k[3] < 0.0)
		return (0);
	t[0] = (-k[1] - sqrt(k[3])) / (2.0 * k[0]);
	t[1] = (-k[1] + sqrt(k[3])) / (2.0 * k[0]);
	if (t[0] > 0)
		data->rec.t = t[0];
	else
		data->rec.t = t[1];
	if (data->rec.t < 0)
		return (0);
	return (1.0);
}
