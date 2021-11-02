/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 09:47:27 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 09:47:29 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "minirt.h"

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}				t_vector;

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}				t_color;

t_vector		new_vec(double x, double y, double z);
t_vector		ft_subtraction(t_vector *a, t_vector *b);
double			ft_prodt(t_vector a, t_vector b);
t_vector		ft_multScal(double aux, t_vector vec);
t_vector		ft_add(t_vector *a, t_vector *b);
t_vector		ft_div(t_vector *a, t_vector *b);
t_vector		ft_divScale(t_vector a, double aux);
t_vector		ft_cross(t_vector *a, t_vector *b);
double			ft_magnitude(t_vector vec);
t_vector		ft_normalize(t_vector vec);
t_color			ft_setupColor(double r, double g, double b);
t_color			ft_addColor(t_color col1, t_color col2);
t_color			ft_divColor(t_color col, double k);
void			min_max_color(t_color *result);

#endif
