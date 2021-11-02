/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 09:46:48 by mda-silv          #+#    #+#             */
/*   Updated: 2021/05/20 09:46:57 by mda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 100

int		get_next_line(int fd, char **line);
int		ft_index(char const *s, char c);
char	*ft_strnjoin_gnl(char *s1, char const *s2, long n);
void	*ft_memmove(void *dest, const void *src, unsigned long n);

#endif