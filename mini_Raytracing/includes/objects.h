/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 09:47:16 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 09:47:18 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "minirt.h"

typedef struct s_sphere
{
	t_vector	center;
	double		radius;
	t_color		s_color;
}				t_sphere;

typedef struct s_plane
{
	t_vector	point_at_pl;
	t_vector	plane_norm;
	t_color		pl_col;
}				t_plane;

typedef struct s_triangle
{
	t_vector	fp;
	t_vector	spt;
	t_vector	tpt;
	t_vector	norm_tr;
	t_color		tr_col;
}				t_triangle;

typedef struct s_square
{
	t_vector	sq_center;
	t_vector	or_vec;
	double		size_side;
	t_color		sq_col;
	t_vector	p1;
	t_vector	p2;
	t_vector	p3;
	t_vector	p4;
}				t_square;

typedef struct s_cylinder
{
	t_vector	pos;
	t_vector	n;
	double		diameter;
	double		height;
	t_color		col;
}				t_cylinder;

#endif
