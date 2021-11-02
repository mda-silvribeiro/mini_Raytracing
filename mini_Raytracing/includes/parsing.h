/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 09:28:12 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 09:47:57 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minirt.h"

double		ft_strtod(const char *str);
void		ft_pars_scene(t_data *data, char **av);
void		parser_resolution(t_data *data, char *line);
int			ft_ignore_whitespaces(char *line);
char		*check_spaces_between_comma(char *line);
void		parser_ambiant_light(t_data *data, char *line);
void		parser_light(t_data *data, char *line);
void		parser_camera(t_data *data, char *line);
void		parser_sphere(t_data *data, char *line);
void		parser_plane(t_data *data, char *line);
void		parser_square(t_data *data, char *line);
void		parser_cylinder(t_data *data, char *line);
void		parser_triangle(t_data *data, char *line);
t_vector	parser_vector(char **split);
t_color		parser_color(char **split);
void		exit_error(t_data *tmp, char *string);
void		ft_configCams(t_camera **alst, t_camera *new);
void		ft_configObjects(t_objects **alst, t_objects *new);
void		ft_configLight(t_light **alst, t_light *new);
void		ft_free_split(char **split);

int			ft_argumentsCount(char **s);
void		ft_checkColor(t_data *tmp, char **spt2);
void		ft_checkVector2(t_data *tmp, char **spt);
void		ft_checkVector(t_data *tmp, char **spt);
void		ft_checkScene(t_data *tmp);
void		ft_free_scene(t_data *data);

#endif
