/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:59:12 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 13:00:02 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	ft_div(t_vector *a, t_vector *b)
{
	return (new_vec(a->x / b->x, a->y / b->y, a->z / b->z));
}

t_vector	ft_divScale(t_vector a, double aux)
{
	return (new_vec(a.x / aux, a.y / aux, a.z / aux));
}

t_vector	ft_cross(t_vector *a, t_vector *b)
{
	return (new_vec((a->y * b->z) - (a->z * b->y),
			(a->z * b->x) - (a->x * b->z),
			(a->x * b->y) - (a->y * b->x)));
}

double	ft_magnitude(t_vector vec)
{
	return (sqrt((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z)));
}

t_vector	ft_normalize(t_vector vec)
{
	return (ft_divScale(vec, ft_magnitude(vec)));
}
