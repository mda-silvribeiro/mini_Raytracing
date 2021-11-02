/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:55:02 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 12:00:16 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	ft_setupColor(double r, double g, double b)
{
	t_color	col;

	col.r = r;
	col.g = g;
	col.b = b;
	return (col);
}

void	min_max_color(t_color *result)
{
	if (result->r > 1.0)
		result->r = 1.0;
	if (result->g > 1.0)
		result->g = 1.0;
	if (result->b > 1.0)
		result->b = 1.0;
	if (result->r < 0.0)
		result->r = 0.0;
	if (result->g < 0.0)
		result->g = 0.0;
	if (result->b < 0.0)
		result->b = 0.0;
}

t_vector	point_of_hit(double t, t_ray r)
{
	t_vector	tmp;

	tmp.x = r.origin.x + t * r.dest.x;
	tmp.y = r.origin.y + t * r.dest.y;
	tmp.z = r.origin.z + t * r.dest.z;
	return (tmp);
}

t_color	ft_addColor(t_color col1, t_color col2)
{
	t_color	tmp;

	tmp.r = col1.r + col2.r;
	tmp.g = col1.g + col2.g;
	tmp.b = col1.b + col2.b;
	return (tmp);
}

t_color	ft_mulScaleCol(t_color col, double k)
{
	t_color	tmp;

	tmp.r = col.r * k;
	tmp.g = col.g * k;
	tmp.b = col.b * k;
	return (tmp);
}
