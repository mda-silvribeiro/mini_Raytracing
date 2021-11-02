/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:54:04 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 11:54:56 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	ft_divColor(t_color col, double k)
{
	t_color	tmp;

	tmp.r = col.r / k;
	tmp.g = col.g / k;
	tmp.b = col.b / k;
	return (tmp);
}

t_color	ft_multCol(t_color col1, t_color col2)
{
	t_color	tmp;

	tmp.r = col1.r * col2.r;
	tmp.g = col1.g * col2.g;
	tmp.b = col1.b * col2.b;
	return (tmp);
}
