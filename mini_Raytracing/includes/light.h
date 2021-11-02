/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 09:24:21 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 09:25:07 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "minirt.h"

typedef struct s_light
{
	t_vector		position;
	double			kd;
	t_color			intensity;
	struct s_light	*next;
}				t_light;

typedef struct s_illum
{
	t_color	amb_col;
	double	ka;
}				t_illum;

#endif
