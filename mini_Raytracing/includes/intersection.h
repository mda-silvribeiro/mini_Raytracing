/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 09:24:02 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 09:47:42 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

# include "minirt.h"

double		intersect_sphere(t_data *data, t_objects *obect, t_ray *r);
double		intersect_plan(t_data *data, t_objects *obj, t_ray *r);
double		intersect_triangle(t_data *data, t_objects *obj, t_ray *ray);
double		intersect_square(t_data *data, t_objects *obj, t_ray *ray);
double		intersect_stCylinder(t_data *data, t_objects *obj, t_ray *ray);
t_vector	point_of_hit(double t, t_ray r);
t_objects	*find_the_closest_obj(t_data *data, t_ray *ray, t_objects *obj);
void		calcul_normal_at_hit_point(t_data *data, t_objects *obj);
int			intersection_ray_obj(t_data *data, t_objects *tmp_objs, t_ray *ray);

#endif
