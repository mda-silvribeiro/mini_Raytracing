/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_triangles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:36:43 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 12:37:18 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	intersect_triangle(t_data *data, t_objects *obj, t_ray *ray)
{
	t_vector	vec[5];
	double		det;
	double		invdet;
	double		u;
	double		v;

	vec[0] = ft_subtraction(&obj->triangle.spt, &obj->triangle.fp);
	vec[1] = ft_subtraction(&obj->triangle.tpt, &obj->triangle.fp);
	vec[2] = ft_cross(&ray->dest, &vec[1]);
	det = ft_prodt(vec[0], vec[2]);
	if (fabs(det) < 0.0000001)
		return (0);
	invdet = 1.0 / det;
	vec[4] = ft_subtraction(&ray->origin, &obj->triangle.fp);
	u = ft_prodt(vec[4], vec[2]) * invdet;
	if (u < 0.0 || u > 1.0)
		return (0);
	vec[3] = ft_cross(&vec[4], &vec[0]);
	v = ft_prodt(ray->dest, vec[3]) * invdet;
	if (v < 0.0 || u + v > 1.0)
		return (0);
	data->rec.t = ft_prodt(vec[1], vec[3]) * invdet;
	if (data->rec.t > 0.0000001)
		return (1);
	return (0);
}
