/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:57:54 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 12:59:07 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	new_vec(double x, double y, double z)
{
	t_vector	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_vector	ft_subtraction(t_vector *a, t_vector *b)
{
	return (new_vec(a->x - b->x, a->y - b->y, a->z - b->z));
}

double	ft_prodt(t_vector a, t_vector b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

t_vector	ft_multScal(double aux, t_vector vec)
{
	return (new_vec(vec.x * aux, vec.y * aux, vec.z * aux));
}

t_vector	ft_add(t_vector *a, t_vector *b)
{
	return (new_vec(a->x + b->x, a->y + b->y, a->z + b->z));
}
