/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 10:55:52 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 10:56:12 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_resolution(t_data *data)
{
	int	width;
	int	height;

	mlx_get_screen_size(data->mlx.mlx_ptr, &width, &height);
	if (data->mlx.x_res > width)
		data->mlx.x_res = width;
	if (data->mlx.y_res > height)
		data->mlx.y_res = height;
}

void	parser_resolution(t_data *data, char *line)
{
	char	**split_line;

	if (data->mlx.x_res != 0 || data->mlx.y_res != 0)
		exit_error(data, "You can't use the resolution twice in scene.");
	split_line = ft_split(line, ' ');
	if (ft_argumentsCount(split_line) != 3 || ft_strchr(*split_line, ','))
		exit_error(data, "The resolution have a width and height.");
	if (ft_strtod(split_line[1]) <= 0 || ft_strtod(split_line[2]) <= 0.0)
		exit_error(data, "The resolution can't be negative or null");
	data->mlx.x_res = ft_strtod(split_line[1]);
	data->mlx.y_res = ft_strtod(split_line[2]);
	check_resolution(data);
	ft_free_split(split_line);
}
