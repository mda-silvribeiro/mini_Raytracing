/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:37:27 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 12:39:18 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vector	normal_at_cylinder(t_data *data, t_objects *obj)
{
	t_vector	p_c;
	t_vector	n_x_m;
	t_vector	nor;

	p_c = ft_subtraction(&data->rec.hit_point, &obj->cylinder.pos);
	n_x_m = ft_multScal(data->rec.m, obj->cylinder.n);
	nor = ft_subtraction(&p_c, &n_x_m);
	if (ft_prodt(nor, data->ray.dest) > 0)
		nor = ft_multScal(-1, nor);
	data->rec.normal = ft_normalize(data->rec.normal);
	return (nor);
}

t_vector	normal_at_triangle(t_data *data, t_objects *obj)
{
	t_vector	edge[2];
	t_vector	normal;

	edge[0] = ft_subtraction(&obj->triangle.spt, &obj->triangle.fp);
	edge[1] = ft_subtraction(&obj->triangle.tpt, &obj->triangle.fp);
	normal = ft_cross(&edge[0], &edge[1]);
	if (ft_prodt(data->ray.dest, normal) > 0)
		normal = ft_multScal(-1, normal);
	normal = ft_normalize(normal);
	return (normal);
}

void	calcul_normal_at_hit_point(t_data *data, t_objects *obj)
{
	if (obj->obj_type == SP)
		data->rec.normal
			= ft_subtraction(&data->rec.hit_point, &obj->sphere.center);
	else if (obj->obj_type == PL)
		data->rec.normal = obj->plane.plane_norm;
	else if (obj->obj_type == TR)
		data->rec.normal = normal_at_triangle(data, obj);
	else if (obj->obj_type == SQ)
		data->rec.normal = obj->square.or_vec;
	else if (obj->obj_type == CY)
		data->rec.normal = normal_at_cylinder(data, obj);
	data->rec.normal = ft_normalize(data->rec.normal);
}

int	intersection_ray_obj(t_data *data, t_objects *tmp_objs, t_ray *ray)
{
	double	t_hit;

	t_hit = 0;
	if (tmp_objs->obj_type == SP)
		t_hit = intersect_sphere(data, tmp_objs, ray);
	else if (tmp_objs->obj_type == PL)
		t_hit = intersect_plan(data, tmp_objs, ray);
	else if (tmp_objs->obj_type == SQ)
		t_hit = intersect_square(data, tmp_objs, ray);
	else if (tmp_objs->obj_type == TR)
		t_hit = intersect_triangle(data, tmp_objs, ray);
	else if (tmp_objs->obj_type == CY)
		t_hit = intersect_stCylinder(data, tmp_objs, ray);
	return (t_hit);
}

t_objects	*find_the_closest_obj(t_data *data, t_ray *ray, t_objects *obj)
{
	t_objects	*closest_obj;
	t_objects	*tmp_objs;

	tmp_objs = data->objects;
	closest_obj = NULL;
	while (tmp_objs)
	{
		if (tmp_objs != obj)
		{
			if (intersection_ray_obj(data, tmp_objs, ray) == 1)
			{
				if (!closest_obj && data->rec.t >= 0)
					data->rec.t_closest = data->rec.t;
				else if (data->rec.t < data->rec.t_closest && data->rec.t >= 0)
					data->rec.t_closest = data->rec.t;
				closest_obj = tmp_objs;
			}
		}
		tmp_objs = tmp_objs->next;
	}
	return (closest_obj);
}
