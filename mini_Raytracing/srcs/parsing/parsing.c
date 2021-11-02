/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 10:56:19 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 10:57:20 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	ft_check_file_(char *file)
{
	int		i;
	int		j;
	char	**split;
	char	**check_name;

	i = 0;
	j = 0;
	i = ft_strlen(file);
	if (ft_strncmp(file + i - 3, ".rt", 3))
		exit_error(NULL, "The file should end with .rt");
	split = ft_split(file, '/');
	j = ft_argumentsCount(split);
	if (j >= 1)
	{
		check_name = ft_split(split[j - 1], '.');
		if (ft_argumentsCount(check_name) != 2)
			exit_error(NULL, "The name file in begin with point.");
		ft_free_split(check_name);
	}
	ft_free_split(split);
}

void	ft_parser_element(t_data *data, char *line)
{
	if (line[0] == 'R')
		parser_resolution(data, line);
	else if (line[0] == 'A')
		parser_ambiant_light(data, line);
	else if (line[0] == 'c' && line[1] == ' ')
		parser_camera(data, line);
	else if (line[0] == 'l' && line[1] == ' ')
		parser_light(data, line);
	else if (line[0] == 'p' && line[1] == 'l')
		parser_plane(data, line);
	else if (line[0] == 's' && line[1] == 'p')
		parser_sphere(data, line);
	else if (line[0] == 's' && line[1] == 'q')
		parser_square(data, line);
	else if (line[0] == 'c' && line[1] == 'y')
		parser_cylinder(data, line);
	else if (line[0] == 't' && line[1] == 'r')
		parser_triangle(data, line);
}

void	ft_pars_scene(t_data *data, char **av)
{
	int			fd;
	int			read;
	char		*line;
	extern int	errno;

	line = NULL;
	read = 0;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit_error(NULL, strerror(errno));
	ft_check_file_(av[1]);
	read = get_next_line(fd, &line);
	while (read > 0)
	{
		line = check_spaces_between_comma(line);
		ft_parser_element(data, line + ft_ignore_whitespaces(line));
		free(line);
		read = get_next_line(fd, &line);
	}
	line = check_spaces_between_comma(line);
	ft_parser_element(data, line + ft_ignore_whitespaces(line));
	ft_checkScene(data);
	free(line);
	close(fd);
}
